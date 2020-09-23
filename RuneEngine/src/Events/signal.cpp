#include "signal.h"
#include "subject.h"

///@param creator A pointer to the person who pushed out the signal.
/// @param callback The function to call when this signal is sent.
rune::Signal::Signal(Subject* creator, void* callback)
  : signalCreator(creator), functionPtr(callback)
{}

