#include "torrentlistview.hpp"

#include <wx/math.h>
#include <wx/msw/private.h>
#include <wx/msw/uxtheme.h>
#include <wx/persist.h>
#include <wx/settings.h>

#include "../bittorrent/torrenthandle.hpp"
#include "models/torrentlistmodel.hpp"
#include "persistence/persistenttorrentlistview.hpp"
#include "translator.hpp"

using pt::UI::TorrentListView;
using pt::UI::Models::TorrentListModel;

namespace
{
    RECT ConvertToRECT(wxDC& dc, wxRect const& rect)
    {
        RECT rc;
        wxCopyRectToRECT(dc.GetImpl()->MSWApplyWXTransform(rect), rc);
        return rc;
    }

    // wxDataViewProgressRenderer only draws the bar itself - there is no
    // built-in way to also show the percentage as text, so track the value
    // ourselves and draw it centered on top of the bar.
    //
    // We also draw the bar itself rather than delegating to
    // wxDataViewProgressRenderer::Render(): that ends up in wx's own
    // wxRendererXP::DrawGauge() (src/msw/renderer.cpp), which opens the
    // "PROGRESS" UxTheme class without ever requesting its dark mode
    // variant - so in dark mode the filled and unfilled parts of the bar
    // come out barely distinguishable. This is already fixed on wx's
    // unreleased master (requesting "DarkMode_DarkTheme::Progress"), just
    // not yet in the 3.3.3 release we build against. Requesting that class
    // ourselves fixes it the same way; wxUxThemeHandle only substitutes it
    // when dark mode is actually active, so light mode is unaffected.
    //
    // Drawing it ourselves also lets us split the percentage text color to
    // match what it's drawn over - the same technique qBittorrent gets from
    // Qt's Fusion progress bar style: white text on the filled part,
    // ordinary window text color on the unfilled part. A single fixed text
    // color is never reliably readable on both, in either light or dark
    // mode, selected or not.
    class ProgressWithLabelRenderer : public wxDataViewProgressRenderer
    {
    public:
        bool SetValue(wxVariant const& value) override
        {
            m_progress = value.GetLong();
            return wxDataViewProgressRenderer::SetValue(value);
        }

        bool Render(wxRect cell, wxDC* dc, int state) override
        {
            wxWindow* win = GetView();
            wxUxThemeHandle theme(win, L"PROGRESS", L"DarkMode_DarkTheme::Progress");

            wxRect fillRect = cell;

            if (theme)
            {
                RECT const barRect = ConvertToRECT(*dc, cell);
                theme.DrawBackground(GetHdcOf(dc->GetTempHDC()), barRect, PP_BAR);

                RECT contentRect;
                ::GetThemeBackgroundContentRect(
                    theme,
                    GetHdcOf(dc->GetTempHDC()),
                    PP_BAR,
                    0,
                    &barRect,
                    &contentRect);

                contentRect.right = contentRect.left
                    + wxMulDivInt32(contentRect.right - contentRect.left, m_progress, 100);

                // The theme's own PP_CHUNK is a fixed green with no way to
                // recolor it (no alternate class name, no PBM_SETBARCOLOR
                // equivalent for a part drawn this way) - fill it ourselves
                // instead, in the system accent color, so it matches the
                // user's Windows theme.
                dc->SetPen(*wxTRANSPARENT_PEN);
                dc->SetBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
                dc->DrawRectangle(wxRect(
                    contentRect.left,
                    contentRect.top,
                    contentRect.right - contentRect.left,
                    contentRect.bottom - contentRect.top));

                fillRect = wxRect(
                    contentRect.left,
                    contentRect.top,
                    contentRect.right - contentRect.left,
                    contentRect.bottom - contentRect.top);
            }
            else
            {
                // No theme support at all (classic/unthemed desktop) - fall
                // back to the plain, untextured gauge and just estimate the
                // fill width ourselves for the text color split below.
                wxDataViewProgressRenderer::Render(cell, dc, state);
                fillRect.width = wxMulDivInt32(cell.width, m_progress, 100);
            }

            DrawLabel(cell, fillRect, dc);

            return true;
        }

