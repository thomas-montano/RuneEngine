#pragma once

/**
 * @class rune::Mat2
 * @brief 2 x 2 matrix to be used for math.
 *
 * @author Thomas Montano
 * @date May 15 2020
*/

#include "core.h"
#include <iostream>

namespace rune{

class RUNE_ENGINE Mat2
{
public:
  ///First row of the matrix.
  double row1[2];
  ///Second row of the matrix.
  double row2[2];
  ///Default empty constructor that sets X and Y to 0.
  Mat2();
  ///Constructor that sets up a new vector.
  Mat2(double newRow1[2], double newRow2[2]);
  ///Overload of subtraction operator.
  Mat2 operator- (const Mat2& right);
  ///Overload of addition operator.
  Mat2 operator+ (const Mat2& right);
  ///Overload of mutiplication operator.
  Mat2 operator* (const Mat2& right);
  ///Overload of division operator.
  Mat2 operator/ (const Mat2& right);
  ///Overload of -= operator.
  Mat2& operator-=(const Mat2& right);
  ///Overload of += operator.
  Mat2& operator+=(const Mat2& right);
  ///Overload of *= operator.
  Mat2& operator*=(const Mat2& right);
  ///Overload of *= operator for a scalar multiplier.
  Mat2& operator*=(const double right);
  ///Overload of comparator operator.
  bool operator==(const Mat2& right);
  ///Overload of != operator.
  bool operator!=(const Mat2& right);
  ///Overload of muliplication operator for a scalar on the left.
  friend RUNE_ENGINE Mat2 operator* (double scalar, Mat2& vec);
  ///Overload of muliplication operator for a scalar on the right.
  friend RUNE_ENGINE Mat2 operator* (Mat2& vec, double scalar);
  ///Overload of stream operator for printing.
  friend RUNE_ENGINE std::ostream& operator<<(std::ostream& os, const Mat2& vector);

};

}
