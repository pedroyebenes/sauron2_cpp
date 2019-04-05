#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>

#include "../src/Core/EventQueue.h"

using namespace ::testing;

TEST(EventQueueTest, Emptiness)
{
	EventQueue eq;
	EXPECT_THAT( eq.is_not_empty(), Eq(false) );

	eq.add_event(std::make_unique<Event>());
	EXPECT_THAT( eq.is_not_empty(), Eq(true) );

	auto e = eq.get_next_event();
	EXPECT_THAT( eq.is_not_empty(), Eq(false) );
}

TEST(EventQueueTest, AssureOrder)
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
		EXPECT_THAT( e->time, Ge(time) );
		time = e->time;
	}
}

TEST(EventQueueTest, BackToPast)
{
	auto exception = false;
	EventQueue eq;
	try
	{
		eq.add_event(std::make_unique<Event>(1));
		auto e = eq.get_next_event();
		eq.add_event(std::make_unique<Event>(0));
	}
	catch(const std::string msg)
	{
		exception = true;
	}
	EXPECT_THAT( exception, Eq(true) );
}