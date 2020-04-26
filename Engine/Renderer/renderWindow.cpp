#include "renderWindow.h"
#include "drawable.h"
#include <iostream>

unsigned int CompileShader(unsigned int type, const std::string& source)
{
  unsigned int id = glCreateShader(type);
  const char* src = source.c_str();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  //Error handling
  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);

  if(result == GL_FALSE)
  {
    int length;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
    char* message= (char*)alloca(length * sizeof(char));
    glGetShaderInfoLog(id, length, &length, message);
    std::cout << "Shader failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
    std::cout << message << std::endl;
    glDeleteShader(id);
    return 0;
  }

  return id;
}

unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{

  unsigned int program = glCreateProgram();
  unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  glAttachShader(program,vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);

  return program;

}

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

  //Shader code GLSL
  std::string vertexShader = 
    "#version 330 core\n"
    "\n"
    "layout(location = 0) in vec4 position;\n"
    "\n"
    "void main()\n"
    "{\n"
    " gl_Position = position;\n"
    "}\n";

  std::string fragmentShader = 
    "#version 330 core\n"
    "\n"
    "layout(location = 0) out vec4 color;\n"
    "\n"
    "void main()\n"
    "{\n"
    " color = vec4(0.0,0.0,1.0,1.0);\n"
    "}\n";

  unsigned int shader = CreateShader(vertexShader, fragmentShader);
  glUseProgram(shader);

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