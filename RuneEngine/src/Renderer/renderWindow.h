/**
 * @class rune::RenderWindow
 * @brief A window that the game can be drawn to.
 * 
 * @author Thomas Montano
 * @date April 20 2020
*/

#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include "core.h"
#include "color.h"
#include <vector>
#include "Math\vec2.h"
#include <Renderer\camera.h>
#include <string>

struct GLFWwindow;

namespace rune{

class Drawable;

class RUNE_ENGINE RenderWindow
{
private:
  bool windowOpen;
  int width, height;
  GLFWwindow* GLwindow;

  Camera* windowCamera;

  ///Resize the drawing area if the window is resized
  static void onWindowResize(GLFWwindow* window, int width, int height);

public:
  ///Get the camera currently being used by the scene.
  Camera getCamera(void);
  ///Set a camera to be used by the scene.
  void setCamera(Camera&);  
  ///Default constructor to give an openGL context and window.
  RenderWindow(int newWidth, int newHeight, std::string const& title);
  ///Destructor to handle window clean up.
  ~RenderWindow(void);
  ///Renders a drawable to the screen.
  void draw(Drawable&);
  ///Set the window title.
  void setWindowTitle(std::string const&);
  ///Display on screen what has been rendered to the window so far.
  void display(void);
  ///Clear the entire screen with a single color.
  void clear(rune::Color);
  ///Tell whether or not the window is open.
  bool isOpen(void);
  ///Gets the current size of the RenderWindow.
  rune::Vec2 getSize(void);
  ///Enables or disables Vsync.
  void enableVsync(bool enable);
  ///Close the window
  void close(void);
  ///Return a pointer to the OpenGL window.
  GLFWwindow* GetGLWindow();
  ///Returns the size of the current monitor in pixels
  static rune::Vec2 getDesktopSize(void);
  ///Maximize the currently open window
  void maximizeWindow(void);

};
}

#endif