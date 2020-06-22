#pragma once

#include <RuneEngine.h>
#include "editorWindowComponent.h"
#include <vector>

struct createdGameObject
{


};

struct createdGameScene
{
  std::vector<createdGameObject> m_sceneObjects;

};

class EditorWindowObject : public rune::GameObject
{
private:
  std::vector<createdGameScene> m_createdScenes;
public:

  EditorWindowComponent toolbar;

  EditorWindowObject()
  {
    addComponent(toolbar);
  }

};
