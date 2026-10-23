#include "subject.h"
#include "observer.h"
#include "signal.h"

///@param signalToSend The signal to be sent out to all the observers.
void rune::Subject::sendSignal(Signal signalToSend)
{

  for (int i = 0; i < observers.size(); i++)
  {

    observers[i]->onNotify(signalToSend);

  }

}

///@return The number of observers currently subscribed to this subject.
int rune::Subject::getNumObservers(void)
{
  return observers.size();
}

///@param newObserver The observer that would like to be notified of signals.
void rune::Subject::subscribe(Observer& newObserver)
{
  observers.push_back(&newObserver);
}

///@param observer The observer that would no longer like to be notified of signals.
/// @return Whether or not the observer was successfully unsubscribed.
bool rune::Subject::unsubscribe(Observer& observer)
{

  for(int i = 0; i < observers.size(); i++)
  {
  
    if(observers[i] == &observer)
    {
    
      observers.erase(observers.begin() + i);
    
      return true;

    }
  
  }

  return false;
}
