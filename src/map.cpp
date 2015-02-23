#include "map.hpp"

namespace speditor {

void Map::addNode(NodePtr node)
{
	nodes_.push_back(node);
}

void Map::calcRoute(RoutePtr route)
{
	route->roads_.clear();
	std::vector<NodePtr> nodes = std::move(route->getAllNodes());
	for (auto it = nodes.begin() + 1; it != nodes.end(); ++it)
	{
		for (auto road : algDijkstra_(*(it-1), *it))
		{
			route->roads_.push_back(road);
		}
	}
}

void Map::calcRoadsParams()
{
	// calc each road params using traffic factor
}

std::vector<RoadPtr> Map::algDijkstra_(NodePtr begin, NodePtr end)
{
	// use Dijkstra algorithm to find shortest path from begin to end
}

}
