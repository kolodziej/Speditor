#include "map.hpp"

namespace speditor {

void Map::addNode(NodePtr node)
{
	nodes_.insert(std::make_pair(node->id(), node));
}

void Map::calcRoute(RoutePtr route)
{
	route->roads_.clear();
	std::vector<NodePtr> nodes = std::move(route->getAllNodes());
	if (nodes.empty() == false)
	{
		for (auto it = nodes.begin() + 1; it != nodes.end(); ++it)
		{
			for (auto road : algDijkstra_(*(it-1), *it))
			{
				route->roads_.push_back(road);
			}
		}
	}
}

void Map::calcRoadsParams()
{
	for (auto node_pair : nodes_)
	{
		NodePtr node = node_pair.second;
		for (auto road : node->roads())
		{
			road->average_speed_ = road->max_speed_ * (1.2 - road->traffic_);
		}
	}
}

NodeId Map::nextNodeId()
{
	return ++last_node_id_;
}

std::vector<RoadPtr> Map::algDijkstra_(NodePtr begin, NodePtr end)
{
	// use Dijkstra algorithm to find shortest path from begin to end
}

}
