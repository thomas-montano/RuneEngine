#include "sceneViewport.h"
#include "mainEditorWindow.h"

void SceneViewPort::draw(rune::RenderWindow& window)
{

  ImGui::Begin("View Port", NULL, ImGuiWindowFlags_NoCollapse);

  ImGui::SetCursorPosX((ImGui::GetContentRegionAvail().x - 67.5) / 2);

  bool highlightStartButton = false;
  if(EditorWindow::getWindow()->isSceneRunning)
  {
    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.2f);
    highlightStartButton = true;
  }

  if (ImGui::Button("Play"))
  {
    EditorWindow::getWindow()->startScene();
  }

  if (highlightStartButton)
  {
    ImGui::PopStyleVar();
  }

  ImGui::SameLine();

  bool highlightStopButton = false;

  if (!EditorWindow::getWindow()->isSceneRunning)
  {
    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.2f);
    highlightStopButton = true;
  }

  if (ImGui::Button("Stop"))
  {
    EditorWindow::getWindow()->stopScene();
  }

  if (highlightStopButton)
  {
    ImGui::PopStyleVar();
  }

  ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 50);

  double scalingFactor;

  //Adjust the size of the viewport image to make sure that no image stretching occurs
  if (ImGui::GetContentRegionAvail().x / viewBuffer.getSize().x < ImGui::GetContentRegionAvail().y / viewBuffer.getSize().y)
  {

    scalingFactor = ImGui::GetContentRegionAvail().x / viewBuffer.getSize().x;

  }
  else
  {

    scalingFactor = ImGui::GetContentRegionAvail().y / viewBuffer.getSize().y;

  }

  uint32_t textureID = viewBuffer.getColorBuffer();

  ImGui::SetCursorPosY(0.5 * (ImGui::GetWindowSize().y + ImGui::GetFrameHeight()) - (0.5 * scalingFactor * viewBuffer.getSize().y));

  ImGui::Image((void*)textureID, ImVec2(scalingFactor* viewBuffer.getSize().x, scalingFactor* viewBuffer.getSize().y), ImVec2(0, 1), ImVec2(1, 0));

  ImGui::End();

}
