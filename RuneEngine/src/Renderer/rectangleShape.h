/**
 * @class rune::RectangleShape
 * @brief A rectangle that can be drawn to the screen.
 * 
 * @author Thomas Montano
 * @date April 25 2020
 * 
*/

#ifndef RECTANGLE_H_DEFINED
#define RECTANGLE_H_DEFINED

#include "core.h"
#include "renderWindow.h"
#include "shader.h"
#include <Entities\component.h>
#include "drawable.h"
#include <Math\vec2.h>

namespace rune{

class GameApplication;
class SceneManager;

class RUNE_ENGINE RectangleShape : public rune::Drawable, public rune::Component
{

private:
  rune::ShaderProgramSource defaultShader =
  rune::ShaderProgramSource(
  "#version 330 core\n"

  "layout(location = 0) in vec2 aPos;\n"
  "layout(location = 1) in vec4 aColor;\n"
  "layout(location = 2) in vec2 aTexCoord;\n"

  "uniform vec2 cameraPos = vec2(0, 0);\n"
  "uniform float cameraZoom = 1;\n"
  "uniform float rotation = 0;\n"
  "uniform vec2 origin = vec2(0,0);\n"
  "uniform float aspectRatio = 1;\n"

  "out vec4 ourColor;\n"

  "void main()\n"
  "{\n"

    "vec2 vertices = cameraZoom*aPos - cameraPos;\n"

    "if(rotation != 0)\n"
    "{\n"
      "float angle = radians(rotation);\n"
      "mat2 rotationMatrix = mat2(cos(angle), aspectRatio*sin(angle), -sin(angle)/aspectRatio, cos(angle));\n"

      "vertices = vertices - (cameraZoom*origin - cameraPos);\n"
      "vertices = rotationMatrix * vertices;\n"
      "vertices = vertices + (cameraZoom*origin - cameraPos);\n"
    "}\n" 

    "ourColor = aColor;\n"
    "gl_Position = vec4(vertices,0,1);\n"

  "};\n"
  ,
  "#version 330 core\n"

  "out vec4 FragColor;\n"

  "in vec4 ourColor;\n"

  "void main()\n"
  "{\n"
    "FragColor = ourColor;\n"
  "};\n"
  );

  rune::Color m_fillColor;
  Shader rectangleShader;
  rune::Vec2 origin;

  unsigned int indices[6] =
  {
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  unsigned int VBO;
  unsigned int EBO;
  unsigned int VAO;

  void setUpBuffers(void);

public:

  virtual void start() override;
  ///The draw call for rendering the shape to the screen.
  virtual void draw(rune::RenderWindow&);
  ///Default constructor that will create a white rectangle by default.
  ///@param newColor The color that should be used to draw the rectangle.
  RectangleShape(rune::Color newColor = rune::Color::White);
  ///Set the color used to fill the rectangle.
  ///@param newFillColor the new color that should be used to draw the rectangle.
  void setFillColor(rune::Color newFillColor);
  ///Change the active shader on the rune::RectangleShape to be something else.
  ///@param filePath The shader code to be loaded onto the GPU.
  void changeShader(std::string const& filePath);

};
}

#endif