#ifndef MESSAGE_MANAGER_DEFINED
#define MESSAGE_MANAGER_DEFINED

#include "gameObject.h"
#include <SFML/Graphics.hpp>

class MessageManager
{
private:
    static std::vector<GameObject*> m_messagerMidGround;
    static sf::RenderWindow* m_messagerWindow;
    static float deltaTime;
public:
    static void setMidGroundObjects(std::vector<GameObject*> midGroundObjects);
    static std::vector<GameObject*> getMidGroundObjects(void);

    static void setWindow(sf::RenderWindow* window);
    static sf::RenderWindow* getWindow(void);

    static float getDeltaTime(void);
    static void setDeltaTime(float dT);
};

#endif