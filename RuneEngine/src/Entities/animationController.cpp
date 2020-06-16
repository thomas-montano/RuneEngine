#include "animationController.h"


void rune::AnimationController::start()
{

  spriteParent = parentObject->findComponent<rune::Sprite>();

}

void rune::AnimationController::update()
{

}

/**
 * \param animationName The name of the animation to play.
 */
void rune::AnimationController::playAnimation(std::string animationName)
{

  if (m_animations.find(animationName) != m_animations.end())
  {

    if(m_animations[animationName].isMirrored())
    {
      //m_objectSprite.setTextureRect(IntRect((currentAnimation->getCurrentFrame() * currentAnimation->getFrameWidth()),0,currentAnimation->getFrameWidth(), m_objectRigidBody.getBoundingBox().max.y-m_objectRigidBody.getBoundingBox().min.y));
    }
    else
    {
      //m_objectSprite.setTextureRect(IntRect(((currentAnimation->getCurrentFrame()+1) * currentAnimation->getFrameWidth()),0,-currentAnimation->getFrameWidth(), m_objectRigidBody.getBoundingBox().max.y-m_objectRigidBody.getBoundingBox().min.y));
    }

    m_animations[animationName].incCurrentFrame();
  }

}

/**
 * \param animationName The name of the animation to be referred to later when playing.
 * \param frameWidth The width of each frame of animation.
 * \param numFrames The total number of frames in the sprite sheet.
 * \param frameRate The rate that the frames should be displayed (in frames per second)
 * \param fileName The name of the file containing the sprite sheet.
 */
void rune::AnimationController::addAnimation(std::string animationName, int frameWidth, int numFrames, int frameRate, std::string fileName)
{

  //ObjectAnimation* newAnimation = new ObjectAnimation;
  //Texture* spriteSheet = new Texture;

  ObjectAnimation* newAnimation = new ObjectAnimation();

  newAnimation->setCurrentFame(0);
  newAnimation->setFrameWidth(frameWidth);
  newAnimation->setNumFrames(numFrames);
  newAnimation->setFrameRate(frameRate);

  newAnimation->setSheet(fileName);

  newAnimation->setFrameHeight(newAnimation->getSheet()->getHeight());

  m_animations[animationName] = *newAnimation;

  delete newAnimation;

}

