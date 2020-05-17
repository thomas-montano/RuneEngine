#include "layer.h"

/**
 * @param physics Whether or not the layer should have collisions.
 * @param brightness The ambient lighting level for the scene (0.0-1.0).
 * @param opacity The opacity level for the layer (0.0-1.0).
*/
rune::SceneLayer::SceneLayer(bool physics, double brightness, double opacity)
{
  hasPhysics = physics;
  layerOpacity = opacity;
  layerBrightness = brightness;

  globalLightColor = rune::Color(255,255,255);

}

/**
 * @param object GameObject to add to the scene on this layer.
*/
void rune::SceneLayer::addToLayer(rune::GameObject* object)
{

  objects.push_back(object);
  objectRigidBodies.push_back(object->getRigidBody());

}

/**
 * @param object ParticleEmitter to add to the scene on this layer.
*/
void rune::SceneLayer::addToLayer(rune::ParticleEmitter* object)
{

  particles.push_back(object);

}


/**
 * @return An array of pointers to the objects on this layer.
*/
std::vector<rune::GameObject*> rune::SceneLayer::getObjects(void)
{
  return objects;
}

/**
 * @return The number of objects on the current layer.
*/
int rune::SceneLayer::getTotalSize(void)
{

  return objects.size() + particles.size();

}

/**
 * @param opacity Global opacity level for the layer (0.0-1.0).
*/
void rune::SceneLayer::setOpacity(double opacity)
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
void rune::SceneLayer::draw(rune::RenderWindow& window)
{
  
   

  for(int i = 0; i < objects.size(); i++)
  {
    //objects[i]->getSprite()->setColor(sf::Color(globalLightColor.r*layerBrightness,globalLightColor.g*layerBrightness,globalLightColor.b*layerBrightness,255*layerOpacity));
    window.draw(*objects[i]);
  }

  /*for(int i = 0; i < particles.size(); i++)
  {
    target.draw(*particles[i]);
  }*/
}

/**
 * @param newSelfPointer Pointer that is passed to GameObject in the scene to use as a reference back to the current SceneLayer.
*/
void rune::SceneLayer::setScenePointer(rune::SceneLayer* newSelfPointer)
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
std::vector<physics::RigidBody*> rune::SceneLayer::getRigidBodies()
{
  return objectRigidBodies;
}