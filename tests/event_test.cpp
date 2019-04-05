#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>

#include "../src/Core/Event.h"

using namespace ::testing;

TEST(EventTest, ID_order)
{
	for(auto i = 0; i < 5; i++)
	{
		auto e = std::make_unique<Event>();
		EXPECT_THAT( e->id, Eq(i) );
	}
}
