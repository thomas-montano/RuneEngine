#pragma once

#include <RuneEngine.h>
#include "EngineDataStructures/runeEngineProject.h"
#include "SceneHierarchy/sceneHierarchyWindow.h"
#include "MenuBar/menuBar.h"
#include "InspectorTab/inspector.h"
#include "ResourcesTab/resourceTab.h"
#include "SceneViewport/sceneViewport.h"

class EditorWindow : public rune::GameScene
{

private:
  SceneHierarchyWindow sceneContents;
  MenuBar menuBar;
  InspectorTab inspectorTab;
  ResourceTab resourceTab;
  SceneViewPort viewPort;
  
  void setUpStyle(void);

public:

  static RuneEngineProject currentlyOpenProject;
  
  virtual void doInit(void);
  virtual void Draw(rune::RenderWindow&) override;

  virtual void updateVariable(void);
};