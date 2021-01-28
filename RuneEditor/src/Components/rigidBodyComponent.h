#pragma once

#include <RuneEngine.h>
#include "mainEditorWindow.h"
#include <EngineDataStructures/createdComponent.h>
#include <EngineDataStructures/createdGameObject.h>

class RigidBodyComponent : public CreatedComponent
{
public:
  physics::RigidBody body;
  
  RigidBodyComponent(std::string newType, std::string newName, rune::GameObject* parent, std::string newFilePath = "")
    : CreatedComponent(newType, newName, parent, newFilePath)
  {

    parent->addComponent(body);

  }

  virtual void inspectComponent()
  {
    toolTip("A rigid body that allows this game object to respond to physics.");

    static float buf;
    ImGui::InputFloat("Object Mass",&buf,1,5,1);

  }

};
