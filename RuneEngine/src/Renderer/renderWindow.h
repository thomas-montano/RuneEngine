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
#include "opengl.h"
#include "color.h"
#include <Events\event.h>
#include "vec2.h"
#include <string>

class Drawable;

class RUNE_ENGINE RenderWindow
{
private:
  bool windowOpen;
  int width, height;
  Event windowEvents;
  GLFWwindow* GLwindow;

public:
  ///Default constructor to give an openGL context and window.
  RenderWindow(int newWidth, int newHeight, std::string title);

  ///Renders a drawable to the screen.
  void draw(Drawable&);

  ///Determines if any window level events have happened.
  void pollEvents(Event& event);

  ///Display on screen what has been rendered to the window so far.
  void display(void);

  ///Clear the entire screen with a single color.
  void clear(Color);

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