/**
 * @class GameScene
 * @brief This class is responsible for serving as a parent class for each instance
  of the game. In order to create a new instance for the game, copy this class
  and add objects as needed
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "physicsEngine.h"
#include "gameObject.h"
#include "gameUI.h"
#include "messageManager.h"
#include "layer.h"
#include "particleEmitter.h"

class GameScene
{
private:
  bool isStateActive = false;
  
protected:  
  bool m_changeStateFlag = false;
  int m_nextState;
  bool m_quitGame = false;

  std::vector<SceneLayer> sceneLayers;
  
  sf::Clock variableClock;
  float dT; //Time between variable update calls
  float accumulator;
  float frameStart;

  std::vector<GameUI*> m_stateUI;

  sf::View m_camera;

public:
  ///Initializes the state
  virtual void doInit(void);

  ///Reset the scene without unloading game objects
  virtual void reInit(void);
  void deInit(void);
  virtual void pause(void);
  virtual void resume(void);
  virtual void handleEvents(sf::Event theEvent);
  virtual void updateFixed(void);
  virtual void updateVariable(void);
  virtual void Draw(sf::RenderWindow& window);
  virtual void updateLayerPhysics(void);
  virtual void handleCleanup(void);
  virtual void handleUI(sf::RenderWindow& window, sf::Event theEvent);

  virtual bool getStateFlag();
  virtual int getNextState();
  virtual void setStateFlag(bool value);
  virtual bool getQuitFlag(void);
  virtual bool isActive(void);
  void changeState(int nextState);
  void addLayerToScene(SceneLayer);


};


#endif
