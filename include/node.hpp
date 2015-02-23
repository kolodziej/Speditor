#ifndef SPEDITOR_NODE_HPP
#define SPEDITOR_NODE_HPP
#include "node_type.hpp"
#include "road.hpp"

#include <vector>
#include <memory>

namespace speditor {

class Road;

using RoadPtr = std::shared_ptr<Road>;

class Node
{
public:
	Node() {}
	virtual NodeType type() = 0;
	void addRoad(std::shared_ptr<Road>);

private:
	std::vector<std::shared_ptr<Road>> roads_;
};

}

#endif
