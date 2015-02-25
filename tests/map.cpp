#include "gtest/gtest.h"
#include "map.hpp"
#include "city.hpp"
#include "tools/logger.hpp"

#include <iostream>
#include <memory>

#define ADD_ROAD(from, to, length, speed) { \
	auto road = std::make_shared<Road>(to, length, 90, speed); \
	map.addRoad(from, road); \
}

speditor::tools::Logger global_logger(std::cerr, false, false);

using namespace speditor;

class MapTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		cities =
		{
			std::make_shared<City>(map, "Warsaw", 100, 100),
			std::make_shared<City>(map, "Lodz", 100, 100),
			std::make_shared<City>(map, "Pabianice", 100, 100),
			std::make_shared<City>(map, "Berlin", 100, 100)
		};
		for (auto city : cities)
		{
			map.addNode(city);
		}

		ADD_ROAD(cities[0], cities[1], 200, 60);
		ADD_ROAD(cities[0], cities[1], 250, 85);
		ADD_ROAD(cities[1], cities[2], 30, 85);
		ADD_ROAD(cities[1], cities[2], 20, 60);
		ADD_ROAD(cities[1], cities[2], 25, 63);
		ADD_ROAD(cities[1], cities[3], 800, 80);
		ADD_ROAD(cities[1], cities[3], 900, 55);
	}

	Map map;
	std::vector<std::shared_ptr<City>> cities;
};

TEST_F(MapTest, Dijkstra1)
{
	Route route = map.calcRoute({ cities[0], cities[3] });
	ASSERT_EQ(route.startNode(), cities[0]);
	ASSERT_EQ(route.endNode(), cities[3]);
	auto roads = route.roads();
	ASSERT_EQ(roads.size(), 2);
	ASSERT_EQ(roads[0]->length(), 250);
	ASSERT_EQ(roads[1]->length(), 800);
}

TEST_F(MapTest, Dijkstra2)
{
	Route route = map.calcRoute({ cities[0], cities[2], cities[3] });
	ASSERT_EQ(route.startNode(), cities[0]);
	ASSERT_EQ(route.endNode(), cities[3]);
	auto roads = route.roads();
	ASSERT_EQ(roads.size(), 4);

	ASSERT_EQ(roads[0]->length(), 250);
	ASSERT_EQ(roads[1]->length(), 30);
	ASSERT_EQ(roads[2]->length(), 30);
	ASSERT_EQ(roads[3]->length(), 800);
}
