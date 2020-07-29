#include "subject.h"
#include "observer.h"
#include "signal.h"

///@param signalValue The type of signal
void rune::Subject::notify(unsigned int signalValue)
{

  Signal signal = Signal(this, signalValue);

  for (int i = 0; i < observers.size(); i++)
  {

    observers[i]->onNotify(signal);

  }

}

///@param newObserver The observer that would like to be notified of signals.
/// @return Whether or not the observer was successfully subscribed.
bool rune::Subject::subscribe(Observer& newObserver)
{
  observers.push_back(&newObserver);
  return true;
}

///@param newObserver The observer that would no longer like to be notified of signals.
/// @return Whether or not the observer was successfully subscribed.
bool rune::Subject::unsubscribe(Observer& newObserver)
{

  return true;
}
