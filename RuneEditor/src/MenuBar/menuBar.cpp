#include "menuBar.h"
#include "mainEditorWindow.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <shlobj.h>

#include <Components/SpriteComponent.h>
#include <Components/transformComponent.h>
#include <Components/rectangleComponent.h>
#include <Components/rigidBodyComponent.h>
#include <Components/animatorComponent.h>

#include <EngineDataStructures/runeEngineProject.h>

void MenuBar::draw(rune::RenderWindow& window)
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

//   ImGui::DockBuilderRemoveNode(dockspace_id);
//   ImGui::DockBuilderAddNode(dockspace_id, dockspace_flags); // Add empty node
//   ImGui::DockBuilderSetNodeSize(dockspace_id, viewport->GetWorkSize());

  //Go ahead and render the menu bar.
  if (ImGui::BeginMainMenuBar())
  {
    if (ImGui::BeginMenu("File"))
    {
      if (ImGui::MenuItem("New Scene"))
      {
        CreatedScene* newScene = new CreatedScene("New Scene");
        EditorWindow::getWindow()->currentlyOpenProject.projectScenes.push_back(newScene);
        EditorWindow::getWindow()->currentlyOpenProject.activeScene = EditorWindow::getWindow()->currentlyOpenProject.projectScenes[EditorWindow::getWindow()->currentlyOpenProject.projectScenes.size()-1];
      }

      ImGui::MenuItem("Open Scene");
      ImGui::Separator();

      if (ImGui::MenuItem("New Project"))
      {
        createNewProject = true;

      }

      if(ImGui::MenuItem("Open Project"))
      {
        EditorWindow::getWindow()->currentlyOpenProject = openProject();
      }

      if(ImGui::MenuItem("Save Project"))
      {

      }

      ImGui::Separator();

      if (ImGui::MenuItem("Build"))
      {

        EditorWindow::getWindow()->currentlyOpenProject.buildProject();

      }

      ImGui::MenuItem("Build and Run");
      
      if(ImGui::MenuItem("Exit"))
      {
        getGameInstance()->quitApplication();
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
    
    //The game object menu is responsible for creating new game objects
    if (ImGui::BeginMenu("GameObject"))
    {
      if (ImGui::MenuItem("Create New Empty"))
      {

        std::string objectName = "GameObject";
        int smallestObjectNum = EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects.size();

        //Disallow a new game object to be given the same name as another object
        for(int i = 0; i < EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects.size(); i ++)
        {
        
          if(strcmp(EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects[i]->objectName.c_str(),"GameObject") == 0)
          {
            
            for (int i = 1; i < EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects.size(); i++)
            {
              bool foundSmaller = false;
              for (int j = 0; j < EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects.size(); j++)
              {

                if (strcmp(EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects[j]->objectName.c_str(), ("GameObject (" + std::to_string(i) + ")").c_str()) == 0)
                {
                  foundSmaller = true;
                }

              }

              if (!foundSmaller && i < smallestObjectNum)
              {
                smallestObjectNum = i;
              }

            }

            objectName = "GameObject (" + std::to_string(smallestObjectNum) + ")";
          }
        
        }
        
        //Create the new object in the scene
        if (EditorWindow::getWindow()->currentlyOpenProject.projectScenes.size() > 0)
        {
          CreatedGameObject* newObject = new CreatedGameObject(objectName);
          EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects.push_back(newObject);
          EditorWindow::getWindow()->selectedObject = newObject;
        }

      }

      ImGui::EndMenu();
    }

    //The component menu is responsible for adding components to the currently selected game object.
    if (ImGui::BeginMenu("Component"))
    {

      displayComponents();

      ImGui::EndMenu();
    }

    //The view menu is responsible for opening other editor windows such as animation and code windows.
    if(ImGui::BeginMenu("View"))
    {
    
      if(ImGui::MenuItem("Save Layout"))
      {
        ImGui::SaveIniSettingsToDisk("./RuneEngineLayout.ini");
      }

      if(ImGui::MenuItem("Load Layout"))
      {
        ImGui::LoadIniSettingsFromDisk("./RuneEngineLayout.ini");
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


  //Popup wizard for creating a new project or opening an old one. This will be displayed at the start of opening the editor.
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
    ImGui::SameLine();

    if(ImGui::Button("..."))
    {
    
      strcpy_s(projectDirectory,openDirectoryBrowser().c_str());

      
    
    }

    ImGui::NewLine();

    ImGui::SetItemDefaultFocus();
    if (ImGui::Button("Cancel", ImVec2(120, 0))) { EditorWindow::getWindow()->currentlyOpenProject.setProjectName(""); ImGui::CloseCurrentPopup(); }

    ImGui::SameLine();

    if (projectName[0] != 0 && projectDirectory[0] != 0)
    {
      if (ImGui::Button("Create Project", ImVec2(120, 0)))
      {
        ImGui::CloseCurrentPopup();
        EditorWindow::getWindow()->currentlyOpenProject.setProjectName((std::string)projectName);
        EditorWindow::getWindow()->currentlyOpenProject.projectSaveLocation = projectDirectory;
      }
    }


    

    ImGui::EndPopup();
  }

  if (EditorWindow::getWindow()->currentlyOpenProject.getProjectName() == "")
  {

    ImGui::OpenPopup("StartupMenu");

  }


  if (ImGui::BeginPopupModal("StartupMenu", NULL, ImGuiWindowFlags_AlwaysAutoResize))
  {

    ImGui::Text("Welcome To The Rune Engine Editor!");

    if (ImGui::Button("Create New Project"))
    {
      createNewProject = true;
      ImGui::CloseCurrentPopup();

      EditorWindow::getWindow()->currentlyOpenProject.setProjectName("New Project");

    }

    ImGui::SameLine();

    if (ImGui::Button("Open Project"))
    {

      EditorWindow::getWindow()->currentlyOpenProject = openProject();

      ImGui::CloseCurrentPopup();

    }

    ImGui::EndPopup();

  }

}

RuneEngineProject MenuBar::openProject()
{

  const int BUFSIZE = 1024;
  wchar_t buffer[BUFSIZE] = { 0 };
  OPENFILENAME ofns = { 0 };

  ofns.lpstrFilter = L"Rune Project (*.rproj)\0*.rproj\0\0";

  ofns.lpstrInitialDir = L"Documents";

  ofns.lStructSize = sizeof(ofns);
  ofns.lpstrFile = buffer;
  ofns.nMaxFile = BUFSIZE;
  ofns.lpstrTitle = L"Open a Rune Engine Project";
  GetOpenFileName(&ofns);

  std::wstring myString(buffer);

  std::string str(myString.begin(), myString.end());

  //length of .rproj = 6
  str = str.substr(0,str.length()-6);

  int i = str.length()-1;
  while(str[i] != '\\' && i >= 0)
  {
    i--;
  }

  RuneEngineProject newProject(str.substr(i + 1, str.length() - i));

  newProject.projectSaveLocation = str.substr(0,i+1);

  EditorWindow::getWindow()->currentlyOpenProject.setProjectName(newProject.getProjectName());

  return newProject;

}

std::string MenuBar::openScene()
{

  const int BUFSIZE = 1024;
  wchar_t buffer[BUFSIZE] = { 0 };
  OPENFILENAME ofns = { 0 };

  ofns.lpstrFilter = L"Rune Scenes (*.rsc)\0*.rsc\0\0";

  ofns.lpstrInitialDir = L"C:";

  ofns.lStructSize = sizeof(ofns);
  ofns.lpstrFile = buffer;
  ofns.nMaxFile = BUFSIZE;
  ofns.lpstrTitle = L"Open a Rune Engine Scene";
  GetOpenFileName(&ofns);

  std::wstring myString(buffer);

  std::string str(myString.begin(), myString.end());

  return str;

}

std::string MenuBar::openDirectoryBrowser()
{

  const int BUFSIZE = 1024;
  wchar_t buffer[BUFSIZE] = { 0 };

  BROWSEINFO bi = { 0 };
  bi.lpszTitle = L"Select your project's directory...";
  bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_USENEWUI;
  //::OleInitialize(NULL);
  //bi.lpfn = BrowseCallbackProc;
  //bi.lParam = (LPARAM)"D:\\Documents\\MakefileTest\\ConsoleApplication1\\";

  IFileOpenDialog* pfd;

  LPITEMIDLIST pidl = SHBrowseForFolder(&bi);

  ::SHGetPathFromIDList(pidl, buffer);

  // free memory used
  IMalloc* imalloc = 0;
  if (SUCCEEDED(SHGetMalloc(&imalloc)))
  {
    imalloc->Free(pidl);
    imalloc->Release();
  }

  std::wstring myString2(buffer);

  std::string folderPath(myString2.begin(), myString2.end());

  return folderPath;

}

std::string MenuBar::saveFileBrowser()
{

  const int BUFSIZE = 1024;
  wchar_t buffer[BUFSIZE] = { 0 };
  OPENFILENAME ofns = { 0 };

  ofns.lpstrFilter = L"Rune Scenes (*.rsc)\0*.rsc\0\0";

  ofns.lpstrInitialDir = L"C:\\";

  ofns.lStructSize = sizeof(ofns);
  ofns.lpstrFile = buffer;
  ofns.nMaxFile = BUFSIZE;
  ofns.lpstrTitle = L"Open a Rune Engine Project";
  GetSaveFileName(&ofns);

  std::wstring myString(buffer);

  std::string str(myString.begin(), myString.end());

  return str;

}

void MenuBar::displayComponents()
{

  bool disabled = EditorWindow::getWindow()->selectedObject != nullptr;

  if (ImGui::MenuItem("Sprite Renderer", NULL, false, disabled))
  {

    SpriteComponent* newComponent = new SpriteComponent("rune::Sprite", "Sprite Renderer", EditorWindow::getWindow()->selectedObject->gameObject,"test");
    EditorWindow::getWindow()->selectedObject->objectComponents.push_back(newComponent);

  }

  if (ImGui::MenuItem("Rectangle Renderer", NULL, false, disabled))
  {

    RectangleComponent* newComponent = new RectangleComponent("rune::RectangleShape", "Rectangle Renderer", EditorWindow::getWindow()->selectedObject->gameObject,"test");
    EditorWindow::getWindow()->selectedObject->objectComponents.push_back(newComponent);


  }

  if (ImGui::MenuItem("Rigid Body", NULL, false, disabled))
  {

    RigidBodyComponent* newComponent = new RigidBodyComponent("physics::RigidBody", "RigidBody", EditorWindow::getWindow()->selectedObject->gameObject, "test");
    EditorWindow::getWindow()->selectedObject->objectComponents.push_back(newComponent);

  }

  if (ImGui::MenuItem("Particle Emitter", NULL, false, disabled))
  {

    /*CreatedComponent newComponent(std::string(typeid(rune::ParticleEmitter).name()), "Particle Emitter", "test");
    EditorWindow::getWindow()->selectedObject->objectComponents.push_back(newComponent);

    //rune::ParticleEmitter emitter(rune::Vec2(0,0), rune::Vec2(0,0), rune::Color::White);
    //EditorWindow::getWindow()->selectedObject->gameObject.addComponent(emitter);*/

  }

  if (ImGui::MenuItem("Animator", NULL, false, disabled))
  {
    AnimatorComponent* newComponent = new AnimatorComponent("rune::Animator", "Animator", EditorWindow::getWindow()->selectedObject->gameObject, "test");
    EditorWindow::getWindow()->selectedObject->objectComponents.push_back(newComponent);
  }

  if (ImGui::MenuItem("Light Source", NULL, false, disabled))
  {

    /*CreatedComponent newComponent(std::string(typeid(rune::LightSource).name()), "Light Source", "test");
    EditorWindow::getWindow()->selectedObject->objectComponents.push_back(newComponent);

    //rune::LightSource lightSource;
    //EditorWindow::getWindow()->selectedObject->gameObject.addComponent(lightSource);*/

  }

}

