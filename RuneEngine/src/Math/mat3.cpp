#include "mat3.h"


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
  return *this;
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
  return *this;
}

rune::Mat3& rune::Mat3::operator+=(const Mat3& right)
{
  return *this;
}

rune::Mat3& rune::Mat3::operator*=(const rune::Mat3& right)
{
  return *this;
}

rune::Mat3& rune::Mat3::operator*=(const double right)
{
  return *this;
}

bool rune::Mat3::operator==(const rune::Mat3& right)
{
  return false;
}

bool rune::Mat3::operator!=(const rune::Mat3& right)
{
  return false;
}

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
 * @memberof rune::Mat3
 * 
 * \param scalar
 * \param mat
 * \return 
 */
rune::Mat3 operator*(double scalar, rune::Mat3 mat)
{
  rune::Mat3 temp;

  for (int i = 0; i < 3; i++)
  {
    temp[0][i] = scalar * mat[0][i];
  }

  for (int i = 0; i < 3; i++)
  {
    temp[1][i] = scalar * mat[1][i];
  }

  for (int i = 0; i < 3; i++)
  {
    temp[2][i] = scalar * mat[2][i];
  }

  return temp;
}

std::ostream& rune::operator<<(std::ostream& os, const rune::Mat3& mat)
{
  
  os << mat.row1[0] << "," << mat.row1[1] << "," << mat.row1[2] << std::endl;
  os << mat.row2[0] << "," << mat.row2[1] << "," << mat.row2[2] << std::endl;
  os << mat.row3[0] << "," << mat.row3[1] << "," << mat.row3[2] << std::endl;

  return os;
}

rune::Mat3 rune::invert(rune::Mat3)
{
  return Mat3();
}

double rune::Mat3::determinant()
{
  return 0.0;
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