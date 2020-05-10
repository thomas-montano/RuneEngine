#pragma once

#ifndef COLOR_H_DEFINED
#define COLOR_H_DEFINED

#include "core.h"

class RUNE_ENGINE Color
{
private:
  double red;
  double green;
  double blue;
  double alpha;

public:
  Color(double, double, double, double alpha = 1);
  Color();

};

#endif