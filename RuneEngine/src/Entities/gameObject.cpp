#include "gameObject.h"
#include <gameApplication.h>
#include <SceneManager/gameScene.h>

rune::GameObject::GameObject(const GameObject& gameObject)
  : transform(gameObject.transform)
{

  objectComponents.resize(gameObject.objectComponents.size());

  for(int i = 0; i < gameObject.objectComponents.size();i++)
  {
    if(objectComponents[i] == nullptr)
    {
      objectComponents[i] = new rune::Component(*gameObject.objectComponents[i]);
      //rune::RectangleShape test = dynamic_cast<rune::RectangleShape>(*gameObject.objectComponents[2]);
      //objectComponents[i] = dynamic_cast<> gameObject.objectComponents[i];
      objectComponents[i]->setParent(this);
    }
    else
    {
      *objectComponents[i] = *gameObject.objectComponents[i];
      objectComponents[i]->setParent(this);
    }
  }

  std::cout << "A GameObject is being copied!" << std::endl;

}

rune::GameObject::GameObject()
{
  addComponent(transform);
}

/**
 * \param newScript The new component to be added to the game object.
 */
void rune::GameObject::addComponent(rune::Component& newScript)
{
  newScript.setParent(this);
  objectComponents.push_back(&newScript);
  newScript.awake();

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
void rune::GameObject::instantiate(rune::GameObject& newObject)
{

  rune::GameScene* currentScene = getGameInstance()->getCurrentScene();

  GameObject* newObjectPtr = new GameObject();
  *newObjectPtr = newObject;

  /*std::vector<Component*>

  for (int i = 0; i < )
  {
    currentComponent->start();
  }*/
  
}

/**
 * \param index The position in the components vector to be accessed.
 * \return A pointer to the component requested.
 */
std::vector<rune::Component*>& rune::GameObject::getComponentList()
{
  return objectComponents;
}


