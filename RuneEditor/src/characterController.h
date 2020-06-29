#pragma once

#include <RuneEngine.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>

class CharacterController : public rune::Component
{

private:
  bool touchingGround = true;
  bool hasJumped = false;
  float angularVelocity = 0;
  
public:

  rune::GameObject* contactMarker;

  void start() override
  {
  
    touchingGround = false;
    hasJumped = true;

  }

  void update() override
  {

    //ImGui::Text(std::to_string(rune::GameApplication::getFrameRate()).c_str());
  
    //Get some info from the message manager needed later
    const int moveSpeed = 100;
    const int jumpSpeed = 200;
    rune::Vec2 moveVelocity;
    rune::RenderWindow* window = rune::GameApplication::getWindow();

    if(rune::Keyboard::isKeyPressed(rune::Keyboard::UP))
    {
      parentObject->transform.setRotationZ(parentObject->transform.getRotation().z+.1);
    }

    if (rune::Keyboard::isKeyPressed(rune::Keyboard::DOWN))
    {
      parentObject->transform.setRotationZ(parentObject->transform.getRotation().z - .1);
    }

    //Move the player left and right based on keyboard input
   if(rune::Keyboard::isKeyPressed(rune::Keyboard::D))
    {
        moveVelocity += rune::Vec2(moveSpeed,0);
    }
    
    if(rune::Keyboard::isKeyPressed(rune::Keyboard::A))
    {
      moveVelocity -= rune::Vec2(moveSpeed, 0);
    }
  
  }


};