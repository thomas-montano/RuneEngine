#pragma once

#include <RuneEngine.h>
#include "EngineDataStructures/runeEngineProject.h"
#include "SceneHierarchy/sceneHierarchyWindow.h"

class EditorWindow : public rune::GameScene
{

private:
  SceneHierarchyWindow sceneContents;

public:

  static RuneEngineProject currentlyOpenProject;
  
  virtual void doInit(void);

  virtual void updateVariable(void);
};