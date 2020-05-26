#include "mat2.h"

rune::Mat2::Mat2(): row1{ 0,0 }, row2{ 0,0 }
{

}

/**
 * \param a11 Element a11 of the matrix.
 * \param a12 Element a12 of the matrix.
 * \param a21 Element a21 of the matrix.
 * \param a22 Element a22 of the matrix.
 */
rune::Mat2::Mat2(double a11, double a12, double a21, double a22) : row1 { a11, a12 }, row2{ a21, a22 }
{

}

/**
 * \param right The matrix to be subtracted.
 * \return A memberwise subtraction.
 */
rune::Mat2 rune::Mat2::operator- (const rune::Mat2& right)
{
  Mat2 temp(this->row1[0]-right.row1[0],this->row1[1]-right.row1[1],this->row2[0]-right.row2[0],this->row2[1]-right.row2[1]);  

  return temp;
}

/**
 * \return The negative of the matrix.
 */
rune::Mat2 rune::Mat2::operator-()
{
  return Mat2(-1*this->row1[0], -1 * this->row1[1], -1 * this->row2[0], -1 * this->row2[1]);
}

/**
 * \param right The matrix to be added.
 * \return The memberwise addition.
 */
rune::Mat2 rune::Mat2::operator+ (const rune::Mat2& right)
{
  Mat2 temp(this->row1[0] + right.row1[0], this->row1[1] + right.row1[1], this->row2[0] + right.row2[0], this->row2[1] + right.row2[1]);

  return temp;
}

/**
 * \param right The matrix to multiply by.
 * \return The result of the matrix multiplication.
 */
rune::Mat2 rune::Mat2::operator* (const rune::Mat2& right)
{
  Mat2 temp = *this;

  double newRow1[2];
  double newRow2[2];

  newRow1[0] = rune::dotProduct(rune::Vec2(temp.row1[0], temp.row1[1]),rune::Vec2(right.row1[0], right.row2[0]));
  newRow1[1] = rune::dotProduct(rune::Vec2(temp.row1[0], temp.row1[1]),rune::Vec2(right.row1[1], right.row2[1]));

  newRow2[0] = rune::dotProduct(rune::Vec2(temp.row2[0], temp.row2[1]), rune::Vec2(right.row1[0], right.row2[0]));
  newRow2[1] = rune::dotProduct(rune::Vec2(temp.row2[0], temp.row2[1]), rune::Vec2(right.row1[1], right.row2[1]));

  return Mat2(newRow1[0],newRow1[1],newRow2[0],newRow2[1]);
}

/**
 * \param right The matrix to divide by
 * \return The result of the multiplication by the inverse of the matrix.
 */
rune::Mat2 rune::Mat2::operator/ (const rune::Mat2& right)
{

  double determinant = (right.row1[0]*right.row2[1]) - (right.row1[1]*right.row2[0]);

  Mat2 inverse = Mat2(right.row2[1]/determinant,-1*right.row1[1] / determinant,-1*right.row2[0] / determinant,right.row1[0] / determinant);

  return (*this)*inverse;
}

/**
 * \param right The matrix to be subtracted.
 * \return The memberwise subtraction.
 */
rune::Mat2& rune::Mat2::operator-=(const rune::Mat2& right)
{
  Mat2 temp(this->row1[0] - right.row1[0], this->row1[1] - right.row1[1], this->row2[0] - right.row2[0], this->row2[1] - right.row2[1]);
  *this = temp;

  return *this;
}

/**
 * \param right The matrix to be added.
 * \return The memberwise addition.
 */
rune::Mat2& rune::Mat2::operator+=(const rune::Mat2& right)
{

  Mat2 temp(this->row1[0] + right.row1[0], this->row1[1] + right.row1[1], this->row2[0] + right.row2[0], this->row2[1] + right.row2[1]);
  *this = temp; 
  
  return *this;
}

/**
 * \param scalar The scalar to be added.
 * \return A memberwise addition.
 */
rune::Mat2& rune::Mat2::operator+=(const double scalar)
{
  this->row1[0] += scalar;
  this->row1[1] += scalar;
  this->row2[0] += scalar;
  this->row2[1] += scalar;

  return *this;
}

/**
 * \param right The matrix to be multiplied by.
 * \return The result of the matrix multiplication.
 */
