#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
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
  void createButton(float posX, float posY,float width, float height);
  sf::Sprite getDrawable();
  bool isClicked(sf::Vector2i, sf::Event mouseEvent);
};

#endif
