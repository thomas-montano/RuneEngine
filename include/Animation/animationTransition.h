#pragma once

#include <core.h>
#include "objectAnimation.h"

namespace rune{

class RUNE_ENGINE AnimationTransition
{

public:
  ObjectAnimation* originAnimation;
  ObjectAnimation* endAnimation;

};

}//namespace rune