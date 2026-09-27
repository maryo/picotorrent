# PQL - the PicoTorrent Query Language

PQL is a simple query language for filtering torrents in PicoTorrent.

The generated parser files under `generated/` are checked into the repo, so
you only need to regenerate them when `Query.g4` changes. The C++ runtime
itself comes from the `antlr4` vcpkg port - only the generator (a Java tool,
kept in sync with the runtime's version) needs to be run manually.


## Building

Requires a JDK/JRE and the ANTLR tool jar matching the vendored runtime
version (currently 4.13.2, see `vcpkg.json`), downloadable from
https://www.antlr.org/download.html.

```
java -jar .\antlr-4.13.2-complete.jar -Dlanguage=Cpp -package pt::PQL -visitor -no-listener -o generated .\Query.g4
```
