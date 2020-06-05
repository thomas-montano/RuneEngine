#pragma once

#include <core.h>

#ifndef BEHAVIOR_H_INCLUDED
#define BEHAVIOR_H_INCLUDED

namespace rune{

class RUNE_ENGINE Component
{
public:
  virtual void start();
  
  virtual void update();
  
  virtual void fixedUpdate();
  
};
}

#endif