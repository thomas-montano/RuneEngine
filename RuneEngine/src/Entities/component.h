/**
 * @class rune::Component
 * @brief A component of a rune::GameObject, this class is used to add functionality to a object in the game world.
 *
 * @author Thomas Montano
 * @date June 9 2020
*/

#pragma once

#include <core.h>

#ifndef BEHAVIOR_H_INCLUDED
#define BEHAVIOR_H_INCLUDED

namespace rune{

class GameObject;

class RUNE_ENGINE Component
{
protected:
  GameObject* parentObject = nullptr;

public:
  virtual void start();
  
  virtual void update();
  
  virtual void fixedUpdate();

  void setParent(GameObject* newParent)
  {
    parentObject = newParent;
  }
  
};
}

#endif