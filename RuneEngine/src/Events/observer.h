/**
 * @class rune::Observer
 * @brief An interface that allows objects to watch a subject for signals, and perform some action when notified.
 *
 * @author Thomas Montano
 * @date July 29 2020
*/


#pragma once

#include <core.h>
#include "signal.h"

namespace rune{

class RUNE_ENGINE Observer
{
public:
  ///A virtual method to be overridden by a concrete implementation of the observer class.
  virtual void onNotify(Signal const& signal) = 0;

};

}//namespace rune