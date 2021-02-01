#include "gameScene.h"
#include <gameApplication.h>
#include <Input/mouse.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>

rune::GameScene::GameScene() 
  : accumulator(0), dT(getGameInstance()->getDeltaTime()), frameStart(0)
{
  variableClock.reset();
}

rune::GameScene::GameScene(GameScene& newScene)
  : accumulator(0), dT(getGameInstance()->getDeltaTime()), frameStart(0)
{
  
  this->isStateActive = newScene.isStateActive;

  /*for(int i = 0; i < newScene.physicsBodies.size();i++)
  {
    physics::RigidBody* bodyPtr = new physics::RigidBody();
    *bodyPtr = *newScene.physicsBodies[i];

    std::cout << "Test" << std::endl;
    //this->physicsBodies.push_back(bodyPtr);
  }*/

  for (GameObject** currentObject = newScene.sceneObjects.getList(); currentObject != nullptr; currentObject = newScene.sceneObjects.getNext())
  {
    GameObject objPtr = GameObject(**currentObject);
    sceneObjects.add(&objPtr);
  }

  for(int i = 0; i < sceneObjects.size();i++)
  {
    for(int j = 0; j < sceneObjects[i]->getNumComponents();j++)
    sceneObjects[i]->getComponentList()[j]->start();
  }

  std::cout << "Scene Copied" << std::endl;
}

/**
 * DoInit is responsible for initializing this State.  HandleCleanup will
 * be called if mCleanup is true so Derived classes should always call
 * IState::DoInit() first before initializing their assets.
 */
void rune::GameScene::doInit(void)
{

}

/**
 * ReInit is responsible for Resetting this state when the
 * StateManager::ResetActiveState() method is called.  This way a Game
 * State can be restarted without unloading and reloading the game assets
 */
void rune::GameScene::reInit(void)
{

}

/**
 * DeInit is responsible for marking this state to be cleaned up
 */
void rune::GameScene::deInit(void)
{
  isStateActive = false;
}

/**
 * Pause is responsible for pausing this State since the Application
 * may have lost focus or another State has become activate.
 */
void rune::GameScene::pause(void)
{

}

/**
 * Resume is responsible for resuming this State since the Application
 * may have gained focus or the previous State was removed.
 */
void rune::GameScene::resume(void)
{

}

/**
 * Handle scene level UI that needs to be run independent of the update rate.
 * @param window Render window that should be used for mouse positions
 */
void rune::GameScene::handleUI(RenderWindow& window)
{

}

/**
 * UpdateFixed is responsible for handling all State fixed update needs for this
 * State when it is the active State.
 */
void rune::GameScene::updateFixed(void)
{

}

/**
 * UpdateVariable is responsible for handling all State variable update needs for this
 * State when it is the active State.
 */
void rune::GameScene::updateVariable(void)
{

}

void rune::GameScene::addObjectToScene(rune::GameObject& newObject)
{

  sceneObjects.add(&newObject);

  //If the new object has a physics component on it, add it to the physicsBody vector.
  auto tempPtr = newObject.getComponent<physics::RigidBody>();

  if(tempPtr)
    physicsBodies.push_back(tempPtr);

}

///@param newDrawable a pointer to an object that needs to be drawn to the screen.
void rune::GameScene::submitToRenderer(rune::Drawable& newDrawable)
{
  drawableObjects.push_back(&newDrawable);
}

void rune::GameScene::addPhysicsObject(physics::RigidBody& body)
{
  physicsBodies.push_back(&body);
}

void rune::GameScene::startComponents(void)
{

  for (GameObject** currentObject = sceneObjects.getList(); currentObject != nullptr; currentObject = sceneObjects.getNext())
  {
    
    std::vector<Component*>& componentList = (*currentObject)->getComponentList();
    
    for (int i = 0; i < componentList.size(); i ++)
    {
      componentList[i]->start();
    }
  }

}

void rune::GameScene::updateComponents()
{

  for (GameObject** currentObject = sceneObjects.getList(); currentObject != nullptr; currentObject = sceneObjects.getNext())
  {
    
    std::vector<Component*>& componentList = (*currentObject)->getComponentList();

    for (int i = 0; i < componentList.size(); i++)
    {
      if(componentList[i]->isComponentEnabled())
      {
        componentList[i]->update();
      }
    }

  }

}

///@param window A handle to the rune::RenderWindow that is being drawn to.
/// @warning This function is only meant to be used in between a frame buffer bind and unbind only.
void rune::GameScene::renderScene(RenderWindow& window)
{

  window.clear(clearColor);

  for (int i = 0; i < drawableObjects.size(); i++)
  {

    getGameInstance()->getWindow()->draw(*drawableObjects[i]);

  }

}

/**
 * Update the RigidBodies in the scene.
 */
void rune::GameScene::updatePhysics(void)
{

  double currentTime = variableClock.getElapsedTimeAsMilliseconds()/1000.0;
  
  accumulator += currentTime - frameStart;
  frameStart = currentTime;

  if(accumulator > 0.2)
  {
    accumulator = 0.2;
  }

  //Deal with physics updates
  while(accumulator > dT)
  {
    physics::updatePhysics(physicsBodies, dT);

    accumulator -= dT;
  }

  const double alpha = accumulator / dT;

  //Update position for every object in every layer

  for (int j = 0; j < physicsBodies.size(); j++)
  {
    physicsBodies[j]->interpolatePosition(alpha);
  }


}

/**
 * Draw is responsible for handling all Drawing needs for this State
 * when it is the Active State.
 * @param window RenderWindow to which the object should be drawn to.
 */
void rune::GameScene::Draw(RenderWindow& window)
{
  window.clear(clearColor);

  //Prepare to render debug UI
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  for(int i = 0; i < drawableObjects.size(); i++)
  {
  
    getGameInstance()->getWindow()->draw(*drawableObjects[i]);
  
  }

  //Draw the debug UI
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  window.display();

}

/**
 * HandleCleanup is responsible for performing any cleanup required before
 * this State is removed.
 */
void rune::GameScene::handleCleanup(void)
{

}

/**
 * @return Whether or not the current scene is flagged as active.
 */
bool rune::GameScene::isActive()
{
  return isStateActive;
}