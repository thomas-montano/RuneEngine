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
    Left = 0, Right = 1, Middle = 2, XButton1 = 3,
    XButton2 = 4
  };

  static bool isButtonPressed(rune::Mouse::Button button);
  static rune::Vec2 getPosition(void);

};
}

#endif