#pragma once

/**
 * @class rune::Vec3
 * @brief 1 x 3 vector to be used for math.
 *
 * @author Thomas Montano
 * @date May 21 2020
*/

#include <core.h>
#include <iostream>

#ifndef VEC3_H_DEFINED
#define VEC3_H_DEFINED

namespace rune{

class RUNE_ENGINE Vec3
{

public:
  ///X coordinate of the vector.
  double x;
  ///Y coordinate of the vector.
  double y;
  ///Z coordinate of the vector.
  double z;
  ///Constructor that sets up a new vector.
  Vec3(double newX = 0, double newY = 0, double newZ = 0);
  ///Overload of subtraction operator.
  Vec3 operator- (const Vec3& right);
  ///Overload of negation operator.
  Vec3 operator-();

  ///Overload of addition operator.
  Vec3 operator+ (const Vec3& right);

  ///Overload of mutiplication operator.
  Vec3 operator* (const Vec3& right);

  ///Overload of division operator.
  Vec3 operator/ (const Vec3& right);
  ///Overload of division operator for a scalar on the right.
  Vec3 operator/ (double scalar);

  ///Overload of -= operator.
  Vec3& operator-=(const Vec3& right);

  ///Overload of += operator.
  Vec3& operator+=(const Vec3& right);

  ///Overload of *= operator.
  Vec3& operator*=(const Vec3& right);
  ///Overload of *= operator for a scalar multiplier.
  Vec3& operator*=(const double right);
  ///Overload of muliplication operator for a scalar on the right.
  Vec3 operator* (double scalar);

  ///Overload of comparator operator.
  bool operator==(const Vec3& right);
  ///Overload of != operator.
  bool operator!=(const Vec3& right);

  ///Determine the magnitude of the vector.
  double magnitude(void);

};

///Overload of stream operator for printing.
/// @memberof rune::Vec3
RUNE_ENGINE std::ostream& operator<<(std::ostream& os, const Vec3& vector);

/**
 * @memberof rune::Vec3
 * @brief Dot product calculation of two vectors.
 */
RUNE_ENGINE double dotProduct(rune::Vec3 vector1, rune::Vec3 vector2);

/**
 * @memberof rune::Vec3
 * @brief Divides each component of a vector by the vector magnitude to make the vector magnitude equal to 1.
 */
RUNE_ENGINE rune::Vec3 normalize(rune::Vec3 vector);

/**
 * @memberof rune::Vec3
 * @brief Cross product of two vectors.
 */
RUNE_ENGINE rune::Vec3 crossProduct(rune::Vec3, rune::Vec3);

/// Overload of muliplication operator for a scalar on the left.
/// @memberof rune::Vec3
RUNE_ENGINE rune::Vec3 operator*(double scalar, rune::Vec3 mat);

}
#endif