#include "layer.h"

RenderLayer::RenderLayer(bool physics, float opacity)
{
  hasPhysics = physics;
  layerOpacity = opacity;
}

void RenderLayer::addToLayer(GameObject* object)
{

  objects.push_back(object);

}

void RenderLayer::addToLayer(ParticleEmitter* object)
{

  particles.push_back(object);

}

std::vector<GameObject*> RenderLayer::getObjects(void)
{

  return objects;

}

int RenderLayer::getTotalSize(void)
{

  return objects.size() + particles.size();

}

void RenderLayer::setOpacity(float opacity)
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

void RenderLayer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

  for(int i = 0; i < objects.size(); i++)
  {
    objects[i]->getSprite()->setColor(sf::Color(255,255,255,255*layerOpacity));
    target.draw(*objects[i],sf::BlendAdd);
  }

  for(int i = 0; i < particles.size(); i++)
  {
    target.draw(*particles[i]);
  }
}