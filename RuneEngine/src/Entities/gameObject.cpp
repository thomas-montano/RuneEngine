#include "gameObject.h"

rune::GameObject::GameObject()
{



}

rune::GameObject::~GameObject()
{

}

void rune::GameObject::addComponent(rune::Component& newScript)
{
  objectComponents.push_back(&newScript);
  
}

int rune::GameObject::getNumComponents(void)
{
  return objectComponents.size();
}

void rune::GameObject::instantiate(rune::GameObject newObject)
{


}

rune::Component* rune::GameObject::getComponent(int index)
{

  return objectComponents[index];

}
