#include "mainEditorWindow.h"

RuneEngineProject EditorWindow::currentlyOpenProject("New Project");

void EditorWindow::doInit()
{

  //static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

  clearColor = rune::Color::White;

  ImGuiIO& io = ImGui::GetIO();

  ImVec4* colors = ImGui::GetStyle().Colors;
  colors[ImGuiCol_WindowBg] = ImVec4(0.15f, 0.17f, 0.23f, 0.94f);
  colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.13f, 0.18f, 1.00f);
  colors[ImGuiCol_Separator] = ImVec4(0.78f, 0.78f, 0.78f,1.f);
  colors[ImGuiCol_Border] = ImVec4(0.78f, 0.78f, 0.78f, 1.f);

  addObjectToScene(menuBar);
  addObjectToScene(sceneContents);
  addObjectToScene(inspectorTab);
  addObjectToScene(resourceTab);
  addObjectToScene(viewPort);

  static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

  rune::GameApplication::getWindow()->setWindowTitle(EditorWindow::currentlyOpenProject.projectName + " - Rune Engine Editor Version 0.7.5-alpha");

  rune::GameApplication::getWindow()->maximizeWindow();

}

void EditorWindow::updateVariable(void)
{


}

