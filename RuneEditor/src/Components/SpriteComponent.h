#pragma once

#include <RuneEngine.h>
#include <EngineDataStructures/createdComponent.h>
#include <EngineDataStructures/createdGameObject.h>

class SpriteComponent : public CreatedComponent
{
public:
  rune::Sprite sprite;
  char spriteFilePath[256] = { 0 };
  int index = 0;
  const char* FILTER_OPTIONS[2] = { "Linear Filter", "Nearest Filter" };
  const unsigned int FILTER_MODES[2] = { LINEAR_FILTER, NEAREST_FILTER };

  SpriteComponent(std::string newType, std::string newName, rune::GameObject* parent, std::string newFilePath = "")
    : CreatedComponent(newType, newName, parent, newFilePath)
  {

    parent->addComponent(sprite);
    EditorWindow::currentlyOpenProject.activeScene->scene->submitToRenderer(&sprite);

  }

  virtual void inspectComponent()
  {

    ImGui::InputText("Texture Location", spriteFilePath, 256);
    ImGui::SameLine();

    if (ImGui::Button("..."))
    {
      strcpy_s(spriteFilePath, openTexture().c_str());
      sprite.setTexture(spriteFilePath);
    }

    if (ImGui::BeginCombo("combo 1", FILTER_OPTIONS[index]))
    {
      for (int n = 0; n < IM_ARRAYSIZE(FILTER_OPTIONS); n++)
      {
        const bool is_selected = (index == n);
        if (ImGui::Selectable(FILTER_OPTIONS[n], is_selected))
        {
          index = n;
        }
        // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
        if (is_selected)
          ImGui::SetItemDefaultFocus();
      }
      ImGui::EndCombo();
    }

    if(ImGui::Button("Reload Sprite"))
    {
      
      sprite.setTexture(spriteFilePath,FILTER_MODES[index]);
    }
  
  }

  std::string openTexture()
  {

    const int BUFSIZE = 1024;
    wchar_t buffer[BUFSIZE] = { 0 };
    OPENFILENAME ofns = { 0 };

    ofns.lpstrFilter = L"PNG (*.rsc)\0*.png\0\0";

    ofns.lpstrInitialDir = L"C:";

    ofns.lStructSize = sizeof(ofns);
    ofns.lpstrFile = buffer;
    ofns.nMaxFile = BUFSIZE;
    ofns.lpstrTitle = L"Open an image";
    GetOpenFileName(&ofns);

    std::wstring myString(buffer);

    std::string str(myString.begin(), myString.end());

    return str;

  }

};