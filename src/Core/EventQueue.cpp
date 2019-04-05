#include "EventQueue.h"

EventQueue::EventQueue()
{
	this->event_count = 0;
	this->last_time = 0;
}

bool EventQueue::is_not_empty()
{
	return event_count != 0;
}

void EventQueue::add_event(UPtrEvent e)
{
	if(e->time < last_time)
	{
		throw "Event time " + std::to_string(e->time) + " < last time " + std::to_string(last_time); 
	}

	if(!dict_queues.count(e->time))
	{
		times.insert(e->time);

		dict_queues.insert(std::pair<uint64_t, UPtrQueue<UPtrEvent>>(e->time, (std::make_unique<std::queue<UPtrEvent>>()) ) );
	}
	(dict_queues[e->time])->push(std::move(e));
	event_count++;
}

UPtrEvent EventQueue::get_next_event()
{
	uint64_t min_time = *times.begin();

	while(dict_queues[min_time]->size() == 0)
	{ // Get next queue
		times.erase(times.begin());
		dict_queues.erase(min_time);
		min_time = *times.begin();
	}

	last_time = min_time;
	event_count--;

	auto event = std::move((dict_queues[min_time])->front());
	(dict_queues[min_time])->pop();

	return event;
}