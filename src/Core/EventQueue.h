#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include <stdint.h>
#include <memory>
#include <queue>
#include <map>
#include <set>

#include "Event.h"

template<typename T> using UPtrQueue = std::unique_ptr<std::queue<T>>;

class EventQueue
{
  private:
	std::set<uint64_t> times;
	std::map<uint64_t, UPtrQueue<UPtrEvent>> dict_queues;

	uint64_t event_count;
	uint64_t last_time;

  public:
	EventQueue();

	bool is_not_empty();
	void add_event(UPtrEvent e);
	UPtrEvent get_next_event();
};

#endif /* EVENT_QUEUE_H */ 