#include "gtest/gtest.h"
#include "map.hpp"
#include "city.hpp"
#include "timepoint.hpp"
#include "tools/logger.hpp"

#include "routing_policy/policies.hpp"
#include "traffic_policy/policy.hpp"

#include <iostream>
#include <memory>

using namespace speditor;

class PolicyPercent : public traffic_policy::Policy
{
public:
	PolicyPercent(double traffic) :
		traffic_{traffic}
	{}
	virtual double traffic(Timepoint /*unused*/)
	{
		return traffic_;
	}
private:
	double traffic_;
};

#define AR(map, from, to, length, speed, percent) { \
	auto road = std::make_shared<Road>(to, length, speed, std::shared_ptr<traffic_policy::Policy>(new PolicyPercent(percent))); \
	map.addRoad(from, road); \
}

speditor::tools::Logger global_logger(std::cerr, speditor::tools::Logger::ShowType);

std::string roadsStr(std::vector<std::shared_ptr<Road>> roads)
{
	std::stringstream stream;
	for (auto road : roads)
	{
		stream << "Road info: " << road->length() << "km, " << road->averageSpeed() << " (max: " << road->maxSpeed() << ") km/h, " << road->time() << " min\n";
	}

	return stream.str();
}


class MapTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		// map
		cities =
		{
			std::make_shared<City>("Warsaw"),
			std::make_shared<City>("Lodz"),
			std::make_shared<City>("Pabianice"),
			std::make_shared<City>("Berlin")
		};
		for (auto city : cities)
		{
			map.addNode(city);
			map2.addNode(city);
		}

		AR(map, cities[0], cities[1], 200, 60, 0.0);
		AR(map, cities[0], cities[1], 250, 85, 0.0);
		AR(map, cities[1], cities[2], 30, 85, 0.0);
		AR(map, cities[1], cities[2], 20, 60, 0.0);
		AR(map, cities[1], cities[2], 25, 63, 0.0);
		AR(map, cities[1], cities[3], 800, 80, 0.0);
		AR(map, cities[1], cities[3], 900, 55, 0.0);

		// map2
		nodes = {
			std::make_shared<City>("A"),
			std::make_shared<City>("B"),
			std::make_shared<City>("C"),
		};

		for (auto node : nodes)
		{
			map2.addNode(node);
		}

		AR(map2, nodes[0], nodes[1], 30, 70, 0.0);
		AR(map2, nodes[1], nodes[2], 20, 70, 0.0);
		AR(map2, nodes[2], nodes[0], 35, 36, 0.0);
	}

	Map map;
	Map map2;
	std::vector<std::shared_ptr<City>> cities;
	std::vector<std::shared_ptr<Node>> nodes;
};

TEST_F(MapTest, Dijkstra1)
{
	routing_policy::Fastest policy;
	Route route = map.getRoute(policy, { cities[0], cities[3] });
	ASSERT_EQ(route.startNode(), cities[0]);
	ASSERT_EQ(route.endNode(), cities[3]);
	ASSERT_TRUE(route.continuous());
	auto roads = route.roads();
	ASSERT_EQ(roads.size(), 2u);
	ASSERT_EQ(roads[0]->length(), 250) << roadsStr(roads);
	ASSERT_EQ(roads[1]->length(), 800) << roadsStr(roads);
}

TEST_F(MapTest, Dijkstra2)
{
	routing_policy::Fastest policy;
	Route route = map.getRoute(policy, { cities[0], cities[2], cities[3] });
	ASSERT_EQ(route.startNode(), cities[0]);
	ASSERT_EQ(route.endNode(), cities[3]);
	ASSERT_TRUE(route.continuous());
	auto roads = route.roads();
	ASSERT_EQ(roads.size(), 4u);

	ASSERT_EQ(roads[0]->length(), 250) << roadsStr(roads);
	ASSERT_EQ(roads[1]->length(), 20) << roadsStr(roads);
	ASSERT_EQ(roads[2]->length(), 20) << roadsStr(roads);
	ASSERT_EQ(roads[3]->length(), 800) << roadsStr(roads);
}

#define PC(x) { \
	auto city = x; \
	cities.push_back(city); \
	map.addNode(city); \
}

TEST_F(MapTest, ShortestRoute)
{
	routing_policy::Shortest policy;
	Route route = map2.getRoute(policy, { nodes[0], nodes[2] });
	ASSERT_TRUE(route.continuous());
	ASSERT_EQ(route.roads().size(), 1u);
	ASSERT_EQ(route.roads()[0]->length(), 35);
}

TEST_F(MapTest, FastestRoute)
{
	routing_policy::Fastest policy;
	Route route = map2.getRoute(policy, { nodes[0], nodes[2] });
	ASSERT_TRUE(route.continuous());
	ASSERT_EQ(route.roads().size(), 2u) << roadsStr(route.roads());
}
