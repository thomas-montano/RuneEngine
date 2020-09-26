/**
 * @class rune::ObjectAnimation
 * @brief Class responsible for managing sprite animations and 
 * updating which frame of the animation is to be shown
 * 
 * @author Thomas Montano
 * @date April 13 2020
*/

#ifndef OBJECT_ANIMATION_HEADER_DEFINED
#define OBJECT_ANIMATION_HEADER_DEFINED

#include "core.h"
#include <string>
#include <Events\clock.h>
#include <Renderer\texture.h>

namespace rune{

class RUNE_ENGINE ObjectAnimation
{
private:
  int m_frameHeight;
  int m_frameWidth;
  int m_numFrames;
  int m_frameRate;
  int m_currentFrame;

  bool m_mirror;

  rune::Clock m_animationClock;

  Texture m_animationSheet;

public:
  ///Default constructor to create a new animation for a rune::GameObject.
  ObjectAnimation();
  ///Set the frame rate for the animation.
  void setFrameRate(int frameRate);
  ///Get the frame rate for the animation.
  int getFrameRate(void);
  ///Get whether or not the animation should be mirrored.
  bool isMirrored(void);
  ///Set the width in pixels of each frame on the sprite sheet.
  void setFrameWidth(int frameWidth);
  ///Get the width in pixels of each frame on the sprite sheet.
  int getFrameWidth(void);
  ///Set the height in pixels of each frame on the sprite sheet.
  void setFrameHeight(int frameHeight);
  ///Get the height in pixels of each frame on the sprite sheet.
  int getFrameHeight(void);
  ///Set the number of frames the animation contains.
  void setNumFrames(int numFrames);
  ///Get the number of frames the animation contains.
  int getNumFrames(void);
  ///Set the sprite sheet of the animation from a texture object.
  void setSheet(std::string const& filePath, unsigned int drawMode);
  ///Get the sprite sheet of the animation.
  Texture* getSheet(void);
  ///Get the frame that the animation is currently on.
  int getCurrentFrame(void);
  ///Set the frame that the animation is currently on.
  void setCurrentFame(int);
  ///Tell the animation to go to the next frame.
  void incCurrentFrame(void);
  ///Set whether or not the sprite should be mirrored across the vertical axis.
  void setMirror(bool);

};
}

#endif