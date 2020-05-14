/**
 * @class Vec2
 * @brief 2 x 1 vector to be used for math.
 * 
 * @author Thomas Montano
 * @date April 20 2020
*/

#ifndef VEC2_H_DEFINED
#define VEC2_H_DEFINED

#include "core.h"
#include <iostream>

class RUNE_ENGINE Vec2
{
public:
  float x;
  float y;

  Vec2();
  Vec2(float newX, float newY);

  Vec2& operator -(const Vec2& right);
  Vec2& operator +(const Vec2& right);

  Vec2& operator *(const Vec2& right);
  Vec2& operator /(const Vec2& right);

  friend RUNE_ENGINE std::ostream& operator<<(std::ostream& os, const Vec2& vector);

};

#endif