#pragma once

/**
 * @class rune::Mouse
 *
 * @brief Interface for getting input from the mouse
 *
 * @author Thomas Montano
 * @date May 21 2020
 */

#ifndef MOUSE_H_DEFINED
#define MOUSE_H_DEFINED

#include <core.h>
#include <Math\vec2.h>

namespace rune{

class RUNE_ENGINE Mouse
{
public:
  enum Button {
    ///The left mouse button.
    Left = 0,
    ///The right mouse button.
    Right = 1, 
    ///The middle mouse button.
    Middle = 2, 
    ///The first extra button on the mouse.
    XButton1 = 3,
    ///The second extra button on the mouse.
    XButton2 = 4
  };
  ///Determines whether or not the button is being pressed at the time of function call.
  ///@param button The button to be looked at.
  ///@return Whether or not the button is being pressed.
  static bool isButtonPressed(rune::Mouse::Button button);
  ///Returns the position of the mouse in screen coordinates. Bottom left of screen is (0,0).
  ///@return The location of the mouse cursor in screen coordinates.
  static rune::Vec2 getPosition(void);

};
}

#endif