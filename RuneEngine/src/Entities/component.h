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
  ///A function for each component that is called once at the beginning of the components lifetime.
  virtual void start();
  ///A function for each component that is called every frame.
  virtual void update();
  ///A function for each component that is called once every physics update.
  virtual void fixedUpdate();
  ///A function to set the pointer to the parent rune::GameObject for each component.
  void setParent(GameObject* newParent);
  
};
}

#endif