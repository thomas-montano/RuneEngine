#ifndef EVENT_H_DEFINED
#define EVENT_H_DEFINED

enum EventType{None,Closed,Resized,KeyPressed};

class Event
{

public:
  EventType type = None;

};

#endif