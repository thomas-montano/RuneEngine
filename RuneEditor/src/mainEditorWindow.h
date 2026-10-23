#pragma once

#include <RuneEngine.h>
#include "EngineDataStructures/runeEngineProject.h"
#include "SceneHierarchy/sceneHierarchyWindow.h"
#include "MenuBar/menuBar.h"
#include "InspectorTab/inspector.h"
#include "ResourcesTab/resourceTab.h"
#include "SceneViewport/sceneViewport.h"

#include <SceneManager/SceneSerializer.h>

class EditorWindow : public rune::GameScene
{

private:
  static EditorWindow* editorWindow;

  SceneHierarchyWindow sceneContents;
  MenuBar menuBar;
  InspectorTab inspectorTab;
  ResourceTab resourceTab;
  SceneViewPort viewPort;
  bool initialSetUp = false;

  rune::Camera sceneCamera;

  rune::SceneSerializer serializer;

  void setUpStyle(void);

  EditorWindow()
    : currentlyOpenProject("")
  {
  
  }

public:

  static EditorWindow* getWindow()
  {
    if (!editorWindow)
    {
      editorWindow = new EditorWindow();
    }

    return editorWindow;
  }

  EditorWindow(const EditorWindow&) = delete;

  bool isSceneRunning = false;

  rune::FrameBuffer* viewPortBuffer;

  RuneEngineProject currentlyOpenProject;
  CreatedGameObject* selectedObject;

  virtual void doInit(void);
  virtual void Draw(rune::RenderWindow&) override;

  virtual void updateVariable(void);

  void startScene();
  void stopScene();
};