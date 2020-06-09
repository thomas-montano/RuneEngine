#include "sprite.h"
#include <GL\glew.h>
#include <GL\glu.h>
#include <GLFW\glfw3.h>
#include <gameApplication.h>
#include <Renderer\camera.h>
#include <Math\mat2.h>

rune::Sprite::Sprite() :  origin(rune::Vec2(0, 0))
{
  spriteShader.makeNewShader(defaultShader);
  this->setUpBuffers();

}

/**
 * @param dimensions A rune::Vec2 specifying the size of the sprite.
 * @param position A rune::Vec2 specifying the location of the sprite with respect to the bottom left corner.
 * @param spriteLocation A filepath for the sprite .png file to be drawn.
*/
rune::Sprite::Sprite(std::string spriteLocation) : spriteTexture(spriteLocation.c_str()), origin(rune::Vec2(0,0))
{
  spriteShader.makeNewShader(defaultShader);
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

void rune::Sprite::start()
{

}

void rune::Sprite::update()
{

  rune::GameApplication::getWindow()->draw(*this);

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

  rune::Vec3 position = parentObject->transform.getPosition();
  rune::Vec3 size = parentObject->transform.getScale();

  //Set up camera data for shader
  spriteShader.setUniform4f("cameraPos", zoomLevel * cameraPos.x / windowSize.x, zoomLevel * cameraPos.y / windowSize.y, 0, 0);

  rune::Mat2 drawMatrix((position.x + size.x - origin.x) / windowSize.x, (position.y + size.y - origin.y) / windowSize.y,
                        (position.x - origin.x) / windowSize.x,            (position.y - origin.y) / windowSize.y);

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

void rune::Sprite::setOrigin(rune::Vec2 newOrigin)
{
  origin = newOrigin;
}

void rune::Sprite::setTexture(std::string texture)
{

  spriteTexture.loadFromFile(texture.c_str());

}