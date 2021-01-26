#pragma once

/**
 * @class rune::Mat2
 * @brief 2 x 2 matrix to be used for math.
 * 
 * You should access this matrix using row major order. That means accessing the matrix using Mat2[y][x] where
 * y is the row and x is the column number.
 *
 * @author Thomas Montano
 * @date May 15 2020
*/

#include "core.h"
#include "vec2.h"
#include <iostream>

namespace rune{

class RUNE_ENGINE Mat2
{
private:
  ///First row of the matrix.
  double row1[2];
  ///Second row of the matrix.
  double row2[2];
public:
  ///Default empty constructor that sets X and Y to 0.
  Mat2();
  ///Constructor that sets up a new vector.
  Mat2(double a11, double a12, double a21, double a22);
  ///Overload of subtraction operator.
  Mat2 operator- (const Mat2& right);
  ///Overload of negation operator.
  Mat2 operator-();
  ///Overload of addition operator.
  Mat2 operator+ (const Mat2& right);
  ///Overload of multiplication operator.
  Mat2 operator* (const Mat2& right);
  ///Overload of multiplication operator for a scalar on the left.
  Mat2 operator* (double scalar);
  ///Overload of multiplication operator for a rune::Mat2
  Vec2 operator*(const Vec2& right);
  ///Overload of division operator.
  Mat2 operator/ (const Mat2& right);
  ///Overload of -= operator.
  Mat2& operator-=(const Mat2& right);
  ///Overload of += operator.
  Mat2& operator+=(const Mat2& right);
  ///Overload of += operator for scalar.
  Mat2& operator+=(const double scalar);
  ///Overload of *= operator.
  Mat2& operator*=(const Mat2& right);
  ///Overload of *= operator for a scalar multiplier.
  Mat2& operator*=(const double right);
  ///Overload of comparator operator.
  bool operator==(const Mat2& right);
  ///Overload of != operator.
  bool operator!=(const Mat2& right);
  ///Overload of division operator for a scalar.
  rune::Mat2 operator/ (double scalar);
  ///Inversion of the matrix.
  Mat2 invert();
  ///Determinant of the matrix.
  double determinant();
  ///Array like accessing of elements.
  double* operator[](int index);
  ///Overload of stream operator for printing.
  friend RUNE_ENGINE std::ostream& operator<<(std::ostream& os, const Mat2& vector);
};

///Overload of multiplication operator for a rune::Mat2
RUNE_ENGINE rune::Vec2 operator*(rune::Vec2 const& vec, rune::Mat2& mat);
///Overload of multiplication operator for a scalar on the right.
RUNE_ENGINE Mat2 operator* (double scalar, rune::Mat2& mat);

}
