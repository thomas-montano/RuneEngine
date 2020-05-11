#pragma once

#ifndef COLOR_H_DEFINED
#define COLOR_H_DEFINED

#include "core.h"

class RUNE_ENGINE Color
{
public:
  double red;
  double green;
  double blue;
  double alpha;

  Color(double, double, double, double alpha = 1);
  Color();

  static Color Blue;

};

#endif