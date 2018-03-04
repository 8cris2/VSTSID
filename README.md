# VSTSID

This is a VST3.0 plug-in version of the [WebSID](https://www.igorski.nl/experiment/websid) Commodore 64
synthesizer.

## On compatibility

VST3.0 is great and all, but support across DAW's is poor (shout out to Bitwig Studio for being awesome).
For OS X users, this plugin can also be built as an (v2) Audio Unit (see below).

Depending on your host software having 32-bit or 64-bit support, you can best compile for a
wider range of architectures, e.g. by replacing all _cmake_ invocations listed here like so:

    cmake "-DCMAKE_OSX_ARCHITECTURES=x86_64;i386" ..

## Build instructions

The project uses [CMake](https://cmake.org) to generate the build system
after which you can use _make_ to build the application.

The project has been developed against the VST 3.6.9 Audio Plug-Ins SDK
on OS X (see dependencies listed below). It should work completely via
CLI without requiring XCode (apart from the Audio Unit build).
Windows and Linux builds are also provided, but are as yet untested (see _CMakeLists.txt_).

### Environment setup

Apart from requiring _CMake_ and a _g++_ compiler, the only other dependency is
the [VST SDK from Steinberg](https://www.steinberg.net/en/company/developers.html).
Update _CMakeLists.txt_ to point to the root of the Steinberg SDK installation
location (update "_VSTSDK_PATH_").

Additionally, the Steinberg VST sources need to be built as well. Following
Steinbergs guidelines, the target is a _/build_-subfolder of the _/VST3_SDK_-folder, e.g.:

Execute from the Steinberg VST SDK root:

    ./copy_vst2_to_vst3_sdk.sh
    cd VST3_SDK
    mkdir build
    cd build
    cmake ..
    make

The result being that in _{VSTSDK_PATH}/VST3_SDK/build/lib_ all
Steinberg VST libraries are prebuilt.

### Building VSTSID as a VST3 plugin

Run CMake to generate VSTSID's Makefile for your environment, e.g.:

    cmake .

After which you can run:

    make

To compile the plugin. The build output will be stored in _./build/VST3/vstsid.vst_
as well as copied to your systems VST3 plugin folder.

## Running the plugin

You can copy the build output into your system VST(3) folder and run it directly in a
VST host / DAW of your choice.

When debugging, you can also choose to run the plugin against Steinbergs validator
and editor host utilities:

    {VSTSDK_PATH}/build/bin/validator  build/VST3/vstsid.vst3
    {VSTSDK_PATH}/build/bin/editorhost build/VST3/vstsid.vst3
    
## Building VSTSID as an Audio Unit

To build VSTSID as an AU plugin for OS X, first build the _auwrapper_-project in the VST SDK (you can
find it in _public.sdk/source/vst/auwrapper/auwrapper.xcodeproj_).

All Audio Unit related code in this repository resides in the _./au/_-folder.

Update the Library search path so that it points to the directory where _libauwrapper.a_ exists
Search in the _./au/_-folder for AUWRAPPER_CHANGE and change the settings accordingly in the following files:

 * _audiounitconfig.h_
 * _Info.plist_
 * _the "Make Links Script"_ for easier debugging/development

Build. For the release version, you must place a copy of the VST 3 build in the resource folder of the bundle
named _"plugin.vst3"_.
