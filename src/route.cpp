#include "route.hpp"

#include "road.hpp"
#include <algorithm>
#include <iostream>

namespace speditor {

Route::Route(NodePtr start_node) :
	start_node_(start_node)
{}

Route::Route(NodePtr start_node, std::vector<RoadPtr> roads) :
	start_node_(start_node),
	roads_(roads)
{}

std::vector<RoadPtr> Route::roads()
{
	return roads_;
}

NodePtr Route::startNode()
{
	return start_node_;
}

NodePtr Route::endNode()
{
	if (roads_.empty())
	{
		return nullptr;
	}

	return roads_.back()->destination();
}

Route Route::operator+(Route right)
{
	Route left = *this;
	if (left.endNode() == right.startNode())
	{
		for (auto road : right.roads())
		{
			left.addRoad_(road);
		}
	} else
	{
		// throw proper exception
	}

	return left;
}

Route& Route::operator+=(Route right)
{
	if (endNode() == right.startNode())
	{
		for (auto road : right.roads())
		{
			addRoad_(road);
		}
	} else
	{
		// throw proper exception
	}

	return *this;
}
	
void Route::addRoad_(RoadPtr road)
{
	roads_.push_back(road);
}
}
