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
#include <string>
#include <Renderer\color.h>
#include <SceneTools\console.h>
#include <Physics\physicsEngine.h>
#include <Entities\gameObject.h>
#include <Entities\gameUI.h>
#include <Events\clock.h>
#include <SceneTools\layer.h>
#include <Entities\particleEmitter.h>
#include <Renderer\camera.h>

namespace rune{

class RUNE_ENGINE GameScene
{
protected:
  //Flags that are used to communicate with the state manager.
  bool isStateActive = false;
  bool m_changeStateFlag = false;
  int m_nextState;
  bool m_quitGame = false;

  ///All of the layers that make up the scene.
  std::vector<SceneLayer> sceneLayers;
  
  ///A clock that records the amount of time between variable update calls.
  rune::Clock variableClock;
  ///Time between variable update calls
  double dT;
  ///Clamping value for physics simulator.
  double accumulator;
  ///The time that the current frame started.
  double frameStart;
  ///The color that the screen will be when cleared.
  rune::Color clearColor;
  ///Ui to be included in the scene.
  std::vector<GameUI*> m_stateUI;
  ///The camera used to render objects to the screen.
  rune::Camera SceneCamera;
  ///A console to use for debugging.
  rune::Console debugConsole;

public:
  GameScene();
  ///Initializes the state
  virtual void doInit(void);
  ///Reset the scene without unloading game objects
  virtual void reInit(void);
  void deInit(void);
  virtual void pause(void);
  virtual void resume(void);
  virtual void handleEvents(rune::Event theEvent);
  virtual void updateFixed(void);
  void runObjectUpdates(void);
  virtual void updateVariable(void);
  virtual void Draw(RenderWindow& window);
  virtual void updateLayerPhysics(void);
  virtual void handleCleanup(void);
  virtual void handleUI(RenderWindow& window);

  virtual bool getStateFlag();
  virtual int getNextState();
  virtual void setStateFlag(bool value);
  virtual bool getQuitFlag(void);
  bool isActive(void);
  void changeState(int nextState);
  void addLayerToScene(SceneLayer);

};
}

#endif
