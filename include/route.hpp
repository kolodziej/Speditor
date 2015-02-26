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
	Route(NodePtr start_node);
	Route(NodePtr start_node, std::vector<RoadPtr>);

	std::vector<RoadPtr> roads() const;
	NodePtr startNode() const;
	NodePtr endNode() const;
	Route& operator+=(Route);
	bool continuous() const;
	int length() const;
	int time() const;

private:
	NodePtr start_node_;
	std::vector<RoadPtr> roads_;

	void addRoad_(RoadPtr);

friend class Map;
friend Route operator+(Route, Route);
};

Route operator+(Route, Route);

}

#endif
