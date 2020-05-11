#include "sprite.h"

Sprite::Sprite() : spriteShader("./sprite.shader")
{


}

/**
 * @param dimensions A Vec2 specifying the size of the sprite.
 * @param position A Vec2 specifying the location of the sprite with respect to the bottom left corner.
 * @param spriteLocation A filepath for the sprite .png file to be drawn.
*/
Sprite::Sprite(Vec2 dimensions,Vec2 position, std::string spriteLocation) : m_position(position), m_size(dimensions),spriteTexture(spriteLocation.c_str()), spriteShader("./sprite.shader") 
{
  //Generate and bind vertex array object
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  //Generate and bind the vertices array in the buffer
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  // texture coord attribute
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);

}

/**
 * @param windowSize The size of the window the sprite is being drawn to.
*/
void Sprite::draw(Vec2 windowSize)
{
  //Bind the vertex array object
  spriteTexture.bind();
  spriteShader.bind();
  glBindVertexArray(VAO);

  float drawVertices[32] = 
  {
    // positions                                                                                // colors           // texture coords
    (m_position.x + m_size.x)/windowSize.x-1, (m_position.y+ m_size.y)/windowSize.y-1, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
    (m_position.x+m_size.x)/windowSize.x-1, m_position.y/windowSize.y-1, 0.0f,                  0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    m_position.x/windowSize.x-1, m_position.y/windowSize.y-1, 0.0f,                             0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    m_position.x/windowSize.x-1, (m_position.y+ m_size.y)/windowSize.y-1, 0.0f,                 0.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
  };

  glBufferData(GL_ARRAY_BUFFER, sizeof(drawVertices), drawVertices, GL_DYNAMIC_DRAW);

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  spriteTexture.unbind();
}

/**
 * @param newPos The new position of the RectangleShape with respect to the bottom left corner.
*/
void Sprite::addPosition(Vec2 newPos)
{
  m_position.x += newPos.x;
  m_position.y += newPos.y;
}

/**
 * @param newSize The new size of the RectangleShape.
*/
void Sprite::setPosition(Vec2 newSize)
{
  m_position.x = newSize.x;
  m_position.y = newSize.y;
}

void Sprite::setTexture(Texture newTexture)
{

  spriteTexture = newTexture;

}