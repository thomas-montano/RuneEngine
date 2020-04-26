#include "layer.h"
#include <iostream>

SceneLayer::SceneLayer(bool physics, float brightness, float opacity)
{
  hasPhysics = physics;
  layerOpacity = opacity;
  layerBrightness = brightness;

  globalLightColor = sf::Color(255,255,255);

}

void SceneLayer::addToLayer(GameObject* object)
{

  objects.push_back(object);
  objectRigidBodies.push_back(object->getRigidBody());

}

void SceneLayer::addToLayer(ParticleEmitter* object)
{

  particles.push_back(object);

}

std::vector<GameObject*> SceneLayer::getObjects(void)
{
  return objects;
}

int SceneLayer::getTotalSize(void)
{

  return objects.size() + particles.size();

}

void SceneLayer::setOpacity(float opacity)
{

  if(opacity > 1.0)
  {
    layerOpacity = 1.0;
  }
  else
  {
    layerOpacity = opacity;
  }

}

void SceneLayer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

  for(int i = 0; i < objects.size(); i++)
  {
    objects[i]->getSprite()->setColor(sf::Color(globalLightColor.r*layerBrightness,globalLightColor.g*layerBrightness,globalLightColor.b*layerBrightness,255*layerOpacity));
    target.draw(*objects[i],states);
    target.draw(*objects[i]->getRigidBody(),states);
  }

  for(int i = 0; i < particles.size(); i++)
  {
    target.draw(*particles[i]);
  }
}

void SceneLayer::setScenePointer(SceneLayer* newSelfPointer)
{
  selfPointer = newSelfPointer;

  for(int i = 0; i < objects.size(); i ++)
  {
    objects[i]->setLayer(selfPointer);
  }

}

std::vector<RigidBody*> SceneLayer::getRigidBodies()
{
  return objectRigidBodies;
}