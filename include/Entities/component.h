/**
 * @class rune::Component
 * @brief A component of a rune::GameObject, this class is used to add functionality to a object in the game world.
 *
 * @author Thomas Montano
 * @date June 9 2020
*/

#pragma once

#include <core.h>
#include <Events/Observer.h>
#include <Events/signal.h>

#ifndef BEHAVIOR_H_INCLUDED
#define BEHAVIOR_H_INCLUDED

namespace rune{

class GameObject;

class RUNE_ENGINE Component : public Observer
{
protected:
  GameObject* parentObject = nullptr;
  bool isEnabled = true;

public:
  ///Default constructor to set up
  Component() = default;
  Component(const Component& component);
  ///A function for each component that is called once at the beginning of the components lifetime.
  virtual void start();
  ///A function for each component that is called every frame.
  virtual void update();
  ///A function for each component that is called once every physics update.
  virtual void fixedUpdate();
  ///A function to set the pointer to the parent rune::GameObject for each component.
  void setParent(GameObject* newParent);
  ///Enable or disable the component.
  void setEnable(bool newEnable);
  ///Gets whether or not the current component is enabled.
  bool isComponentEnabled(void);

  void onNotify(Signal const& signal) override{}

  
};
}

#endif