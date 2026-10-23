#include "mat3.h"
#include "mat2.h"


rune::Mat3::Mat3() : row1{ 0,0,0 }, row2{ 0,0,0 }, row3{ 0,0,0 }
{

}

rune::Mat3::Mat3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) : row1{a11,a12,a13}, row2{a21,a22,a23}, row3{a31,a32,a33}
{

}

/**
 * \return The negative of the matrix.
 */
rune::Mat3 rune::Mat3::operator- ()
{

  Mat3 temp = *this;

  for (int i = 0; i < 3; i++)
  {
    temp.row1[i] = -1*temp.row1[i];
  }

  for (int i = 0; i < 3; i++)
  {
    temp.row2[i] = -1*temp.row2[i];
  }

  for (int i = 0; i < 3; i++)
  {
    temp.row3[i] = -1*temp.row3[i];
  }

  return temp;

}

/**
 * \param right The matrix to be subtracted.
 * \return An element wise subtraction.
 */
rune::Mat3 rune::Mat3::operator- (const rune::Mat3& right)
{
  Mat3 temp = *this;

  for(int i = 0; i < 3; i ++)
  {
    temp.row1[i] = temp.row1[i] - right.row1[i];
  }

  for (int i = 0; i < 3; i++)
  {
    temp.row2[i] = temp.row2[i] - right.row2[i];
  }

  for (int i = 0; i < 3; i++)
  {
    temp.row3[i] = temp.row3[i] - right.row3[i];
  }

  return temp;

}

/**
 * \param right The matrix to be added.
 * \return An element wise addition.
 */
rune::Mat3 rune::Mat3::operator+ (const Mat3& right)
{
  Mat3 temp = *this;

  for (int i = 0; i < 3; i++)
  {
    temp.row1[i] = temp.row1[i] + right.row1[i];
  }

  for (int i = 0; i < 3; i++)
  {
    temp.row2[i] = temp.row2[i] + right.row2[i];
  }

  for (int i = 0; i < 3; i++)
  {
    temp.row3[i] = temp.row3[i] + right.row3[i];
  }

  return temp;
}

/**
 * \param right The matrix to be multiplied by.
 * \return The result of the multiplication.
 */
rune::Mat3 rune::Mat3::operator* (const Mat3& right)
{
  rune::Mat3 temp;

  temp[0][0] = this->row1[0] * right.row1[0] + this->row1[1] * right.row2[0] + this->row1[2] * right.row3[0];
  temp[0][1] = this->row1[0] * right.row1[1] + this->row1[1] * right.row2[1] + this->row1[2] * right.row3[1];
  temp[0][2] = this->row1[0] * right.row1[2] + this->row1[1] * right.row2[2] + this->row1[2] * right.row3[2];

  temp[1][0] = this->row2[0] * right.row1[0] + this->row2[1] * right.row2[0] + this->row2[2] * right.row3[0];
  temp[1][1] = this->row2[0] * right.row1[1] + this->row2[1] * right.row2[1] + this->row2[2] * right.row3[1];
  temp[1][2] = this->row2[0] * right.row1[2] + this->row2[1] * right.row2[2] + this->row2[2] * right.row3[2];

  temp[2][0] = this->row3[0] * right.row1[0] + this->row3[1] * right.row2[0] + this->row3[2] * right.row3[0];
  temp[2][1] = this->row3[0] * right.row1[1] + this->row3[1] * right.row2[1] + this->row3[2] * right.row3[1];
  temp[2][2] = this->row3[0] * right.row1[2] + this->row3[1] * right.row2[2] + this->row3[2] * right.row3[2];
  
  return temp;
}

/**
 * \param right The matrix to be divided by.
 * \return The result of the multiplication by the matrix inverse.
 */
rune::Mat3 rune::Mat3::operator/ (const Mat3& right)
{
  Mat3 temp = right;

  return *this * temp.invert();
}

/**
 * \param scalar The scalar value to be multiplied by.
 * \return An elementwise multiplication.
 */
