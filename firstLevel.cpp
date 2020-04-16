#include "firstLevel.h"
#include <chrono>

/**
     * DoInit is responsible for initializing this State.  HandleCleanup will
     * be called if mCleanup is true so Derived classes should always call
     * IState::DoInit() first before initializing their assets.
     */
    void FirstLevel::doInit(void)
    {

      testParticle = new ParticleEmitter(sf::Vector2f(100,450), sf::Vector2f(0,-100), sf::Color::Blue, 4,sf::Vector2f(0,-80));

      isStateActive = true;

      m_sceneHeight = 720;
      m_sceneLength = 1280;

      m_midGround = {
      
      &m_ball,
      &m_player,
      //Create the level floor
      &m_groundTile1,
      &m_groundTile2,
      &m_groundTile3,
      &m_groundTile4,
      &m_groundTile5,
      &m_groundTile6,
      &m_groundTile7,
      &m_groundTile8,
      &m_groundTile9,
      &m_groundTile10
      };

      m_camera.setSize(512.f,256.f);
      m_camera.setCenter(1280/2,720/2);

      m_ball.objectInit(100,600,16,16,"./Assets/Images/ball.png");
      m_player.objectInit(50.0,500.f,16,32,"./Assets/Images/knoxV1.png");
      
      m_backDrop.objectInit(1280.0/2,720.0/2,1280,720,"./Assets/Images/background.png");

      m_groundTile1.objectInit(64,m_sceneHeight-32,128,64,"./Assets/Images/groundTile.png",0);
      m_groundTile2.objectInit(192.f,m_sceneHeight-32,128,64,"./Assets/Images/groundTile.png",0);
      m_groundTile3.objectInit(320.f,m_sceneHeight-32,128,64,"./Assets/Images/groundTile.png",0);
      m_groundTile4.objectInit(448.f,m_sceneHeight-32,128,64,"./Assets/Images/groundTile.png",0);
      m_groundTile5.objectInit(576,m_sceneHeight-32,128,64,"./Assets/Images/groundTile.png",0);
      m_groundTile6.objectInit(704,m_sceneHeight-32,128,64,"./Assets/Images/groundTile.png",0);
      m_groundTile7.objectInit(832,m_sceneHeight-32,128,64,"./Assets/Images/groundTile.png",0);
      m_groundTile8.objectInit(960,m_sceneHeight-32,128,64,"./Assets/Images/groundTile.png",0);
      m_groundTile9.objectInit(1080,m_sceneHeight-32,128,64,"./Assets/Images/groundTile.png",0);
      m_groundTile10.objectInit(1208,m_sceneHeight-32,128,64,"./Assets/Images/groundTile.png",0);

      MessageManager::setMidGroundObjects(m_midGround);

      dT = MessageManager::getDeltaTime();
      accumulator = 0;

      // In units seconds
      variableClock.restart();
      frameStart = variableClock.getElapsedTime().asMilliseconds() / 1000.0;
    }

    /**
     * ReInit is responsible for Reseting this state when the
     * StateManager::ResetActiveState() method is called.  This way a Game
     * State can be restarted without unloading and reloading the game assets
     */
    void FirstLevel::reInit(void)
    {

    }

     /* DeInit is responsible for marking this state to be cleaned up
     */
    void FirstLevel::deInit(void)
    {

    }

    /**
     * Pause is responsible for pausing this State since the Application
     * may have lost focus or another State has become activate.
     */
    void FirstLevel::pause(void)
    {

    }

    /**
     * Resume is responsible for resuming this State since the Application
     * may have gained focus or the previous State was removed.
     */
    void FirstLevel::resume(void)
    {

    }

    /*
     * HandleEvents is responsible for handling input events for this
     * State when it is the active State.
     * @param[in] theEvent to process from the App class Loop method
     */
    void FirstLevel::handleEvents(sf::Event theEvent)
    {



    }

    void FirstLevel::handleUI(sf::RenderWindow& window)
    {



    }

    /**
     * UpdateFixed is responsible for handling all State fixed update needs for this
     * State when it is the active State.
     */
    void FirstLevel::updateFixed(void)
    {

      //Debugging escape code to get back to main menu
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        m_changeStateFlag = true;
        m_nextState = 0;
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
      {
        testParticle->fuel(5);
      }

      for(int i = 0; i < m_midGround.size();i++)
      {
        m_midGround[i]->update();
      }

      testParticle->update(dT);

    }

    /**
     * UpdateVariable is responsible for handling all State variable update needs for this
     * State when it is the active State.
     */
    void FirstLevel::updateVariable(void)
    {
      //Handle camera movement
      sf::Vector2f cameraSize = m_camera.getSize();
      m_camera.setCenter(sf::Vector2f(m_player.getRigidBody()->getBoundingBox().min.x,m_sceneHeight - (cameraSize.y/2)));

      if(m_player.getRigidBody()->getBoundingBox().min.x < cameraSize.x/2)
      {
        m_camera.setCenter(sf::Vector2f(cameraSize.x/2,m_sceneHeight - (cameraSize.y/2)));
      }

      if(m_player.getRigidBody()->getBoundingBox().min.x > m_sceneLength-cameraSize.x/2)
      {
        m_camera.setCenter(sf::Vector2f(m_sceneLength-cameraSize.x/2,m_sceneHeight - (cameraSize.y/2)));
      }
      
      float currentTime = variableClock.getElapsedTime().asMilliseconds()/1000.0;
      
      accumulator += currentTime - frameStart;
      frameStart = currentTime;
      
      std::vector<RigidBody*> rigidBodies(m_midGround.size());

      for(int i = 0; i < m_midGround.size();i++)
      {

        rigidBodies[i] = m_midGround[i]->getRigidBody();

      }

      if(accumulator > 0.2)
      {
        accumulator = 0.2;
      }

      //Deal with physics updates
      std::cout << dT << std::endl;
      while(accumulator > dT)
      {

        updatePhysics(rigidBodies,dT);
        accumulator -= dT;

      }

      const float alpha = accumulator / dT;

      for(int i = 0; i < m_midGround.size();i++)
      {
        m_midGround[i]->updatePosition(alpha);
      }

    }

   /**
     * HandleCleanup is responsible for performing any cleanup required before
     * this State is removed.
     */
    void FirstLevel::handleCleanup(void)
    {

    }

    //Determine whether or not the state is active
    bool FirstLevel::isActive(void)
    {
      return isStateActive;
    }
