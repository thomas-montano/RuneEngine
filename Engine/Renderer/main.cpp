/*
  Main function used as a sandbox for the renderer

  This class provides a rectangle that can be rendered to a render window

  Thomas Montano
  4/25/20
*/

#include <string>
#include <iostream>
#include "sprite.h"
#include "renderWindow.h"
#include "event.h"
#include "rectangleShape.h"
#include "vec2.h"
#include "clock.h"

using namespace std;

int main(void)
{

  int width = 640;
  int height = 480;
  
  RenderWindow myWindow(width,height, "Render Window test");
  Event event;
  Clock myClock;

  
  Sprite mySprite(Vec2(128,256),Vec2(300,300),"./knoxIdleSheet.png");
  //RectangleShape myRectangle(Vec2(50,50),Vec2(64,128));

  while(myWindow.isOpen())
  {
    myWindow.clear();

    //Draw first triangle
    //myWindow.draw(myRectangle);
    myWindow.draw(mySprite);

    /* Swap front and back buffers */
    myWindow.display();

    /* Poll for and process events */
    myWindow.pollEvents(event);

    if(myWindow.isKeyPressed(GLFW_KEY_UP))
    {
      mySprite.addPosition(Vec2(0,10));
    }

    if(myWindow.isKeyPressed(GLFW_KEY_DOWN))
    { 
      mySprite.addPosition(Vec2(0,-10));
    }

    if(myWindow.isKeyPressed(GLFW_KEY_LEFT))
    {
      mySprite.addPosition(Vec2(-10,0));
    }

    if(myWindow.isKeyPressed(GLFW_KEY_RIGHT))
    {
      mySprite.addPosition(Vec2(10,0));
    }

  }

  return 0;

}