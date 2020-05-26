#include "mat3.h"
#include "mat2.h"


rune::Mat3::Mat3() : row1{ 0,0,0 }, row2{ 0,0,0 }, row3{ 0,0,0 }
{

}

rune::Mat3::Mat3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) : row1{a11,a12,a13}, row2{a21,a22,a23}, row3{a31,a32,a33}
{

}

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

rune::Mat3 rune::Mat3::operator* (const Mat3& right)
{
  Mat3 temp;
  
  return temp;
}

rune::Mat3 rune::Mat3::operator/ (const Mat3& right)
{
  return *this;
}

rune::Mat3 rune::Mat3::operator/ (double scalar)
{
  return *this;
}

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

rune::Mat3& rune::Mat3::operator*=(const rune::Mat3& right)
{
  return *this;
}

/**
 * \param right The matrix to multiply by.
 * \return A memberwise multiplication.
 */
rune::Mat3& rune::Mat3::operator*=(const double right)
{
  *this = *this * right;

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
 * \param vector The vector to be multiplied with.
 * \param mat The rune::Mat3 to be multiplied by.
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
 * @memberof rune::Mat3
 * 
 * \param scalar
 * \param mat
 * \return 
 */
rune::Mat3 rune::operator*(double scalar, rune::Mat3 mat)
{
  return mat*scalar;
}

std::ostream& rune::operator<<(std::ostream& os, const rune::Mat3& mat)
{
  
  os << mat.row1[0] << "," << mat.row1[1] << "," << mat.row1[2] << std::endl;
  os << mat.row2[0] << "," << mat.row2[1] << "," << mat.row2[2] << std::endl;
  os << mat.row3[0] << "," << mat.row3[1] << "," << mat.row3[2] << std::endl;

  return os;
}

rune::Mat3 rune::Mat3::invert()
{
  double determinant = this->determinant();

  if(determinant == 0)
    return Mat3();

  
}

double rune::Mat3::determinant()
{
  rune::Mat3 temp = *this;

  return temp[0][0] * rune::Mat2(temp[1][1], temp[1][2], temp[2][1], temp[2][2]).determinant() 
  - temp[0][1] * rune::Mat2(temp[1][0],temp[1][2],temp[2][0],temp[2][2]).determinant()
  + temp[0][2] * rune::Mat2(temp[1][0],temp[1][1],temp[2][0],temp[2][1]).determinant();

}

double* rune::Mat3::operator[](int index)
{
  if(index == 0)
    return row1;
  if(index == 1)
    return row2;
  if(index == 2)
    return row3;
}