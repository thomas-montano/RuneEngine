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
  double red;
  ///The Green component.
  double green;
  ///The Blue component.
  double blue;
  ///The Opacity Component.
  double alpha;

  Color(double, double, double, double alpha = 1);
  Color();

  static Color Blue;

};
}

#endif