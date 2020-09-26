/**
 * @class rune::Signal
 * @brief Object that is used as a signal to notify observers of action.
 * 
 * @author Thomas Montano
 * @date July 24 2020
*/

#ifndef EVENT_H_DEFINED
#define EVENT_H_DEFINED

#include <core.h>

namespace rune{

  class Subject;

  class RUNE_ENGINE Signal
  {
  public:
    ///Who the signal originated from.
    Subject* signalCreator;
    ///What was the type of signal sent.
    void (*functionPtr);
    ///Default constructor to create a signal.
    Signal(Subject* creator, void* callback);

  };

}

#endif

/**
 * page Signals Signals
 * 
 * Objects in Rune communicate with each other through the concept of signals. For instance, when a rune::RigidBody collides with another rune::RigidBody a signal is sent to the parent rune::GameObject that a collision has happened.
 * This subsequently calls the `onCollisionEnter(physics::collision)` function on each component of that rune::GameObject.
 * 
 * 
 */