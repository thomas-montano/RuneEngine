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
#include <Physics\physicsEngine.h>
#include <Entities\gameObject.h>
#include <Events\clock.h>
#include <Renderer\camera.h>
#include <Renderer\frameBuffer.h>
#include <DataStructures\list.h>

namespace rune{

class RUNE_ENGINE GameScene
{
protected:
  //Flags that are used to communicate with the state manager.
  bool isStateActive = false;

  std::vector<physics::RigidBody*> physicsBodies;

  //This list can be non-pointers because it is a list.
  List<rune::GameObject> sceneObjects;

  std::vector<rune::Drawable*> drawableObjects;
  
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

public:
  ///Default constructor to create a new rune::GameScene
  GameScene();
  ///Initializes the state
  virtual void doInit(void);
  ///Reset the scene without unloading game objects
  virtual void reInit(void);
  void deInit(void);
  virtual void pause(void);
  virtual void resume(void);
  virtual void updateFixed(void);
  virtual void updateVariable(void);
  virtual void Draw(RenderWindow& window);
  virtual void updatePhysics(void);
  virtual void handleCleanup(void);
  virtual void handleUI(RenderWindow& window);
  ///Call the start function for all the components on all the objects in the scene.
  void startComponents(void);
  ///Call the update function for all the components on all the objects in the scene.
  void updateComponents(void);
  ///This function should be used in between a frame buffer bind and unbind only.
  void renderScene(RenderWindow& window);
  ///Determines whether or not the scene is currently active.
  bool isActive(void);
  ///Place a new rune::GameObject into the scene.
  void addObjectToScene(rune::GameObject&);
  ///Submits a drawable object into the rendering stack to be drawn to the screen each frame.
  void submitToRenderer(rune::Drawable&);

};
}

#endif
