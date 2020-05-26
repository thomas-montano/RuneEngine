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

  ///Default empty constructor that sets X and Y to 0.
  Vec2();
  ///Constructor that sets up a new vector.
  Vec2(double newX, double newY);

  ///Overload of subtraction operator.
  Vec2 operator- (const Vec2& right);
  ///Overload of negation operator.
  Vec2 operator-();

  ///Overload of addition operator.
  Vec2 operator+ (const Vec2& right);

  ///Overload of mutiplication operator.
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
  ///Overload of muliplication operator for a scalar on the right.
  Vec2 operator* (double scalar);

  ///Overload of comparator operator.
  bool operator==(const Vec2& right);
  ///Overload of != operator.
  bool operator!=(const Vec2& right);

};

///Overload of division operator
RUNE_ENGINE Vec2 operator/ (double scalar, Vec2 vec);

/**
 * @memberof rune::Vec2
 * @brief Dot product calculation of two vectors.
 */
RUNE_ENGINE double dotProduct(rune::Vec2 vector1, rune::Vec2 vector2);

/**
 * @memberof rune::Vec2
 * @brief Find the vector normal to a surface 
 */
RUNE_ENGINE rune::Vec2 findNormal(rune::Vec2 axis);

/**
 * @memberof rune::Vec2
 * @brief Divides each component of a vector by the vector magnitude to make the vector magnitude equal to 1.
 */
RUNE_ENGINE rune::Vec2 normalize(rune::Vec2);

/**
 * @memberof rune::Vec2
 * @brief Cross product of two vectors.
 */
RUNE_ENGINE double crossProduct(rune::Vec2, rune::Vec2);

///Overload of muliplication operator for a scalar on the left.
RUNE_ENGINE rune::Vec2 operator*(double scalar, rune::Vec2 mat);

///Overload of stream operator for printing.
/// @memberof rune::Vec2
RUNE_ENGINE std::ostream& operator<<(std::ostream& os, const rune::Vec2& vector);

}

#endif