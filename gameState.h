/*

  GameState

  This class is responsible for serving as a parent class for each instance
  of the game. In order to create a new instance for the game, copy this class
  and add objects as needed

*/

#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "gameObject.h"
#include "gameUI.h"

class GameState
{
private:
  bool isStateActive = false;
protected:
  bool m_changeStateFlag = false;
  int m_nextState;
  bool m_quitGame = false;

  sf::Clock variableClock;
  float dT; //Time between variable update calls
  float accumulator;
  float frameStart;

  std::vector<GameObject*> m_background;
  std::vector<GameObject*> m_midGround;
  std::vector<GameObject*> m_foreground;
  std::vector<GameUI*> m_stateUI;

  GameObject m_backDrop;
  sf::View m_camera;

public:
  virtual void doInit(void);
  virtual void reInit(void);
  void deInit(void);
  virtual void pause(void);
  virtual void resume(void);
  virtual void handleEvents(sf::Event theEvent);
  virtual void updateFixed(void);
  virtual void updateVariable(void);
  virtual void Draw(sf::RenderWindow& window);
  virtual void handleCleanup(void);
  virtual void handleUI(sf::RenderWindow& window, sf::Event theEvent);

  virtual bool getStateFlag();
  virtual int getNextState();
  virtual void setStateFlag(bool value);
  virtual bool getQuitFlag(void);
  virtual bool isActive(void);
  std::vector<GameObject*> getMidGround(void); 

};


#endif
