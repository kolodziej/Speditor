#include "node.hpp"

namespace speditor {

void Node::addRoad(std::shared_ptr<Road> road)
{
	roads_.push_back(road);
}

}
