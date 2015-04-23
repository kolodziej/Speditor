#ifndef SPEDITOR_MAP_HPP
#define SPEDITOR_MAP_HPP
#include <vector>
#include <map>
#include <memory>
#include <mutex>
#include <tuple>

#include "road.hpp"
#include "route.hpp"
#include "node.hpp"
#include "routing_policy/abstract.hpp"

namespace speditor {

using NodePtr = std::shared_ptr<Node>;
using RoadPtr = std::shared_ptr<Road>;

using Path = std::tuple<NodePtr, NodePtr, size_t>;

class Timepoint;

class Map
{
 public:
	Map();

	void addNode(NodePtr);
	void addRoad(NodePtr, RoadPtr);
	Route getRoute(routing_policy::Abstract&, std::vector<NodePtr>);
	void calcRoadsParams(Timepoint);

 private:
	NodeId last_node_id_;

	NodeId nextNodeId_();
	Route findShortestRoute_(routing_policy::Abstract&, NodePtr, NodePtr);
	Route algDijkstra_(routing_policy::Abstract&, NodePtr, NodePtr);
	std::map<NodeId, NodePtr> nodes_;
	std::map<Path, Route> routes_;
};

}

#endif
