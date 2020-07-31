#pragma once

/**
 * @namespace rune
 * @brief The main namespace to be used for interfacing with the engine
 */

#include <gameApplication.h>

#include <Entities/gameObject.h>
#include <Entities/component.h>
#include <Entities/transform.h>

#include <Particles/particleEmitter.h>

#include <Animation/animator.h>

#include <Lighting/lightSource.h>

#include <SceneManager/gameScene.h>

#include <Events/clock.h>

#include <Input/keyboard.h>
#include <Input/mouse.h>

#include <Math/vec2.h>
#include <Math/vec3.h>
#include <Math/mat2.h>
#include <Math/mat3.h>

#include <DataStructures/list.h>

#include <Renderer/camera.h>
#include <Renderer/rect.h>
#include <Renderer/sprite.h>
#include <Renderer/rectangleShape.h>
#include <Renderer/color.h>
#include <Renderer/shader.h>
#include <Renderer/texture.h>
#include <Renderer/drawable.h>

#include <physics/rigidBody.h>


#ifndef RUNE_BUILD_DLL
  #define IMGUI_API __declspec( dllimport )
#endif

#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>