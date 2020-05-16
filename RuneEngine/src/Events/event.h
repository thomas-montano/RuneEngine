/**
 * @class rune::Event
 * @brief Object that holds all the events for a render window.
 * 
 * @author Thomas Montano
 * @date April 20 2020
*/

#ifndef EVENT_H_DEFINED
#define EVENT_H_DEFINED

namespace rune{

///Possible window level events that can be triggered
enum EventType{None,Closed,Resized,KeyPressed};

class Event
{

public:
  EventType type = None;

};
}

#endif