#pragma once

#include <RuneEngine.h>

class MenuBarComponent : public rune::Component
{
public:
  bool createNewProject;
  void update();

};