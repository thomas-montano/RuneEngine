#pragma once

#include <RuneEngine.h>

class SceneViewPort : public rune::Drawable
{
public:
  rune::FrameBuffer viewBuffer;

  SceneViewPort()
  {
  
    viewBuffer.setSize(getGameInstance()->getWindow()->getSize());

  }

  virtual void draw(rune::RenderWindow& window) override;
  

};