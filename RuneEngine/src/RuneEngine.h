#pragma once

/**
 * @namespace rune
 * @brief The main namespace to be used for interfacing with the engine
 */

#include <gameApplication.h>

#include <Entities\gameObject.h>
#include <Entities\component.h>
#include <Entities\transform.h>
#include <Entities\particleEmitter.h>
#include <Entities\animationController.h>
#include <Entities\lightSource.h>

#include <SceneTools\gameScene.h>

#include <Events\clock.h>

#include <Input\keyboard.h>
#include <Input\mouse.h>

#include <Math\vec2.h>
#include <Math\vec3.h>
#include <Math\mat2.h>
#include <Math\mat3.h>

#include <Renderer\camera.h>
#include <Renderer\sprite.h>
#include <Renderer\rectangleShape.h>
#include <Renderer\color.h>
#include <Renderer\shader.h>
#include <Renderer\texture.h>

#include <Physics\collider2d.h>
#include <physics\rigidBody.h>

#define IMGUI_API __declspec( dllimport )
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>