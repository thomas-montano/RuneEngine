#pragma once

#include <RuneEngine.h>
#include "Editor/editorWindowObject.h"

class EditorWindow : public rune::GameScene
{

private:
  EditorWindowObject sceneContents;

public:
  
  virtual void doInit(void);

  virtual void updateVariable(void);
};