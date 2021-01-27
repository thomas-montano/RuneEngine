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
#include <Entities\component.h>
#include <Renderer\renderWindow.h>
#include <Events\subject.h>
#include <vector>

namespace rune{

class RUNE_ENGINE GameObject : public Subject
{
private:
  //This must be a vector of pointers because of the fact that they can't be stored in a List.
  //They can't be stored in a list because during iteration of components, getComponent would
  //reset the list index and enter into an infinite loop.
  std::vector<rune::Component*> objectComponents;

public:
  ///The location, scale, and rotation of the object in the world.
  rune::Transform transform;
  ///Default empty constructor.
  GameObject();
  ///Constructor to be used for copying another rune::GameObject.
  GameObject(const GameObject& gameObject);
  ///Add a component to this game object.
  void addComponent(rune::Component&);
  ///Get the number of components present on this game object.
  int getNumComponents(void);
  //Create a new dynamically allocated version of this game object.
  void instantiate(GameObject&);
  ///Return a pointer to a component based off of index. Used for iterating through all components.
  std::vector<Component*>& getComponentList();
  ///Locate components of the object based on data type
  ///Call the function like this: getComponent<rune::Sprite>();
  /// @warning Do not call this in a rune::GameObject constructor. Call it in either start() or update()
  template<class classVariable>
  classVariable* getComponent()
  {

    for(int i = 0; i < objectComponents.size(); i++)
    {

      if (typeid(*objectComponents[i]) == typeid(classVariable))
      {

        return dynamic_cast<classVariable*>(objectComponents[i]);

      }

    }

    return nullptr;

  }

};
}

#endif

/**
 * 
 * @page gameObjects Game Objects
 * 
 * @section objects Creating an Object
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
 * After you have created your new rune::GameObject, go ahead and create a .cpp file (or just do this all in the header file) so that we can set up all these components we've just declared. For any of the components that have constructors you want to use, go ahead
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
 *
 * @section Scripts Scripting
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
