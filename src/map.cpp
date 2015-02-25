#include "map.hpp"

#include <limits>
#include <queue>

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

Route Map::findShortestRoute_(NodePtr begin, NodePtr end)
{
	auto route_it = routes_.find(std::make_pair(begin, end));
	if (route_it == routes_.end())
	{
		return algDijkstra_(begin, end);
	}

	return route_it->second;
}

Route Map::algDijkstra_(NodePtr begin, NodePtr end)
{
	for (auto node : nodes_)
	{
		node.second->time_ = std::numeric_limits<int>::max();
		node.second->previous_node_ = nullptr;
		node.second->road_ = nullptr;
	}
	
	begin->time_ = 0;
	struct less_node
	{
		bool operator()(NodePtr a, NodePtr b)
		{
			return (a->time_ == b->time_) ? a->id() < b->id() : a->time_ < b->time_;
		}
	};
	std::priority_queue<NodePtr, std::vector<NodePtr>, less_node> queue;
	queue.push(begin);

	while (queue.empty() == false)
	{
		NodePtr node = queue.top();
		queue.pop();
		for (auto road : node->roads())
		{
			if (road->destination()->time_ > node->time_ + road->time())
			{
				NodePtr destination = road->destination();
				destination->time_ = node->time_ + road->time();
				destination->previous_node_ = node;
				destination->road_ = road;
				queue.push(destination);
			}
		}
	}

	std::vector<RoadPtr> roads;
	NodePtr node;
	for (node = end; node != nullptr; node = node->previous_node_)
	{
		roads.insert(roads.begin(), node->road_);
	}

	return Route(node, roads);
}

}
