find_package(antlr4-runtime CONFIG REQUIRED)

add_library(
    PicoTorrentPQL
    STATIC
    generated/QueryBaseVisitor
    generated/QueryLexer
    generated/QueryParser
    generated/QueryVisitor
)

target_compile_definitions(
    PicoTorrentPQL
    PUBLIC
    -D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
    -DANTLR4CPP_STATIC
)

target_include_directories(
    PicoTorrentPQL
    INTERFACE
    generated/
)

target_link_libraries(
    PicoTorrentPQL
    PUBLIC
    antlr4_static
)
