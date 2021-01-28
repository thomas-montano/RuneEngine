#include "mouse.h"
#include <GLFW\glfw3.h>
#include <gameApplication.h>

bool rune::Mouse::isButtonPressed(Button button)
{
    if(GLFW_PRESS == glfwGetMouseButton(getGameInstance()->getWindow()->GetGLWindow(), button))
    {
      return true;
    }

    return false;
}

rune::Vec2 rune::Mouse::getPosition(void)
{
  double xpos, ypos;
  
  glfwGetCursorPos(getGameInstance()->getWindow()->GetGLWindow(), &xpos, &ypos);

  return rune::Vec2(xpos,-1 * (ypos - getGameInstance()->getWindow()->getSize().y));
}

void rune::Mouse::setPosition(rune::Vec2 newPosition)
{
  glfwSetCursorPos(getGameInstance()->getWindow()->GetGLWindow(), newPosition.x, getGameInstance()->getWindow()->getSize().y - newPosition.y);
}
