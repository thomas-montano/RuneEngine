#include "color.h"

rune::Color rune::Color::Red = rune::Color(255, 0, 0, 255);
rune::Color rune::Color::Blue = rune::Color(0,0, 255,255);
rune::Color rune::Color::Green = rune::Color(0, 255, 0, 255);
rune::Color rune::Color::Black = rune::Color(0, 0, 0, 255);
rune::Color rune::Color::White = rune::Color(255, 255, 255, 255);
rune::Color rune::Color::Yellow = rune::Color(255, 255, 25, 255);
rune::Color rune::Color::Magenta = rune::Color(255, 0, 255, 255);
rune::Color rune::Color::Cyan = rune::Color(0, 255, 255, 255);
rune::Color rune::Color::Transparent = rune::Color(0, 0, 0, 0);

rune::Color::Color(double r, double g , double b , double a)
  : red(r), green(g), blue(b), alpha(a)
{
  
}

rune::Color::Color() : red(255), green(255), blue(255), alpha(255)
{

}