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
