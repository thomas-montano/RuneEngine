#include "objectAnimation.h"

/**
 * @param frameRate The framerate of the new ObjectAnimation.
*/
void ObjectAnimation::setFrameRate(int frameRate)
{

    m_frameRate = frameRate;

}

/**
 * @return The framerate of the ObjectAnimation.
*/
int ObjectAnimation::getFrameRate(void)
{

    return m_frameRate;

}

/**
 * @param frameWidth The width in pixels of each frame from the sprite sheet.
*/
void ObjectAnimation::setFrameWidth(int frameWidth)
{

    m_frameWidth = frameWidth;

}

/**
 * @return The width in pixels of each frame from the sprite sheet.
*/
int ObjectAnimation::getFrameWidth(void)
{

    return m_frameWidth;

}

/**
 * @param frameHeight The height in pixels of each frame from the sprite sheet.
*/
void ObjectAnimation::setFrameHeight(int frameHeight)
{

    m_frameHeight = frameHeight;

}

/**
 * @return The height in pixels of each frame from the sprite sheet.
*/
int ObjectAnimation::getFrameHeight(void)
{

    return m_frameHeight;

}

/**
 * @param numFrames The total number of frames that are present in the sprite sheet.
*/
void ObjectAnimation::setNumFrames(int numFrames)
{

    m_numFrames = numFrames;

}

/**
 * @return The total number of frames that are present in the sprite sheet.
*/
int ObjectAnimation::getNumFrames(void)
{

    return m_numFrames;

}

/**
 * @param animationSheet The texture to be used as the sprite sheet.
*/
void ObjectAnimation::setSheet(sf::Texture& animationSheet)
{

    m_animationSheet = &animationSheet;

}

/**
 * @return A pointer referencing the texture to be used as the sprite sheet.
*/
sf::Texture* ObjectAnimation::getSheet(void)
{
    return m_animationSheet;
}

/**
 * @return Which frame the animation is currently on.
*/
int ObjectAnimation::getCurrentFrame()
{
    return m_currentFrame;
}

/**
 * @param frame The frame that the current animation should be set to.
*/
void ObjectAnimation::setCurrentFame(int frame)
{
    m_currentFrame = frame;
}

void ObjectAnimation::incCurrentFrame()
{   

    sf::Int32 currentTime = m_animationClock.getElapsedTime().asMilliseconds();

    if(currentTime >= (1000/m_frameRate))
    {
        m_animationClock.restart();
        m_currentFrame++;
        m_currentFrame = (m_currentFrame) % (m_numFrames);
    }

}

/**
 * @param fileName A string representing the file location of the sprite sheet.
*/
void ObjectAnimation::setFile(std::string fileName)
{
    m_filePath = fileName;
}

/**
 * @return A string representing the file location of the sprite sheet.
*/
std::string ObjectAnimation::getFile(void)
{
    return m_filePath;
}