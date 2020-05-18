#include "mat2.h"

rune::Mat2::Mat2()
{

}

rune::Mat2::Mat2(double newRow1[2], double newRow2[2])
{

}

rune::Mat2 rune::Mat2::operator- (const rune::Mat2& right)
{

  return *this;
}

rune::Mat2 rune::Mat2::operator+ (const rune::Mat2& right)
{

  return *this;
}

rune::Mat2 rune::Mat2::operator* (const rune::Mat2& right)
{

  return *this;
}

rune::Mat2 rune::Mat2::operator/ (const rune::Mat2& right)
{

  return *this;
}

rune::Mat2& rune::Mat2::operator-=(const rune::Mat2& right)
{

  return *this;
}

rune::Mat2& rune::Mat2::operator+=(const rune::Mat2& right)
{

  return *this;
}

rune::Mat2& rune::Mat2::operator*=(const rune::Mat2& right)
{

  return *this;
}

rune::Mat2& rune::Mat2::operator*=(const double right)
{

  return *this;
}

bool rune::Mat2::operator==(const Mat2& right)
{

  return false;
}

bool rune::Mat2::operator!=(const rune::Mat2& right)
{

  return false;
}

rune::Mat2 rune::operator* (double scalar, rune::Mat2& mat)
{

  return Mat2();
}

rune::Mat2 rune::operator* (Mat2& vec, double scalar)
{

  return Mat2();
}

std::ostream& operator<<(std::ostream& os, const rune::Mat2& vector)
{

  return os;
}
