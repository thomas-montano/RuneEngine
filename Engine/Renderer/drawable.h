#ifndef DRAWABLE_DEFINED
#define DRAWABLE_DEFINED

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "vec2.h"

class RenderWindow;

class Drawable
{

public:
  virtual void draw(Vec2 windowSize) = 0;

};

#endif