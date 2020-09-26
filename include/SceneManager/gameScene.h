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
//#include <Physics\world.h>

namespace rune{

class RUNE_ENGINE GameScene
{
protected:
  //Flags that are used to communicate with the state manager.
  bool isStateActive = false;

  std::vector<physics::RigidBody*> physicsBodies;

  //This list can be non-pointers because it is a list.
  List<rune::GameObject*> sceneObjects;

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
  ///Makes all of the draw calls for the scene.
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

/**
 * @page scenes Game Scenes
 * 
 * Start off by declaring the header file and including all the objects you'll need for this scene.
 * 
 * @code
 * 
 * #include <RuneEngine.h>
 * #include "..\Objects\player.h"
 * #include "..\Objects\floorTile.h"
 *
 * class FirstLevel : public rune::GameScene
 * {
 *
 * private:
 *
 *   //Add a player object
 *   Player playerObject;
 *
 *   //Create the scene floor
 *   FloorTile groundTile1;
 *   FloorTile groundTile2;
 *
 *   rune::Camera sceneCamera;
 *
 *
 * };
 * 
 * @endcode
 * 
 * After you have all of these objects added in the header, go ahead and instantiate the objects in the scene by creating a `doInit(void)` function.
 * 
 * @code
 * public: 
 *   virtual void doInit(void) override;
 *  
 * @endcode
 * 
 * Then in this function you can add objects to scene, set up cameras, change positions of objects, and anything else you could normally do with a rune::GameObject.
 * 
 * @code
 * 
void FirstLevel::doInit(void)
{
  //Change the color that the screen will be cleared with.
  clearColor = rune::Color(49,77,121);

  //Add player object
  addObjectToScene(playerObject)

  //Add the floor to the scene
  addObjectToScene(groundTile1);
  addObjectToScene(groundTile2);

  //Change the position of each object independently.
  m_groundTile1.transform.setPosition(rune::Vec3(0,0));
  m_groundTile2.transform.setPosition(rune::Vec3(128, 0));

  //Set up the camera
  SceneCamera.setZoom(2.5);
  SceneCamera.setCenter(rune::Vec2(m_player.transform.getPosition().x+180, m_player.transform.getPosition().y+30));
  getGameInstance()->getWindow()->setCamera(SceneCamera);
}

 * 
 * @endcode
 * 
 * And now you should have your first rune::GameScene up and running! All that's left to do is add it to your rune::GameApplication in your main function.
 * 
 * See how to [create a new rune::GameApplication](entry_point.html)
 * 
 */
