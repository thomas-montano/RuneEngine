#pragma once

#include <RuneEngine.h>

class MenuBar : public rune::Drawable
{

public:
  bool createNewProject;
  bool initialMenu = true;

  std::string openProject();
  std::string openScene();

  std::string openDirectoryBrowser();
  std::string saveFileBrowser();

  virtual void draw(rune::RenderWindow&) override;

};