#ifndef SCENELAYER_H_DEFINED
#define SCENELAYER_H_DEFINED

#include <SFML/Graphics.hpp>
#include "gameObject.h"
#include "gameUI.h"
#include "messageManager.h"
#include "layer.h"
#include "particleEmitter.h"
#include "rigidBody.h"

class SceneLayer: public sf::Drawable
{
private:
  bool hasPhysics;

  std::vector<GameObject*> objects;
  std::vector<ParticleEmitter*> particles;
  std::vector<RigidBody*> objectRigidBodies;

  SceneLayer* selfPointer;

  float layerOpacity;
  float layerBrightness;

  sf::Color globalLightColor;
  float layerLighting;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
  SceneLayer(bool hasPhysics, float brightness = 1.0, float opacity = 1.0);

  void addToLayer(GameObject* object);
  void addToLayer(ParticleEmitter* object);

  void setScenePointer(SceneLayer* newSelfPointer);

  int getTotalSize(void);

  std::vector<GameObject*> getObjects(void);
  std::vector<RigidBody*> getRigidBodies(void);

  void setOpacity(float opacity);

};

#endif