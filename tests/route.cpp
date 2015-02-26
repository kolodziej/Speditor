#include "gtest/gtest.h"
#include "map.hpp"
#include "route.hpp"
#include "road.hpp"
#include "city.hpp"

#include <vector>
#include <memory>

#include "tools/logger.hpp"

using namespace speditor;

speditor::tools::Logger global_logger(std::cerr, true, false);

class RouteTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		cities = {
			std::make_shared<City>("One"),
			std::make_shared<City>("Two"),
			std::make_shared<City>("Three"),
			std::make_shared<City>("Four")
		};

		for (auto city : cities)
		{
			for (auto in_city : cities)
			{
				if (city == in_city)
					continue;

				city->addRoad(std::make_shared<Road>(in_city, 100));
			}
		}
	}

	std::vector<NodePtr> cities;
};

TEST_F(RouteTest, Continuous)
{
	Route route(cities[0], {
		cities[0]->roads()[0],
		cities[1]->roads()[2],
		cities[3]->roads()[2]
	});

	ASSERT_EQ(route.startNode(), cities[0]);
	ASSERT_EQ(route.endNode(), cities[2]);
	ASSERT_TRUE(route.continuous());
}

TEST_F(RouteTest, NotContinuous)
{
	Route route(cities[0], {
		cities[0]->roads()[0],
		cities[1]->roads()[2],
		cities[3]->roads()[2],
		cities[1]->roads()[0]
	});

	ASSERT_EQ(route.startNode(), cities[0]);
	ASSERT_EQ(route.endNode(), cities[0]);
	ASSERT_FALSE(route.continuous());
}
