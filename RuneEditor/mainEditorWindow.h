#pragma once

#include <RuneEngine.h>
#include "EngineDataStructures/runeEngineProject.h"
#include "SceneHierarchy/sceneHierarchyWindow.h"
#include "MenuBar/menuBar.h"
#include "InspectorTab/inspector.h"
#include "ResourcesTab/resourceTab.h"
#include "SceneViewport/sceneViewport.h"
#include <src/player.h>

class EditorWindow : public rune::GameScene
{

private:
  SceneHierarchyWindow sceneContents;
  MenuBar menuBar;
  InspectorTab inspectorTab;
  ResourceTab resourceTab;
  SceneViewPort viewPort;

  Player player;

  bool initialSetUp = false;

  rune::Camera sceneCamera;
  
  void setUpStyle(void);

public:

  rune::FrameBuffer* viewPortBuffer;

  static RuneEngineProject currentlyOpenProject;
  static CreatedGameObject* selectedObject;

  virtual void doInit(void);
  virtual void Draw(rune::RenderWindow&) override;

  virtual void updateVariable(void);
};