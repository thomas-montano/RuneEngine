#pragma once

#ifdef RUNE_PLATFORM_WINDOWS
  #ifdef RUNE_BUILD_DLL
    #define RUNE_ENGINE __declspec(dllexport)
  #else
    #define RUNE_ENGINE __declspec(dllimport)
  #endif
#else
  #error Rune only supports windows!
#endif