#include "vec2.h"

Vec2::Vec2() : x(0), y(0)
{

}

/**
 * \param newX The initial value for the X component.
 * \param newY The initial value for the Y component.
 */
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

/**
 * \param right The vector to be subtracter.
 * \return A memberwise subtraction.
 */
Vec2 Vec2::operator -(const Vec2& right)
{

  return Vec2(this->x - right.x, this->y - right.y);

}

/**
 * \param right The vector to be added.
 * \return A memberwise addition.
 */
Vec2 Vec2::operator +(const Vec2& right)
{

  return Vec2(this->x + right.x,this->y + right.y);

}

/**
 * \param right The vector to multiply by.
 * \return A memberwise multiplication.
 */
Vec2 Vec2::operator *(const Vec2& right)
{

  return Vec2(this->x * right.x, this->y * right.y);

}

/**
 * \param right The vector to divide by.
 * \return A memberwise division.
 */
Vec2 Vec2::operator /(const Vec2& right)
{

  return Vec2(this->x / right.x, this->y / right.y);

}

/**
 * \param right The vector to be subtracted.
 * \return A memberwise subtraction.
 */
Vec2& Vec2::operator-=(const Vec2& right)
{
  
  this->x -= right.x;
  this->y -= right.y;

  return *this;
}

/**
 * \param right The vector to be added.
 * \return A memberwise addition.
 */
Vec2& Vec2::operator+=(const Vec2& right)
{

  this->x += right.x;
  this->y += right.y;

  return *this;
}

/**
 * \param right The vector to be multiplied by.
 * \return A memberwise multiplication.
 */
Vec2& Vec2::operator*=(const Vec2& right)
{
  this->x *= right.x;
  this->y *= right.y;

  return *this;
}

/**
 * \param right The scalar to be multiplied by.
 * \return A memberwise multiplication.
 */
Vec2& Vec2::operator*=(const double right)
{

  this->x *= right;
  this->y *= right;

  return *this;
}

/**
 * \param right The vector to be compared to.
 * \return Whether or not the two vectors are memberwise equivalent.
 */
bool Vec2::operator==(const Vec2& right)
{
  if(this->x == right.x && this->y == right.y)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/**
 * \param right The vector to be compared to.
 * \return Whether or not the two vectors are memberwise unequivalent.
 */
bool Vec2::operator!=(const Vec2& right)
{

  if (this->x != right.x || this->y != right.y)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/**
 * \param scalar The scalar to be multiplied with.
 * \param vec The vector to be multiplied.
 * \return A memberwise multiplication.
 */
Vec2 operator* (double scalar, Vec2& vec)
{

  return Vec2(vec.x*scalar,vec.y*scalar);

}

/**
 * \param scalar The scalar to be multiplied with.
 * \param vec The vector to be multiplied.
 * \return A memberwise multiplication.
 */
Vec2 operator* (Vec2& vec, double scalar)
{
  return Vec2(vec.x * scalar, vec.y * scalar);
}

/**
 * @param v1 First vector to be used in the dot product.
 * @param v2 Seconds vector to be used in the dot product.
 * @return The result of the dot product calculation.
*/
double dotProduct(Vec2 v1, Vec2 v2)
{

  double dotProduct = v1.x * v2.x + v1.y * v2.y;

  return dotProduct;

}

/**
 * @param axis Vector to use to calculate the surface normal.
 * @return Left hand normal of the surface.
*/
Vec2 findNormal(Vec2 axis)
{

  Vec2 normal = Vec2(-axis.y, axis.x);
  double magnitude = sqrt(pow(axis.y, 2) + pow(axis.x, 2));

  return Vec2(normal.x / magnitude, normal.y / magnitude);

}

/**
 * @param vector Vector that should be normalized.
 * @return Vector in the direction of vector but with magnitude of 1.
*/
Vec2 normalize(Vec2 vector)
{
  double magnitude = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
  return Vec2(magnitude != 0 ? vector.x / magnitude : 0, magnitude != 0 ? vector.y / magnitude : 0);
}

/**
 * 
 * @param vector1 The first vector. 
 * @param vector2 The second vector.
 * @return The result of the cross product.
 */
double crossProduct(Vec2 vector1, Vec2 vector2)
{
  return vector1.x * vector2.y - vector1.y * vector2.x;
}