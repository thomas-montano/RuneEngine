#ifndef VEC2_H_DEFINED
#define VEC2_H_DEFINED

class Vec2
{
public:
  float x;
  float y;

  Vec2();
  Vec2(float newX, float newY);

  Vec2& operator -(const Vec2& right);
  Vec2& operator +(const Vec2& right);

  Vec2* operator *(const Vec2& right);
  Vec2* operator /(const Vec2& right);

};

#endif