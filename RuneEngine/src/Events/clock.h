#pragma once
/**
 * @class rune::Clock
 * @brief A clock that can be used to tell how much time has passed.
 * 
 * @author Thomas Montano
 * @date April 27 2020
*/

#ifndef CLOCK_H_DEFINED
#define CLOCK_H_DEFINED

#include "core.h"
#include <time.h>

namespace rune{

class RUNE_ENGINE Clock
{
private:
  struct timespec ts;
  long long startTime;
  long long lastNanos;

public:
  ///Default constructor to create a clock and have the start time be equal to the time it was created.
  Clock();

  ///Get the number of milliseconds since the clock was created or restarted.
  long getElapsedTimeAsMilliseconds();

  ///Reset the clock so that the total amount of time pass equals 0.
  void reset();
};
}

#endif