#ifndef RENDERLAYER_H_DEFINED
#define RENDERLAYER_H_DEFINED

#include <SFML/Graphics.hpp>
#include "gameObject.h"
#include "gameUI.h"
#include "messageManager.h"
#include "layer.h"
#include "particleEmitter.h"

class RenderLayer : public sf::Drawable
{
private:
  bool hasPhysics;

  std::vector<GameObject*> objects;
  std::vector<ParticleEmitter*> particles;

  float layerOpacity;

  float layerLighting;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
  RenderLayer(bool hasPhysics, float opacity = 1.0);

  void addToLayer(GameObject* object);
  void addToLayer(ParticleEmitter* object);

  int getTotalSize(void);
  std::vector<GameObject*> getObjects(void);
  void setOpacity(float opacity);

};

#endif