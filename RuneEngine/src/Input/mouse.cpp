#include "mouse.h"
#include <GLFW\glfw3.h>
#include <gameApplication.h>

bool rune::Mouse::isButtonPressed(Button button)
{
    if(GLFW_PRESS == glfwGetMouseButton(rune::GameApplication::getWindow()->GetGLWindow(), button))
    {
      return true;
    }

    return false;
}

rune::Vec2 rune::Mouse::getPosition(void)
{
  double xpos, ypos;
  
  glfwGetCursorPos(rune::GameApplication::getWindow()->GetGLWindow(), &xpos, &ypos);

  return rune::Vec2(xpos,-1 * (ypos - rune::GameApplication::getWindow()->getSize().y));
}
