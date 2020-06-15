#include "rectangleShape.h"
#include "shader.h"
#include <math\mat2.h>
#include <Renderer\camera.h>
#include <GL\glew.h>
#include <GL\glu.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <gameApplication.h>
#include <SceneTools\sceneManager.h>

rune::RectangleShape::RectangleShape(rune::Color newColor) 
: rectangleShader(defaultShader), origin(rune::Vec2(0,0)), shapeColor(newColor)
{
  setUpBuffers();
  setUpUniforms();
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

void rune::RectangleShape::setUpUniforms()
{

  u_cameraPos = rectangleShader.getUniformLocation("cameraPos");
  u_cameraZoom = rectangleShader.getUniformLocation("cameraZoom");
  u_rotation = rectangleShader.getUniformLocation("rotation");
  u_origin = rectangleShader.getUniformLocation("origin");
  u_aspectRatio = rectangleShader.getUniformLocation("aspectRatio");

}

void rune::RectangleShape::start()
{

}

void rune::RectangleShape::update()
{

  rune::GameApplication::getWindow()->draw(*this);

}

/**
 * @param windowSize The size of the window that the RectangleShape is being drawn on.
*/
void rune::RectangleShape::draw(rune::RenderWindow& window)
{

  //Bind the vertex array object
  rectangleShader.bind();

  rune::Vec3 position = parentObject->transform.getPosition();
  rune::Vec3 size = parentObject->transform.getScale();

  rune::Vec2 windowSize = window.getSize();
  rune::Vec2 cameraPos = rune::Camera::getCenter();
  double zoomLevel = rune::Camera::getZoom();

  //Set up camera data for shader
  rectangleShader.setUniform2f(u_cameraPos, zoomLevel * cameraPos.x / (0.5*windowSize.x), zoomLevel * cameraPos.y / (0.5*windowSize.y));
  rectangleShader.setUniform1f(u_cameraZoom,zoomLevel);

  //Set up rotation information
  rectangleShader.setUniform1f(u_rotation, parentObject->transform.getRotation().z);
  rectangleShader.setUniform1f(u_aspectRatio, rune::GameApplication::getWindow()->getSize().x / rune::GameApplication::getWindow()->getSize().y);
  rectangleShader.setUniform2f(u_origin, (position.x + (0.5 * size.x)) / (0.5 * windowSize.x), (position.y + (0.5 * size.y)) / (0.5 * windowSize.y));

  rune::Mat2 drawMatrix((position.x + size.x) / (0.5*windowSize.x), (position.y + size.y) / (0.5*windowSize.y),
    (position.x) / (0.5*windowSize.x), (position.y) / (0.5*windowSize.y));

  float drawVertices[32] =
  {
    // positions                              // colors and alpha
    static_cast<float>(drawMatrix[0][0]),   drawMatrix[0][1],     shapeColor.red / 255.0, shapeColor.green / 255.0, shapeColor.blue / 255.0, shapeColor.alpha / 255.0,
    drawMatrix[0][0],   drawMatrix[1][1],     shapeColor.red / 255.0, shapeColor.green / 255.0, shapeColor.blue / 255.0, shapeColor.alpha / 255.0,
    drawMatrix[1][0],   drawMatrix[1][1],     shapeColor.red / 255.0, shapeColor.green / 255.0, shapeColor.blue / 255.0, shapeColor.alpha / 255.0,
    drawMatrix[1][0],   drawMatrix[0][1],     shapeColor.red / 255.0, shapeColor.green / 255.0, shapeColor.blue / 255.0, shapeColor.alpha / 255.0,
  };

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(drawVertices), drawVertices, GL_DYNAMIC_DRAW);

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void rune::RectangleShape::setFillColor(rune::Color newColor)
{
  shapeColor = newColor;
}