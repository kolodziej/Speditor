#include "node.hpp"

namespace speditor {

void Node::addRoad(RoadPtr road)
{
	roads_.push_back(road);
}

}
