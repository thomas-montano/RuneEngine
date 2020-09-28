//You should include your scene headers and the RuneEngine header.
#include <RuneEngine.h>
#include "myScene.h"
#include <iostream>

int main(void)
{
  //Initialize your game application to have a really awesome title.
  rune::GameApplication* mainApplication = mainApplication->getApplication();

  getGameInstance()->getWindow()->setWindowTitle("My Game Title");

  //Load the first level into the game application
  myScene* firstLevel = new myScene();
  mainApplication->loadScene("First Level", firstLevel);

  //Start the game
  mainApplication->run();

  //Command line output
  std::cout << "Returned code: " << mainApplication->m_errorCode << std::endl;

  //Once the game has ended, clean up
  delete mainApplication;
  delete firstLevel;
  return 0;
}