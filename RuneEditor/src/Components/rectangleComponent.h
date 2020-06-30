#pragma once

#include <RuneEngine.h>
#include "mainEditorWindow.h"
#include <EngineDataStructures/createdComponent.h>
#include <EngineDataStructures/createdGameObject.h>

class RectangleComponent : public CreatedComponent
{
public:
  rune::RectangleShape rectangle;
  float colors[3] = {0.0};
    
  RectangleComponent(std::string newType, std::string newName, rune::GameObject* parent, std::string newFilePath = "")
    : CreatedComponent(newType, newName, parent, newFilePath)
  {

    parent->addComponent(rectangle);
    EditorWindow::currentlyOpenProject.activeScene->scene->submitToRenderer(&rectangle);

  }

  virtual void inspectComponent()
  {

    if(ImGui::ColorPicker3("Color", colors))
    {
    
      rectangle.setFillColor(rune::Color(255*colors[0], 255 * colors[1], 255 * colors[2]));

    }

  }

};