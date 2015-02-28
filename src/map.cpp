#include "map.hpp"

#include <limits>
#include <queue>
#include <typeinfo>

#include "tools/logger.hpp"

namespace speditor {

Map::Map() :
	last_node_id_{0}
{}

void Map::addNode(NodePtr node)
{
	node->setId_(nextNodeId_());
	nodes_.insert(std::make_pair(node->id(), node));
}

void Map::addRoad(NodePtr node, RoadPtr road)
{
	node->addRoad(road);
	RoadPtr neg_direction = std::make_shared<Road>(*(road.get()));
	neg_direction->destination_ = node;
	road->destination()->addRoad(neg_direction);
}

Route Map::getRoute(routing_policy::Abstract& policy, std::vector<NodePtr> nodes)
{
	if (nodes.size() > 1)
	{
		Route rt(nodes.front());
		for (auto it = nodes.begin() + 1; it != nodes.end(); ++it)
		{
			rt += findShortestRoute_(policy, *(it-1), *it);
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

NodeId Map::nextNodeId_()
{
	return ++last_node_id_;
}

Route Map::findShortestRoute_(routing_policy::Abstract& policy, NodePtr begin, NodePtr end)
{
	auto route_it = routes_.find(std::make_tuple(begin, end, typeid(policy).hash_code()));
	if (route_it == routes_.end())
	{
		return algDijkstra_(policy, begin, end);
	}

	return route_it->second;
}

Route Map::algDijkstra_(routing_policy::Abstract& policy, NodePtr begin, NodePtr end)
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
			if (road->destination()->time_ > node->time_ + policy.getRoadWeight(road))
			{
				NodePtr destination = road->destination();
				destination->time_ = node->time_ + policy.getRoadWeight(road);
				destination->previous_node_ = node;
				destination->road_ = road;
				queue.push(destination);
			}
		}
	}

	std::vector<RoadPtr> roads;
	NodePtr node;
	for (node = end; node->previous_node_ != nullptr; node = node->previous_node_)
	{
		roads.insert(roads.begin(), node->road_);
	}

	Route route(node, roads);
	routes_.insert(std::make_pair(std::make_tuple(begin, end, typeid(policy).hash_code()), route));
	return route;
}

}
