/**
 * @class rune::Subject
 * @brief A subject that can be watched for signals by observers.
 *
 * @author Thomas Montano
 * @date July 29 2020
*/

#pragma once

#include <core.h>
#include <DataStructures/list.h>
#include <vector>

namespace rune{

  class Observer;
  class Signal;

  class RUNE_ENGINE Subject
  {
  protected:
    ///Send a signal to all observers
    void sendSignal(Signal);
    ///List of observers currently subscribed to this object.
    std::vector<Observer*> observers;
    ///Get the number of observers subscribed to this subject.
    int getNumObservers(void);

  public:
    ///Tell the subject that an observer would like to be notified of signals.
    void subscribe(Observer& newObserver);
    ///Tell the subject that an observer would no longer like to be notified of signals.
    bool unsubscribe(Observer& newObserver);

  };

}//namespace rune

