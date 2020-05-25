#include "rectangleShape.h"
#include "shader.h"
#include <math\mat2.h>
#include <Renderer\camera.h>
#include <GL\glew.h>
#include <GL\glu.h>
#include <GLFW\glfw3.h>
#include <iostream>

rune::RectangleShape::RectangleShape() : rectangleShader("./RuneEngine/src/Shaders/rectangle.shader"), position(rune::Vec2(0,0)), size(rune::Vec2(0,0)), origin(rune::Vec2(0,0))
{
  setUpBuffers();
}

/**
 * @param newPosition The position of the new RectangleShape with respect to the bottom left corner.
 * @param newSize The size of the new RectangleShape.
*/
rune::RectangleShape::RectangleShape(rune::Vec2 newPosition, rune::Vec2 newSize) : rectangleShader("./RuneEngine/src/Shaders/rectangle.shader"), position(newPosition), size(newSize), origin(rune::Vec2(0, 0))
{

  setUpBuffers();

}

void rune::RectangleShape::setUpBuffers()
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
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // color attribute
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
  glEnableVertexAttribArray(1);

}

/**
 * @param windowSize The size of the window that the RectangleShape is being drawn on.
*/
void rune::RectangleShape::draw(rune::RenderWindow& window)
{

  //Bind the vertex array object
  rectangleShader.bind();

  origin = rune::Vec2(size.x / 2.0, size.y /2.0);

  rune::Vec2 windowSize = window.getSize();
  rune::Vec2 cameraPos = rune::Camera::getCenter();
  double zoomLevel = rune::Camera::getZoom();

  //Set up camera data for shader
  rectangleShader.setUniform4f("cameraPos", zoomLevel * cameraPos.x / windowSize.x, zoomLevel * cameraPos.y / windowSize.y, 0, 0);

  rune::Mat2 drawMatrix((position.x + size.x - origin.x) / windowSize.x, (position.y + size.y - origin.y) / windowSize.y,
    (position.x - origin.x) / windowSize.x, (position.y - origin.y) / windowSize.y);

  drawMatrix *= zoomLevel;

  const float drawVertices[32] =
  {
    // positions                              // colors and alpha
    drawMatrix[0][0],   drawMatrix[0][1],     shapeColor.red / 255.0, shapeColor.green / 255.0, shapeColor.blue / 255.0, shapeColor.alpha / 255.0,
    drawMatrix[0][0],   drawMatrix[1][1],     shapeColor.red / 255.0, shapeColor.green / 255.0, shapeColor.blue / 255.0, shapeColor.alpha / 255.0,
    drawMatrix[1][0],   drawMatrix[1][1],     shapeColor.red / 255.0, shapeColor.green / 255.0, shapeColor.blue / 255.0, shapeColor.alpha / 255.0,
    drawMatrix[1][0],   drawMatrix[0][1],     shapeColor.red / 255.0, shapeColor.green / 255.0, shapeColor.blue / 255.0, shapeColor.alpha / 255.0,
  };

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(drawVertices), drawVertices, GL_DYNAMIC_DRAW);

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

/**
 * @param newPos The new position of the RectangleShape with respect to the bottom left corner.
*/
void rune::RectangleShape::addPosition(rune::Vec2 newPos)
{
  position.x += newPos.x;
  position.y += newPos.y;
}

/**
 * @param newSize The new size of the RectangleShape.
*/
void rune::RectangleShape::setPosition(rune::Vec2 newSize)
{
  position.x = newSize.x;
  position.y = newSize.y;
}

void rune::RectangleShape::setSize(rune::Vec2 newSize)
{
  size = newSize;
}

void rune::RectangleShape::setFillColor(rune::Color newColor)
{
  shapeColor = newColor;
}