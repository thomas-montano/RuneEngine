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

  componentFile << "public:\n\n";

  componentFile << "};";

  componentFile.close();

}

void toolTip(std::string tooltip)
{

  ImGui::SameLine();
  ImGui::TextDisabled("(?)");

  if (ImGui::IsItemHovered())
  {
    ImGui::BeginTooltip();
    ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
    ImGui::TextUnformatted(tooltip.c_str());
    ImGui::PopTextWrapPos();
    ImGui::EndTooltip();
  }

}
