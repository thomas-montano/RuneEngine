#ifndef PLAYER_OBJECT_DEFINED
#define PLAYER_OBJECT_DEFINED

#include "gameObject.h"
#include "messageManager.h"
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
