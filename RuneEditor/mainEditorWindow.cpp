#include "mainEditorWindow.h"

void EditorWindow::doInit()
{

  clearColor = rune::Color::Blue;

  addObjectToScene(sceneContents);


}

void EditorWindow::updateVariable(void)
{

  //Debugging escape code to get back to main menu
  if (rune::Keyboard::isKeyPressed(rune::Keyboard::ESCAPE))
  {
    quitGame();
  }

}

