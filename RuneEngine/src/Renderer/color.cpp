#include "color.h"

Color Color::Blue = Color(0,1,0,1);

Color::Color(double r, double g , double b , double a)
: red(r), green(g), blue(b), alpha(a)
{
  
}

Color::Color() : red(1), green(1), blue(1), alpha(1)
{

}