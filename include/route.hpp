#ifndef SPEDITOR_ROUTE_HPP
#define SPEDITOR_ROUTE_HPP
#include <memory>
#include <vector>

namespace speditor {

class Node;
class Road;
class Map;

class Route
{
public:
	Route(std::shared_ptr<Node>, std::shared_ptr<Node> = nullptr);

	std::vector<std::shared_ptr<Node>> getAllNodes();
	void addMiddleNode(std::shared_ptr<Node>);
	bool removeMiddleNode(std::shared_ptr<Node>);

private:
	std::shared_ptr<Node> start_node_;
	std::shared_ptr<Node> end_node_;
	std::vector<std::shared_ptr<Node>> middle_nodes_;
	std::vector<std::shared_ptr<Road>> roads_;

	friend class Map;
};

}

#endif
