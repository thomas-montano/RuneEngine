/*
  Shader

  This class provides each drawable object with a compiled and bindable shader

  Thomas Montano
  4/25/20
*/

#ifndef SHADER_H_DEFINED
#define SHADER_H_DEFINED

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "renderWindow.h"

struct ShaderProgramSource
{
  std::string VertexSource;
  std::string FragmentSource;
};

class Shader
{
private:
  unsigned int m_shaderID;

public:
  Shader(const std::string& filePath);
  unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
  unsigned int CompileShader(unsigned int type, const std::string& source);
  ShaderProgramSource ParseShader(const std::string& filePath);
  void setActive(void);
};

#endif