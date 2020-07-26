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
#include <unordered_map>
#include <string>
#include "gameScene.h"

namespace rune{

class RUNE_ENGINE SceneManager
{
private:
  //Name of the currently active scene.
  std::string m_currentScene;
  //Array to hold all of the object pointers for the virtual functions
  std::unordered_map<std::string, GameScene*> m_scenes;
public:
  ///Adds a GameScene into the SceneManager scene buffer.
  void addScene(std::string const& sceneName, GameScene* newScene);
  ///Get the currently active GameScene.
  rune::GameScene* getCurrentScene(void);
  ///Set the currently active GameScene.
  void setScene(std::string const& newState);
  ///Get the total number of scenes currently stored in the SceneManger scene buffer.
  int getNumScenes(void);
};
}

#endif
