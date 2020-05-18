#include "renderWindow.h"
#include "drawable.h"
#include <Input\keyboard.h>

/**
 * @param newWidth The width of the window in pixels to be created.
 * @param newHeight The height of the window in pixels to be created.
 * @param title The title of the window to be displayed at the top.
*/
rune::RenderWindow::RenderWindow(int newWidth, int newHeight, std::string title)
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

}

void rune::RenderWindow::display(void)
{

  glfwSwapBuffers(GLwindow);

}

void rune::RenderWindow::clear(rune::Color clearColor)
{

  glClearColor(clearColor.red/255.0, clearColor.green / 255.0, clearColor.blue / 255.0, clearColor.alpha / 255.0);
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