#include "inspector.h"
#include "mainEditorWindow.h"
#include "EngineDataStructures/createdComponent.h"

void InspectorTab::draw(rune::RenderWindow& window)
{

  ImGui::Begin("Inspector", NULL, ImGuiWindowFlags_NoCollapse);

  if (EditorWindow::selectedObject != nullptr)
  {

    for(int i = 0; i < EditorWindow::selectedObject->objectComponents.size(); i++)
    {

      if(ImGui::CollapsingHeader(EditorWindow::selectedObject->objectComponents[i]->componentName.c_str(), ImGuiTreeNodeFlags_DefaultOpen))
      {
        EditorWindow::selectedObject->objectComponents[i]->inspectComponent();
      }
    }

  }

  ImGui::End();

}
