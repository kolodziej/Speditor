#ifndef SPEDITOR_ROUTE_HPP
#define SPEDITOR_ROUTE_HPP
#include <memory>
#include <vector>

namespace speditor {

class Node;
class Road;
class Map;

using NodePtr = std::shared_ptr<Node>;
using RoadPtr = std::shared_ptr<Road>;

class Route
{
public:
	Route(NodePtr, NodePtr);

	std::vector<NodePtr> getAllNodes();
	void addMiddleNode(NodePtr);
	bool removeMiddleNode(NodePtr);

private:
	NodePtr start_node_;
	NodePtr end_node_;
	std::vector<NodePtr> middle_nodes_;
	std::vector<RoadPtr> roads_;

	friend class Map;
};

}

#endif
