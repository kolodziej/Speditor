#include "node.hpp"

#include "map.hpp"

namespace speditor {

Node::Node(Map& map) :
	id_(map.nextNodeId())
{}

NodeId Node::id() const
{
	return id_;
}

void Node::addRoad(RoadPtr road)
{
	roads_.push_back(road);
}

std::vector<RoadPtr> Node::roads()
{
	std::vector<RoadPtr> roads = roads_;
	return roads_;
}

}
