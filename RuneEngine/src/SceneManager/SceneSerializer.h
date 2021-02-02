#pragma once
#include <core.h>
#include "gameScene.h"

namespace YAML{class Emitter;}

namespace rune{

class RUNE_ENGINE SceneSerializer
{
public:
  SceneSerializer();
  ///Default constructor to create a SceneSerializer.
  SceneSerializer(rune::GameScene& scene);
  ///Serialize the scene to a human readable file.
  void serialize(const std::string& filePath);
  ///Serialize the scene to binary.
  void serializeRuntime(const std::string& filePath);
  ///Read the scene back in from a file.
  void deserialize(const std::string& filePath);
  ///Read the scene back in from a binary file.
  void deserializeRuntime(const std::string& filePath);

  ///Serialize a GameObject to YAML.
  void serializeObject(YAML::Emitter& out, rune::GameObject&);

private:
  rune::GameScene* m_scene;

};

}//namespace rune
