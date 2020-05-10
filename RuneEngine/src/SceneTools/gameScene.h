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

#include "core.h"
#include <Physics\physicsEngine.h>
#include <Entities\gameObject.h>
#include <Entities\gameUI.h>
#include <Renderer\clock.h>
#include "messageManager.h"
#include "layer.h"
#include <Entities\particleEmitter.h>

class RUNE_ENGINE GameScene
{
private:
  bool isStateActive = false;
  
protected:  
  bool m_changeStateFlag = false;
  int m_nextState;
  bool m_quitGame = false;

  std::vector<SceneLayer> sceneLayers;
  
  Clock variableClock;
  float dT; //Time between variable update calls
  float accumulator;
  float frameStart;

  std::vector<GameUI*> m_stateUI;

  //View m_camera;

public:

  ///Initializes the state
  virtual void doInit(void);

  ///Reset the scene without unloading game objects
  virtual void reInit(void);
  void deInit(void);
  virtual void pause(void);
  virtual void resume(void);
  virtual void handleEvents(Event theEvent);
  virtual void updateFixed(void);
  virtual void updateVariable(void);
  virtual void Draw(RenderWindow& window);
  virtual void updateLayerPhysics(void);
  virtual void handleCleanup(void);
  virtual void handleUI(RenderWindow& window, Event theEvent);

  virtual bool getStateFlag();
  virtual int getNextState();
  virtual void setStateFlag(bool value);
  virtual bool getQuitFlag(void);
  virtual bool isActive(void);
  void changeState(int nextState);
  void addLayerToScene(SceneLayer);


};


#endif
