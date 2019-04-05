#include <iostream>
#include "Core/Event.h"
#include "Core/EventQueue.h"

int main()
{
	try
	{
		EventQueue eq;

		for(auto i = 0; i < 5; i++)
		{
			eq.add_event(std::make_unique<Event>(5-i));
		}

		uint64_t time = 0;
		while(eq.is_not_empty())
		{
			auto e = eq.get_next_event();
			time = e->time;

			std::cout << "T=" << time << " -> Event (id: " << e->id << "; time: " << e->time << ")" << std::endl;
		}
	}
	catch(const std::string msg)
	{
		std::cerr << msg << '\n';
	}

	return 0;
}
