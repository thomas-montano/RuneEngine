/**
 * @class rune::Color
 * @brief A color object to be applied to drawable objects.
 *
 * @author Thomas Montano
 * @date May 13 2020
 */

#pragma once

#ifndef COLOR_H_DEFINED
#define COLOR_H_DEFINED

#include "core.h"

namespace rune{

class RUNE_ENGINE Color
{
public:
  ///The Red component.
  unsigned char red;
  ///The Green component.
  unsigned char green;
  ///The Blue component.
  unsigned char blue;
  ///The Opacity Component.
  unsigned char alpha;

  ///Default constructor that sets the default color to be white.
  Color(double red = 255, double green = 255, double blue = 255, double alpha = 255);

  ///Red predefined color.
  static Color Red;
  ///Green predefined color.
  static Color Green;
  ///Blue predefined color.
  static Color Blue;
  ///Black predefined color.
  static Color Black;
  ///White predefined color.
  static Color White;
  ///Yellow predefined color.
  static Color Yellow;
  ///Magenta predefined color.
  static Color Magenta;
  ///Cyan predefined color.
  static Color Cyan;
  ///Transparent predefined color.
  static Color Transparent;

};
}

#endif