#include "gameObject.h"
#include <iostream>

/*rune::GameObject::GameObject()
{

}

rune::GameObject::~GameObject()
{

}*/

/**
 * \param newScript The new component to be added to the game object.
 */
void rune::GameObject::addComponent(rune::Component& newScript)
{
  objectComponents.push_back(&newScript);
  newScript.setParent(this);
}

/**
 * \return The number of components currently attached to this game object.
 */
int rune::GameObject::getNumComponents(void)
{
  return objectComponents.size();
}

/**
 * \param newObject The object that should be instantiated and copied.
 */
void rune::GameObject::instantiate(rune::GameObject newObject)
{


}

/**
 * \param index The position in the components vector to be accessed.
 * \return A pointer to the component requested.
 */
rune::Component* rune::GameObject::getComponent(int index)
{
  if(index < objectComponents.size())
    return objectComponents[index];

  return nullptr;

}
