/**
 * @class rune::GameScene
 * @brief This class is responsible for serving as a parent class for each instance
  of the game. In order to create a new instance for the game, copy this class
  and add objects as needed
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include <core.h>
#include <vector>
#include <Physics\physicsEngine.h>
#include <Entities\gameObject.h>
#include <Entities\gameUI.h>
#include <Events\clock.h>
#include <SceneTools\layer.h>
#include <Entities\particleEmitter.h>

namespace rune{

class RUNE_ENGINE GameScene
{
private:
  bool isStateActive = false;
  
protected:  
  bool m_changeStateFlag = false;
  int m_nextState;
  bool m_quitGame = false;

  std::vector<SceneLayer> sceneLayers;
  
  rune::Clock variableClock;
  double dT; //Time between variable update calls
  double accumulator;
  double frameStart;

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
  virtual void handleEvents(rune::Event theEvent);
  virtual void updateFixed(void);
  virtual void updateVariable(void);
  virtual void Draw(RenderWindow& window);
  virtual void updateLayerPhysics(void);
  virtual void handleCleanup(void);
  virtual void handleUI(RenderWindow& window);

  virtual bool getStateFlag();
  virtual int getNextState();
  virtual void setStateFlag(bool value);
  virtual bool getQuitFlag(void);
  virtual bool isActive(void);
  void changeState(int nextState);
  void addLayerToScene(SceneLayer);

};
}


#endif
