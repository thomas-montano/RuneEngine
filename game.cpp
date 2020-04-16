/*

Main function for Private Eye
This file just instantiates the game application and handles
the return code

Thomas Montano
2/27/19

*/

#include <SFML/Graphics.hpp>
#include "gameApplication.h"
#include "firstLevel.h"
#include "mainMenu.h"
#include <iostream>

using namespace sf;

int main(int argc, char* argv[])
{

    //Initialize our game application at a 60 Hz clock
    GameApplication* mainApplication = new GameApplication(60);

    MainMenu* titleScreen = new MainMenu();
    mainApplication->loadScene(titleScreen);

    FirstLevel* firstLevel = new FirstLevel();
    mainApplication->loadScene(firstLevel);

    //Start the game
    mainApplication->run();

    //Command line output
    std::cout << "Returned code: " << mainApplication->m_errorCode << std::endl;

    //Once the game has ended, clean up
    delete mainApplication;
    delete firstLevel;
    delete titleScreen;

    return 0;
}
