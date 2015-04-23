h#include "map.hpp"
#include "timepoint.hpp"

#include <limits>
#include <queue>
#include <typeinfo>
#include <stdexcept>
#include <cmath>

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
	if (nodes.size() < 2)
	{
		throw std::logic_error("nodes number < 2");
	}
	Route rt(nodes.front());
	for (auto it = nodes.begin() + 1; it != nodes.end(); ++it)
	{
		rt += findShortestRoute_(policy, *(it-1), *it);
	}

	return rt;
}

void Map::calcRoadsParams(Timepoint tp)
{
	for (auto node_pair : nodes_)
	{
		NodePtr node = node_pair.second;
		for (auto road : node->roads())
		{
			road->traffic_ = road->policy_->traffic(tp);
			road->average_speed_ = road->max_speed_ - std::exp(std::log(road->max_speed_) * road->traffic_); // average = max - (max ^ traffic);
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
		node.second->weight_ = std::numeric_limits<int>::max();
		node.second->previous_node_ = nullptr;
		node.second->road_ = nullptr;
	}
	
	begin->weight_ = 0;
	struct less_node
	{
		bool operator()(NodePtr a, NodePtr b)
		{
			return (a->weight_ == b->weight_) ? a->id() < b->id() : a->weight_ < b->weight_;
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
			if (road->destination()->weight_ > node->weight_ + policy.getRoadWeight(road))
			{
				NodePtr destination = road->destination();
				destination->weight_ = node->weight_ + policy.getRoadWeight(road);
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
