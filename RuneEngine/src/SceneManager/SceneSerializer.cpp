#include "SceneSerializer.h"
#include <yaml-cpp/yaml.h>
#include <Entities/transform.h>
#include <Math/vec2.h>
#include <Math/vec3.h>

namespace rune{

  YAML::Emitter& operator<<(YAML::Emitter& out, const Vec3& v)
  {
    out << YAML::Flow;
    out << YAML::BeginSeq << v.x << v.y << v.z << YAML::EndSeq;
    return out;
  }

  YAML::Emitter& operator<<(YAML::Emitter& out, const Vec2& v)
  {
    out << YAML::Flow;
    out << YAML::BeginSeq << v.x << v.y << YAML::EndSeq;
    return out;
  }
}

/**
 * \param scene The scene that should be serialized.
 */
rune::SceneSerializer::SceneSerializer(rune::GameScene& scene)
  : m_scene(&scene)
{
}

rune::SceneSerializer::SceneSerializer()
{
  m_scene = nullptr;
}

/**
 * \param filePath The location of the YAML source file.
 */
void rune::SceneSerializer::serialize(const std::string& filePath)
{

  std::cout << "A scene is being written to a file" << std::endl;
  std::cout << filePath << std::endl;

  if(m_scene != nullptr)
  {
  
    YAML::Emitter out;

    out << YAML::BeginMap;
    out << YAML::Key << "Scene";
    out << YAML::Value << "runTimeScene";
    out << YAML::Key << "Entities";

    for (GameObject** currentObject = m_scene->sceneObjects.getList(); currentObject != nullptr; currentObject = m_scene->sceneObjects.getNext())
    {
      serializeObject(out,**currentObject);
    }

    out << YAML::EndSeq;
    out << YAML::EndMap;

    YAML::EndMap;
    std::ofstream fout(filePath +".yaml");

    fout << out.c_str();

  }

}

/**
 * \param filePath The location of the YAML source file.
 */
void rune::SceneSerializer::serializeRuntime(const std::string& filePath)
{
  if (m_scene != nullptr)
  {

  }
}

/**
 * \param filePath The location of the YAML source file.
 */
void rune::SceneSerializer::deserialize(const std::string& filePath)
{
  std::cout << "A scene is being read from a file" << std::endl;
  std::cout << filePath << std::endl;

  if (m_scene != nullptr)
  {

  }
}

/**
 * \param filePath The location of the YAML source file.
 */
void rune::SceneSerializer::deserializeRuntime(const std::string& filePath)
{
  if (m_scene != nullptr)
  {

  }
}

/**
 * \param out The YAML buffer that is currently being written to.
 * \param object The GameObject that is going to be written to a file.
 */
void rune::SceneSerializer::serializeObject(YAML::Emitter& out, rune::GameObject& object)
{

  auto ptr = object.getComponent<rune::Transform>();

  if(ptr != nullptr)
  {
    out << YAML::Key << "Position" << YAML::Value;
    out << ptr->getPosition();
  }

}

