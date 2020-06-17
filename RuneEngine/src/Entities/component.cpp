#include "component.h"

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
}
