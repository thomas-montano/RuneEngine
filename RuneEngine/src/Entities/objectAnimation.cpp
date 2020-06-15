#include "objectAnimation.h"

rune::ObjectAnimation::ObjectAnimation() : m_numFrames(0), m_mirror(false), m_frameHeight(0), m_frameWidth(0), m_frameRate(0), m_currentFrame(0), m_animationSheet(nullptr)
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
void rune::ObjectAnimation::setSheet(Texture& animationSheet)
{

    m_animationSheet = animationSheet;

}

/**
 * @return A pointer referencing the texture to be used as the sprite sheet.
*/
rune::Texture rune::ObjectAnimation::getSheet(void)
{
    return m_animationSheet;
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

/**
 * @param fileName A string representing the file location of the sprite sheet.
*/
void rune::ObjectAnimation::setFile(std::string fileName)
{
    m_filePath = fileName;
}

/**
 * @return A string representing the file location of the sprite sheet.
*/
std::string rune::ObjectAnimation::getFile(void)
{
    return m_filePath;
}