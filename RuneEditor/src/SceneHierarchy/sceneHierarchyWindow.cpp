#include "sceneHierarchyWindow.h"
#include "mainEditorWindow.h"

void SceneHierarchyWindow::draw(rune::RenderWindow& window)
{

  bool createNewProject = false;
  static int selectionIndex = 0;


  ImGui::Begin("Scene Hierarchy", NULL, ImGuiWindowFlags_NoCollapse);

  if (ImGui::CollapsingHeader(EditorWindow::getWindow()->getWindow()->currentlyOpenProject.activeScene->sceneName.c_str(), NULL, ImGuiTreeNodeFlags_DefaultOpen))
  {

    for (int j = 0; j < EditorWindow::getWindow()->getWindow()->currentlyOpenProject.activeScene->m_sceneObjects.size(); j++)
    {
      if (ImGui::Selectable(EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects[j]->objectName.c_str()))
      {
        //Show the game object in the inspector if its been clicked.
        EditorWindow::getWindow()->selectedObject = EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects[j];
      }
      //ImGui::IsWindowAppearing("GameObjectRightClick")
      ImGui::OpenPopupOnItemClick("GameObjectRightClick", 1);

      if(ImGui::BeginPopupContextItem())
      {
        selectionIndex = j;

        if (ImGui::Selectable("Delete Object"))
        {
          CreatedGameObject* deleteObject = EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects[selectionIndex];
          EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects.erase(EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects.begin() + selectionIndex);
          delete deleteObject;
          EditorWindow::getWindow()->selectedObject = NULL;
        }
        ImGui::EndPopup();
      }

      if (rune::Mouse::isButtonPressed(rune::Mouse::Left) && !ImGui::IsAnyItemHovered() && ImGui::IsWindowHovered())
      {

        EditorWindow::getWindow()->selectedObject = nullptr;

      }

    }

  }

  

  ImGui::End();

}

