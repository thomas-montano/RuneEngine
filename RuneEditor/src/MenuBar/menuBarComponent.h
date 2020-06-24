#pragma once

#include <RuneEngine.h>

class MenuBarComponent : public rune::Component
{
public:
  bool createNewProject;
  bool initialMenu = true;
  void update();

  std::string openProject();
  std::string openScene();

  std::string openDirectoryBrowser();
  std::string saveFileBrowser();

};