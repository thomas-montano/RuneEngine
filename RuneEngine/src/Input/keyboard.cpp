#include "keyboard.h"

bool rune::Keyboard::isKeyPressed(Key key)
{

  if (glfwGetKey(rune::GameApplication::getWindow()->GetGLWindow(), key) == GLFW_PRESS)
  {
    return true;
  }
  return false;

}