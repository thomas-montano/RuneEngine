/**
 * \class rune::Console
 * \brief  A terminal that can be used by the user to call functions at run time.
 * 
 * \author Thomas
 * \date   May 2020
 */

#pragma once

#ifndef CONSOLE_H_DEFINED
#define CONSOLE_H_DEFINED

#include "core.h"
#include <vector>
#include <string>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>

namespace rune{

class RUNE_ENGINE Console
{

private:
  char InputBuf[256];
  std::vector<std::string> log;

public:
  std::string update();

};
}

#endif