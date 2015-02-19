#ifndef SPEDITOR_MAP_HPP
#define SPEDITOR_MAP_HPP
#include <vector>
#include <memory>
#include <istream>

namespace speditor {

class Node;
class Route;

class Map
{
public:
	void addNode(std::shared_ptr<Node>);
	void calcRoute(std::shared_ptr<Route>);
	void calcRoadsParams();

private:
	std::vector<std::shared_ptr<Road>> algDijkstra_(std::shared_ptr<Node>, std::shared_ptr<Node>);

	std::vector<std::shared_ptr<Node>> nodes_;
};

}

#endif