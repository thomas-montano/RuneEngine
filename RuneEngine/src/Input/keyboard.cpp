#include "keyboard.h"

GLFWwindow* rune::Keyboard::window = nullptr;

bool rune::Keyboard::isKeyPressed(Key key)
{

  if (glfwGetKey(window, key) == GLFW_PRESS)
  {
    return true;
  }
  return false;

}

void rune::Keyboard::SetWindow(GLFWwindow* newWindow)
{

  window = newWindow;

}