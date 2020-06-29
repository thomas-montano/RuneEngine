#include "sceneHierarchyWindow.h"
#include "mainEditorWindow.h"

void SceneHierarchyWindow::draw(rune::RenderWindow& window)
{

  bool createNewProject = false;


  ImGui::Begin("Scene Hierarchy", NULL, ImGuiWindowFlags_NoCollapse);

  if (ImGui::IsItemHovered())
  {
    ImGui::BeginTooltip();
    ImGui::Text("This is the scene editor!");
    ImGui::EndTooltip();
  }


  if (ImGui::CollapsingHeader(EditorWindow::currentlyOpenProject.activeScene->sceneName.c_str(), NULL, ImGuiTreeNodeFlags_DefaultOpen))
  {

    for (int j = 0; j < EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects.size(); j++)
    {
      if (ImGui::Selectable(EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects[j].objectName.c_str()))
      {
        //Show the game object in the inspector if its been clicked.
        EditorWindow::selectedObject = &EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects[j];

      }

      if (rune::Mouse::isButtonPressed(rune::Mouse::Left) && !ImGui::IsItemActive() && ImGui::IsWindowHovered())
      {

        EditorWindow::selectedObject = nullptr;

      }

    }

  }

  ImGui::End();

}

