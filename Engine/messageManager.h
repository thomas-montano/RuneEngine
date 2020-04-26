/**
 * @brief Container for passing of information globally
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef MESSAGE_MANAGER_DEFINED
#define MESSAGE_MANAGER_DEFINED

#include "gameObject.h"
#include <SFML/Graphics.hpp>

class MessageManager
{
private:
  static sf::RenderWindow* m_messagerWindow;
  static float deltaTime;
public:
  ///Sets the reference to the currently active render window.
  static void setWindow(sf::RenderWindow* window);

  ///Returns the reference to the currently active render window.
  static sf::RenderWindow* getWindow(void);

  ///Gets the change in time since the last frame in seconds.
  static float getDeltaTime(void);

  ///Sets the change in time since the last frame in seconds.
  static void setDeltaTime(float dT);
};

#endif