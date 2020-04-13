#include "mainMenu.h"


  /**
     * DoInit is responsible for initializing this State.  HandleCleanup will
     * be called if mCleanup is true so Derived classes should always call
     * IState::DoInit() first before initializing their assets.
     */
    void MainMenu::doInit(void)
    {

      testParticle = new Particles(sf::Vector2f(100,550), sf::Vector2f(3,3), sf::Color::Green);

      isStateActive = true;

      m_stateUI =
      {

        &m_startButton,
        &m_quitButton

      };

      m_startButton.createButton(580,100,120,60);
      m_quitButton.createButton(580, 200, 120, 60);

      m_camera.setSize(1280.f,720.f);
      m_camera.setCenter(1280/2,720/2);

      m_soundBuffer.loadFromFile("./Assets/Sounds/buttonClick");
      m_soundEffect.setBuffer(m_soundBuffer);

      backgroundMusic.openFromFile("./Assets/Music/mainTheme.wav");
      backgroundMusic.setVolume(30.f);
      backgroundMusic.play();
      backgroundMusic.setLoop(true);

    }

    /**
     * ReInit is responsible for Reseting this state when the
     * StateManager::ResetActiveState() method is called.  This way a Game
     * State can be restarted without unloading and reloading the game assets
     */
    void MainMenu::reInit(void)
    {

    }

    /**
     * DeInit is responsible for marking this state to be cleaned up
     */
    void MainMenu::deInit(void)
    {

    }

    /**
     * Pause is responsible for pausing this State since the Application
     * may have lost focus or another State has become activate.
     */
    void MainMenu::pause(void)
    {

    }

    /**
     * Resume is responsible for resuming this State since the Application
     * may have gained focus or the previous State was removed.
     */
    void MainMenu::resume(void)
    {

    }

    /*
     * HandleEvents is responsible for handling input events for this
     * State when it is the active State.
     * @param[in] theEvent to process from the App class Loop method
     */
    void MainMenu::handleEvents(sf::Event theEvent)
    {



    }

    void MainMenu::handleUI(sf::RenderWindow& window, sf::Event theEvent)
    {

      sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

      if(m_startButton.isClicked(mousePosition,theEvent))
      {
        //m_soundEffect.play();
        m_changeStateFlag = true;
        m_nextState = 1;
        isStateActive = false;

      }

      if(m_quitButton.isClicked(mousePosition,theEvent))
      {
        //m_soundEffect.play();
        m_quitGame = true;

      }

    }

    /**
     * UpdateFixed is responsible for handling all State fixed update needs for this
     * State when it is the active State.
     */
    void MainMenu::updateFixed(void)
    {

    }

    /**
     * UpdateVariable is responsible for handling all State variable update needs for this
     * State when it is the active State.
     */
    void MainMenu::updateVariable(void)
    {



    }

   /**
     * HandleCleanup is responsible for performing any cleanup required before
     * this State is removed.
     */
    void MainMenu::handleCleanup(void)
    {

      backgroundMusic.stop();

    }

    //Determine whether or not the state is active
    bool MainMenu::isActive(void)
    {
      return isStateActive;
    }
