#pragma once

/**
 * @class rune::Mat2
 * @brief 2 x 2 matrix to be used for math.
 *
 * @author Thomas Montano
 * @date May 15 2020
*/

#include "core.h"
#include "vec2.h"

namespace rune{

class RUNE_ENGINE Mat2
{
public:
  Vec2 col1;
  Vec2 col2;

};

}
