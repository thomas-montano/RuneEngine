#include "renderWindow.h"

/**
 * @param newWidth The width of the window in pixels to be created.
 * @param newHeight The height of the window in pixels to be created.
 * @param title The title of the window to be displayed at the top.
*/
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

/**
 * @param keyCode The integer keycode of the key that's being tested.
 * @return Whether or not the key is being pressed.
*/
bool RenderWindow::isKeyPressed(unsigned int keyCode)
{
  if(glfwGetKey(GLwindow, keyCode)==GLFW_PRESS)
  {
    return true;
  }
  return false;
}

/**
 * @param event the Event object for the events to be stored in.
*/
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

/**
 * @return Whether or not the RenderWindow is currently open.
*/
bool RenderWindow::isOpen()
{
  if(!windowOpen)
  {
    glfwTerminate();
  }

  return windowOpen;
}

/**
 * @param drawObject Drawable that should be displayed on the screen.
*/
void RenderWindow::draw(Drawable& drawObject)
{
  drawObject.draw(Vec2(width,height));
}

/**
 * @return A Vec2 corresponding to the size in pixels of the RenderWindow.
*/
Vec2 RenderWindow::getSize()
{
  return Vec2(width,height);
}