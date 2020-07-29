/**
 * @class rune::Rect
 * @brief A rectangle that can be used for specifying a dimension.
 *
 * @author Thomas Montano
 * @date July 22 2020
*/

#pragma once

#include <core.h>
#include <Math/vec2.h>

namespace rune{

template <typename T>
class RUNE_ENGINE Rect
{
public:
  Rect()
    : left(0), top(0), width(0), height(0)
  {
  }

  Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight)
    : left(rectLeft), top(rectTop), width(rectWidth), height(rectHeight)
  {
  }

  //Member data
  T left;
  T top;
  T width;
  T height;

};

template Rect<float>::Rect<float>(float,float,float,float);
template Rect<int>::Rect<int>(int, int, int, int);
template Rect<double>::Rect<double>(double, double, double, double);

using IntRect = Rect<int>;
using FloatRect = Rect<float>;
using DoubleRect = Rect<double>;

}//namespace rune