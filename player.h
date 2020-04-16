/*

  Player

  Main game object controlled by the player

  Thomas Montano
  3/2/20

*/

#ifndef PLAYER_OBJECT_DEFINED
#define PLAYER_OBJECT_DEFINED

#include "Engine/gameObject.h"
#include "Engine/messageManager.h"
#include <SFML/Graphics.hpp>

class Player : public GameObject
{

private:
  bool hasJumped;
  bool touchingGround;
public:
  virtual void update(void);
  virtual void start(void);

};

#endif
