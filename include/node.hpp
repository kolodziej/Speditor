#ifndef SPEDITOR_NODE_HPP
#define SPEDITOR_NODE_HPP
#include "node_type.hpp"
#include "road.hpp"

#include <vector>
#include <memory>

namespace speditor {

class Map;
class Road;

using RoadPtr = std::shared_ptr<Road>;
using NodePtr = std::shared_ptr<Node>;
using NodeId = unsigned long long;

class Node
{
public:
	Node(Map&);
	NodeId id() const;
	virtual NodeType type() = 0;
	void addRoad(RoadPtr);
	std::vector<RoadPtr> roads();

private:
	NodeId id_;
	std::vector<RoadPtr> roads_;

	// Dijkstra algorithm fields
	int time_;
	RoadPtr road_;
	NodePtr previous_node_;

friend class Map;
};

}

#endif
