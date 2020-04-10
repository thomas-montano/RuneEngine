#include "gameUI.h"

void GameUI::createButton(float posX, float posY, float width, float height)
{

  m_posX = posX;
  m_posY = posY;
  m_height = height;
  m_width = width;


  if(!m_objectTexture.loadFromFile("./Assets/Images/button-Sheet.png"))
  {

    m_objectTexture.loadFromFile("./Assets/Images/textureFailure.png");
    m_uiObject.setTexture(m_objectTexture);

  }else
  {
    m_uiObject.setTexture(m_objectTexture);
    m_uiObject.setTextureRect(sf::IntRect(0,0,120,60));
  }

  m_uiObject.setPosition(sf::Vector2f(m_posX,m_posY));

}

sf::Sprite GameUI::getDrawable(void)
{

  return m_uiObject;

}

bool GameUI::isClicked(sf::Vector2i mouseLocation, sf::Event mouseEvent)
{

  int My = mouseLocation.y;
  int Mx = mouseLocation.x;

  sf::RenderWindow* window = MessageManager::getWindow();

  int xPos = window->mapCoordsToPixel(sf::Vector2f(m_posX,0)).x;
  int yPos = window->mapCoordsToPixel(sf::Vector2f(0,m_posY)).y;

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
  if(Mx > xPos &&
      Mx < xPos + m_width &&
      My > yPos &&
      My < yPos + m_height &&
      !sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    m_uiObject.setTextureRect(sf::IntRect(120,0,120,60));
  }else if(Mx > xPos &&
      Mx < xPos + m_width &&
      My > yPos &&
      My < yPos + m_height &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    m_uiObject.setTextureRect(sf::IntRect(240,0,120,60));
  }
  else
  {
    m_uiObject.setTextureRect(sf::IntRect(0,0,120,60));
  }

  //If the user clickes over the button, m_clickedDown = true
  if(mouseEvent.type == sf::Event::MouseButtonPressed)
  {
    if(Mx > xPos &&
        Mx < xPos + m_width &&
        My > yPos &&
        My < yPos + m_height &&
        mouseEvent.mouseButton.button == sf::Mouse::Left)
    {
      m_clickedDown = true;
    }

  }

  //If the user lets go of the mouse over the button m_clickedUp = true
  if(mouseEvent.type == sf::Event::MouseButtonReleased)
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
  }

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
