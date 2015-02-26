#include "node.hpp"

#include "map.hpp"

namespace speditor {

Node::Node() :
	id_{0}
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
	return roads_;
}

void Node::setId_(NodeId id)
{
	if (id_ != 0)
	{
		// throw exception
	}
	id_ = id;
}

}
