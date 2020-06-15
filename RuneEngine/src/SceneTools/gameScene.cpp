#include "gameScene.h"
#include <gameApplication.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>

rune::GameScene::GameScene() 
  : accumulator(0), dT(rune::GameApplication::getDeltaTime()), m_nextState(0), frameStart(0)
{
  variableClock.reset();

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
 * ReInit is responsible for Reseting this state when the
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
 * HandleEvents is responsible for handling input events for this
 * State when it is the active State.
 * @param theEvent to process from the App class Loop method
 */
void rune::GameScene::handleEvents(rune::Event theEvent)
{

}

/**
 * Handle scene level UI that needs to be run independent of the update rate.
 * @param window Render window that should be used for mouse positions
 * @param theEvent Event object used for mouse position at the moment of click 
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

void rune::GameScene::addObjectToScene(rune::GameObject newObject)
{

  sceneObjects.push_back(newObject);

}

void rune::GameScene::startComponents(void)
{

  for (int i = 0; i < sceneObjects.size(); i++)
  {
    for (int j = 0; j < sceneObjects[i].getNumComponents(); j++)
    {
      sceneObjects[i].getComponent(j)->start();
    }
  }

}

void rune::GameScene::updateComponents()
{
  
  rune::GameApplication::getWindow()->clear(clearColor);

  for(int i = 0; i < sceneObjects.size(); i++)
  {
    for(int j = 0; j < sceneObjects[i].getNumComponents();j++)
    {
      sceneObjects[i].getComponent(j)->update();
    }
  }

  //Prepare to render debug UI
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGui::Begin("FPS");

  ImGui::SetWindowSize(ImVec2(100, 50));
  ImGui::SetWindowPos(ImVec2(0, 0));

  if (ImGui::IsItemHovered())
  {
    ImGui::BeginTooltip();
    ImGui::Text("This is the debug UI!");
    ImGui::EndTooltip();
  }

  ImGui::Text(std::to_string(rune::GameApplication::getFrameRate()).c_str());

  ImGui::End();

  //Draw the debug UI
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  rune::GameApplication::getWindow()->display();

}

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
  /*while(accumulator > dT)
  {

    for(int i = 0; i < sceneLayers.size(); i++)
    {

      std::vector<physics::RigidBody*> rigidBodies = sceneLayers[i].getRigidBodies();
      updatePhysics(rigidBodies,dT);
    
    }

    accumulator -= dT;
  }

  const double alpha = accumulator / dT;

  //Update position for every object in every layer
  for(int i = 0; i < sceneLayers.size();i++)
  {
    std::vector<rune::GameObject*> sceneObjects = sceneLayers[i].getObjects();

    for(int j = 0; j < sceneObjects.size(); j++)
    {
      sceneObjects[j]->updatePosition(alpha);
    }
  }*/

}

/**
 * Draw is responsible for handling all Drawing needs for this State
 * when it is the Active State.
 * @param window RenderWindow to which the object should be drawn to.
 */
void rune::GameScene::Draw(RenderWindow& window)
{

  //window.clear(clearColor);

  /*for(int i = 0; i < drawables.size();i++)
  {
  
    window.draw(*drawables[i]);
    
  }*/

  //window.display();

}

/**
 * HandleCleanup is responsible for performing any cleanup required before
 * this State is removed.
 */
void rune::GameScene::handleCleanup(void)
{

}

/** 
 * Determines whether or not the current state is
 * asking to change to a different state.
 * @return Whether or not the state manager is being asked to change the scene.
 */
bool rune::GameScene::getStateFlag()
{

  return m_changeStateFlag;

}

/**
 * Tells the state manager what state should be switched to next.
 * @return The state that the state manager should switch to.
 */
int rune::GameScene::getNextState()
{

  return m_nextState;

}

/**
 * Set a flag that says the current scene wants to change to a different scene
 * @param value Set the flag that controls whether or not the state is going to be changed.
*/
void rune::GameScene::setStateFlag(bool value)
{

  m_changeStateFlag = value;

}

/**
 * Determines whether or not the current scene is asking for the game to be shut down. Used for things like quit buttons.
 * @return Whether or not the state flag has been thrown.
*/
bool rune::GameScene::getQuitFlag()
{

  return m_quitGame;

}

/**
 * Determines whether or not the state is currently active.
 * @return Whether or not the current scene is flagged as active.
 */
bool rune::GameScene::isActive()
{
  return isStateActive;
}

/**
 * Change the currently active state. Scene index must be handled by the user.
 * @param nextState The index in the GameApplication GameScene buffer.
 */
void rune::GameScene::changeState(int nextState)
{
    m_changeStateFlag = true;
    m_nextState = nextState;
}