
//#define IMGUI_IMPL_OPENGL_LOADER_GLEW

#include "renderWindow.h"
#include "drawable.h"
#include <GL\glew.h>
#include <GL\glu.h>
#include <GLFW\glfw3.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"
#include <Input\keyboard.h>

/**
 * @param newWidth The width of the window in pixels to be created.
 * @param newHeight The height of the window in pixels to be created.
 * @param title The title of the window to be displayed at the top.
*/
rune::RenderWindow::RenderWindow(int newWidth, int newHeight, std::string title)
{
  
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

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

  glClearColor(0.0f,0.0f,0.0f,0.0f);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

  //Setup IMGUI
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(GLwindow, true);
  ImGui_ImplOpenGL3_Init((char*)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));

}

rune::RenderWindow::~RenderWindow(void)
{

  //Shutdown
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();

  ImGui::DestroyContext();

}


/**
 * \param newTitle The title that should be displayed on the window.
 */
void rune::RenderWindow::setWindowTitle(std::string newTitle)
{
  glfwSetWindowTitle(GLwindow,newTitle.c_str());
}

/**
 * \return A pointer for the GLFW window.
 */
GLFWwindow* rune::RenderWindow::GetGLWindow()
{
  return GLwindow;
}

rune::Vec2 rune::RenderWindow::getDesktopSize(void)
{
  const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

  return rune::Vec2(mode->width, mode->height);
}

void rune::RenderWindow::maximizeWindow(void)
{
  glfwMaximizeWindow(GLwindow);
}

/**
 * @param event the Event object for the events to be stored in.
*/
void rune::RenderWindow::pollEvents(rune::Event& event)
{

  glfwPollEvents();

  if(glfwWindowShouldClose(GLwindow))
  {
    event.type = rune::EventType::WindowClose;
    windowOpen = false;
  }
  
  //Handling window resizing, make this better

  glfwGetWindowSize(GLwindow,&width,&height);

  glViewport(0, 0, width, height);



}

void rune::RenderWindow::display(void)
{

  glfwSwapBuffers(GLwindow);

}

/**
 * \param clearColor The color that the screen should be cleared with.
 */
void rune::RenderWindow::clear(rune::Color clearColor)
{
  const double MAXCOLOR = 255;

  glClearColor(clearColor.red/ MAXCOLOR, clearColor.green / MAXCOLOR, clearColor.blue / MAXCOLOR, clearColor.alpha / MAXCOLOR);
  glClear(GL_COLOR_BUFFER_BIT);
}

/**
 * @return Whether or not the RenderWindow is currently open.
*/
bool rune::RenderWindow::isOpen()
{
  if(!windowOpen)
  {
    glfwTerminate();
  }

  return windowOpen;
}

void rune::RenderWindow::close(void)
{
  glfwSetWindowShouldClose(GLwindow, true);
}

/**
 * @param drawObject Drawable that should be displayed on the screen.
*/
void rune::RenderWindow::draw(Drawable& drawObject)
{
  drawObject.draw(*this);
}

/**
 * @return A rune::Vec2 corresponding to the size in pixels of the RenderWindow.
*/
rune::Vec2 rune::RenderWindow::getSize()
{
  return rune::Vec2(width,height);
}

/**
 * @param enable Whether or not Vsync should be turned on.
*/
void rune::RenderWindow::enableVsync(bool enable)
{ 
  if(enable)
  {
    glfwSwapInterval(1);
  }
  else
  {
    glfwSwapInterval(0);
  }
  
}