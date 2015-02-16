#ifndef SPEDITOR_NAVIGATION_NODE_HPP
#define SPEDITOR_NAVIGATION_NODE_HPP
#include "road.hpp"
#include <vector>

namespace speditor { namespace navigation {

class Node
{
public:
	virtual constexpr NodeType type();
	void addRoad(Road);

private:
	std::vector<Road> roads_;
};

} }

#endif
