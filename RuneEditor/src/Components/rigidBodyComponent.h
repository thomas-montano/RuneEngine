#pragma once

#include <RuneEngine.h>
#include "mainEditorWindow.h"
#include <EngineDataStructures/createdComponent.h>
#include <EngineDataStructures/createdGameObject.h>

class RigidBodyComponent : public CreatedComponent
{
public:
  physics::RigidBody body;
  float gravity[2];
  float mass;
  
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

    if(ImGui::InputFloat("Object Mass",&mass,1,5,1))
    {
      body.getBodyStruct()->invMass = (1.0/mass);
    }

    if(ImGui::DragFloat2("Gravity Vector",gravity))
    {
      body.getBodyStruct()->gravityFactor = rune::Vec2(gravity[0],gravity[1]);
    }

    if(ImGui::Button("Reset Velocity"))
    {
      //Reset the rigid body to the original state.
      body.setVelocity(rune::Vec2(0,0));
      body.setPosition(rune::Vec2(parentObject->transform.getPosition().x + body.getBodyStruct()->vertexes[1].x, parentObject->transform.getPosition().y + body.getBodyStruct()->vertexes[1].y));
      body.setPreviousPosition(rune::Vec2(parentObject->transform.getPosition().x, parentObject->transform.getPosition().y) );

      rune::Vec3 dimensions = rune::Vec3(parentObject->transform.getBounds());//parentObject->transform.getScale();

      body.setUpObject(dimensions.x, dimensions.y, 1.0 / body.getBodyStruct()->invMass, false);
    }

  }

};
