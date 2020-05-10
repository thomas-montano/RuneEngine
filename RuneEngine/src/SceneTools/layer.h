/**
 * @class SceneLayer
 * @brief Main component of scenes. Can have objects, particles, light sources, or any other in game entity
 * added to a level through a layer.
 * 
 * Each object in a layer contains a pointer to the layer object.
 * 
 * Layers control lighting, opacity, translation, and collisions.
 * 
 * @author Thomas Montano
 * @date April 20 2020
*/

#ifndef SCENELAYER_H_DEFINED
#define SCENELAYER_H_DEFINED

#include "core.h"
#include <Entities\gameobject.h>
#include <Entities\gameUI.h>
#include "messageManager.h"
#include <Entities\particleEmitter.h>
#include <Physics\rigidBody.h>

class RUNE_ENGINE SceneLayer //: public Drawable
{
private:
  bool hasPhysics;

  std::vector<GameObject*> objects;
  std::vector<ParticleEmitter*> particles;
  std::vector<RigidBody*> objectRigidBodies;

  SceneLayer* selfPointer;

  float layerOpacity;
  float layerBrightness;

  Color globalLightColor;
  float layerLighting;

  //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
  ///Default constructor for setting up layer parameters.
  SceneLayer(bool hasPhysics, float brightness = 1.0, float opacity = 1.0);

  ///Adds a GameObject to the layer.
  void addToLayer(GameObject* object);

  ///Adds a particle emitter to the layer.
  void addToLayer(ParticleEmitter* object);

  ///Sets the SceneLayer pointer contained in the scene to be the location of the layer stored by the scene.
  void setScenePointer(SceneLayer* newSelfPointer);

  ///Gets the total number of objects currently stored in the scene
  int getTotalSize(void);

  ///Returns an array of pointers to the GameObjects stored in the scene.
  std::vector<GameObject*> getObjects(void);

  ///Returns an array of pointers to the rigid body elements currently stored in the scene.
  std::vector<RigidBody*> getRigidBodies(void);

  ///Sets the global opacity of the layer.
  void setOpacity(float opacity);

};

#endif