#ifndef SPEDITOR_ROAD_HPP
#define SPEDITOR_ROAD_HPP
#include <memory>


namespace speditor {

class Node;

class Road
{
public:
	Road() {}

private:
	int length_;
	int max_speed_;
	int avarage_speed_;
	double traffic_;
	std::shared_ptr<Node> destination_;
};

}

#endif
