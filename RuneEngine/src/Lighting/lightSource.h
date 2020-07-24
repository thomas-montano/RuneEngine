/**
 * @class rune::LightSource
 * @brief A light source to be used in a scene. Casts light and shadows on objects.
 * 
 * @author Thomas Montano
 * @date April 22 2020
*/

#ifndef LIGHTSOURCE_H_DEFINED
#define LIGHTSOURCE_H_DEFINED

#include "core.h"
#include <Renderer\drawable.h>
#include <Entities\component.h>
#include <Renderer\shader.h>

namespace rune{

class RUNE_ENGINE LightSource : public Drawable, public Component
{

private:

  Shader lightShader;


public:

  void start() override;
  void update() override;

};
}

#endif