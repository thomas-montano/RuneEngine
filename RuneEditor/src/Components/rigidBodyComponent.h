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

    body.start();

    EditorWindow::currentlyOpenProject.activeScene->scene->addPhysicsObject(body);

  }

  virtual void inspectComponent()
  {
    toolTip("A rigid body that allows this game object to respond to physics.");

    static float mass;
    if(ImGui::InputFloat("Object Mass",&mass,1,5,1))
    {
      body.getBodyStruct()->invMass = (1.0/mass);
    }



    static float gravity[2];
    if(ImGui::DragFloat2("Gravity Vector",gravity))
    {
      body.getBodyStruct()->gravityFactor = rune::Vec2(gravity[0],gravity[1]);
    }

    if(ImGui::Button("Reset Velocity"))
    {
      body.setVelocity(rune::Vec2(0,0));
      body.setPreviousPosition(rune::Vec2(parentObject->transform.getPosition().x, parentObject->transform.getPosition().y));
    }

  }

};
