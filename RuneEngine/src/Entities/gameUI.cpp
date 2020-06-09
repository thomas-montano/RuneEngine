#include "gameUI.h"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>
#include <gameApplication.h>

rune::GameUI::GameUI() : m_height(0), m_width(0), m_posX(0), m_posY(0)
{

}

/**
 * @param posX Horizontal position relative to the bottom left corner of the button to place the button on the screen.
 * @param posY Vertical position relative to the bottom left corner of the button to place the button on the screen.
 * @param width The width of the button in pixels.
 * @param height The height of the button in pixels.
*/
void rune::GameUI::createButton(double posX, double posY, double width, double height)
{

  m_posX = posX;
  m_posY = posY;
  m_height = height;
  m_width = width;


  /*if(!m_objectTexture.loadFromFile("./Assets/Images/button-Sheet.png"))
  {

    

  }else
  {
    //m_uiObject.setTexture(m_objectTexture);
    //m_uiObject.setTextureRect(IntRect(0,0,120,60));
  }*/

  //m_uiObject.setTexture("./Assets/Images/ball.png");
  //m_uiObject.setPosition(rune::Vec2(m_posX,m_posY));
  //m_uiObject.setSize(rune::Vec2(width,height));

}

/**
 * @param mouseLocation The location at which the mouse button was clicked.
 * @param mouseEvent The event triggered by the mouse click.
 * @return Whether or not the button was clicked.
*/
bool rune::GameUI::isClicked(rune::Vec2 mouseLocation, rune::Event mouseEvent)
{

  double My = mouseLocation.y;
  double Mx = mouseLocation.x;

  RenderWindow* window = rune::GameApplication::getWindow();

  //int xPos = window->mapCoordsToPixel(Vector2f(m_posX,0)).x;
  //int yPos = window->mapCoordsToPixel(Vector2f(0,m_posY)).y;

  bool clicked = false;

  //m_clickedDown is if the user clicks while over the button
  //m_clickedUp is if the user let go of the button while over the mouse


  /*

  if the user clicked down while over the button, and let
  go of the mouse click while over the button, return true
  m_uiObject.setTextureRect(sf::IntRect(120,0,120,60));

  Mx > m_posX &&
      Mx < m_posX + m_width &&
      My > m_posY &&
      My < m_posY + m_height

  */

  //This if statement is just for handling texture
  /*if(Mx > xPos &&
      Mx < xPos + m_width &&
      My > yPos &&
      My < yPos + m_height &&
      !Mouse::isButtonPressed(Mouse::Left))
  {
    m_uiObject.setTextureRect(IntRect(120,0,120,60));
  }else if(Mx > xPos &&
      Mx < xPos + m_width &&
      My > yPos &&
      My < yPos + m_height &&
      Mouse::isButtonPressed(Mouse::Left))
  {
    m_uiObject.setTextureRect(IntRect(240,0,120,60));
  }
  else
  {
    m_uiObject.setTextureRect(sf::IntRect(0,0,120,60));
  }*/

  //If the user clickes over the button, m_clickedDown = true
  /*if(mouseEvent.type == Event::MouseButtonPressed)
  {
    if(Mx > xPos &&
        Mx < xPos + m_width &&
        My > yPos &&
        My < yPos + m_height &&
        mouseEvent.mouseButton.button == Mouse::Left)
    {
      m_clickedDown = true;
    }

  }

  //If the user lets go of the mouse over the button m_clickedUp = true
  if(mouseEvent.type == Event::MouseButtonReleased)
  {
    if(Mx > xPos &&
        Mx < xPos + m_width &&
        My > yPos &&
        My < yPos + m_height &&
        mouseEvent.mouseButton.button == sf::Mouse::Left)
    {
      m_clickedUp = true;
    }

  }

  //Reset the booleans if the user moves away from the button
  if(!(Mx > xPos &&
      Mx < xPos + m_width &&
      My > yPos &&
      My < yPos + m_height))
  {
    m_clickedDown = false;
    m_clickedUp = false;
  }*/

  /*if the user clicked down while over the button, and let
  go of the mouse click while over the button, return true*/
  if(m_clickedUp == true && m_clickedDown == true)
  {
    m_clickedDown = false;
    m_clickedUp = false;
    return true;
  }
  else
  {
    return false;
  }
  
}

void rune::GameUI::draw(RenderWindow& window)
{

  window.draw(m_uiObject);

}
