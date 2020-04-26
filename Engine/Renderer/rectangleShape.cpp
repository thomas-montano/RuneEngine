#include "rectangleShape.h"
#include <iostream>

RectangleShape::RectangleShape(Vec2 newPosition, Vec2 newSize)
{
  position = newPosition;
  size = newSize;

  vertices[0] = Vec2(position.x, position.y+size.y);
  vertices[1] = Vec2(position.x + size.x, position.y+size.y);
  vertices[2] = Vec2(position.x + size.x, position.y);
  vertices[3] = Vec2(position.x, position.y);

}

void RectangleShape::draw(Vec2 windowSize)
{

  const int vertexes = 12;

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glGenBuffers(1,&buffer);

  float drawVertices[vertexes] = 
  {

    position.x/windowSize.x-1, position.y/windowSize.y-1,
    position.x/windowSize.x-1, (position.y+ size.y)/windowSize.y-1,
    (position.x + size.x)/windowSize.x-1, (position.y+ size.y)/windowSize.y-1,
    position.x/windowSize.x-1, position.y/windowSize.y-1,
    (position.x + size.x)/windowSize.x-1, (position.y+ size.y)/windowSize.y-1,
    (position.x+size.x)/windowSize.x-1, position.y/windowSize.y-1
  };

  glBindBuffer(GL_ARRAY_BUFFER, buffer);

  glBufferData(GL_ARRAY_BUFFER,vertexes*sizeof(float), drawVertices, GL_DYNAMIC_DRAW);

  glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float)*2,(void*)0);
  glEnableVertexAttribArray(0);

  //Draw Two Triangles
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES,0,3);
  glDrawArrays(GL_TRIANGLES,3,3);

}

void RectangleShape::addPosition(Vec2 newPos)
{
  position.x += newPos.x;
  position.y += newPos.y;
}

void RectangleShape::setPosition(Vec2)
{
  
}