#include "editorWindowComponent.h"

void EditorWindowComponent::drawSceneContents()
{

  ImGui::Begin("FPS", NULL, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove);

  ImGui::SetWindowSize(ImVec2(400, rune::GameApplication::getWindow()->getSize().y));
  ImGui::SetWindowPos(ImVec2(0, 0));

  if (ImGui::IsItemHovered())
  {
    ImGui::BeginTooltip();
    ImGui::Text("This is the scene editor!");
    ImGui::EndTooltip();
  }

  //ImGui::Text(std::to_string(rune::GameApplication::getFrameRate()).c_str());

  //ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.65f);

  if (ImGui::BeginMenuBar())
  {
    if (ImGui::BeginMenu("File"))
    {
      ImGui::MenuItem("New Scene");
      ImGui::MenuItem("Open Scene");
      ImGui::Separator();
      ImGui::MenuItem("New Project");
      ImGui::MenuItem("Open Project");
      ImGui::MenuItem("Save Project");
      ImGui::Separator();
      ImGui::MenuItem("Build");
      ImGui::MenuItem("Build and Run");
      ImGui::MenuItem("Exit");
      ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Edit"))
    {
      ImGui::MenuItem("Undo");
      ImGui::MenuItem("Redo");
      ImGui::Separator();
      ImGui::MenuItem("Cut");
      ImGui::MenuItem("Copy");
      ImGui::MenuItem("Paste");
      ImGui::Separator();
      ImGui::MenuItem("Duplicate");
      ImGui::MenuItem("Rename");
      ImGui::MenuItem("Delete");
      ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("GameObject"))
    {
      ImGui::MenuItem("Create New Empty");
      ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Component"))
    {
      if (ImGui::BeginMenu("Sprite"))
      {
        ImGui::MenuItem("Test");
        ImGui::EndMenu();

      }
      ImGui::EndMenu();
    }
    ImGui::EndMenuBar();
  }

  if (ImGui::CollapsingHeader("Current Scene", NULL, ImGuiTreeNodeFlags_DefaultOpen))
  {

    /*for (int i = 0; i < currentSceneObjects.size(); i++)
    {
      //ImGui::Text(std::to_string(i).c_str());
      ImGui::Selectable(("Game Object " + std::to_string(i)).c_str());
      if ()
      {

        ImGui::TreePop();

      }

    }*/

  }

  ImGui::End();
}

