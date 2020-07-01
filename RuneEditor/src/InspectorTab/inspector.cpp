#include "inspector.h"
#include "mainEditorWindow.h"
#include "EngineDataStructures/createdComponent.h"

void InspectorTab::draw(rune::RenderWindow& window)
{

  ImGui::Begin("Inspector", NULL, ImGuiWindowFlags_NoCollapse);

  if (EditorWindow::selectedObject != nullptr)
  {
    std::string objectName = EditorWindow::selectedObject->objectName;
    std::stringstream address;

    //Store the address of the gameobject so that we can display it on the screen as a reference
    address << static_cast<void const*>(EditorWindow::selectedObject->gameObject);


    if(ImGui::InputText((address.str()).c_str(), &objectName[0], 32, ImGuiInputTextFlags_EnterReturnsTrue))
    {
      
      bool validName = true;
      
      //Make sure that the name being assigned to the object is a unique name
      for(int i = 0; i < EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects.size();i++)
      {
      
        bool test1 = strcmp(EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects[i]->objectName.c_str(),objectName.c_str()) == 0;
        bool test2 = EditorWindow::selectedObject != EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects[i];

        bool test3 = 1;

        if(strcmp(EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects[i]->objectName.c_str(), objectName.c_str()) == 0
          && EditorWindow::selectedObject != EditorWindow::currentlyOpenProject.activeScene->m_sceneObjects[i])
        {
        
          validName = false;
        
        }
      
      }
      //If it is a unique name, go ahead and assign it to the object
      if(validName)
      {
        EditorWindow::selectedObject->objectName = objectName;
      }
    }

    ImGui::Separator();

    for(int i = 0; i < EditorWindow::selectedObject->objectComponents.size(); i++)
    {
      
      if(ImGui::TreeNodeEx(EditorWindow::selectedObject->objectComponents[i]->componentName.c_str(),ImGuiTreeNodeFlags_DefaultOpen))
      {
        EditorWindow::selectedObject->objectComponents[i]->inspectComponent();
      
        ImGui::TreePop();
      }

      ImGui::Separator();

    }

  }

  ImGui::End();

}
