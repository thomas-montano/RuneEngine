#include "gameScene.h"

/**
 * DoInit is responsible for initializing this State.  HandleCleanup will
 * be called if mCleanup is true so Derived classes should always call
 * IState::DoInit() first before initializing their assets.
 */
void GameScene::doInit(void)
{

}

/**
 * ReInit is responsible for Reseting this state when the
 * StateManager::ResetActiveState() method is called.  This way a Game
 * State can be restarted without unloading and reloading the game assets
 */
void GameScene::reInit(void)
{

}

/**
 * DeInit is responsible for marking this state to be cleaned up
 */
void GameScene::deInit(void)
{
  
}

/**
 * Pause is responsible for pausing this State since the Application
 * may have lost focus or another State has become activate.
 */
void GameScene::pause(void)
{

}

/**
 * Resume is responsible for resuming this State since the Application
 * may have gained focus or the previous State was removed.
 */
void GameScene::resume(void)
{

}

/**
 * HandleEvents is responsible for handling input events for this
 * State when it is the active State.
 * @param[in] theEvent to process from the App class Loop method
 */
void GameScene::handleEvents(sf::Event theEvent)
{

}

void GameScene::handleUI(sf::RenderWindow& window, sf::Event theEvent)
{

}

/**
 * UpdateFixed is responsible for handling all State fixed update needs for this
 * State when it is the active State.
 */
void GameScene::updateFixed(void)
{



}

/**
 * UpdateVariable is responsible for handling all State variable update needs for this
 * State when it is the active State.
 */
void GameScene::updateVariable(void)
{

}

void GameScene::updateLayerPhysics(void)
{

  float currentTime = variableClock.getElapsedTime().asMilliseconds()/1000.0;
  
  accumulator += currentTime - frameStart;
  frameStart = currentTime;

  if(accumulator > 0.2)
  {
    accumulator = 0.2;
  }

  //Deal with physics updates
  while(accumulator > dT)
  {

    for(int i = 0; i < sceneLayers.size(); i++)
    {

      std::vector<RigidBody*> rigidBodies = sceneLayers[i].getRigidBodies();
      updatePhysics(rigidBodies,dT);
    
    }

    accumulator -= dT;
  }

  const float alpha = accumulator / dT;

  //Update position for every object in every layer
  for(int i = 0; i < sceneLayers.size();i++)
  {
    std::vector<GameObject*> sceneObjects = sceneLayers[i].getObjects();

    for(int j = 0; j < sceneObjects.size(); j++)
    {
      sceneObjects[j]->updatePosition(alpha);
    }
  }

}

/**
 * Draw is responsible for handling all Drawing needs for this State
 * when it is the Active State.
 */
void GameScene::Draw(sf::RenderWindow& window)
{

  window.setView(m_camera);
  window.clear(sf::Color(102, 102, 102));

  //Draw the scene layers
  for(int i = 0; i < sceneLayers.size();i++)
  {
    window.draw(sceneLayers[i]);
  }

  //Draw the user interface objects in front of everything else
  for(int i = 0; i < m_stateUI.size();i++)
  {

    window.draw(m_stateUI[i]->getDrawable());

  }

  window.display();

}

/**
 * HandleCleanup is responsible for performing any cleanup required before
 * this State is removed.
 */
void GameScene::handleCleanup(void)
{

}

//getStateFlag determines whether or not the current state is
//asking to change to a different state
bool GameScene::getStateFlag()
{

  return m_changeStateFlag;

}

//Tell the state manager what state to change to
int GameScene::getNextState()
{

  return m_nextState;

}

//Set the flag to say the current state wants to change the state
void GameScene::setStateFlag(bool value)
{

  m_changeStateFlag = value;

}

//Determine if the current state is asking to quit the game
bool GameScene::getQuitFlag()
{

  return m_quitGame;

}

//Determine whether or not the state is active
bool GameScene::isActive()
{
  return isStateActive;
}

//Function to change the current active state
void GameScene::changeState(int nextState)
{
    m_changeStateFlag = true;
    m_nextState = nextState;
}

//Take a layer and add it to the sceneLayers array as well as pushing the correct pointer
//to the layer so that objects can be given a pointer back
void GameScene::addLayerToScene(SceneLayer newScene)
{

  sceneLayers.push_back(newScene);
  newScene.setScenePointer(&sceneLayers[sceneLayers.size()-1]);

}
