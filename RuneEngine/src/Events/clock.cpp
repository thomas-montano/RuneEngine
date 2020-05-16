#include "clock.h"
#include <iostream>

rune::Clock::Clock()
{
  timespec_get(&ts,TIME_UTC);
  startTime = ts.tv_sec;
  lastNanos = ts.tv_nsec;
}

/**
 * @return The total elapsed time in milliseconds.
*/
long rune::Clock::getElapsedTimeAsMilliseconds()
{
  timespec_get(&ts,TIME_UTC);
  return ((ts.tv_nsec - lastNanos)/1000000.0) + (ts.tv_sec - startTime)*1000;

}

void rune::Clock::reset()
{
  timespec_get(&ts,TIME_UTC);
  startTime = ts.tv_sec;
  lastNanos = ts.tv_nsec;
}