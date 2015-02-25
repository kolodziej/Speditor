#include "gtest/gtest.h"
#include "map.hpp"
#include "city.hpp"

#include <iostream>
#include <memory>

#define ADD_ROAD(from, to, length, speed) { \
	auto road = std::make_shared<Road>(to, length, 90, speed); \
	from->addRoad(road); \
}

using namespace speditor;

TEST(Map, CreatingMap)
{
	ASSERT_TRUE(true);
}

TEST(Map, Dijkstra1)
{
	Map map;
	std::vector<std::shared_ptr<City>> cities =
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

	Route route = map.calcRoute({ cities[0], cities[3] });
	RoadPtr p[3] =
	{
		route.roads()[0],
		route.roads()[1],
		route.roads()[2]
	};
	ASSERT_EQ(route.startNode(), cities[0]);
	ASSERT_EQ(route.endNode(), cities[3]);
	for (auto r : route.roads())
	{
		ASSERT_NE(r, nullptr);
	}
}
