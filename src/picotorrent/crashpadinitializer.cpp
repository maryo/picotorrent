#include "crashpadinitializer.hpp"

#include <cstring>
#include <filesystem>

#include <boost/log/trivial.hpp>
#include <sentry.h>

#include "buildinfo.hpp"
#include "core/environment.hpp"

namespace fs = std::filesystem;
using pt::CrashpadInitializer;

void CrashpadInitializer::Initialize(std::shared_ptr<pt::Core::Environment> env)
{
    auto databasePath = env->GetApplicationDataPath() / "Crashpad" / "db";
    auto handlerPath = env->GetApplicationPath() / "crashpad_handler.exe";

    BOOST_LOG_TRIVIAL(info) << "Initializing Sentry (handler: " << handlerPath << ", database: " << databasePath << ")";

    if (!fs::exists(handlerPath))
    {
        BOOST_LOG_TRIVIAL(warning) << "Could not find crashpad_handler.exe, skipping initialization...";
        return;
    }

    std::error_code ec;
    bool exists = fs::exists(databasePath, ec);

    if (ec)
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to check if database path exists: " << ec;
        return;
    }

    if (!exists)
    {
        fs::create_directories(databasePath, ec);

        if (ec)
        {
            BOOST_LOG_TRIVIAL(error) << "Failed to create Crashpad database directories: " << ec;
            return;
        }
    }

    std::string environment = "Production";
    std::string release = "PicoTorrent-" + std::string(pt::BuildInfo::version());

    if (strcmp(pt::BuildInfo::branch(), "master") != 0)
    {
        environment = "Experimental";
        release = "";
    }

    sentry_options_t* options = sentry_options_new();
    sentry_options_set_dsn(options, env->GetCrashpadReportUrl().c_str());
    sentry_options_set_handler_pathw(options, handlerPath.wstring().c_str());
    sentry_options_set_database_pathw(options, databasePath.wstring().c_str());
    sentry_options_set_environment(options, environment.c_str());

    if (!release.empty())
    {
        sentry_options_set_release(options, release.c_str());
    }

    if (sentry_init(options) != 0)
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to initialize Sentry";
        return;
    }

    sentry_set_tag("branch", pt::BuildInfo::branch());
    sentry_set_tag("commitish", pt::BuildInfo::commitish());
    sentry_set_tag("version", pt::BuildInfo::semver());

    BOOST_LOG_TRIVIAL(info) << "Sentry initialized";
}
