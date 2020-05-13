#include "vec2.h"

Vec2::Vec2()
{

}

Vec2::Vec2(float newX, float newY)
{
  x = newX;
  y = newY;
}

std::ostream& operator<<(std::ostream& os, const Vec2& vector)
{

  os << vector.x << "," << vector.y;

  return os;

}

Vec2& Vec2::operator -(const Vec2& right)
{

  return *this;
}

Vec2& Vec2::operator +(const Vec2& right)
{

  this->x += right.x;
  this->y += right.y;

  return *this;
}

Vec2* Vec2::operator *(const Vec2& right)
{

  return this;

}

Vec2* Vec2::operator /(const Vec2& right)
{

  return this;

}