rune::Mat2& rune::Mat2::operator*=(const rune::Mat2& right)
{

  Mat2 temp = *this;

  double newRow1[2];
  double newRow2[2];

  newRow1[0] = rune::dotProduct(rune::Vec2(temp.row1[0], temp.row1[1]), rune::Vec2(right.row1[0], right.row2[0]));
  newRow1[1] = rune::dotProduct(rune::Vec2(temp.row1[0], temp.row1[1]), rune::Vec2(right.row1[1], right.row2[1]));

  newRow2[0] = rune::dotProduct(rune::Vec2(temp.row2[0], temp.row2[1]), rune::Vec2(right.row1[0], right.row2[0]));
  newRow2[1] = rune::dotProduct(rune::Vec2(temp.row2[0], temp.row2[1]), rune::Vec2(right.row1[1], right.row2[1]));

  *this = Mat2(newRow1[0], newRow1[1], newRow2[0], newRow2[1]);

  return *this;
}

/**
 * \param right The scalar to multiply by.
 * \return A memberwise scalar multiplication.
 */
rune::Mat2& rune::Mat2::operator*=(const double right)
{

  Mat2 temp(this->row1[0] * right, this->row1[1] * right, this->row2[0] * right, this->row2[1] * right);
  *this = temp;

  return *this;
}

/**
 * \param right The matrix to compare with.
 * \return The result of a memberwise comparison.
 */
bool rune::Mat2::operator==(const Mat2& right)
{

  if(this->row1[0] == right.row1[0] &&
    this->row1[1] == right.row1[1] &&
    this->row2[0] == right.row2[0] &&
    this->row2[1] == right.row2[1])
    {
      return true;
    }

  return false;
}

/**
 * \param right THe matrix to compare with.
 * \return The result of a memberwise comparison.
 */
bool rune::Mat2::operator!=(const rune::Mat2& right)
{

  if (this->row1[0] != right.row1[0] ||
      this->row1[1] != right.row1[1] ||
      this->row2[0] != right.row2[0] ||
      this->row2[1] != right.row2[1])
  {
    return true;
  }
  
  return false;
}

/**
 * \param right The scalar to multiply by.
 * \return A memberwise scalar multiplication.
 */
rune::Mat2 rune::Mat2::operator* (double scalar)
{

  Mat2 temp(this->row1[0] * scalar, this->row1[1] * scalar, this->row2[0] * scalar, this->row2[1] * scalar);

  return temp;
}

/**
 * \param right The rune::Vec2 to be multiplied by.
 * \return The result of the multiplication.
 */
rune::Vec2 rune::Mat2::operator*(const rune::Vec2& right)
{
  
  rune::Mat2 temp = *this;

  return Vec2(right.x * temp[0][0] + right.x * temp[1][0], right.y * temp[0][1] + right.y * temp[1][1]);

}

/**
 * \param right The left operand rune::Vec2.
 * \param left The right operand rune::Mat2.
 * \return The result of the multiplication.
 */
rune::Vec2 rune::operator*(rune::Vec2 right, rune::Mat2 left)
{
  return left * right;
}

/**
 * \param right The scalar to multiply by.
 * \return A memberwise scalar division.
 */
rune::Mat2 rune::Mat2::operator/ (double scalar)
{

  return Mat2(this->row1[0]/scalar, this->row1[1]/scalar, this->row2[0]/scalar, this->row2[1]/scalar);

}

/**
 * \param right The scalar to multiply by.
 * \return A memberwise scalar multiplication.
 */
rune::Mat2 rune::operator* (double scalar, rune::Mat2 mat)
{
  return scalar*mat;
}

std::ostream& rune::operator<<(std::ostream& os, const rune::Mat2& matrix)
{
  os << matrix.row1[0] << "," << matrix.row1[1] << std::endl;
  os << matrix.row2[0] << "," << matrix.row2[1] << std::endl;

  return os;
}

/**
 * \param right The matrix to invert.
 * \return The inverse of the square matrix.
 */
rune::Mat2 rune::invert(rune::Mat2 right)
{

  double determinant = right.determinant();
  return Mat2(right.row2[1] / determinant, -1 * right.row1[1] / determinant, -1 * right.row2[0] / determinant, right.row1[0] / determinant);

}

/**
 * \return The determinant of the matrix.
 */
double rune::Mat2::determinant()
{
  return(this->row1[0] * this->row2[1]) - (this->row1[1] * this->row2[0]);
}

// Provide array-like index operators for the columns of the matrix.
double* rune::Mat2::operator[](int index)
{
  //Array accessing
  if(index == 0)
    return row1;
  else if(index == 1)
    return row2;

  return row1;
}

