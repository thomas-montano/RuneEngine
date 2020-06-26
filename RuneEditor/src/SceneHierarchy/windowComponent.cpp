#include "windowComponent.h"
#include "sceneHierarchyWindow.h"
#include "mainEditorWindow.h"

void windowComponent::drawSceneContents()
{

  bool createNewProject = false;

  ImGui::Begin("Scene Hierarchy", NULL, ImGuiWindowFlags_NoCollapse);

  if (ImGui::IsItemHovered())
  {
    ImGui::BeginTooltip();
    ImGui::Text("This is the scene editor!");
    ImGui::EndTooltip();
  }


  if (ImGui::CollapsingHeader("Current Scene", NULL, ImGuiTreeNodeFlags_DefaultOpen))
  {

    for (int i = 0; i < EditorWindow::currentlyOpenProject.projectScenes.size(); i++)
    {
      //ImGui::Text(std::to_string(i).c_str());
      ImGui::SetNextItemOpen(true,ImGuiCond_Once);
      if(ImGui::TreeNode(EditorWindow::currentlyOpenProject.projectScenes[i].sceneName.c_str()))
      {
      
        for(int j = 0; j < EditorWindow::currentlyOpenProject.projectScenes[i].m_sceneObjects.size();j++)
        {
          if(ImGui::Selectable(EditorWindow::currentlyOpenProject.projectScenes[i].m_sceneObjects[j].objectName.c_str()))
          {
            //Show the game object in the inspector if its been clicked.
          }
        }
        
        ImGui::TreePop();
      }
    }

  }

  ImGui::End();

}

