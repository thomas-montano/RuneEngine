#include "messageManager.h"

RenderWindow* MessageManager::m_messagerWindow = 0;
float MessageManager::deltaTime = 0;

/**
 * @param window The RenderWindow reference to be stored.
*/
void MessageManager::setWindow(RenderWindow* window)
{
    MessageManager::m_messagerWindow = window;
}

/**
 * @return a reference to the currently store RenderWindow.
*/
RenderWindow* MessageManager::getWindow(void)
{
    return MessageManager::m_messagerWindow;
}

/**
 * @return The time between update frames in seconds.
*/
float MessageManager::getDeltaTime()
{
    return MessageManager::deltaTime;
}

/**
 * @param dT The time between update frames in seconds to be stored.
*/
void MessageManager::setDeltaTime(float dT)
{
    MessageManager::deltaTime = dT/1000.0;
}