/**
 * @class rune::GameObject
 * @brief Entity control system main object used for all objects in the scene
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef GAMEOBJECT_INCLUDE_H
#define GAMEOBJECT_INCLUDE_H

#include "core.h"
#include "transform.h"
#include <typeinfo>
#include <vector>
#include <Entities\component.h>
#include <Renderer\renderWindow.h>


namespace rune{

class RUNE_ENGINE GameObject
{
private:
  std::vector<rune::Component*> objectComponents;

public:
  ///The location, scale, and rotation of the object in the world.
  rune::Transform transform;

  //GameObject();
  //~GameObject();
  ///Add a component to this game object.
  void addComponent(rune::Component&);
  ///Get the number of components present on this game object.
  int getNumComponents(void);
  //Create a new dynamically allocated version of this game object.
  void instantiate(GameObject);
  ///Return a pointer to a component based off of index. Used for iterating through all components.
  rune::Component* getComponent(int index);

  ///Locate components of the object based on data type
  ///Call the function like this: findComponent<rune::Sprite>();
  /// @warning Do not call this in a rune::GameObject constructor. Call it in either start() or update()
  template<class classVariable>
  classVariable* findComponent()
  {

    for(auto & objectComponent : objectComponents)
    {

      if (std::string(typeid(*objectComponent).name()) == std::string(typeid(classVariable).name()))
      {

        return dynamic_cast<classVariable*>(objectComponent);

      }

    }

    return nullptr;

  }

};
}

#endif

/**
 * 
 * @page GameObjects How To Make Your Own Custom GameObjects
 * 
 * Start off by declaring your header file and including your components. You'll also want to declare a constructor so that these components can be added onto the rune::GameObject.
 * 
 * @code
 * 
 * #include <RuneEngine.h>
 * 
 * class Player : public rune::GameObject
 * {
 * 
 * public:
 *  rune::Sprite sprite;
 *  rune::AnimationController animController;
 *  physics::RigidBody body;
 *  physics::Collider2D collider;
 * 
 *  //Create a constructor for object initialization.
 *  Player();
 * 
 * }
 * 
 * @endcode
 * 
 * After you have created your new rune::GameObject, go ahead and create a cpp file so that we can set up all these components we've just declared. For any of the components that have constructors you want to use, go ahead
 * and declare these in the initialization line.
 * 
 * @code 
 * 
 * #include "Player.h"
 * 
 * Player::Player()
 *  : sprite("Path to your sprite")
 * {
 * 
 *  //Set up a default position for this object.
 *  //Any elements not specifically added to a rune::Vec3 will be defaulted to 0.
 *  transform.setPosition(rune::Vec3(0,0));
 *
 *  //You should make sure to set the scale of your object to be what you want, otherwise it will default to a 1 pixel by 1 pixel object.
 *  transform.setScale(rune::Vec3(16,32));
 *
 *  //Let's add the components we declared earlier.
 *  addComponent(sprite);
 *  addComponent(animController);
 *  addComponent(body);
 *  addComponent(collider);
 * 
 *  //This is also where you should add animations for your object.
 *  animController.addAnimation("idle",16,2,2,"Path to your sprite sheet");
 *  
 * };
 * 
 * @endcode
 * 
 * And that's all you need! Go ahead and add it to your rune::GameScene and hit play!
 * 
 */
