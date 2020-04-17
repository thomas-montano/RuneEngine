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

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
    for(int i = 0; i < objects.size(); i++)
    {
      target.draw(*objects[i]);
    }

    for(int i = 0; i < particles.size(); i++)
    {
      target.draw(*particles[i]);
    }
  }

public:
  RenderLayer(bool);
  void addToLayer(GameObject* object);
  void addToLayer(ParticleEmitter* object);
  int getTotalSize(void);
  std::vector<GameObject*> getObjects(void);

};

#endif