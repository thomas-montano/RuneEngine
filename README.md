![Private Eye Logo](Logo.png)
# Rune Engine
This is the GitHub for the Rune Engine. The engine was developed by Thomas Montano from 2020 to 2021.

## Project Documentation
- [Doxygen](https://thomas-montano.github.io/RuneEngine/)

## Getting Started

Visual Studio 2022 or later is recommended. Rune is officially untested on other development environments and is only supported by Windows.

To build the engine from source, open RuneEngine.sln and build the x64 configuration.

You can check out the latest release of the engine here:

https://github.com/thomas-montano/RuneEngine/releases

## Setting up a Project

1. Add the path "Rune Engine Directory"/RuneEngine/src in the C/C++ settings of your project.
2. Add the path "Rune Engine Directory"/bin/Release-x64/RuneEngine (or Debug-x64) in the linker settings of your project.
3. Link the LIB files in the linker settings of your project. Use RuneEngine-d.lib and RuneEngine-d.dll for debug builds.
4. Move the DLL files into your game's working directory.
5. Declare RUNE_PLATFORM_WINDOWS in the preprocessor definitions of your project.
6. #include <RuneEngine.h> in the files using the engine.

### Warning
Make sure you are building in 64-bit, Rune does not currently support 32-bit.

## Engine Features
- Full In-Engine Visual Editor
- Custom 2D renderer
- Custom Physics Engine
- Customizable Game Objects
- Particle System
- Lighting System
- Physically Accurate Collisions
- Animated Sprites
- Debug Interface with imgui
- Tile workflow and sprite workflow
