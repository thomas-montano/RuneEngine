/**
 * @class rune::GameUI
 * @brief Class responsible for managing the user interface
 * elements and baking text into other textures.
 * 
 * @author Thomas Montano
 * @date April 13 2020
*/

#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include "core.h"
#include <Math\vec2.h>
#include <Events\event.h>
#include <Renderer\sprite.h>
#include <Renderer\texture.h>

namespace rune{

class RUNE_ENGINE GameUI// :public Drawable
{
private:
  Sprite m_uiObject;
  Texture m_objectTexture;
  bool m_clickedUp = false;
  bool m_clickedDown = false;
  float m_posX;
  float m_posY;
  float m_height;
  float m_width;
public:
  ///Creates a UI level button.
  void createButton(float posX, float posY,float width, float height);

  ///Determines whether or not the UI element has been clicked on.
  bool isClicked(rune::Vec2, rune::Event mouseEvent);
};
}
#endif
