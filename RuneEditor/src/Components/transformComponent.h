#pragma once

#include <RuneEngine.h>
#include <EngineDataStructures/createdComponent.h>
#include <EngineDataStructures/createdGameObject.h>

class TransformComponent : public CreatedComponent
{
public:
  TransformComponent(std::string newType, std::string newName, rune::GameObject* parent, std::string newFilePath = "")
    : CreatedComponent(newType, newName, parent, newFilePath)
  {
  
  }

  float position[3] = {0};
  float size[3] = { 0 };
  float rotation[3] = { 0 };

  virtual void inspectComponent()
  {
  
    ImGui::Text("Position:");
    ImGui::DragFloat3(" ", position, .1);
    ImGui::Text("Scale:");
    ImGui::DragFloat3("", size, .1);
    ImGui::Text("Rotation:");
    ImGui::DragFloat3("  ", rotation, .1);

    parentObject->transform.setPosition(rune::Vec3(static_cast<double>(position[0]), static_cast<double>(position[1]), static_cast<double>(position[2])));
    parentObject->transform.setScale(rune::Vec3(size[0], size[1], size[2]));
    parentObject->transform.setRotation(rune::Vec3(rotation[0], rotation[1], rotation[2]));

  }

};