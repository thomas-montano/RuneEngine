#pragma once

#include <RuneEngine.h>
#include "mainEditorWindow.h"
#include <EngineDataStructures/createdComponent.h>
#include <EngineDataStructures/createdGameObject.h>

class AnimatorComponent : public CreatedComponent
{
public:
  rune::Animator animator;

  AnimatorComponent(std::string newType, std::string newName, rune::GameObject* parent, std::string newFilePath = "")
    : CreatedComponent(newType, newName, parent, newFilePath)
  {

    parent->addComponent(animator);

  }

  virtual void inspectComponent()
  {
    
    toolTip("An animator allows for a sprite renderer to play an animation.");

    ImGui::CollapsingHeader("Animation");

  }

};