        wxSize GetSize() const override
        {
            return GetView()->FromDIP(wxSize(-1, 16));
        }

    private:
        void DrawLabel(wxRect const& cell, wxRect const& fillRect, wxDC* dc)
        {
            wxString const text = wxString::Format("%d%%", m_progress);
            wxSize const textSize = dc->GetTextExtent(text);
            wxPoint const pos(
                cell.x + (cell.width - textSize.x) / 2,
                cell.y + (cell.height - textSize.y) / 2);

            wxColour const savedForeground = dc->GetTextForeground();

            // Filled part: fixed white, readable on any reasonably
            // saturated accent color.
            dc->SetClippingRegion(fillRect);
            dc->SetTextForeground(*wxWHITE);
            dc->DrawText(text, pos);
            dc->DestroyClippingRegion();

            // Unfilled part: ordinary window text color, so it stays
            // correct in both light and dark mode without us having to
            // detect which one is active.
            wxRect trackRect = cell;
            trackRect.x = fillRect.GetRight() + 1;
            trackRect.width = cell.GetRight() - trackRect.x + 1;

            dc->SetClippingRegion(trackRect);
            dc->SetTextForeground(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
            dc->DrawText(text, pos);
            dc->DestroyClippingRegion();

            dc->SetTextForeground(savedForeground);
        }

        long m_progress = 0;
    };
}

TorrentListView::TorrentListView(wxWindow* parent, wxWindowID id, pt::UI::Models::TorrentListModel* model)
    : wxDataViewCtrl(parent, id, wxDefaultPosition, wxDefaultSize, wxDV_MULTIPLE, wxDefaultValidator, "TorrentListView"),
    m_model(model)
{
    this->AssociateModel(m_model);
    m_model->DecRef();

    auto defaultFlags = wxDATAVIEW_COL_REORDERABLE | wxDATAVIEW_COL_RESIZABLE | wxDATAVIEW_COL_SORTABLE;

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("name"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::Name,
                FromDIP(180),
                wxALIGN_NOT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("queue_position"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::QueuePosition,
                FromDIP(30),
                wxALIGN_RIGHT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("size"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::Size,
                FromDIP(80),
                wxALIGN_RIGHT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("size_remaining"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::SizeRemaining,
                FromDIP(80),
                wxALIGN_RIGHT,
                defaultFlags),
            true));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("status"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::Status,
                FromDIP(120),
                wxALIGN_NOT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("progress"),
                new ProgressWithLabelRenderer(),
                TorrentListModel::Columns::Progress,
                FromDIP(100),
                wxALIGN_NOT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("eta"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::ETA,
                FromDIP(80),
                wxALIGN_RIGHT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("dl"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::DownloadSpeed,
                FromDIP(80),
                wxALIGN_RIGHT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("ul"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::UploadSpeed,
                FromDIP(80),
                wxALIGN_RIGHT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("availability"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::Availability,
                FromDIP(80),
                wxALIGN_RIGHT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("ratio"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::Ratio,
                FromDIP(80),
                wxALIGN_RIGHT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("seeds"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::Seeds,
                FromDIP(80),
                wxALIGN_RIGHT,
                wxDATAVIEW_COL_REORDERABLE | wxDATAVIEW_COL_RESIZABLE)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("peers"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::Peers,
                FromDIP(80),
                wxALIGN_RIGHT,
                wxDATAVIEW_COL_REORDERABLE | wxDATAVIEW_COL_RESIZABLE)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("added_on"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::AddedOn,
                FromDIP(120),
                wxALIGN_RIGHT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("completed_on"),
                new wxDataViewTextRenderer(),
                TorrentListModel::Columns::CompletedOn,
                FromDIP(120),
                wxALIGN_RIGHT,
                defaultFlags)));

    m_columns.push_back(
        ColumnMetadata(
            new wxDataViewColumn(
                i18n("label"),
                new wxDataViewIconTextRenderer(),
                TorrentListModel::Columns::Label,
                FromDIP(80),
                wxALIGN_LEFT,
                defaultFlags),
            true));

    /*
    nameCol->GetRenderer()->EnableEllipsize(wxELLIPSIZE_END);
    statusCol->GetRenderer()->EnableEllipsize(wxELLIPSIZE_END);*/

    // Just add all columns. The persistence manager will set the saved
    // widths, order and hidden attributes. Otherwise we use our defaults.
    for (auto const& cmd : m_columns)
    {
        InsertColumn(GetColumnCount(), cmd.column);
    }

    if (!wxPersistenceManager::Get().RegisterAndRestore(this))
    {
        for (auto const& cmd : m_columns)
        {
            cmd.column->SetHidden(cmd.hidden);
        }
    }

    // insert the "fake" column last, always
    AppendColumn(new wxDataViewColumn(wxEmptyString, new wxDataViewTextRenderer(), TorrentListModel::Columns::_Max, 0, wxALIGN_CENTER, 0));

    // Keyboard accelerators
    std::vector<wxAcceleratorEntry> entries =
    {
        wxAcceleratorEntry(wxACCEL_CTRL,   int('A'),   ptID_KEY_SELECT_ALL),
        wxAcceleratorEntry(wxACCEL_NORMAL, WXK_DELETE, ptID_KEY_DELETE),
        wxAcceleratorEntry(wxACCEL_SHIFT,  WXK_DELETE, ptID_KEY_DELETE_FILES),
    };

    this->SetAcceleratorTable(wxAcceleratorTable(static_cast<int>(entries.size()), entries.data()));

    this->Bind(wxEVT_DATAVIEW_COLUMN_HEADER_RIGHT_CLICK, &TorrentListView::ShowHeaderContextMenu, this);

    this->Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&)
        {
            wxDataViewItemArray items;
            this->GetSelections(items);

            if (items.IsEmpty()) { return; }

            for (wxDataViewItem& item : items)
            {
                m_model->GetTorrentFromItem(item)->Remove();
            }
        },
        ptID_KEY_DELETE);

    this->Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&)
        {
            wxDataViewItemArray items;
            this->GetSelections(items);

            if (items.IsEmpty()) { return; }

            if (wxMessageBox(
                i18n("confirm_remove_description"),
                i18n("confirm_remove"),
                wxOK | wxCANCEL | wxICON_INFORMATION,
                m_parent) != wxOK) {
                return;
            }

            for (wxDataViewItem& item : items)
            {
                m_model->GetTorrentFromItem(item)->RemoveFiles();
            }
        },
        ptID_KEY_DELETE_FILES);

    this->Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&)
        {
            this->SelectAll();
            wxPostEvent(
                GetParent(),
                wxCommandEvent(wxEVT_DATAVIEW_SELECTION_CHANGED, this->GetId()));
        },
        ptID_KEY_SELECT_ALL);
}

TorrentListView::~TorrentListView()
{
}

void TorrentListView::ShowHeaderContextMenu(wxCommandEvent&)
{
    wxMenu menu;

    // Do not iterate through the last column since it is the one we
    // append to prevent the last real column to stretch

    for (size_t i = 0; i < GetColumnCount() - 1; i++)
    {
        auto col = GetColumnAt(i);
        auto item = menu.Append(wxID_HIGHEST + i, col->GetTitle());
        item->SetCheckable(true);
        item->Check(!col->IsHidden());
    }

    menu.Bind(
        wxEVT_MENU,
        [this](wxCommandEvent& evt)
        {
            auto col = GetColumnAt(evt.GetId() - wxID_HIGHEST);
            col->SetHidden(!col->IsHidden());
        });

    PopupMenu(&menu);
}
