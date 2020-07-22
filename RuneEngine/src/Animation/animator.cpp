#include "animator.h"


rune::Animator::Animator()
  : spriteParent(nullptr)
{}

void rune::Animator::start()
{

  spriteParent = parentObject->findComponent<rune::Sprite>();

}

/**
 * \param animationName The name of the animation to play.
 */
void rune::Animator::playAnimation(std::string animationName)
{

  ObjectAnimation* currentAnimation =  m_animations[animationName];
  IntRect textureDimensions = spriteParent->getTextureRect();

  spriteParent->setTexture(currentAnimation->getSheet());

  if (m_animations.find(animationName) != m_animations.end())
  {

    if(!m_animations[animationName]->isMirrored())
    {
      spriteParent->setTextureRect((currentAnimation->getCurrentFrame() * currentAnimation->getFrameWidth()), 0, currentAnimation->getFrameWidth(), textureDimensions.height);
    }
    else
    {
      spriteParent->setTextureRect(((currentAnimation->getCurrentFrame()+1) * currentAnimation->getFrameWidth()), 0, -currentAnimation->getFrameWidth(), textureDimensions.height);
    }

    m_animations[animationName]->incCurrentFrame();
  }

}

/**
 * \param animationName The name of the animation to be referred to later when playing.
 * \param frameWidth The width of each frame of animation.
 * \param numFrames The total number of frames in the sprite sheet.
 * \param frameRate The rate that the frames should be displayed (in frames per second)
 * \param fileName The name of the file containing the sprite sheet.
 */
void rune::Animator::addAnimation(std::string animationName, int frameWidth, int numFrames, int frameRate, std::string fileName)
{

  ObjectAnimation* newAnimation = new ObjectAnimation();

  newAnimation->setCurrentFame(0);
  newAnimation->setFrameWidth(frameWidth);
  newAnimation->setNumFrames(numFrames);
  newAnimation->setFrameRate(frameRate);

  newAnimation->setSheet(fileName,spriteParent->getDrawMode());

  newAnimation->setFrameHeight(newAnimation->getSheet()->getHeight());

  m_animations[animationName] = newAnimation;

}

/// @param name The name of the animation to be returned.
/// @return A pointer to the animation that was requested.
rune::ObjectAnimation* rune::Animator::getAnimation(std::string name)
{
  if (m_animations.find(name) != m_animations.end())
  {
  
    return m_animations[name];
  
  }
  
  return nullptr;
}

