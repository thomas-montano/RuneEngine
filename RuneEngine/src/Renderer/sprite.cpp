#include "sprite.h"
#include <Renderer\camera.h>
#include <Math\mat2.h>

rune::Sprite::Sprite() : spriteShader("./RuneEngine/src/Shaders/sprite.shader"), origin(rune::Vec2(0, 0))
{

  this->setUpBuffers();

}

/**
 * @param dimensions A rune::Vec2 specifying the size of the sprite.
 * @param position A rune::Vec2 specifying the location of the sprite with respect to the bottom left corner.
 * @param spriteLocation A filepath for the sprite .png file to be drawn.
*/
rune::Sprite::Sprite(rune::Vec2 dimensions,rune::Vec2 position, std::string spriteLocation) : m_position(position), m_size(dimensions),spriteTexture(spriteLocation.c_str()), spriteShader("./RuneEngine/src/Shaders/sprite.shader"), origin(rune::Vec2(0,0))
{
  
  this->setUpBuffers();

}

void rune::Sprite::setUpBuffers()
{

  //Generate and bind vertex array object
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  //Generate and bind the vertices array in the buffer
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // color attribute
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(2 * sizeof(float)));
  glEnableVertexAttribArray(1);
  // texture coord attribute
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);

}

/**
 * @param windowSize The window that the sprite is being drawn to.
*/
void rune::Sprite::draw(rune::RenderWindow& window)
{

  //Bind the vertex array object
  spriteTexture.bind();
  spriteShader.bind();
  
  rune::Vec2 windowSize = window.getSize();
  rune::Vec2 cameraPos = rune::Camera::getCenter();
  double zoomLevel = rune::Camera::getZoom();

  //Set up camera data for shader
  spriteShader.setUniform4f("cameraPos", zoomLevel * cameraPos.x / windowSize.x, zoomLevel * cameraPos.y / windowSize.y, 0, 0);

  rune::Mat2 drawMatrix((m_position.x + m_size.x - origin.x) / windowSize.x, (m_position.y + m_size.y - origin.y) / windowSize.y,
                        (m_position.x - origin.x) / windowSize.x,            (m_position.y - origin.y) / windowSize.y);

  drawMatrix *= zoomLevel;



  const float drawVertices[32] = 
  {
    // positions                              // colors and alpha         // texture coords
    drawMatrix[0][0],   drawMatrix[0][1],     1.0f, 1.0f, 1.0f, 1.0f,     1.0f, 1.0f, // top right
    drawMatrix[0][0],   drawMatrix[1][1],     1.0f, 1.0f, 1.0f, 1.0f,     1.0f, 0.0f, // bottom right
    drawMatrix[1][0],   drawMatrix[1][1],     1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 0.0f, // bottom left
    drawMatrix[1][0],   drawMatrix[0][1],     1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 1.0f  // top left 
  };

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER,VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(drawVertices), drawVertices, GL_DYNAMIC_DRAW);

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  spriteTexture.unbind();

}

/**
 * @param newPos The new position of the RectangleShape with respect to the bottom left corner.
*/
void rune::Sprite::addPosition(rune::Vec2 newPos)
{
  m_position.x += newPos.x;
  m_position.y += newPos.y;
}

/**
 * @param newSize The new size of the RectangleShape.
*/
void rune::Sprite::setPosition(rune::Vec2 newSize)
{
  m_position = newSize;
}

void rune::Sprite::setOrigin(rune::Vec2 newOrigin)
{
  origin = newOrigin;
}

void rune::Sprite::setTexture(std::string texture)
{

  spriteTexture.loadFromFile(texture.c_str());

}

void rune::Sprite::setSize(rune::Vec2 newSize)
{
  m_size = newSize;
}

rune::Vec2 rune::Sprite::getPosition(void)
{
  return m_position;
}

rune::Vec2 rune::Sprite::getSize(void)
{
  return m_size;
}