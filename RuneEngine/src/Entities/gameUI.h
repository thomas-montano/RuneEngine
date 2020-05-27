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
#include <Renderer\renderWindow.h>

namespace rune{

class RUNE_ENGINE GameUI : public Drawable
{
private:
  Sprite m_uiObject;
  Texture m_objectTexture;
  bool m_clickedUp = false;
  bool m_clickedDown = false;
  double m_posX;
  double m_posY;
  double m_height;
  double m_width;
public:
  GameUI();
  ///Creates a UI level button.
  void createButton(double posX, double posY,double width, double height);

  ///Determines whether or not the UI element has been clicked on.
  bool isClicked(rune::Vec2, rune::Event mouseEvent);

  void draw(RenderWindow&);
};
}
#endif
