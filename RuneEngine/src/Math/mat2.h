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
  ///Overload of divison operator for a scalar.
  rune::Mat2 operator/ (double scalar);
  ///Overload of stream operator for printing.
  friend RUNE_ENGINE std::ostream& operator<<(std::ostream& os, const Mat2& vector);
  ///Inversion of the matrix.
  friend RUNE_ENGINE Mat2 invert(Mat2);
  ///Determinant of the matrix.
  double determinant();
  ///Array like accessing of elements.
  double* operator[](int index);
};

}
