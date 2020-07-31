#include "quad.h"

#include <Renderer\camera.h>
#include <GL\glew.h>
#include <GL\glu.h>
#include <GLFW\glfw3.h>
#include "shader.h"
#include <Shaders/rectangleBorder.glsl>

rune::Quad::Quad(Vec2 position, Vec2 size)
  : m_position(position), m_size(size), quadShader(rectangleBorder), m_fillColor(rune::Color::White)
{
  setUpBuffers();
}

void rune::Quad::drawQuad(rune::RenderWindow& window)
{
  rune::Vec2 windowSize = window.getSize();
  rune::Vec2 cameraPos = window.getCamera().getCenter();
  double zoomLevel = window.getCamera().getZoom();

  //Set up camera data for shader
  quadShader.setUniform2f("cameraPos", zoomLevel * cameraPos.x / (0.5 * windowSize.x), zoomLevel * cameraPos.y / (0.5 * windowSize.y));
  quadShader.setUniform1f("cameraZoom", zoomLevel);

  //Set up rotation information
  quadShader.setUniform1f("rotation", rotation);
  quadShader.setUniform1f("aspectRatio", window.getSize().x / window.getSize().y);
  quadShader.setUniform2f("origin", (m_position.x + (0.5 * m_size.x)) / (0.5 * windowSize.x), (m_position.y + (0.5 * m_size.y)) / (0.5 * windowSize.y));

  rune::Mat2 drawMatrix((m_position.x + m_size.x) / (0.5 * windowSize.x), (m_position.y + m_size.y) / (0.5 * windowSize.y),
    (m_position.x) / (0.5 * windowSize.x), (m_position.y) / (0.5 * windowSize.y));

  float drawVertices[32] =
  {
    // positions                              // colors and alpha
    drawMatrix[0][0],   drawMatrix[0][1],     m_fillColor.red / 255.0, m_fillColor.green / 255.0, m_fillColor.blue / 255.0, m_fillColor.alpha / 255.0,
    drawMatrix[0][0],   drawMatrix[1][1],     m_fillColor.red / 255.0, m_fillColor.green / 255.0, m_fillColor.blue / 255.0, m_fillColor.alpha / 255.0,
    drawMatrix[1][0],   drawMatrix[1][1],     m_fillColor.red / 255.0, m_fillColor.green / 255.0, m_fillColor.blue / 255.0, m_fillColor.alpha / 255.0,
    drawMatrix[1][0],   drawMatrix[0][1],     m_fillColor.red / 255.0, m_fillColor.green / 255.0, m_fillColor.blue / 255.0, m_fillColor.alpha / 255.0,
  };

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(drawVertices), drawVertices, GL_DYNAMIC_DRAW);

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void rune::Quad::setUpBuffers(void)
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
