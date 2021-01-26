#include "sprite.h"
#include <GL\glew.h>
#include <GL\glu.h>
#include <GLFW\glfw3.h>
#include <gameApplication.h>
#include <Renderer\camera.h>
#include <Math\mat2.h>

rune::Sprite::Sprite() 
  : objectShader(defaultSprite), textureSpace(0,0,0,0), spriteDrawMode(LINEAR_FILTER)
{
  setUpBuffers();
}

/**
 * @param spriteLocation A filepath for the sprite png file to be drawn.
 * @param drawMode How would you like the sprite to be filtered when drawn.
 * @warning Use NEAREST_FILTER for pixel art sprites. LINEAR_FILTER is used by default.
*/
rune::Sprite::Sprite(std::string const& spriteLocation, unsigned int drawMode) 
  : spriteTexture(spriteLocation.c_str(), drawMode), objectShader(defaultSprite), textureSpace(0, 0, 0, 0), spriteDrawMode(drawMode)
{
  setUpBuffers();
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
  // texture coordinate attribute
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);

  textureSpace = IntRect(0,0,spriteTexture.getWidth(),spriteTexture.getHeight());

}

void rune::Sprite::start()
{
  getGameInstance()->getCurrentScene()->submitToRenderer(*this);
}

/**
 * @param window The window that the sprite is being drawn to.
*/
void rune::Sprite::draw(rune::RenderWindow& window)
{

  //Bind the vertex array object
  spriteTexture.bind();
  objectShader.bind();
  
  rune::Vec2 windowSize = window.getSize();
  rune::Vec2 cameraPos = window.getCamera().getCenter();
  double zoomLevel = window.getCamera().getZoom();

  rune::Vec3 position = parentObject->transform.getPosition();
  rune::Vec3 size = parentObject->transform.getScale();

  //Set up camera data for shader
  objectShader.setUniform2f("cameraPos", zoomLevel * (cameraPos.x / (0.5 * windowSize.x)), zoomLevel * (cameraPos.y / (0.5 * windowSize.y)));
  objectShader.setUniform1f("cameraZoom",zoomLevel);

  //Add in rotation information so that things rotate correctly
  objectShader.setUniform1f("rotation", parentObject->transform.getRotation().z);
  objectShader.setUniform1f("aspectRatio", getGameInstance()->getWindow()->getSize().x / getGameInstance()->getWindow()->getSize().y);
  objectShader.setUniform2f("origin", (position.x+(0.5 * size.x))/(0.5*windowSize.x), (position.y + (0.5 * size.y)) / (0.5*windowSize.y));

  rune::Mat2 drawMatrix((position.x + size.x) / (0.5*windowSize.x), (position.y + size.y) / (0.5*windowSize.y),
                        (position.x) / (0.5*windowSize.x),            (position.y) / (0.5*windowSize.y));

  Vec2 textureDimension = Vec2(spriteTexture.getWidth(), spriteTexture.getHeight());

  const float drawVertices[32] = 
  {
    // positions                              // colors and alpha         // texture coordinates
    drawMatrix[0][0],   drawMatrix[0][1],     spriteColor.red/255.0, spriteColor.green / 255.0, spriteColor.blue / 255.0, spriteColor.alpha / 255.0,     (textureSpace.width + textureSpace.left) / textureDimension.x, textureSpace.height / textureDimension.y, // top right
    drawMatrix[0][0],   drawMatrix[1][1],     spriteColor.red / 255.0, spriteColor.green / 255.0, spriteColor.blue / 255.0, spriteColor.alpha / 255.0,     (textureSpace.width + textureSpace.left) / textureDimension.x, textureSpace.top / textureDimension.y, // bottom right
    drawMatrix[1][0],   drawMatrix[1][1],     spriteColor.red / 255.0, spriteColor.green / 255.0, spriteColor.blue / 255.0, spriteColor.alpha / 255.0,     textureSpace.left /textureDimension.x,   textureSpace.top / textureDimension.y, // bottom left
    drawMatrix[1][0],   drawMatrix[0][1],     spriteColor.red / 255.0, spriteColor.green / 255.0, spriteColor.blue / 255.0, spriteColor.alpha / 255.0,     textureSpace.left / textureDimension.x,  textureSpace.height / textureDimension.y  // top left
  };

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER,VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(drawVertices), drawVertices, GL_DYNAMIC_DRAW);

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  spriteTexture.unbind();

}

/**
 * \param texture The file path to the texture that is to be loaded onto the sprite.
 * \param drawMode How would you like the sprite to be filtered when drawn.
 */
void rune::Sprite::setTexture(std::string const& texture, unsigned int drawMode)
{

  spriteTexture.loadFromFile(texture.c_str(), drawMode);

}
/**
 * \param texture The texture that should be given to this sprite for drawing.
 */
void rune::Sprite::setTexture(Texture* texture)
{
  spriteTexture = *texture;
}

/**
 * \param xPos The left most x position of the texture to be used.
 * \param yPos The top most y position of the texture to be used.
 * \param width The width of the texture.
 * \param height The height of the texture.
 */
void rune::Sprite::setTextureRect(int xPos, int yPos, int width, int height)
{

  textureSpace = IntRect(xPos,yPos,width,height);

}

/**
 * \return The rune::IntRect currently applied to this sprite.
 */
rune::IntRect rune::Sprite::getTextureRect(void)
{
  return textureSpace;
}

/**
 * \return The draw mode currently being used to render this sprite.
 */
unsigned int rune::Sprite::getDrawMode()
{
  return spriteDrawMode;
}
