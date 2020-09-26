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

class Vec2;

class RUNE_ENGINE Vec3
{

public:
  ///X coordinate of the vector.
  double x;
  ///Y coordinate of the vector.
  double y;
  ///Z coordinate of the vector.
  double z;
  ///Constructor that sets up a new zero vector.
  Vec3(double newX = 0, double newY = 0, double newZ = 0);
  ///Construct a Vec3 from a Vec2 by dropping the z coordinate.
  Vec3(rune::Vec2);
  ///Overload of subtraction operator.
  Vec3 operator- (const Vec3& right);
  ///Overload of negation operator.
  Vec3 operator-();

  ///Overload of addition operator.
  Vec3 operator+ (const Vec3& right);

  ///Overload of multiplication operator.
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
  ///Overload of multiplication operator for a scalar on the right.
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

RUNE_ENGINE double dotProduct(const rune::Vec3& vector1, const rune::Vec3& vector2);

RUNE_ENGINE rune::Vec3 normalize(const rune::Vec3& vector);

RUNE_ENGINE rune::Vec3 crossProduct(const rune::Vec3&, const rune::Vec3&);

/// Overload of multiplication operator for a scalar on the left.
/// @param scalar Scalar value to be multiplied by.
/// @param vec The vector to be multiplied with.
/// @memberof rune::Vec3
RUNE_ENGINE rune::Vec3 operator*(double scalar, const rune::Vec3& vec);

}
#endif