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
    unsigned int signalValue;
    ///Default constructor to create a signal.
    Signal(Subject* creator, unsigned int val);

  };

}

#endif