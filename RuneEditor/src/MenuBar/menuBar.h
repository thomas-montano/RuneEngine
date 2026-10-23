#pragma once

#include <RuneEngine.h>

class RuneEngineProject;

class MenuBar : public rune::Drawable
{

public:
  bool createNewProject;
  bool initialMenu = true;

  RuneEngineProject openProject();
  std::string openScene();

  std::string openDirectoryBrowser();
  std::string saveFileBrowser();

  void displayComponents();

  virtual void draw(rune::RenderWindow&) override;

};