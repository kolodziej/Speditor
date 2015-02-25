#ifndef SPEDITOR_MAP_HPP
#define SPEDITOR_MAP_HPP
#include <vector>
#include <map>
#include <memory>
#include <mutex>

#include "road.hpp"
#include "route.hpp"
#include "node.hpp"

namespace speditor {

using NodePtr = std::shared_ptr<Node>;
using RoadPtr = std::shared_ptr<Road>;

using Path = std::pair<NodePtr,NodePtr>;

class Map
{
public:
	Map();

	void addNode(NodePtr);
	Route calcRoute(std::vector<NodePtr>);
	void calcRoadsParams();

	NodeId nextNodeId();

private:
	NodeId last_node_id_;

	Route findShortestRoute_(NodePtr, NodePtr);
	Route algDijkstra_(NodePtr, NodePtr);
	std::map<NodeId, NodePtr> nodes_;
	std::map<Path, Route> routes_;
};

}

#endif
