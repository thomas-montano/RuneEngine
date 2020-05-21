#pragma once

/**
 * @class rune::Vec3
 * @brief 1 x 3 vector to be used for math.
 *
 * @author Thomas Montano
 * @date May 21 2020
*/

#include <core.h>

#ifndef VEC3_H_DEFINED
#define VEC3_H_DEFINED

namespace rune{

class RUNE_ENGINE Vec3
{

public:
  double x;
  double y;
  double z;

};

}

#endif