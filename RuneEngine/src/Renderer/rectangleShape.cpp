#include "rectangleShape.h"
#include "shader.h"
#include <iostream>

rune::RectangleShape::RectangleShape() : rectangleShader("./RuneEngine/src/Shaders/rectangle.shader")
{

}

/**
 * @param newPosition The position of the new RectangleShape with respect to the bottom left corner.
 * @param newSize The size of the new RectangleShape.
*/
rune::RectangleShape::RectangleShape(rune::Vec2 newPosition, rune::Vec2 newSize) : rectangleShader("./RuneEngine/src/Shaders/rectangle.shader")
{
  position = newPosition;
  size = newSize;  

  vertices[0] = rune::Vec2(position.x, position.y+size.y);
  vertices[1] = rune::Vec2(position.x + size.x, position.y+size.y);
  vertices[2] = rune::Vec2(position.x + size.x, position.y);
  vertices[3] = rune::Vec2(position.x, position.y);

  //Generate and bind vertex array object
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  //Generate and bind the vertices array in the buffer
  glGenBuffers(1,&buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);

  // Set vertex attribute pointer and enable buffer
  glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(double)*2,(void*)0);
  glEnableVertexAttribArray(0);

}

/**
 * @param windowSize The size of the window that the RectangleShape is being drawn on.
*/
void rune::RectangleShape::draw(rune::RenderWindow& window)
{

  rune::Vec2 windowSize = window.getSize();
  const int vertexes = 12;

  //Set the current shader to the rectangle shader
  rectangleShader.bind();

  //Bind the vertex array object
  glBindVertexArray(VAO);

  //Update vertex data
  double drawVertices[vertexes] = 
  {

    position.x/windowSize.x-1, position.y/windowSize.y-1,
    position.x/windowSize.x-1, (position.y+ size.y)/windowSize.y-1,
    (position.x + size.x)/windowSize.x-1, (position.y+ size.y)/windowSize.y-1,
    position.x/windowSize.x-1, position.y/windowSize.y-1,
    (position.x + size.x)/windowSize.x-1, (position.y+ size.y)/windowSize.y-1,
    (position.x+size.x)/windowSize.x-1, position.y/windowSize.y-1
  };

  //Push new data into vertex array
  glBufferData(GL_ARRAY_BUFFER,vertexes*sizeof(double), drawVertices, GL_DYNAMIC_DRAW);

  //Draw Two Triangles to make a square
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES,0,3);
  glDrawArrays(GL_TRIANGLES,3,3);

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