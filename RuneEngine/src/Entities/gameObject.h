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
#include <vector>
#include <Entities\component.h>
#include <Renderer\renderWindow.h>


namespace rune{

class RUNE_ENGINE GameObject
{
private:
  std::vector<rune::Component*> objectComponents;

public:
  rune::Transform transform;

  //GameObject();
  //~GameObject();
  void addComponent(rune::Component&);
  int getNumComponents(void);
  void instantiate(GameObject);
  rune::Component* getComponent(int index);

};
}

#endif
