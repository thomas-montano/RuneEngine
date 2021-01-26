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
  ///Default empty constructor for a Rect.
  Rect()
    : left(0), top(0), width(0), height(0)
  {
  }

  /// Default constructor for a new Rect.
  /// @param rectLeft Left most position of the rectangle.
  /// @param rectTop Top most position of the rectangle.
  /// @param rectWidth Width of the rectangle.
  /// @param rectHeight Height of the rectangle.
  Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight)
    : left(rectLeft), top(rectTop), width(rectWidth), height(rectHeight)
  {
  }

  //Member data
  ///Left most position of the rectangle.
  T left;
  ///Top most position of the rectangle.
  T top;
  ///Width of the rectangle.
  T width;
  ///Height of the rectangle.
  T height;

};

rune::Rect<float>::Rect(float,float,float,float);
rune::Rect<int>::Rect(int, int, int, int);
rune::Rect<double>::Rect(double, double, double, double);

///A Rect that uses integers.
using IntRect = Rect<int>;
///A Rect that uses floats.
using FloatRect = Rect<float>;
///A Rect that uses doubles.
using DoubleRect = Rect<double>;

}//namespace rune