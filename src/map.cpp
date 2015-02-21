#include "map.hpp"

namespace speditor {

void Map::addNode(std::shared_ptr<Node> node)
{
	nodes_.push_back(node);
}

void Map::calcRoute(std::shared_ptr<Route> route)
{
	route->roads_.clear();
	std::vector<std::shared_ptr<Node>> nodes = std::move(route->getAllNodes());
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

std::vector<std::shared_ptr<Road>> Map::algDijkstra_(std::shared_ptr<Node> begin, std::shared_ptr<Node> end)
{
	// use Dijkstra algorithm to find shortest path from begin to end
}

}
