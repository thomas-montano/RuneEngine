#include "objectAnimation.h"

void ObjectAnimation::setFrameRate(int frameRate)
{

    m_frameRate = frameRate;

}

int ObjectAnimation::getFrameRate(void)
{

    return m_frameRate;

}

void ObjectAnimation::setFrameWidth(int frameWidth)
{

    m_frameWidth = frameWidth;

}

int ObjectAnimation::getFrameWidth(void)
{

    return m_frameWidth;

}

void ObjectAnimation::setFrameHeight(int frameHeight)
{

    m_frameHeight = frameHeight;

}

int ObjectAnimation::getFrameHeight(void)
{

    return m_frameHeight;

}

void ObjectAnimation::setNumFrames(int numFrames)
{

    m_numFrames = numFrames;

}

int ObjectAnimation::getNumFrames(void)
{

    return m_numFrames;

}

void ObjectAnimation::setSheet(sf::Texture& animationSheet)
{

    m_animationSheet = &animationSheet;

}

sf::Texture* ObjectAnimation::getSheet(void)
{
    return m_animationSheet;
}

int ObjectAnimation::getCurrentFrame()
{
    return m_currentFrame;
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

void ObjectAnimation::setFile(std::string fileName)
{
    m_filePath = fileName;
}

std::string ObjectAnimation::getFile(void)
{
    return m_filePath;
}