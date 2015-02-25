#ifndef SPEDITOR_ROAD_HPP
#define SPEDITOR_ROAD_HPP
#include <memory>


namespace speditor {

class Map;
class Node;

using NodePtr = std::shared_ptr<Node>;

class Road
{
public:
	Road();
	Road(NodePtr);

	int length() const;
	int maxSpeed() const;
	int averageSpeed() const;
	int time() const;
	NodePtr destination() const;

private:
	int length_;
	int max_speed_;
	int average_speed_;
	double traffic_;
	NodePtr destination_;

friend class Map;
};

}

#endif
