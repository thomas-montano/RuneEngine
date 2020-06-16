#pragma once

/**
 * @class rune::AnimationController
 * @brief This class is used to animate a rune::GameObject.
 *
 * @author Thomas Montano
 * @date June 12 2020
 */

#ifndef ANIMATION_CONTROLLER_H_DEFINED
#define ANIMATION_CONTROLLER_H_DEFINED

#include "core.h"
#include "gameObject.h"
#include "component.h"
#include "objectAnimation.h"
#include <Renderer\sprite.h>
#include <unordered_map>

namespace rune{

class RUNE_ENGINE AnimationController : public Component
{

private:

  std::unordered_map<std::string, rune::ObjectAnimation> m_animations;
  rune::Sprite* spriteParent;

public:
  void start() override;
  void update() override;

  ///Play an animation stored in the controller.
  void playAnimation(std::string animationName);
  ///Add an animation to the controller.
  void addAnimation(std::string animationName, int frameWidth, int numFrames, int frameRate, std::string fileName);


};

}

#endif