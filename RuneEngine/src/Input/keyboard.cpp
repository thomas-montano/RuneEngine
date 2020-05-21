#include "keyboard.h"
#include <GL\glew.h>
#include <GL\glu.h>
#include <GLFW\glfw3.h>

bool rune::Keyboard::isKeyPressed(Key key)
{

  if (glfwGetKey(rune::GameApplication::getWindow()->GetGLWindow(), key) == GLFW_PRESS)
  {
    return true;
  }
  return false;

}