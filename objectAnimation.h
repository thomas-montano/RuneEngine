#ifndef OBJECT_ANIMATION_HEADER_DEFINED
#define OBJECT_ANIMATION_HEADER_DEFINED

#include <SFML/Graphics.hpp>
#include <string.h>

class ObjectAnimation
{
private:
    int m_frameHeight;
    int m_frameWidth;
    int m_numFrames;
    int m_frameRate;
    int m_currentFrame;

    bool m_mirror;

    sf::Clock m_animationClock;

    std::string m_filePath;
    sf::Texture* m_animationSheet;

public:
    void setFrameRate(int frameRate);
    int getFrameRate(void);

    void setFrameWidth(int frameWidth);
    int getFrameWidth(void);

    void setFrameHeight(int frameHeight);
    int getFrameHeight(void);

    void setNumFrames(int numFrames);
    int getNumFrames(void);

    void setSheet(sf::Texture& animationSheet);
    sf::Texture* getSheet(void);

    int getCurrentFrame(void);
    void incCurrentFrame(void);

    void setFile(std::string);
    std::string getFile(void);

};

#endif