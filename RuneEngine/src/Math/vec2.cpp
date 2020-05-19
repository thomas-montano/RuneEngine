#include "Vec2.h"

rune::Vec2::Vec2() : x(0), y(0)
{

}

/**
 * \param newX The initial value for the X component.
 * \param newY The initial value for the Y component.
 */
rune::Vec2::Vec2(double newX, double newY)
{
  x = newX;
  y = newY;
}

///@memberof Vec2
std::ostream& rune::operator<<(std::ostream& os, const rune::Vec2& vector)
{

  os << vector.x << "," << vector.y;

  return os;

}

/**
 * \param right The vector to be subtracter.
 * \return A memberwise subtraction.
 */
rune::Vec2 rune::Vec2::operator -(const rune::Vec2& right)
{

  return rune::Vec2(this->x - right.x, this->y - right.y);

}

rune::Vec2 rune::Vec2::operator-()
{
  return rune::Vec2(-1*this->x,-1*this->y);
}

/**
 * \param right The vector to be added.
 * \return A memberwise addition.
 */
rune::Vec2 rune::Vec2::operator +(const rune::Vec2& right)
{

  return rune::Vec2(this->x + right.x,this->y + right.y);

}

/**
 * \param right The vector to multiply by.
 * \return A memberwise multiplication.
 */
rune::Vec2 rune::Vec2::operator *(const rune::Vec2& right)
{

  return rune::Vec2(this->x * right.x, this->y * right.y);

}

/**
 * \param right The vector to divide by.
 * \return A memberwise division.
 */
rune::Vec2 rune::Vec2::operator /(const rune::Vec2& right)
{

  return rune::Vec2(this->x / right.x, this->y / right.y);

}

/**
 * \param right The vector to be subtracted.
 * \return A memberwise subtraction.
 */
rune::Vec2& rune::Vec2::operator-=(const rune::Vec2& right)
{
  
  this->x -= right.x;
  this->y -= right.y;

  return *this;
}

/**
 * \param right The vector to be added.
 * \return A memberwise addition.
 */
rune::Vec2& rune::Vec2::operator+=(const rune::Vec2& right)
{

  this->x += right.x;
  this->y += right.y;

  return *this;
}

/**
 * \param right The vector to be multiplied by.
 * \return A memberwise multiplication.
 */
rune::Vec2& rune::Vec2::operator*=(const rune::Vec2& right)
{
  this->x *= right.x;
  this->y *= right.y;

  return *this;
}

/**
 * \param right The scalar to be multiplied by.
 * \return A memberwise multiplication.
 */
rune::Vec2& rune::Vec2::operator*=(const double right)
{

  this->x *= right;
  this->y *= right;

  return *this;
}

/**
 * \param right The vector to be compared to.
 * \return Whether or not the two vectors are memberwise equivalent.
 */
bool rune::Vec2::operator==(const rune::Vec2& right)
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
bool rune::Vec2::operator!=(const rune::Vec2& right)
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
 * @memberof Vec2
 * \param scalar The scalar to be multiplied with.
 * \param vec The vector to be multiplied.
 * \return A memberwise multiplication.
 */
rune::Vec2 rune::operator* (double scalar, rune::Vec2& vec)
{

  return rune::Vec2(vec.x*scalar,vec.y*scalar);

}

/**
 * @memberof Vec2
 * \param scalar The scalar to be multiplied with.
 * \param vec The vector to be multiplied.
 * \return A memberwise multiplication.
 */
rune::Vec2 rune::operator* (rune::Vec2& vec, double scalar)
{
  return rune::Vec2(vec.x * scalar, vec.y * scalar);
}

rune::Vec2 rune::operator/ (rune::Vec2& vec, double scalar)
{
  return rune::Vec2(vec.x/scalar,vec.y/scalar);
}

/**
 * @param v1 First vector to be used in the dot product.
 * @param v2 Seconds vector to be used in the dot product.
 * @return The result of the dot product calculation.
*/
double rune::dotProduct(rune::Vec2 v1, rune::Vec2 v2)
{

  double dotProduct = v1.x * v2.x + v1.y * v2.y;

  return dotProduct;

}

/**
 * @param axis Vector to use to calculate the surface normal.
 * @return Left hand normal of the surface.
*/
rune::Vec2 rune::findNormal(rune::Vec2 axis)
{

  rune::Vec2 normal = rune::Vec2(-axis.y, axis.x);
  double magnitude = sqrt(pow(axis.y, 2) + pow(axis.x, 2));

  return rune::Vec2(normal.x / magnitude, normal.y / magnitude);

}

/**
 * @param vector Vector that should be normalized.
 * @return Vector in the direction of vector but with magnitude of 1.
*/
rune::Vec2 rune::normalize(rune::Vec2 vector)
{
  double magnitude = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
  return rune::Vec2(magnitude != 0 ? vector.x / magnitude : 0, magnitude != 0 ? vector.y / magnitude : 0);
}

/**
 * 
 * @param vector1 The first vector. 
 * @param vector2 The second vector.
 * @return The result of the cross product.
 */
double rune::crossProduct(rune::Vec2 vector1, rune::Vec2 vector2)
{
  return vector1.x * vector2.y - vector1.y * vector2.x;
}