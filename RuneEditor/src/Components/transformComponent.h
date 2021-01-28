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
  float size[3] = { 1,1,1 };
  float rotation[3] = { 0 };

  virtual void inspectComponent()
  {
    toolTip("The position, scale, and rotation of the game object. Hold shift to move the value faster.");

    ImGui::Columns(2, "mycolumns2", true);  // 3-ways, no border
    ImGui::AlignTextToFramePadding();
    ImGui::Text("Position:");
    ImGui::NextColumn();
    ImGui::DragFloat3(" ", position, .1);

    ImGui::NextColumn();  // 3-ways, no border
    ImGui::AlignTextToFramePadding();
    ImGui::Text("Scale:");
    ImGui::NextColumn();
    ImGui::DragFloat3("", size, .1, 0, FLT_MAX/INT_MAX);

    ImGui::NextColumn();
    ImGui::AlignTextToFramePadding();
    ImGui::Text("Rotation:");
    ImGui::NextColumn();
    ImGui::DragFloat3("  ", rotation, .1);
    ImGui::Columns(1);

    parentObject->transform.setPosition(rune::Vec3(static_cast<double>(position[0]), static_cast<double>(position[1]), static_cast<double>(position[2])));
    parentObject->transform.setScale(rune::Vec3(size[0], size[1], size[2]));
    parentObject->transform.setRotation(rune::Vec3(rotation[0], rotation[1], rotation[2]));

  }

};