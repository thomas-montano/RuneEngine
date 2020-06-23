#include "menuBarComponent.h"
#include "mainEditorWindow.h"

void MenuBarComponent::update()
{
  
  //Set up the IMGUI dock space THIS MUST COME BEFORE EVERYTHING ELSE
  ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoDocking;

  windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
  windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
  ImGui::Begin("Dock space", NULL, windowFlags);

  ImGui::PopStyleVar();

  static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

  // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
     // and handle the pass-thru hole, so we ask Begin() to not render a background.
  if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
    windowFlags |= ImGuiWindowFlags_NoBackground;  

  ImGuiViewport* viewport = ImGui::GetMainViewport();
  ImGui::SetWindowPos(viewport->GetWorkPos());
  ImGui::SetWindowSize(viewport->GetWorkSize());

  ImGuiID dockspace_id = ImGui::GetID("Dock space");
  ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f),dockspace_flags);
  
  ImGui::End();

  //Go ahead and render the menu bar.
  if (ImGui::BeginMainMenuBar())
  {
    if (ImGui::BeginMenu("File"))
    {
      if (ImGui::MenuItem("New Scene"))
      {
        CreatedScene newScene("New Scene");
        EditorWindow::currentlyOpenProject.projectScenes.push_back(newScene);
      }

      ImGui::MenuItem("Open Scene");
      ImGui::Separator();

      if (ImGui::MenuItem("New Project"))
      {
        createNewProject = true;

      }

      ImGui::MenuItem("Open Project");
      ImGui::MenuItem("Save Project");
      ImGui::Separator();

      if (ImGui::MenuItem("Build"))
      {

        EditorWindow::currentlyOpenProject.buildProject();

      }

      ImGui::MenuItem("Build and Run");
      
      if(ImGui::MenuItem("Exit"))
      {
        rune::GameApplication::quitGame();
      }
      
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
      if (ImGui::MenuItem("Create New Empty"))
      {

        if (EditorWindow::currentlyOpenProject.projectScenes.size() > 0)
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

  if (createNewProject)
  {

    ImGui::OpenPopup("ProjectWizard");
    createNewProject = false;

  }

  if (ImGui::BeginPopupModal("ProjectWizard", NULL, ImGuiWindowFlags_AlwaysAutoResize))
  {
    ImGui::Text("Create a new Rune Engine Project! \n\n");
    ImGui::Separator();

    //static int dummy_i = 0;
    //ImGui::Combo("Combo", &dummy_i, "Delete\0Delete harder\0");

    static char projectName[256] = { 0 };
    static char projectDirectory[256] = { 0 };
    ImGui::InputText("Project Name", projectName, 256);
    ImGui::InputText("Save Location", projectDirectory, 256);

    if (ImGui::Button("Create Project", ImVec2(120, 0)))
    {
      if (projectName[0] != 0)
      {
        ImGui::CloseCurrentPopup();
        EditorWindow::currentlyOpenProject.projectName = (std::string)projectName;
        rune::GameApplication::getWindow()->setWindowTitle(EditorWindow::currentlyOpenProject.projectName + " - Rune Engine Editor Version 0.7.5-alpha");
      }
    }

    ImGui::SetItemDefaultFocus();
    ImGui::SameLine();
    if (ImGui::Button("Cancel", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }

    ImGui::EndPopup();
  }



}

