#include "inspector.h"
#include "mainEditorWindow.h"

void InspectorTab::draw(rune::RenderWindow& window)
{

  ImGui::Begin("Inspector", NULL, ImGuiWindowFlags_NoCollapse);

  if (EditorWindow::selectedObject != nullptr)
  {

    for (int i = 0; i < EditorWindow::selectedObject->objectComponents.size(); i++)
    {

      ImGui::CollapsingHeader(EditorWindow::selectedObject->objectComponents[i].componentName.c_str(), ImGuiTreeNodeFlags_DefaultOpen);

    }

  }

  ImGui::End();

}
