#include "layer.h"

/**
 * @param physics Whether or not the layer should have collisions.
 * @param brightness The ambient lighting level for the scene (0.0-1.0).
 * @param opacity The opacity level for the layer (0.0-1.0).
*/
SceneLayer::SceneLayer(bool physics, float brightness, float opacity)
{
  hasPhysics = physics;
  layerOpacity = opacity;
  layerBrightness = brightness;

  globalLightColor = Color(255,255,255);

}

/**
 * @param object GameObject to add to the scene on this layer.
*/
void SceneLayer::addToLayer(GameObject* object)
{

  objects.push_back(object);
  objectRigidBodies.push_back(object->getRigidBody());

}

/**
 * @param object ParticleEmitter to add to the scene on this layer.
*/
void SceneLayer::addToLayer(ParticleEmitter* object)
{

  particles.push_back(object);

}


/**
 * @return An array of pointers to the objects on this layer.
*/
std::vector<GameObject*> SceneLayer::getObjects(void)
{
  return objects;
}

/**
 * @return The number of objects on the current layer.
*/
int SceneLayer::getTotalSize(void)
{

  return objects.size() + particles.size();

}

/**
 * @param opacity Global opacity level for the layer (0.0-1.0).
*/
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

/**
 * @param target RenderTarget to draw to.
 * @param states States variable to affect the rendering
*/
/*void SceneLayer::draw(sf::RenderTarget& target, sf::RenderStates states) const
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
}*/

/**
 * @param newSelfPointer Pointer that is passed to GameObject in the scene to use as a reference back to the current SceneLayer.
*/
void SceneLayer::setScenePointer(SceneLayer* newSelfPointer)
{
  selfPointer = newSelfPointer;

  for(int i = 0; i < objects.size(); i ++)
  {
    objects[i]->setLayer(selfPointer);
  }

}

/**
 * @return All the rigid bodies currently in the GameScene.
*/
std::vector<RigidBody*> SceneLayer::getRigidBodies()
{
  return objectRigidBodies;
}