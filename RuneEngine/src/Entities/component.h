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
  
};
}

#endif

/**
 * @page Components How To Make Your Own Custom Components
 * 
 * Starting to add new functionality to a rune::GameObject is one of the most important parts of making a game. This is accomplished in Rune through the addition of a rune::Component to your rune::GameObject.
 * You can add a new component created by you the same as any other predefined component. This is how you would go about making your own component.
 * 
 * @code 
 * 
 * #include <RuneEngine.h>
 * 
 * class CharacterController : public rune::Component
 * {
 * 
 * private:
 *  //Declare data members to be used by the component here
 *  //Pointers to components of other GameObject's are also useful to have here.
 * public:
 *  void start()
 *  {
 *    //Things to do when the component is first initialized.
 *  }
 * 
 *  void update()
 *  {
 *    //Things to do every frame.
 *  }
 * 
 * 
 * };
 * 
 * @endcode
 * 
 * 
 */