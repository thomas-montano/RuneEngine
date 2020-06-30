#include "createdGameObject.h"
#include <Components/transformComponent.h>
#include <mainEditorWindow.h>
#include <fstream>

CreatedGameObject::CreatedGameObject(std::string newName)
{

  objectName = newName;
  gameObject = new rune::GameObject;

  TransformComponent* defaultTransform = new TransformComponent("rune::Transform", "Transform", gameObject, "Entities/transform.h");

  objectComponents.push_back(defaultTransform);
  EditorWindow::currentlyOpenProject.activeScene->scene->addObjectToScene(*gameObject);

}

void CreatedGameObject::buildObject(void)
{

  std::ofstream objectFile;

  objectFile.open(objectName + ".h");

  objectFile << "#pragma once\n\n";
  objectFile << "#include <RuneEngine.h>\n\n";

  for(int i = 1; i < objectComponents.size();i++)
  {
  
    objectFile << "#include \"" << objectComponents[i]->componentName << "\"\n";
  
  }

  objectFile << "class " << objectName << " : public rune::GameObject\n";
  objectFile << "{\n";

  objectFile << "public:\n\n";

  for(int i = 0; i < objectComponents.size();i++)
  {
  
    objectFile << objectComponents[i]->componentType << " " << objectComponents[i]->componentName << ";\n";
  
  }

  objectFile << "\n" << objectName << "()\n";
  objectFile << "{\n";
  objectFile << "}\n\n";

  objectFile << "};";

  objectFile.close();

}

