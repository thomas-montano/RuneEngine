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
#include "vec3.h"
#include <iostream>

#ifndef MAT3_H_DEFINED
#define MAT3_H_DEFINED

namespace rune{

class RUNE_ENGINE Mat3
{
private:
  ///First row of the matrix.
  double row1[3];
  ///Second row of the matrix.
  double row2[3];
  ///Third row of the matrix.
  double row3[3];

public:
  ///Default empty constructor that sets X and Y to 0.
  Mat3();
  ///Constructor that sets up a new vector.
  Mat3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33);
  ///Overload of subtraction operator.
  Mat3 operator- (const Mat3& right);
  ///Overload of negation operator.
  Mat3 operator- ();
  ///Overload of addition operator.
  Mat3 operator+ (const Mat3& right);
  ///Overload of multiplication operator.
  Mat3 operator* (const rune::Mat3& right);
  ///Overload of multiplication operator for a scalar on the left.
  Mat3 operator* (double scalar);
  ///Overload of multiplication operator for a rune::Mat3
  rune::Vec3 operator*(const rune::Vec3& right);
  ///Overload of division operator.
  Mat3 operator/ (const Mat3& right);
  ///Overload of -= operator.
  Mat3& operator-=(const Mat3& right);
  ///Overload of += operator.
  Mat3& operator+=(const Mat3& right);
  ///Overload of += operator for scalar.
  Mat3& operator+=(const double scalar);
  ///Overload of *= operator.
  Mat3& operator*=(const Mat3& right);
  ///Overload of *= operator for a scalar multiplier.
  Mat3& operator*=(const double right);
  ///Overload of *= operator.
  Mat3& operator/=(const Mat3& right);
  ///Overload of *= operator for a scalar multiplier.
  Mat3& operator/=(const double right);
  ///Overload of comparator operator.
  bool operator==(const Mat3& right);
  ///Overload of != operator.
  bool operator!=(const Mat3& right);
  ///Overload of division operator.
  Mat3 operator/ (double scalar);
  ///Inversion of the matrix.
  Mat3 invert();
  ///Determinant of the matrix.
  double determinant();
  ///Array like accessing of elements.
  double* operator[](int index);
  ///Overload of stream operator for printing.
  friend RUNE_ENGINE std::ostream& operator<<(std::ostream& os, const Mat3& vector);

};

///Overload of multiplication operator for a scalar on the right.
RUNE_ENGINE rune::Mat3 operator*(double scalar, rune::Mat3& mat);

}

#endif
