#include "shader.h"
#include <GL\glew.h>
#include <GL\glu.h>
#include <GLFW\glfw3.h>

rune::Shader::Shader() : m_shaderID(0)
{

}

rune::Shader::Shader(ShaderProgramSource source)
{

  m_shaderID = CreateShader(source.VertexSource, source.FragmentSource);

}

/**
 * @param filePath The file path for the shader code to be compiled.
*/
rune::Shader::Shader(const std::string& filePath)
{
  ShaderProgramSource source = ParseShader(filePath.c_str());

  m_shaderID = CreateShader(source.VertexSource, source.FragmentSource);
}

void rune::Shader::makeNewShader(const std::string& filePath)
{
  ShaderProgramSource source = ParseShader(filePath.c_str());

  m_shaderID = CreateShader(source.VertexSource, source.FragmentSource);
}

/**
 * @param filePath The file path of the texture code to be loaded.
 * @return A ShaderProgramSource containing the raw shader text for a fragment and vertex shader.
*/
rune::ShaderProgramSource rune::Shader::ParseShader(const std::string& filePath)
{

  std::ifstream stream(filePath.c_str());

  enum class ShaderType
  {
    NONE = -1, VERTEX = 0, FRAGMENT = 1
  };

  std::string line;
  std::stringstream ss[2];
  ShaderType type = ShaderType::NONE;

  while(getline(stream,line))
  {

    if(line.find("#shader") != std::string::npos)
    {
      if(line.find("vertex") != std::string::npos)
      {
        //Set mode to vertex
        type = ShaderType::VERTEX;
      }
      else if(line.find("fragment") != std::string::npos)
      {
        //Set mode to fragment
        type = ShaderType::FRAGMENT;
      }
    }
    else
    {
      ss[(int)type] << line << '\n';
    }
    
  }

  stream.close();

  return {ss[0].str(), ss[1].str()};

}

/**
 * @param type A enum specifying the type of shader to be compiled.
 * @param source The file source of the shader code.
 * @return The OpenGL shader ID pointing to the compiled shader.
*/
unsigned int rune::Shader::CompileShader(unsigned int type, const std::string& source)
{
  unsigned int id = glCreateShader(type);
  const char* src = source.c_str();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  //Error handling
  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);

  if(result == GL_FALSE)
  {
    int length;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
    char* message= (char*)alloca(length * sizeof(char));
    glGetShaderInfoLog(id, length, &length, message);
    std::cout << "Shader failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
    std::cout << message << std::endl;
    glDeleteProgram(id);
    return 0;
  }

  return id;
}

/**
 * @param vertexShader The raw shader code for the vertex shader.
 * @param fragmentShader The raw shader code for the fragment shader.
 * @return The OpenGL shader ID pointing to the created shader program.
*/
unsigned int rune::Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{

  unsigned int program = glCreateProgram();
  unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  glAttachShader(program,vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteProgram(vs);
  glDeleteProgram(fs);

  return program;

}

void rune::Shader::bind()
{
  glUseProgram(m_shaderID);
}

/**
 * @return The id for the OpenGL uniform specified.
*/
int rune::Shader::getUniformLocation(const std::string& name)
{
  if(m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
  {
    return m_UniformLocationCache[name];
  }

  int location = glGetUniformLocation(m_shaderID, name.c_str());

  if(location == -1)
  {
    std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
  }

  m_UniformLocationCache[name] = location;
  return location;
}

/**
 * @param name The exact name of the uniform that is being created.
 * @param value The value being passed to the uniform.
*/
void rune::Shader::setUniform1f(const std::string& name, float value)
{
  glUniform1f(getUniformLocation(name), value);
}

void rune::Shader::setUniform2f(const std::string& name, float v0, float v1)
{
  glUniform2f(getUniformLocation(name), v0, v1);
}

/**
 * @param name The exact name of the uniform that is being created.
 * @param v0 The value being passed to the uniform.
 * @param v1 The value being passed to the uniform.
 * @param v2 The value being passed to the uniform.
 * @param v3 The value being passed to the uniform.
*/
void rune::Shader::setUniform4f(const std::string&name, float v0, float v1, float v2, float v3)
{
  glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}

/**
 * @param name The exact name of the uniform that is being created.
 * @param value The value being passed to the uniform.
*/
void rune::Shader::setUniform1i(const std::string& name, int value)
{
  glUniform1i(getUniformLocation(name), value);
}
