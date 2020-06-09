#include "vec3.h"
#include <cmath>

rune::Vec3::Vec3(double newX, double newY, double newZ) : x(newX), y(newY), z(newZ)
{

}

/**
 * \param right The vector to be subtracted.
 * \return A memberwise subtraction.
 */
rune::Vec3 rune::Vec3::operator- (const Vec3& right)
{
  return rune::Vec3(this->x - right.x, this->y - right.y, this->z - right.z);
}

/**
 * \return The negative of the vector.
 */
rune::Vec3 rune::Vec3::operator-()
{
  return rune::Vec3(-1 * this->x, -1 * this->y, -1 * this->z);
}

/**
 * \param right The vector to be added.
 * \return A memberwise addition.
 */
rune::Vec3 rune::Vec3::operator+ (const Vec3& right)
{
  return rune::Vec3(this->x + right.x, this->y + right.y, this->z + right.z);
}

/**
 * \param right The vector to be multiplied by.
 * \return A memberwise multiplication.
 */
rune::Vec3 rune::Vec3::operator* (const Vec3& right)
{
  return rune::Vec3(this->x * right.x, this->y * right.y, this->z * right.z);
}

/**
 * \param right The vector to be divided by.
 * \return A memberwise division.
 */
rune::Vec3 rune::Vec3::operator/ (const Vec3& right)
{
  
  return rune::Vec3(this->x/right.x, this->y / right.y, this->z / right.z);
}

/**
 * \param scalar The scalar to be divided by.
 * \return A memberwise division by a scalar.
 */
rune::Vec3 rune::Vec3::operator/ (double scalar)
{
  return rune::Vec3(this->x / scalar, this->y / scalar, this->z / scalar);
}

/**
 * \param right The vector to be subtracted by.
 * \return A memberwise subtraction.
 */
rune::Vec3& rune::Vec3::operator-=(const Vec3& right)
{
  this->x -= right.x;
  this->y -= right.y;
  this->z -= right.z;

  return *this;
}

/**
 * \param right The vector to be added.
 * \return A memberwise addition.
 */
rune::Vec3& rune::Vec3::operator+=(const Vec3& right)
{
  this->x += right.x;
  this->y += right.y;
  this->z += right.z;

  return *this;
}

/**
 * \param right The vector to be multiplied by.
 * \return A memberwise multiplication.
 */
rune::Vec3& rune::Vec3::operator*=(const Vec3& right)
{
  this->x *= right.x;
  this->y *= right.y;
  this->z *= right.z;

  return *this;
}

/**
 * \param right The scalar to be multiplied by.
 * \return A memberwise scalar multiplication.
 */
rune::Vec3& rune::Vec3::operator*=(const double right)
{
  this->x *= right;
  this->y *= right;
  this->z *= right;

  return *this;
}

/**
 * \param right The scalar to be multiplied by.
 * \return A memberwise scalar multiplication.
 */
rune::Vec3 rune::Vec3::operator* (double scalar)
{
  return rune::Vec3(this->x * scalar, this->y * scalar, this->z * scalar);
}

/**
 * \param right The vector to compare to.
 * \return Whether or not the vectors are memberwise equivalent.
 */
bool rune::Vec3::operator==(const rune::Vec3& right)
{
  
  if(this->x == right.x && this->y == right.y && this->z == right.z)
  {
    return true;
  }

  return false;

}

/**
 * \param right The vector to compare to.
 * \return Whether or not the vectors are memberwise non equivalent.
 */
bool rune::Vec3::operator!=(const rune::Vec3& right)
{

  if (this->x != right.x || this->y != right.y || this->z != right.z)
  {
    return true;
  }

  return false;

}

std::ostream& rune::operator<<(std::ostream& os, const rune::Vec3& vector)
{

  os << vector.x << "," << vector.y << "," << vector.z;

  return os;

}

/**
 * \return The magnitude of the vector.
 */
double rune::Vec3::magnitude(void)
{
  return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

/**
 * \param vector1 The first vector of the dot product.
 * \param vector2 The second vector of the dot product.
 * \return The result of the dot product.
 */
double rune::dotProduct(rune::Vec3 vector1, rune::Vec3 vector2)
{
  return (vector1.x*vector2.x + vector1.y * vector2.y + vector1.z * vector2.z);
}

/**
 * \param vector The vector to be normalized.
 * \return A vector in the same direction as vector but with magnitude 1.
 */
rune::Vec3 rune::normalize(rune::Vec3 vector)
{
  double magnitude = sqrt(pow(vector.x,2) + pow(vector.y, 2) + pow(vector.z, 2));
  return rune::Vec3(magnitude != 0 ? vector.x / magnitude : 0, magnitude != 0 ? vector.y / magnitude : 0, magnitude != 0 ? vector.z / magnitude : 0);
}

/**
 * \param vec1 The first vector to be used in the cross product.
 * \param vec2 The second vector to be used in the cross product.
 * \return The result of the cross product.
 */
rune::Vec3 rune::crossProduct(rune::Vec3 vec1, rune::Vec3 vec2)
{
  return rune::Vec3(vec1.y * vec2.z - vec1.z * vec2.y, vec1.z * vec2.x - vec1.x * vec2.z, vec1.x * vec2.y - vec1.y * vec2.x);
}

/**
 * \param scalar The scalar to be mutiplied by.
 * \param mat The matrix being mutiplied with.
 * \return A memberwise multiplication.
 */
rune::Vec3 rune::operator*(double scalar, rune::Vec3 mat)
{
  return rune::Vec3(scalar*mat.x, scalar * mat.y, scalar * mat.z);
}
