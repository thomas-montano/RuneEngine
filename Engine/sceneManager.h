/**
 * @brief The state manager is responsible for handling the transfer of the
 * current state pointer that refers to the overwritten state class
 * for each instance of the game.
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef STATEMANAGER_H_INCLUDED
#define STATEMANAGER_H_INCLUDED

#include "gameScene.h"

class SceneManager
{
private:
  int m_currentScene; //Index for the current state

  //Array to hold all of the object pointers for the virtual functions
  std::vector<GameScene*> m_scenes;
public:
  
  void checkFlags(void);
  void addScene(GameScene* newScene);
  GameScene* getCurrentScene(void);
  void setScene(int newState);
  int getNumScenes(void);
};

#endif
