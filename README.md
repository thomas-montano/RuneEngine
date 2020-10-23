![Private Eye Logo](https://github.com/ThomasMontanoGames/PrivateEye/blob/master/Logo.png)
# Rune Engine
This is the GitHub for developing the Rune Engine. The engine is being developed by Thomas Montano, a Senior at Missouri University of Science and Technology.

## Getting Started

Visual Studio 2017 or 2019 is recommended. Rune is officially untested on other development environments and is only supported by Windows.

You can check out the latest release of the engine here:

https://github.com/ThomasMontanoGames/RuneEngine/releases

## Setting up a Project

1. Add the path "Rune Engine Directory"/include in the C/C++ settings of your project.
2. Add the path "Rune Engine Directory"/lib in the linker settings of your project.
3. Link the LIB files in the linker settings of your project. Use RuneEngine-d.lib and RuneEngine-d.dll for debug builds.
4. Move the DLL files into your game's working directory.
5. Declare RUNE_PLATFORM_WINDOWS in the preprocessor definitions of your project.
6. #include <RuneEngine.h> in the files using the engine.

### Warning
Make sure you are building in 64-bit, Rune does not currently cupport 32-bit.

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

## Function Documentation
- [Doxygen](https://thomasmontanogames.github.io/PrivateEye/)
