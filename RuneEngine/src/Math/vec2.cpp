#include "vec2.h"
#include "mat2.h"

/**
 * \param newX The initial value for the X component.
 * \param newY The initial value for the Y component.
 */
rune::Vec2::Vec2(double newX, double newY)
{
  x = newX;
  y = newY;
}

/**
 * \memberof rune::Vec2
 * \param os Output stream that the vector should be printed to.
 * \param vector Vector to be printed.
 * \return Stream to be printed to the console.
 */
std::ostream& rune::operator<<(std::ostream& os, const rune::Vec2& vector)
{

  os << vector.x << "," << vector.y;

  return os;

}

/**
 * \param right The vector to be subtracter.
 * \return A member wise subtraction.
 */
rune::Vec2 rune::Vec2::operator-(const rune::Vec2& right)
{

  return rune::Vec2(this->x - right.x, this->y - right.y);

}

/**
 * \return The member wise negative of the vector.
 */
rune::Vec2 rune::Vec2::operator-()
{
  return rune::Vec2(-1*this->x,-1*this->y);
}

/**
 * \param right The vector to be added.
 * \return A member wise addition.
 */
rune::Vec2 rune::Vec2::operator+(const rune::Vec2& right)
{

  return rune::Vec2(this->x + right.x,this->y + right.y);

}

/**
 * \param right The vector to multiply by.
 * \return A member wise multiplication.
 */
rune::Vec2 rune::Vec2::operator *(const rune::Vec2& right)
{

  return rune::Vec2(this->x * right.x, this->y * right.y);

}

/**
 * \param right The vector to divide by.
 * \return A member wise division.
 */
rune::Vec2 rune::Vec2::operator /(const rune::Vec2& right)
{

  return rune::Vec2(this->x / right.x, this->y / right.y);

}

/**
 * \param right The vector to be subtracted.
 * \return A member wise subtraction.
 */
rune::Vec2& rune::Vec2::operator-=(const rune::Vec2& right)
{
  
  this->x -= right.x;
  this->y -= right.y;

  return *this;
}

/**
 * \param right The vector to be added.
 * \return A member wise addition.
 */
rune::Vec2& rune::Vec2::operator+=(const rune::Vec2& right)
{

  this->x += right.x;
  this->y += right.y;

  return *this;
}

/**
 * \param right The vector to be multiplied by.
 * \return A member wise multiplication.
 */
rune::Vec2& rune::Vec2::operator*=(const rune::Vec2& right)
{
  this->x *= right.x;
  this->y *= right.y;

  return *this;
}

/**
 * \param right The scalar to be multiplied by.
 * \return A member wise multiplication.
 */
rune::Vec2& rune::Vec2::operator*=(const double right)
{

  this->x *= right;
  this->y *= right;

  return *this;
}

/**
 * \param right The vector to be compared to.
 * \return Whether or not the two vectors are member wise equivalent.
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
 * \return Whether or not the two vectors are member wise inequivalent.
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
 * \return A member wise multiplication.
 */
rune::Vec2 rune::operator* (double scalar, rune::Vec2 const& vec)
{

  return rune::Vec2(vec.x*scalar,vec.y*scalar);

}

/**
 * \brief Overload of * operator for a scalar multiplier.
 * \param scalar The scalar to be multiplied with.
 * \return A member wise multiplication.
 */
rune::Vec2 rune::Vec2::operator* (double scalar)
{
  return rune::Vec2(this->x * scalar, this->y * scalar);
}

/**
 * \memberof rune::Vec2
 * \param scalar The scalar to be used as a divisor.
 * \param vec The vector to be element wise divided by.
 * \return A member wise multiplication.
 */
rune::Vec2 rune::operator/ (double scalar, rune::Vec2 vec)
{
  return rune::Vec2(vec.x / scalar, vec.y / scalar);
}

/**
 * @memberof rune::Vec2
 * @brief Overload of / operator for a scalar.
 * @param scalar The scalar to be divided by.
 * @return A member wise division by the scalar.
 */
rune::Vec2 rune::Vec2::operator/ (double scalar)
{
  return rune::Vec2(this->x/scalar,this->y/scalar);
}

/**
 * @memberof rune::Vec2
 * @param v1 First vector to be used in the dot product.
 * @param v2 Seconds vector to be used in the dot product.
 * @return The result of the dot product calculation.
*/
double rune::dotProduct(rune::Vec2 const& v1, rune::Vec2 const& v2)
{

  double dotProduct = v1.x * v2.x + v1.y * v2.y;

  return dotProduct;

}

/**
 * @memberof rune::Vec2
 * @param axis The axis that is used to find the normal.
 * @brief Find the left handed vector normal to a surface
 * @return The left handed vector that is normal to the provided surface.
 */
rune::Vec2 rune::findNormal(rune::Vec2 const& axis)
{

  rune::Vec2 normal = rune::Vec2(-axis.y, axis.x);
  double magnitude = sqrt(pow(axis.y, 2) + pow(axis.x, 2));

  return rune::Vec2(normal.x / magnitude, normal.y / magnitude);

}

/**
 * @memberof rune::Vec2
 * @param vector Vector that should be normalized.
 * @return Vector in the direction of vector but with magnitude of 1.
*/
rune::Vec2 rune::normalize(rune::Vec2 const& vector)
{
  double magnitude = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
  return rune::Vec2(magnitude != 0 ? vector.x / magnitude : 0, magnitude != 0 ? vector.y / magnitude : 0);
}

/**
 * @memberof rune::Vec2
 * @param vec1 The first vector. 
 * @param vec2 The second vector.
 * @return The result of the cross product.
 */
double rune::crossProduct(rune::Vec2 const& vec1, rune::Vec2 const& vec2)
{
  return vec1.x * vec2.y - vec1.y * vec2.x;
}