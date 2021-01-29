#include "sceneHierarchyWindow.h"
#include "mainEditorWindow.h"

void SceneHierarchyWindow::draw(rune::RenderWindow& window)
{

  bool createNewProject = false;
  static int selectionIndex = 0;


  ImGui::Begin("Scene Hierarchy", NULL, ImGuiWindowFlags_NoCollapse);

  if (ImGui::CollapsingHeader(EditorWindow::currentlyOpenProject.activeScene->sceneName.c_str(), NULL, ImGuiTreeNodeFlags_DefaultOpen))
  {

    for (int j = 0; j < EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects.size(); j++)
    {
      if (ImGui::Selectable(EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects[j]->objectName.c_str()))
      {
        //Show the game object in the inspector if its been clicked.
        EditorWindow::selectedObject = EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects[j];
      }
      //ImGui::IsWindowAppearing("GameObjectRightClick")
      /*if(ImGui::OpenPopupContextItem("GameObjectRightClick", 1))
      {
        selectionIndex = j;
      }*/

      if (rune::Mouse::isButtonPressed(rune::Mouse::Left) && !ImGui::IsAnyItemHovered() && ImGui::IsWindowHovered())
      {

        EditorWindow::selectedObject = nullptr;

      }

    }

  }

  if (ImGui::BeginPopupContextItem("GameObjectRightClick"))
  {
    if (ImGui::Selectable("Delete Object"))
    {
      CreatedGameObject* deleteObject = EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects[selectionIndex];
      EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects.erase(EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects.begin() + selectionIndex);
      delete deleteObject;
      EditorWindow::selectedObject = NULL;
    }
    ImGui::EndPopup();
  }

  ImGui::End();

}

