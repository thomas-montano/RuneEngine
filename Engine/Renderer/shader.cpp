#include "shader.h"

Shader::Shader(const std::string& filePath)
{
  ShaderProgramSource source = ParseShader(filePath.c_str());

  /*std::cout << "VERTEX" << std::endl;
  std::cout << source.VertexSource << std::endl;

  std::cout << "FRAGMENT" << std::endl;
  std::cout << source.FragmentSource << std::endl;*/

  m_shaderID = CreateShader(source.VertexSource, source.FragmentSource);
}

ShaderProgramSource Shader::ParseShader(const std::string& filePath)
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

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
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

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
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

void Shader::setActive()
{
  glUseProgram(m_shaderID);
}