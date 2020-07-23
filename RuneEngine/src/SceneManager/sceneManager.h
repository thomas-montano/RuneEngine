/**
 * @class rune::SceneManager
 * @brief The scene manager is responsible for handling the transfer of the
 * current state pointer that refers to the overwritten state class
 * for each instance of the game.
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef STATEMANAGER_H_INCLUDED
#define STATEMANAGER_H_INCLUDED

#include "core.h"
#include <vector>
#include "gameScene.h"

namespace rune{

class RUNE_ENGINE SceneManager
{
private:
  static int m_currentScene; //Index for the current state

  //Array to hold all of the object pointers for the virtual functions
  static std::vector<rune::GameScene*> m_scenes;
public:
  ///Check to see if the current state has thrown any flags. This lets us know whether or not GameApplication needs to do anything
  void checkFlags(void);
  
  ///Adds a GameScene into the SceneManager scene buffer.
  void addScene(rune::GameScene* newScene);

  ///Get the currently active GameScene.
  static rune::GameScene* getCurrentScene(void);

  ///Set the currently active GameScene.
  void setScene(int newState);

  ///Get the total number of scenes currently stored in the SceneManger scene buffer.
  int getNumScenes(void);
};
}

#endif
