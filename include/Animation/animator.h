#pragma once

/**
 * @class rune::Animator
 * @brief This class is used to animate a rune::GameObject.
 *
 * @author Thomas Montano
 * @date July 22 2020
 */

#ifndef ANIMATION_CONTROLLER_H_DEFINED
#define ANIMATION_CONTROLLER_H_DEFINED

#include "core.h"
#include <Entities/gameObject.h>
#include <Entities/component.h>
#include "objectAnimation.h"
#include <Renderer\sprite.h>
#include <unordered_map>

namespace rune{

class RUNE_ENGINE Animator : public Component
{

private:

  std::unordered_map<std::string, rune::ObjectAnimation*> m_animations;
  rune::Sprite* spriteParent;

public:
  ///Default constructor to initialize an empty animation.
  Animator();
  ///Function override for component startup.
  void start() override;
  ///Play an animation stored in the controller.
  void playAnimation(std::string const& animationName);
  ///Add an animation to the controller.
  void addAnimation(std::string const& animationName, int frameWidth, int numFrames, int frameRate, std::string const&  fileName);
  ///Get a pointer to the specified animation.
  ObjectAnimation* getAnimation(std::string const& name);



};

}

#endif