#include "component.h"
#include "gameObject.h"
#include <iostream>

void rune::Component::awake()
{

}

void rune::Component::start()
{

}

void rune::Component::update()
{

}

void rune::Component::fixedUpdate()
{

}

/**
 * \param newParent A pointer to the rune::GameObject that this component belongs to.
 */
void rune::Component::setParent(GameObject* newParent)
{
  parentObject = newParent;

  parentObject->subscribe(*this);
}

/**
 * \param newEnable This value will replace the current value of the isEnable variable;
 */
void rune::Component::setEnable(bool newEnable)
{
  isEnabled = newEnable;
}

bool rune::Component::isComponentEnabled(void)
{
  return isEnabled;
}
