#ifndef EVENT_H
#define EVENT_H

#include <stdint.h>
#include <memory>

class Event
{
private:
   static uint64_t id_count;

public:
    const uint64_t id;
    uint64_t time;

    Event(uint64_t time = 0);
};

using UPtrEvent = std::unique_ptr<Event>;

#endif /* EVENT_H*/