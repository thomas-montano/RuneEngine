![Private Eye Logo](https://github.com/ThomasMontanoGames/PrivateEye/blob/master/Logo.png)
# Rune Engine
This is the GitHub for developing the Rune Engine being used by the game Private Eye. The game and engine are being developed by Thomas Montano, a Senior at Missouri University of Science and Technology.

## Getting Started

Visual Studio 2017 or 2019 is recommended. Rune is officially untested on other development environments and is only supported by Windows.

You can clone the repository to a local destination using git:

`git clone https://github.com/ThomasMontanoGames/PrivateEye.git`

## Setting up a Project

1. Link the LIB file in the linker settings of your project.
2. Move the DLL file into your game's working directory.
3. Declare RUNE_PLATFORM_WINDOWS in the preprocessor definitions of your project.
4. Add the path "Rune Engine Directory"/include in the C/C++ settings of your project.
5. #include <RuneEngine.h> in all files using the engine.

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