rune::Mat3 rune::Mat3::operator/ (double scalar)
{

  Mat3 temp = *this;

  for (int i = 0; i < 3; i++)
  {
    temp.row1[i] = temp.row1[i] / scalar;
  }

  for (int i = 0; i < 3; i++)
  {
    temp.row2[i] = temp.row2[i] / scalar;
  }

  for (int i = 0; i < 3; i++)
  {
    temp.row3[i] = temp.row3[i] / scalar;
  }

  return temp;
}

/**
 * \param right The matrix to be subtracted by.
 * \return A reference to the modified matrix.
 */
rune::Mat3& rune::Mat3::operator-=(const Mat3& right)
{

  for (int i = 0; i < 3; i++)
  {
    this->row1[i] = this->row1[i] - right.row1[i];
  }

  for (int i = 0; i < 3; i++)
  {
    this->row2[i] = this->row2[i] - right.row2[i];
  }

  for (int i = 0; i < 3; i++)
  {
    this->row3[i] = this->row3[i] - right.row3[i];
  }

  return *this;
}

/**
 * \param right The matrix to be added.
 * \return A reference to the modified matrix.
 */
rune::Mat3& rune::Mat3::operator+=(const Mat3& right)
{
  for (int i = 0; i < 3; i++)
  {
    this->row1[i] = this->row1[i] + right.row1[i];
  }

  for (int i = 0; i < 3; i++)
  {
    this->row2[i] = this->row2[i] + right.row2[i];
  }

  for (int i = 0; i < 3; i++)
  {
    this->row3[i] = this->row3[i] + right.row3[i];
  }

  return *this;
}

/**
 * \param scalar The scalar to be added.
 * \return An elementwise addition.
 */
rune::Mat3& rune::Mat3::operator+=(const double scalar)
{
  for (int i = 0; i < 3; i++)
  {
    this->row1[i] = this->row1[i] + scalar;
  }

  for (int i = 0; i < 3; i++)
  {
    this->row2[i] = this->row2[i] + scalar;
  }

  for (int i = 0; i < 3; i++)
  {
    this->row3[i] = this->row3[i] + scalar;
  }

  return *this;
}

/**
 * \param right The matrix to be multiplied by.
 * \return A reference to the modified matrix.
 */
rune::Mat3& rune::Mat3::operator*=(const rune::Mat3& right)
{

  *this = *this * right;

  return *this;
}

/**
 * \param right The matrix to multiply by.
 * \return A member wise multiplication.
 */
rune::Mat3& rune::Mat3::operator*=(const double right)
{
  (*this) = (*this) * right;

  return *this;
}

/**
 * \param right The rune::Mat3 to compare to.
 * \return Whether or not the two matrices are equivalent.
 */
