/**
 * @class MainMenu
 * @brief This is the main menu screen and is displayed on game startup.
 * 
 * @author Thomas Montano
 * @date April 13 2020
*/

#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Engine/gameScene.h"
#include "Engine/gameUI.h"

class MainMenu : public GameScene
{
private:

  bool isStateActive = false;

  GameUI m_startButton;
  GameUI m_quitButton;

  sf::Music backgroundMusic;
  sf::SoundBuffer m_soundBuffer;
  sf::Sound m_soundEffect;


public:
  virtual void doInit(void);
  virtual void reInit(void);
  void deInit(void);
  virtual void pause(void);
  virtual void resume(void);
  virtual void handleEvents(sf::Event theEvent);
  virtual void updateFixed(void);
  virtual void updateVariable(void);
  virtual void handleCleanup(void);
  virtual void handleUI(sf::RenderWindow& window, sf::Event theEvent);

  virtual bool isActive(void);

};


#endif
