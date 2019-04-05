#include "Event.h"

uint64_t Event::id_count = 0;

Event::Event(uint64_t time) : id(id_count++)
{
    this->time = time;
}