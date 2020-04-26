/**
 * @brief Class responsible for managing the user interface
 * elements and baking text into other textures.
 * 
 * @author Thomas Montano
 * @date April 13 2020
*/

/*

  GameUI

  Class responsible for managing the user interface
  elements and baking text into other textures

  Thomas Montano
  4/13/20

*/

#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "messageManager.h"

class GameUI
{
private:
  sf::Sprite m_uiObject;
  sf::Texture m_objectTexture;
  bool m_clickedUp = false;
  bool m_clickedDown = false;
  float m_posX;
  float m_posY;
  float m_height;
  float m_width;
public:
  ///Creates a UI level button.
  void createButton(float posX, float posY,float width, float height);

  ///Returns a sprite to be drawn to the screen (DEPRECATED).
  sf::Sprite getDrawable();

  ///Determines whether or not the UI element has been clicked on.
  bool isClicked(sf::Vector2i, sf::Event mouseEvent);
};

#endif
