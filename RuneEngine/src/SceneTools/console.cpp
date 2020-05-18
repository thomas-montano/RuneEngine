#include "console.h"
#include <iostream>

int TextEditCallbackStub(ImGuiInputTextCallbackData* data)
{
  std::cout << "test" << std::endl;
  return 1;
}

std::string rune::Console::update()
{

  std::string returnString = "";

  ImGui::Begin("Console");

  ImGui::SetWindowSize(ImVec2(400, 500));

  const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing(); // 1 separator, 1 input text
  ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar); // Leave room for 1 separator + 1 InputText

  ImGui::SetCursorPosY(ImGui::GetWindowHeight());

  for(int i = 0; i < log.size();i++)
  {
    ImGui::TextColored(ImVec4(1,1,0,1),("# " + log[log.size()-1-i]).c_str());
    ImGui::SetCursorPosY(ImGui::GetWindowHeight()-(i+1)*ImGui::GetFrameHeightWithSpacing());
  }

  if (log.size() == 1)
  {
    ImGui::SetScrollHereY(1.0f);
  }

  ImGui::EndChild();

  ImGui::Separator();

  bool reclaim_focus = false;
  if (ImGui::InputText("Input", InputBuf, IM_ARRAYSIZE(InputBuf), ImGuiInputTextFlags_EnterReturnsTrue))
  {
    if (InputBuf[0] != '\n')
    {
      //ExecCommand(s);
      log.push_back(InputBuf);
      returnString = InputBuf;
    }
    strcpy_s(InputBuf, sizeof(InputBuf), "");

    reclaim_focus = true;
  }

  if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
    ImGui::SetScrollHereY(1.0f);

  ImGui::SetItemDefaultFocus();

  if (reclaim_focus)
    ImGui::SetKeyboardFocusHere(-1);

  ImGui::End();

  return returnString;

}