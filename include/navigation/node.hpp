#ifndef SPEDITOR_NAVIGATION_NODE_HPP
#define SPEDITOR_NAVIGATION_NODE_HPP
#include "node_type.hpp"
#include "road.hpp"

#include <vector>
#include <memory>

namespace speditor { namespace navigation {

class Node
{
public:
	virtual constexpr NodeType type() = 0;
	void addRoad(std::shared_ptr<Road>);

private:
	std::vector<std::shared_ptr<Road>> roads_;
};

} }

#endif
