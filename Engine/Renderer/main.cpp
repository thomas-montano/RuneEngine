/*
  Main function used as a sandbox for the renderer

  This class provides a rectangle that can be rendered to a render window

  Thomas Montano
  4/25/20
*/

#include <string>
#include <iostream>
#include "renderWindow.h"
#include "event.h"
#include "rectangleShape.h"
#include "vec2.h"

using namespace std;

int main(void)
{

  int width = 640;
  int height = 480;
  
  RenderWindow myWindow(width,height, "Render Window test");
  Event event;

  RectangleShape myRectangle(Vec2(50,50),Vec2(100,100));
  
  while(myWindow.isOpen())
  {
    myWindow.clear();

    //Draw first triangle
    myWindow.draw(myRectangle);

    /* Swap front and back buffers */
    myWindow.display();

    /* Poll for and process events */
    myWindow.pollEvents(event);

    if(myWindow.isKeyPressed(GLFW_KEY_UP))
    {
      myRectangle.addPosition(Vec2(0,10));
    }

    if(myWindow.isKeyPressed(GLFW_KEY_DOWN))
    {
      myRectangle.addPosition(Vec2(0,-10));
    }

    if(myWindow.isKeyPressed(GLFW_KEY_LEFT))
    {
      myRectangle.addPosition(Vec2(-10,0));
    }

    if(myWindow.isKeyPressed(GLFW_KEY_RIGHT))
    {
      myRectangle.addPosition(Vec2(10,0));
    }

  }

  return 0;

}