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
enum class EventType
{

  None = 0,
  WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
  KeyPressed, KeyReleased,
  MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled

};

class Event
{

public:
  EventType type = EventType::None;

};
}

#endif