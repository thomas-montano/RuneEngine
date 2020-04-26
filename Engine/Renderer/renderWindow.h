/**
 * @class RenderWindow
 * @brief A window that the game can be drawn to.
 * 
 * @author Thomas Montano
 * @date April 20 2020
*/

#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include "drawable.h"
#include "event.h"
#include "vec2.h"
#include <string>

class RenderWindow
{
private:
  bool windowOpen;
  int width, height;
  Event windowEvents;
  GLFWwindow* GLwindow;

  unsigned int VBO;
public:
  RenderWindow(int newWidth, int newHeight, std::string title);

  void draw(Drawable&);

  bool isKeyPressed(unsigned int keyCode);

  void pollEvents(Event& event);

  void display(void);

  void clear(void);

  bool isOpen();

  Vec2 getSize();

};

#endif