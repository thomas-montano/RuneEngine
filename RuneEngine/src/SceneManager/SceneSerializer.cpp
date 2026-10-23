#include "SceneSerializer.h"
#include <yaml-cpp/yaml.h>
#include <Entities/transform.h>
#include <Math/vec2.h>
#include <Math/vec3.h>
#include <Renderer/sprite.h>

/// \cond

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

/// \endcond

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
    out << YAML::Key << "Scene" << YAML::Value << sceneName;
    out << YAML::Key << "Entities" << YAML::Value << YAML::BeginSeq;

    int entityID = 0;

    for (GameObject** currentObject = m_scene->sceneObjects.getList(); currentObject != nullptr; currentObject = m_scene->sceneObjects.getNext())
    {
      out << YAML::BeginMap;

      out << YAML::Key << "Entity" << YAML::Value << entityID;
      entityID++;
      
      serializeObject(out,**currentObject);
      out << YAML::EndMap;
    }

    out << YAML::EndSeq;
    out << YAML::EndMap;

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

  auto ptrTransform = object.getComponent<rune::Transform>();

  if(ptrTransform != nullptr)
  {
    out << YAML::Key << "Transform";
    
    out << YAML::BeginMap;
    out << YAML::Key << "Position" << YAML::Value << ptrTransform->getPosition();
    out << YAML::Key << "Scale" << YAML::Value << ptrTransform->getScale();
    out << YAML::Key << "Rotation" << YAML::Value << ptrTransform->getRotation();
    out << YAML::Key << "Bounds" << YAML::Value << ptrTransform->getBounds();
    out << YAML::EndMap;
  }

  auto ptrRect = object.getComponent<rune::RectangleShape>();

  if(ptrRect != nullptr)
  {
    out << YAML::Key << "RectangleShape";

    out << YAML::BeginMap;
    out << YAML::Key << "Color" << YAML::Value << YAML::Flow << YAML::BeginSeq << (int)ptrRect->getFillColor().red << (int)ptrRect->getFillColor().green << (int)ptrRect->getFillColor().blue << (int)ptrRect->getFillColor().alpha << YAML::EndSeq;
    out << YAML::EndMap;
  }

  auto ptrBody = object.getComponent<rune::RigidBody>();

  if(ptrBody != nullptr)
  {
    rune::body body = *ptrBody->getBodyStruct();

    out << YAML::Key << "RigidBody";
    out << YAML::BeginMap;
    out << YAML::Key << "Vertices" << YAML::Value << YAML::Flow << YAML::BeginSeq << body.vertexes[0] << body.vertexes[1] << body.vertexes[2] << body.vertexes[3] << YAML::EndSeq;
    out << YAML::Key << "BoundingBox" << YAML::Value << YAML::Flow << YAML::BeginSeq << body.boundingBox.min << body.boundingBox.max << YAML::EndSeq;

    out << YAML::Key << "Position" << YAML::Value << rune::Vec2(body.xPos,body.yPos);
    out << YAML::Key << "InverseMass" << YAML::Value << body.invMass;

    out << YAML::Key << "Gravity" << YAML::Value << body.gravityFactor;

    out << YAML::EndMap;
  }

  auto ptrSprite = object.getComponent<rune::Sprite>();

  if(ptrSprite != nullptr)
  {
    out << YAML::Key << "Sprite";
    out << YAML::BeginMap;

    //ptrSprite->te spriteTexture.m_filePath;
    out << YAML::Key << "DrawMode" << YAML::Value << ptrSprite->getDrawMode();
    //IntRect textureSpace;

    out << YAML::EndMap;
  }

}