#include "renderWindow.h"

RenderWindow::RenderWindow(int newWidth, int newHeight, std::string title)
{
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  
  glfwInit();

  windowOpen = true;
  width = newWidth;
  height = newHeight;

  GLwindow = glfwCreateWindow(width, height, title.c_str(), NULL,NULL);

  if(!GLwindow)
  {
    glfwTerminate();
  }

  glfwMakeContextCurrent(GLwindow);

  glewInit();

  glClearColor(1.0f,1.0f,1.0f,1.0f);

}

bool RenderWindow::isKeyPressed(unsigned int keyCode)
{
  if(glfwGetKey(GLwindow, keyCode)==GLFW_PRESS)
  {
    return true;
  }
  return false;
}

void RenderWindow::pollEvents(Event& event)
{

  glfwPollEvents();

  if(glfwWindowShouldClose(GLwindow))
  {
    event.type = Closed;
    windowOpen = false;
  }

  if(glfwGetKey(GLwindow, GLFW_KEY_ESCAPE)==GLFW_PRESS)
  {
    glfwSetWindowShouldClose(GLwindow,true);
  }

}

void RenderWindow::display(void)
{

  glfwSwapBuffers(GLwindow);

}

void RenderWindow::clear(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
}

bool RenderWindow::isOpen()
{
  if(!windowOpen)
  {
    glfwTerminate();
  }

  return windowOpen;
}

void RenderWindow::draw(Drawable& drawObject)
{
  drawObject.draw(Vec2(width,height));
}

Vec2 RenderWindow::getSize()
{
  return Vec2(width,height);
}