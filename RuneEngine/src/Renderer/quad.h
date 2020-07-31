#pragma once

#include <core.h>
#include <Renderer/renderWindow.h>
#include <Math/vec3.h>
#include <Renderer/shader.h>

namespace rune{

class RUNE_ENGINE Quad
{

private:
  unsigned int indices[6] =
  {
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  unsigned int VBO;
  unsigned int EBO;
  unsigned int VAO;

  Vec2 m_position;
  Vec2 m_size; 

public:
  Shader quadShader;

  Color m_fillColor;

  float rotation;

  Quad(Vec2 position, Vec2 size);

  void drawQuad(rune::RenderWindow& window);

  void setUpBuffers(void);

};

}///namespace rune