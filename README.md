# PicoTorrent

![CI](https://github.com/picotorrent/picotorrent/workflows/CI/badge.svg)
[![Discord](https://img.shields.io/discord/759537913205227580)](https://discord.gg/tV3dFrv)

A tiny, hackable BitTorrent client written in modern C++. Based on
Rasterbar-libtorrent to provide high performance and low memory usage.

<p align="center">
    <img src="res/screenshot1.png?raw=true" width="614" />
</p>


## Quick facts

- Full support for BitTorrent 2.0 ([BEP-52](http://bittorrent.org/beps/bep_0052.html)), v1, v2 and v1+v2 hybrid torrents.
- Supports DHT, PeX, LSD, UPnP.
- (Azureus-style) peer ID: `-PI-`. Example: `-PI0151-` (major: 0, minor: 15, patch: 1).
- User agent: `PicoTorrent/x.y.z`.
- Native look-and-feel across Windows versions.
- Easy to use with high performance.

*The portable version of PicoTorrent requires manual installation of [the latest Microsoft Visual C++ Redistributable](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist).*


## Download for Windows

[![Download zip](https://custom-icon-badges.demolab.com/badge/-Download-blue?style=for-the-badge&logo=download&logoColor=white "Download zip")](https://github.com/picotorrent/picotorrent/releases)


## Building PicoTorrent

To successfully build PicoTorrent, you need the following applications
installed,

 * [CMake (>= v3.14)](https://cmake.org/download/).
 * [Visual Studio 2022 Build Tools](https://visualstudio.microsoft.com/downloads/) (or newer, or regular Visual Studio) with the C++ toolset.
 * [.NET SDK](https://dotnet.microsoft.com/download). Used for the build scripts.
 * [.NET Framework 4.8.1 Developer Pack](https://dotnet.microsoft.com/download/dotnet-framework) (only needed to build the installer bootstrapper).

All other dependencies (Boost, OpenSSL, libtorrent, wxWidgets, fmt,
nlohmann-json, sqlite3, antlr4, sentry-native, ...) are fetched and built
automatically through the bundled [vcpkg](https://vcpkg.io) submodule - no
manual installation needed.

```
λ git submodule update --init --recursive
λ dotnet tool restore
λ dotnet cake --platform=[x86|x64] --configuration=[Debug|Release] --vcpkg-triplet=[x86|x64]-windows-static-md-release
```


## Translations

PicoTorrent uses [Weblate](https://translate.picotorrent.org/) to handle the translation process. If you want to help, feel free to signup and give your contribution.


## License

Copyright (c) Viktor Elofsson and contributors. PicoTorrent is provided
as-is under the MIT license. For more information see [LICENSE](LICENSE).
