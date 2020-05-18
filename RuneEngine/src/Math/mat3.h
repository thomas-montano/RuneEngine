#pragma once

/**
 * @class rune::Mat3
 * 
 * @brief 3 x 3 matrix to be used for math.
 * 
 * @author Thomas Montano
 * @date May 16 2020
 */

#include "core.h"
#include <iostream>

#ifndef MAT3_H_DEFINED
#define MAT3_H_DEFINED

namespace rune{

class RUNE_ENGINE Mat3
{
public:
  ///First row of the matrix.
  double row1[3];
  ///Second row of the matrix.
  double row2[3];
  ///Third row of the matrix.
  double row3[3];
  ///Default empty constructor that sets X and Y to 0.
  Mat3();
  ///Constructor that sets up a new vector.
  Mat3(double newX, double newY);
  ///Overload of subtraction operator.
  Mat3 operator- (const Mat3& right);
  ///Overload of addition operator.
  Mat3 operator+ (const Mat3& right);
  ///Overload of mutiplication operator.
  Mat3 operator* (const Mat3& right);
  ///Overload of division operator.
  Mat3 operator/ (const Mat3& right);
  ///Overload of -= operator.
  Mat3& operator-=(const Mat3& right);
  ///Overload of += operator.
  Mat3& operator+=(const Mat3& right);
  ///Overload of *= operator.
  Mat3& operator*=(const Mat3& right);
  ///Overload of *= operator for a scalar multiplier.
  Mat3& operator*=(const double right);
  ///Overload of comparator operator.
  bool operator==(const Mat3& right);
  ///Overload of != operator.
  bool operator!=(const Mat3& right);
  ///Overload of muliplication operator for a scalar on the left.
  friend RUNE_ENGINE Mat3 operator* (double scalar, Mat3& vec);
  ///Overload of muliplication operator for a scalar on the right.
  friend RUNE_ENGINE Mat3 operator* (Mat3& vec, double scalar);
  ///Overload of stream operator for printing.
  friend RUNE_ENGINE std::ostream& operator<<(std::ostream& os, const Mat3& vector);

};
}

#endif
