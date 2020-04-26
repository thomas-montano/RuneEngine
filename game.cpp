#include <SFML/Graphics.hpp>
#include "Engine/gameApplication.h"
#include "firstLevel.h"
#include "mainMenu.h"
#include <iostream>

using namespace sf;

int main(int argc, char* argv[])
{
    
    //Initialize our game application at a 60 Hz clock
    GameApplication* mainApplication = new GameApplication(60);

    FirstLevel* firstLevel = new FirstLevel();
    mainApplication->loadScene(firstLevel);

    MainMenu* titleScreen = new MainMenu();
    mainApplication->loadScene(titleScreen);

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
