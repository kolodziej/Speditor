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

	std::vector<std::shared_ptr<Node>> getMiddlePoints();
	void addMiddlePoint(std::shared_ptr<Node>);
	bool removeMiddlePoint(std::shared_ptr<Node>);

private:
	std::shared_ptr<Node> start_point_;
	std::shared_ptr<Node> end_point_;
	std::vector<std::shared_ptr<Node>> middle_points_;
	std::vector<std::shared_ptr<Road>> roads_;

	friend class Map;
};

}

#endif
