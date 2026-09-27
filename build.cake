#tool  "nuget:?package=GitVersion.CommandLine&version=5.12.0"
#tool  "nuget:?package=WiX&version=3.11.2"

//////////////////////////////////////////////////////////////////////
// ARGUMENTS
//////////////////////////////////////////////////////////////////////

var target        = Argument("target", "Default");
var configuration = Argument("configuration", "Release");
var platform      = Argument("platform", "x64");
var vcpkgTriplet  = Argument("vcpkg-triplet", "x64-windows-static-md");

// Parameters
var OutputDirectory       = Directory("./build-" + platform);
var BuildDirectory        = OutputDirectory + Directory(configuration);
var PackagesDirectory     = BuildDirectory + Directory("packages");
var PublishDirectory      = BuildDirectory + Directory("publish");
var BootstrapperDirectory = Directory("./src/installer/bin") + Directory(configuration);
var ResourceDirectory     = Directory("./res");

var Version            = GitVersion();
var Installer          = string.Format("PicoTorrent-{0}-{1}.msi", Version.SemVer, platform);
var InstallerBundle    = string.Format("PicoTorrent-{0}-{1}.exe", Version.SemVer, platform);
var PortablePackage    = string.Format("PicoTorrent-{0}-{1}.zip", Version.SemVer, platform);
var SymbolsPackage     = string.Format("PicoTorrent-{0}-{1}.symbols.zip", Version.SemVer, platform);

//////////////////////////////////////////////////////////////////////
// TASKS
//////////////////////////////////////////////////////////////////////

Task("Clean")
    .Does(() =>
{
    CleanDirectory(BootstrapperDirectory);
    CleanDirectory(BuildDirectory);

    // CleanDirectory(BuildDirectory) only wipes build-x64/Release - it leaves
    // the top-level CMakeCache.txt/CMakeFiles (one directory up, in
    // OutputDirectory) untouched. A stale cache there can keep resolving
    // find_package() calls against whatever state existed the first time
    // CMake ran, silently hiding real configuration errors on later runs.
    // (vcpkg_installed/ is intentionally left alone - wiping it would force
    // every dependency to rebuild from scratch on every clean.)
    var cmakeCache = OutputDirectory + File("CMakeCache.txt");
    var cmakeFiles = OutputDirectory + Directory("CMakeFiles");

    if (FileExists(cmakeCache))
    {
        DeleteFile(cmakeCache);
    }

    if (DirectoryExists(cmakeFiles))
    {
        DeleteDirectory(cmakeFiles, new DeleteDirectorySettings { Recursive = true, Force = true });
    }
});

Task("Generate-Project")
    .IsDependentOn("Clean")
    .Does(() =>
{
    var cmakePlatform = platform == "x86" ? "Win32" : "x64";

    var args = new ProcessArgumentBuilder()
        .Append("-S").AppendQuoted(".")
        .Append("-B").AppendQuoted(OutputDirectory.Path.FullPath)
        .Append("-A").AppendQuoted(cmakePlatform)
        .Append($"-DGITVERSION_VAR_BRANCHNAME={Version.BranchName}")
        .Append($"-DGITVERSION_VAR_SEMVER={Version.SemVer}")
        .Append($"-DGITVERSION_VAR_SHORTSHA={Version.Sha.Substring(0,7)}")
        .Append($"-DGITVERSION_VAR_VERSION_MAJOR={Version.Major}")
        .Append($"-DGITVERSION_VAR_VERSION_MINOR={Version.Minor}")
        .Append($"-DGITVERSION_VAR_VERSION_PATCH={Version.Patch}")
        .Append($"-DGITVERSION_VAR_VERSION={Version.MajorMinorPatch}")
        .Append($"-DVCPKG_TARGET_TRIPLET={vcpkgTriplet}")
        .Append("-DCMAKE_POLICY_VERSION_MINIMUM=3.5")
        .Append("-DCMAKE_CONFIGURATION_TYPES=Release");

    var exitCode = StartProcess("cmake", new ProcessSettings { Arguments = args });
    if (exitCode != 0)
    {
        throw new Exception($"CMake: Process returned an error (exit code {exitCode}).");
    }
});

Task("Build")
    .IsDependentOn("Generate-Project")
    .Does(() =>
{
    var settings = new MSBuildSettings()
        .SetConfiguration(configuration)
        .SetMaxCpuCount(0);
    if(platform == "x86")
    {
        settings.WithProperty("Platform", "Win32")
                .SetPlatformTarget(PlatformTarget.x86);
    }
    else
    {
        settings.WithProperty("Platform", "x64")
                .SetPlatformTarget(PlatformTarget.x64);
    }

    MSBuild(OutputDirectory + File("PicoTorrent.vcxproj"), settings);

    // Plugins
    MSBuild(OutputDirectory + File("Plugin_Updater.vcxproj"), settings);
});

