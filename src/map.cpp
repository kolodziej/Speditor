#include "map.hpp"

namespace speditor {

void Map::addNode(NodePtr node)
{
	nodes_.insert(std::make_pair(node->id(), node));
}

Route Map::calcRoute(std::vector<NodePtr> nodes)
{
	if (nodes.size() > 1)
	{
		Route rt(nodes.front());
		for (auto it = nodes.begin() + 1; it != nodes.end(); ++it)
		{
			rt += algDijkstra_(*(it-1), *it);
		}

		return rt;
	} else
	{
		// throw proper exception
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

Route Map::algDijkstra_(NodePtr begin, NodePtr end)
{
	// use Dijkstra algorithm to find shortest path from begin to end
}

}
