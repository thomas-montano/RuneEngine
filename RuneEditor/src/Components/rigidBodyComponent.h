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
  float mass = 0.0f;
  float bounds[2];
  float velocity[2];
  
  RigidBodyComponent(std::string newType, std::string newName, rune::GameObject* parent, std::string newFilePath = "")
    : CreatedComponent(newType, newName, parent, newFilePath)
  {
    bounds[0] = parentObject->transform.getBounds().x;
    bounds[1] = parentObject->transform.getBounds().y;

    parent->addComponent(body);

    body.start();

    EditorWindow::getWindow()->currentlyOpenProject.activeScene->scene->addPhysicsObject(body);

  }

  virtual void inspectComponent()
  {
    toolTip("A rigid body that allows this game object to respond to physics.");

    if(ImGui::InputFloat("Object Mass",&mass,1.f,5.f,"%.2f"))
    {
      body.setMass(mass);
    }

    if(ImGui::DragFloat2("Gravity Vector",gravity))
    {
      body.getBodyStruct()->gravityFactor = rune::Vec2(gravity[0],gravity[1]);
    }

    if(ImGui::DragFloat2("Collider Bounds", bounds, 1,0, FLT_MAX/INT_MAX))
    {
      body.setUpObject(bounds[0],bounds[1],mass,false);
    }
    else
    {
      bounds[0] = body.getWidth();
      bounds[1] = body.getHeight();
    }

    if(!EditorWindow::getWindow()->isSceneRunning)
    {
      body.setPosition(rune::Vec2(parentObject->transform.getPosition().x + body.getBodyStruct()->vertexes[1].x, parentObject->transform.getPosition().y + body.getBodyStruct()->vertexes[1].y));
      body.setPreviousPosition(rune::Vec2(parentObject->transform.getPosition().x, parentObject->transform.getPosition().y));
    }
    
    if(parentObject->transform.getPosition() != body.getPosition())
    {
      body.setPosition(rune::Vec2(parentObject->transform.getPosition().x + body.getBodyStruct()->vertexes[1].x, parentObject->transform.getPosition().y + body.getBodyStruct()->vertexes[1].y));
    }

    if(ImGui::DragFloat2("Body Velocity", velocity))
    {
      body.setVelocity(rune::Vec2(velocity[0],velocity[1]));
    }
    else
    {
      velocity[0] = body.getVelocity().x;
      velocity[1] = body.getVelocity().y;
    }

    if(ImGui::Button("Reset Velocity"))
    {
      //Reset the rigid body to the original state.
      body.setVelocity(rune::Vec2(0,0));
    }

  }

};