bool rune::Mat3::operator==(const rune::Mat3& right)
{
  for (int i = 0; i < 3; i++)
  {
    if(this->row1[i] != right.row1[i])
    {
      return false;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    if (this->row2[i] != right.row2[i])
    {
      return false;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    if (this->row3[i] != right.row3[i])
    {
      return false;
    }
  }

  return true;
}

/**
 * \param right The rune::Mat3 to compare to.
 * \return Whether or not the two matrices are non equivalent.
 */
bool rune::Mat3::operator!=(const rune::Mat3& right)
{
  for (int i = 0; i < 3; i++)
  {
    if (this->row1[i] != right.row1[i])
    {
      return true;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    if (this->row2[i] != right.row2[i])
    {
      return true;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    if (this->row3[i] != right.row3[i])
    {
      return true;
    }
  }

  return false;
}

/**
 * \param scalar The scalar to be multiplied by.
 * \return A memberwise multiplication.
 */
rune::Mat3 rune::Mat3::operator* (double scalar)
{
  Mat3 temp;

  for (int i = 0; i < 3; i++)
  {
    temp.row1[i] =  scalar * this->row1[i];
  }

  for (int i = 0; i < 3; i++)
  {
    temp.row2[i] = scalar * this->row2[i];
  }

  for (int i = 0; i < 3; i++)
  {
    temp.row3[i] = scalar * this->row3[i];
  }

  return temp;
}

/**
 * \param vec The vector to be multiplied with.
 * \return The result of the multiplication.
 */
rune::Vec3 rune::Mat3::operator*(const rune::Vec3& vec)
{
  
  rune::Mat3 mat = *this;
  double newX, newY, newZ;

  newX = (mat[0][0] * vec.x) + (mat[0][1] * vec.y) + (mat[0][2] * vec.z);
  newY = (mat[1][0] * vec.x) + (mat[1][1] * vec.y) + (mat[1][2] * vec.z);
  newZ = (mat[2][0] * vec.x) + (mat[2][1] * vec.y) + (mat[2][2] * vec.z);

  return rune::Vec3(newX,newY,newZ);
}

/**
 * \memberof rune::Mat3
 * \param os Output stream that the vector should be printed to.
 * \param mat mat to be printed.
 * \return Stream to be printed to the console.
 */
std::ostream& rune::operator<<(std::ostream& os, const rune::Mat3& mat)
{
  
  os << mat.row1[0] << "," << mat.row1[1] << "," << mat.row1[2] << std::endl;
  os << mat.row2[0] << "," << mat.row2[1] << "," << mat.row2[2] << std::endl;
  os << mat.row3[0] << "," << mat.row3[1] << "," << mat.row3[2] << std::endl;

  return os;
}

rune::Mat3 rune::operator*(double scalar, Mat3& mat)
{
  return mat*scalar;
}

/**
 * \return The inverted matrix, if invertible.
 */
rune::Mat3 rune::Mat3::invert()
{
  double determinant = this->determinant();

  if(determinant == 0)
    return Mat3();


  Mat3 transpose(this->row1[0], this->row2[0], this->row3[0], this->row1[1], this->row2[1], this->row3[1], this->row1[2], this->row2[2], this->row3[2]);

  Mat3 determinants;

  determinants[0][0] = rune::Mat2(transpose[1][1], transpose[1][2], transpose[2][1], transpose[2][2]).determinant();
  determinants[0][1] = -1*rune::Mat2(transpose[1][0], transpose[1][2], transpose[2][0], transpose[2][2]).determinant();
  determinants[0][2] = rune::Mat2(transpose[1][0], transpose[1][1], transpose[2][0], transpose[2][1]).determinant();

  determinants[1][0] = -1*rune::Mat2(transpose[0][1], transpose[0][2], transpose[2][1], transpose[2][2]).determinant();
  determinants[1][1] = rune::Mat2(transpose[0][0], transpose[0][2], transpose[2][0], transpose[2][2]).determinant();
  determinants[1][2] = -1*rune::Mat2(transpose[0][0], transpose[0][1], transpose[2][0], transpose[2][1]).determinant();

  determinants[2][0] = rune::Mat2(transpose[0][1], transpose[0][2], transpose[1][1], transpose[1][2]).determinant();
  determinants[2][1] = -1*rune::Mat2(transpose[0][0], transpose[0][2], transpose[1][0], transpose[1][2]).determinant();
  determinants[2][2] = rune::Mat2(transpose[0][0], transpose[0][1], transpose[1][0], transpose[1][1]).determinant();

  determinants /= determinant;
  
  return determinants;
}

/**
 * \param right The matrix to be divided by.
 * \return A reference to the modified matrix.
 */
rune::Mat3& rune::Mat3::operator/=(const Mat3& right)
{

  *this = *this / right;
  
  return *this;

}

/**
 * \param right The scalar to be divided by.
 * \return An element wise division.
 */
rune::Mat3& rune::Mat3::operator/=(const double right)
{
  *this = *this / right;

  return *this;
}

/**
 * \return The determinant of the matrix.
 */
double rune::Mat3::determinant()
{
  rune::Mat3 temp = *this;

  return temp[0][0] * rune::Mat2(temp[1][1], temp[1][2], temp[2][1], temp[2][2]).determinant() 
  - temp[0][1] * rune::Mat2(temp[1][0],temp[1][2],temp[2][0],temp[2][2]).determinant()
  + temp[0][2] * rune::Mat2(temp[1][0],temp[1][1],temp[2][0],temp[2][1]).determinant();

}

/**
 * \param index The element to be accessed.
 * \return The accessed element.
 */
double* rune::Mat3::operator[](int index)
{
  if(index == 0)
    return row1;
  if(index == 1)
    return row2;
  if(index == 2)
    return row3;
}