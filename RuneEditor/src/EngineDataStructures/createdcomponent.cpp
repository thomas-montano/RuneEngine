#include "createdComponent.h"
#include <fstream>

void CreatedComponent::buildComponent(void)
{
  std::ofstream componentFile;

  componentFile.open(componentName + ".h");

  componentFile << "#pragma once\n\n";
  componentFile << "#include <RuneEngine.h>\n\n";

  componentFile << "class " << componentName << " : public rune::Component\n";
  componentFile << "{\n";

  componentFile << "private:\n\n";

  componentFile << "};";

  componentFile.close();

}
