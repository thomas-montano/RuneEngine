#include "color.h"

rune::Color rune::Color::Blue = rune::Color(0,1,0,1);

rune::Color::Color(double r, double g , double b , double a)
: red(r), green(g), blue(b), alpha(a)
{
  
}

rune::Color::Color() : red(1), green(1), blue(1), alpha(1)
{

}