#include "signal.h"
#include "subject.h"

///@param creator A pointer to the person who pushed out the signal.
/// @param val The type of signal pushed.
rune::Signal::Signal(Subject* creator, unsigned int val)

  : signalCreator(creator), signalValue(val)
{}

