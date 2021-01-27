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
  ///The rune::GameObject that this component is attached to. If not attached to a rune::GameObject this will equal nullptr.
  GameObject* parentObject = nullptr;
  ///Whether or not the component is currently enabled. If not enabled, update function will not be called.
  bool isEnabled = true;

public:
  ///Default constructor to set up
  Component() = default;
  ///Default constructor to set up a component when given another component to use as a copy.
  Component(const Component& component);
  ///A function that will be called before all other start functions but after the component has been assigned to a GameObject.
  virtual void awake();
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