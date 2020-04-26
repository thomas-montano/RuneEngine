#include "messageManager.h"

sf::RenderWindow* MessageManager::m_messagerWindow = 0;
float MessageManager::deltaTime = 0;


void MessageManager::setWindow(sf::RenderWindow* window)
{
    MessageManager::m_messagerWindow = window;
}

sf::RenderWindow* MessageManager::getWindow(void)
{
    return MessageManager::m_messagerWindow;
}

float MessageManager::getDeltaTime()
{
    return MessageManager::deltaTime;
}

void MessageManager::setDeltaTime(float dT)
{
    MessageManager::deltaTime = dT/1000.0;
}