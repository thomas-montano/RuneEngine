#include "vec2.h"

Vec2::Vec2()
{

}

Vec2::Vec2(float newX, float newY)
{
  x = newX;
  y = newY;
}

Vec2& Vec2::operator -(const Vec2& right)
{

}

Vec2& Vec2::operator +(const Vec2& right)
{

  this->x += right.x;
  this->y += right.y;

}

Vec2* Vec2::operator *(const Vec2& right)
{

}

Vec2* Vec2::operator /(const Vec2& right)
{

}