/**
 * @class RenderWindow
 * @brief A window that the game can be drawn to.
 * 
 * @author Thomas Montano
 * @date April 20 2020
*/

#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include "core.h"
#include <GL\glew.h>
#include <GL\glu.h>
#include <GLFW\glfw3.h>
#include "drawable.h"
#include <Events\event.h>
#include "vec2.h"
#include <string>

class RUNE_ENGINE RenderWindow
{
private:
  bool windowOpen;
  int width, height;
  Event windowEvents;
  GLFWwindow* GLwindow;

  unsigned int VBO;
public:
  ///Default constructor to give an openGL context and window.
  RenderWindow(int newWidth, int newHeight, std::string title);

  ///Renders a drawable to the screen.
  void draw(Drawable&);

  ///Determines whether a key has been pressed.
  bool isKeyPressed(unsigned int keyCode);

  ///Determines if any window level events have happened.
  void pollEvents(Event& event);

  ///Display on screen what has been rendered to the window so far.
  void display(void);

  ///Clear the entire screen with a single color.
  void clear(void);

  ///Tell whether or not the window is open.
  bool isOpen(void);

  ///Gets the current size of the RenderWindow.
  Vec2 getSize(void);

  ///Enables or disables Vsync.
  void enableVsync(bool enable);

  ///Close the window
  void close(void);

};

#endif