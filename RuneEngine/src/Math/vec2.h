#pragma once

/**
 * @class rune::Vec2
 * @brief 1 x 2 vector to be used for math.
 * 
 * @author Thomas Montano
 * @date April 20 2020
*/

#ifndef VEC2_H_DEFINED
#define VEC2_H_DEFINED

#include <iostream>
#include "core.h"

namespace rune{

class RUNE_ENGINE Vec2
{
public:
  ///X coordinate of the vector.
  double x;
  ///Y coordinate of the vector.
  double y;

  ///Constructor that sets up a new vector.
  Vec2(double newX = 0, double newY = 0);

  ///Overload of subtraction operator.
  Vec2 operator- (const Vec2& right);
  ///Overload of negation operator.
  Vec2 operator-();

  ///Overload of addition operator.
  Vec2 operator+ (const Vec2& right);

  ///Overload of multiplication operator.
  Vec2 operator* (const Vec2& right);

  ///Overload of division operator.
  Vec2 operator/ (const Vec2& right);
  ///Overload of division operator for a scalar on the right.
  Vec2 operator/ (double scalar);

  ///Overload of -= operator.
  Vec2& operator-=(const Vec2& right);

  ///Overload of += operator.
  Vec2& operator+=(const Vec2& right);

  ///Overload of *= operator.
  Vec2& operator*=(const Vec2& right);
  ///Overload of *= operator for a scalar multiplier.
  Vec2& operator*=(const double right);

  Vec2 operator* (double scalar);

  ///Overload of comparator operator.
  bool operator==(const Vec2& right);
  ///Overload of != operator.
  bool operator!=(const Vec2& right);

};

///Overload of division operator
RUNE_ENGINE Vec2 operator/ (double scalar, Vec2 vec);

RUNE_ENGINE double dotProduct(rune::Vec2 const& vector1, rune::Vec2 const& vector2);

/**
 * @memberof rune::Vec2
 * @param axis The axis that is used to find the normal.
 * @brief Find the left handed vector normal to a surface 
 * @return The left handed vector that is normal to the provided surface.
 */
RUNE_ENGINE rune::Vec2 findNormal(rune::Vec2 const& axis);

/**
 * @memberof rune::Vec2
 * @param vec The vector to be normalized.
 * @brief Divides each component of a vector by the vector magnitude to make the vector magnitude equal to 1.
 * @return A vector in the same direction with magnitude of 1.
 */
RUNE_ENGINE rune::Vec2 normalize(rune::Vec2 const& vec);

RUNE_ENGINE double crossProduct(rune::Vec2 const& vec1, rune::Vec2 const& vec2);

///Overload of multiplication operator for a scalar on the left.
RUNE_ENGINE rune::Vec2 operator*(double scalar, rune::Vec2 const& mat);

RUNE_ENGINE std::ostream& operator<<(std::ostream& os, const rune::Vec2& vector);

}

#endif