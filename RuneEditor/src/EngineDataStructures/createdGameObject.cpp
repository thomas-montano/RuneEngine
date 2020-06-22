#include "createdGameObject.h"
#include <fstream>

void CreatedGameObject::buildObject(void)
{

  std::ofstream objectFile;

  objectFile.open(objectName + ".h");

  objectFile << "#pragma once\n\n";
  objectFile << "#include <RuneEngine.h>\n\n";

  for(int i = 1; i < objectComponents.size();i++)
  {
  
    objectFile << "#include \"" << objectComponents[i].componentName << "\"\n";
  
  }

  objectFile << "class " << objectName << " : public rune::GameObject\n";
  objectFile << "{\n";

  objectFile << "public:\n\n";

  for(int i = 0; i < objectComponents.size();i++)
  {
  
    objectFile << objectComponents[i].componentType << " " << objectComponents[i].componentName << ";\n";
  
  }

  objectFile << "\n" << objectName << "()\n";
  objectFile << "{\n";
  objectFile << "}\n\n";

  objectFile << "};";

  objectFile.close();

}

