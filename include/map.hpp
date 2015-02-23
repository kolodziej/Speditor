#ifndef SPEDITOR_MAP_HPP
#define SPEDITOR_MAP_HPP
#include <vector>
#include <memory>
#include <istream>

#include "road.hpp"
#include "route.hpp"
#include "node.hpp"

namespace speditor {

using NodePtr = std::shared_ptr<Node>;
using RoutePtr = std::shared_ptr<Route>;
using RoadPtr = std::shared_ptr<Road>;

class Map
{
public:
	void addNode(NodePtr);
	void calcRoute(RoutePtr);
	void calcRoadsParams();

private:
	std::vector<RoadPtr> algDijkstra_(NodePtr, NodePtr);

	std::vector<NodePtr> nodes_;
};

}

#endif
