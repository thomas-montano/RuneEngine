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
 * @warning Do not call this in an rune::GameObject constructor. The spriteParent pointer must be resolved first.
 */
void rune::Animator::playAnimation(std::string const& animationName)
{

  ObjectAnimation* currentAnimation =  m_animations[animationName];
  IntRect textureDimensions = spriteParent->getTextureRect();

  spriteParent->setTexture(currentAnimation->getSheet());

  if (m_animations.find(animationName) != m_animations.end())
  {

    if(!spriteParent->getMirror())
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
 * \param startFrame The frame that the animation should start on.
 * \param numFrames The total number of frames in the sprite sheet.
 * \param frameRate The rate that the frames should be displayed (in frames per second)
 * \param fileName The name of the file containing the sprite sheet.
 * @warning Do not call this in an rune::GameObject constructor. The spriteParent pointer must be resolved first.
 */
void rune::Animator::addAnimation(std::string const& animationName, int frameWidth, int startFrame, int numFrames, int frameRate, std::string const& fileName)
{

  ObjectAnimation* newAnimation = new ObjectAnimation(frameWidth, startFrame, numFrames, frameRate);

  newAnimation->setSheet(fileName,spriteParent->getDrawMode());

  newAnimation->setFrameHeight(newAnimation->getSheet()->getHeight());

  m_animations[animationName] = newAnimation;

}

/**
 * \param animationName The name of the animation to be referred to later when playing.
 * \param frameWidth The width of each frame of animation.
 * \param numFrames The total number of frames in the sprite sheet.
 * \param frameRate The rate that the frames should be displayed (in frames per second)
 * \param fileName The name of the file containing the sprite sheet.
 * @warning Do not call this in an rune::GameObject constructor. The spriteParent pointer must be resolved first.
 */
void rune::Animator::addAnimation(std::string const& animationName, int frameWidth, int numFrames, int frameRate, std::string const& fileName)
{
  addAnimation(animationName, frameWidth, 0, numFrames,frameRate, fileName);
}

/// @param name The name of the animation to be returned.
/// @return A pointer to the animation that was requested.
rune::ObjectAnimation* rune::Animator::getAnimation(std::string const& name)
{
  if (m_animations.find(name) != m_animations.end())
  {
  
    return m_animations[name];
  
  }
  
  return nullptr;
}

