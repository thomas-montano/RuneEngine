#include "objectAnimation.h"

rune::ObjectAnimation::ObjectAnimation() : m_numFrames(0), m_mirror(false), m_frameHeight(0), m_frameWidth(0), m_frameRate(0), m_currentFrame(0)
{

}

/**
 * @param frameRate The framerate of the new ObjectAnimation.
*/
void rune::ObjectAnimation::setFrameRate(int frameRate)
{

    m_frameRate = frameRate;

}

/**
 * @return The framerate of the ObjectAnimation.
*/
int rune::ObjectAnimation::getFrameRate(void)
{

    return m_frameRate;

}

/// @return Whether or not the sprite is currently being mirrored.
bool rune::ObjectAnimation::isMirrored(void)
{
  return m_mirror;
}

/**
 * @param frameWidth The width in pixels of each frame from the sprite sheet.
*/
void rune::ObjectAnimation::setFrameWidth(int frameWidth)
{

    m_frameWidth = frameWidth;

}

/**
 * @return The width in pixels of each frame from the sprite sheet.
*/
int rune::ObjectAnimation::getFrameWidth(void)
{

    return m_frameWidth;

}

/**
 * @param frameHeight The height in pixels of each frame from the sprite sheet.
*/
void rune::ObjectAnimation::setFrameHeight(int frameHeight)
{

    m_frameHeight = frameHeight;

}

/**
 * @return The height in pixels of each frame from the sprite sheet.
*/
int rune::ObjectAnimation::getFrameHeight(void)
{

    return m_frameHeight;

}

/**
 * @param numFrames The total number of frames that are present in the sprite sheet.
*/
void rune::ObjectAnimation::setNumFrames(int numFrames)
{

    m_numFrames = numFrames;

}

/**
 * @return The total number of frames that are present in the sprite sheet.
*/
int rune::ObjectAnimation::getNumFrames(void)
{
  return m_numFrames;
}

/**
 * @param animationSheet The texture to be used as the sprite sheet.
*/
void rune::ObjectAnimation::setSheet(std::string const& filePath, unsigned int drawMode)
{
  m_animationSheet.loadFromFile(filePath, drawMode);
}

/**
 * @return A pointer referencing the texture to be used as the sprite sheet.
*/
rune::Texture* rune::ObjectAnimation::getSheet(void)
{
  return &m_animationSheet;
}

/**
 * @return Which frame the animation is currently on.
*/
int rune::ObjectAnimation::getCurrentFrame()
{
    return m_currentFrame;
}

/**
 * @param frame The frame that the current animation should be set to.
*/
void rune::ObjectAnimation::setCurrentFame(int frame)
{
    m_currentFrame = frame;
}

void rune::ObjectAnimation::incCurrentFrame()
{   

    int currentTime = m_animationClock.getElapsedTimeAsMilliseconds();

    if(currentTime >= (1000/m_frameRate))
    {
        m_animationClock.reset();
        m_currentFrame++;
        m_currentFrame = (m_currentFrame) % (m_numFrames);
    }

}

/// @param mirrored A boolean representing whether or not the sprite should be mirrored.
void rune::ObjectAnimation::setMirror(bool mirrored)
{
  m_mirror = mirrored;
}

float rune::ObjectAnimation::getAnimationDuration(void)
{
  return (m_numFrames)*(1.0 / m_frameRate);
}
