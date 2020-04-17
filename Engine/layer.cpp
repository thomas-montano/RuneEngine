#include "layer.h"

RenderLayer::RenderLayer(bool physics)
{
  hasPhysics = physics;
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