Task("Setup-Publish-Directory")
    .IsDependentOn("Build")
    .Does(() =>
{
    var files = new FilePath[]
    {
        MakeAbsolute(BuildDirectory + File("PicoTorrent.exe")),
        MakeAbsolute(BuildDirectory + File("coredb.sqlite")),
        MakeAbsolute(BuildDirectory + File("crashpad_handler.exe")),
        MakeAbsolute(BuildDirectory + File("Plugin_Updater.dll")),
    };

    CreateDirectory(PublishDirectory);

    CopyFiles(
        files,            // Source
        PublishDirectory, // Target
        true);            // Preserve folder structure
});

Task("Build-Installer")
    .IsDependentOn("Build")
    .IsDependentOn("Setup-Publish-Directory")
    .Does(() =>
{
    var arch = Architecture.X64;

    if(platform == "x86")
    {
        arch = Architecture.X86;
    }

    var sourceFiles = new FilePath[]
    {
        "./packaging/WiX/PicoTorrent.wxs",
        "./packaging/WiX/PicoTorrent.Components.wxs",
        "./packaging/WiX/PicoTorrent.Directories.wxs"
    };

    var objFiles = new FilePath[]
    {
        BuildDirectory + File("PicoTorrent.wixobj"),
        BuildDirectory + File("PicoTorrent.Components.wixobj"),
        BuildDirectory + File("PicoTorrent.Directories.wixobj")
    };

    WiXCandle(sourceFiles, new CandleSettings
    {
        Architecture = arch,
        Defines = new Dictionary<string, string>
        {
            { "Configuration", configuration },
            { "PublishDirectory", PublishDirectory },
            { "Platform", platform },
            { "ResourceDirectory", ResourceDirectory },
            { "Version", Version.MajorMinorPatch }
        },
        Extensions = new [] { "WixFirewallExtension", "WixUtilExtension" },
        OutputDirectory = BuildDirectory
    });

    WiXLight(objFiles, new LightSettings
    {
        ArgumentCustomization = args =>
            args.Append("-sice:ICE38")
                .Append("-sice:ICE91"),
        Extensions = new [] { "WixFirewallExtension", "WixUtilExtension" },
        OutputFile = PackagesDirectory + File(Installer)
    });
});

Task("Build-Installer-Bootstrapper")
    .Does(() =>
{
    var settings = new MSBuildSettings()
        .SetConfiguration(configuration)
        .SetMaxCpuCount(0);

    MSBuild("./src/installer/PicoTorrentBootstrapper.sln", settings);
});

Task("Build-Installer-Bundle")
    .IsDependentOn("Build-Installer")
    .IsDependentOn("Build-Installer-Bootstrapper")
    .Does(() =>
{
    var arch = Architecture.X64;

    if(platform == "x86")
    {
        arch = Architecture.X86;
    }

    WiXCandle("./packaging/WiX/PicoTorrentBundle.wxs", new CandleSettings
    {
        Architecture = arch,
        Extensions = new [] { "WixBalExtension", "WixNetFxExtension", "WixUtilExtension" },
        Defines = new Dictionary<string, string>
        {
            { "PicoTorrentInstaller", PackagesDirectory + File(Installer) },
            { "Platform", platform },
            { "Version", Version.MajorMinorPatch }
        },
        OutputDirectory = BuildDirectory
    });

    WiXLight((BuildDirectory + File("PicoTorrentBundle.wixobj")).ToString(), new LightSettings
    {
        Extensions = new [] { "WixBalExtension", "WixNetFxExtension", "WixUtilExtension" },
        OutputFile = PackagesDirectory + File(InstallerBundle)
    });
});

Task("Build-Portable-Package")
    .IsDependentOn("Build")
    .IsDependentOn("Setup-Publish-Directory")
    .Does(() =>
{
    Zip(PublishDirectory, PackagesDirectory + File(PortablePackage));
});

Task("Build-Symbols-Package")
    .IsDependentOn("Build")
    .Does(() =>
{
    var files = new FilePath[]
    {
        BuildDirectory + File("PicoTorrent.pdb"),
    };

    Zip(BuildDirectory, PackagesDirectory + File(SymbolsPackage), files);
});

//////////////////////////////////////////////////////////////////////
// TASK TARGETS
//////////////////////////////////////////////////////////////////////

Task("Default")
    .IsDependentOn("Build")
    ;

Task("Publish")
    .IsDependentOn("Build")
    .IsDependentOn("Build-Installer")
    .IsDependentOn("Build-Installer-Bundle")
    .IsDependentOn("Build-Portable-Package")
    .IsDependentOn("Build-Symbols-Package");

//////////////////////////////////////////////////////////////////////
// EXECUTION
//////////////////////////////////////////////////////////////////////

RunTarget(target);
