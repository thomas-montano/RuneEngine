#include "inspector.h"
#include "mainEditorWindow.h"
#include "EngineDataStructures/createdComponent.h"

void InspectorTab::draw(rune::RenderWindow& window)
{

  ImGui::Begin("Inspector", NULL, ImGuiWindowFlags_NoCollapse);

  if (EditorWindow::getWindow()->selectedObject != nullptr)
  {
    char objectName[32]= {0};
    strcpy_s(objectName, EditorWindow::getWindow()->selectedObject->objectName.c_str());
    std::stringstream address;

    //Store the address of the game object so that we can display it on the screen as a reference
    address << static_cast<void const*>(EditorWindow::getWindow()->selectedObject->gameObject);

    
    if(ImGui::InputText(" ", objectName, 32, ImGuiInputTextFlags_EnterReturnsTrue))
    {
      
      bool validName = true;
      
      //Make sure that the name being assigned to the object is a unique name
      for(int i = 0; i < EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects.size();i++)
      {
      
        bool test1 = strcmp(EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects[i]->objectName.c_str(),objectName) == 0;
        bool test2 = EditorWindow::getWindow()->selectedObject != EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects[i];

        bool test3 = 1;

        if(strcmp(EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects[i]->objectName.c_str(), objectName) == 0
          && EditorWindow::getWindow()->selectedObject != EditorWindow::getWindow()->currentlyOpenProject.activeScene->m_sceneObjects[i]   )
        {
        
          validName = false;
        
        }
      
      }
      //If it is a unique name, go ahead and assign it to the object
      if(validName)
      {
        EditorWindow::getWindow()->selectedObject->objectName = objectName;
      }
    }

    ImGui::SameLine();
    ImGui::TextDisabled((address.str()).c_str());

    ImGui::Separator();

    for(int i = 0; i < EditorWindow::getWindow()->selectedObject->objectComponents.size(); i++)
    {
      
      if(ImGui::TreeNodeEx(EditorWindow::getWindow()->selectedObject->objectComponents[i]->componentName.c_str(),ImGuiTreeNodeFlags_DefaultOpen))
      {
        EditorWindow::getWindow()->selectedObject->objectComponents[i]->inspectComponent();
      
        ImGui::TreePop();
      }

      ImGui::Separator();

    }

  }

  ImGui::End();

}
