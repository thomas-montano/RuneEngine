#include "windowComponent.h"
#include "sceneHierarchyWindow.h"
#include "mainEditorWindow.h"

void windowComponent::drawSceneContents()
{

  bool createNewProject = false;

  ImGui::Begin("Scene Hierarchy", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);

  ImGui::SetWindowSize(ImVec2(400, rune::GameApplication::getWindow()->getSize().y - ImGui::GetFrameHeight()));
  ImGui::SetWindowPos(ImVec2(0, ImGui::GetFrameHeight()));

  double test = ImGui::GetFrameHeight();

  if (ImGui::IsItemHovered())
  {
    ImGui::BeginTooltip();
    ImGui::Text("This is the scene editor!");
    ImGui::EndTooltip();
  }

  //ImGui::Text(std::to_string(rune::GameApplication::getFrameRate()).c_str());

  //ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.65f);

  if(ImGui::BeginMainMenuBar())
  {
    if (ImGui::BeginMenu("File"))
    {
      if(ImGui::MenuItem("New Scene"))
      {
        CreatedScene newScene("New Scene");
        EditorWindow::currentlyOpenProject.projectScenes.push_back(newScene);
      }

      ImGui::MenuItem("Open Scene");
      ImGui::Separator();
      
      if(ImGui::MenuItem("New Project"))
      {  
        createNewProject = true;

      }
      
      ImGui::MenuItem("Open Project");
      ImGui::MenuItem("Save Project");
      ImGui::Separator();

      if(ImGui::MenuItem("Build"))
      {
      
        EditorWindow::currentlyOpenProject.buildProject();
      
      }

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
      if(ImGui::MenuItem("Create New Empty"))
      {

        if(EditorWindow::currentlyOpenProject.projectScenes.size() > 0)
        {
          CreatedGameObject newObject("GameObject" + std::to_string(EditorWindow::currentlyOpenProject.projectScenes[0].m_sceneObjects.size()));
          EditorWindow::currentlyOpenProject.projectScenes[0].m_sceneObjects.push_back(newObject);
        }

      }
      
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

    ImGui::EndMainMenuBar();
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

  if (createNewProject)
  {

    ImGui::OpenPopup("ProjectWizard");

  }

  if (ImGui::BeginPopupModal("ProjectWizard", NULL, ImGuiWindowFlags_AlwaysAutoResize))
  {
    ImGui::Text("Create a new Rune Engine Project! \n\n");
    ImGui::Separator();

    //static int dummy_i = 0;
    //ImGui::Combo("Combo", &dummy_i, "Delete\0Delete harder\0");

    static char projectName[256] = {0};
    static char projectDirectory[256] = {0};
    ImGui::InputText("Project Name",projectName,256);
    ImGui::InputText("Save Location",projectDirectory,256);

    if (ImGui::Button("Create Project", ImVec2(120, 0)))
    {
      if(projectName[0] != 0)
        ImGui::CloseCurrentPopup();
    }

    ImGui::SetItemDefaultFocus();
    ImGui::SameLine();
    if (ImGui::Button("Cancel", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }

    ImGui::EndPopup();
  }

}

