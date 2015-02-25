#include "route.hpp"

#include "road.hpp"
#include <algorithm>

namespace speditor {

Route::Route(NodePtr start_node) :
	start_node_(start_node)
{}

Route::Route(NodePtr start_node, std::vector<RoadPtr> roads) :
	start_node_(start_node),
	roads_(roads)
{}

std::vector<RoadPtr> Route::roads()
{
	return roads_;
}

NodePtr Route::startNode()
{
	return start_node_;
}

NodePtr Route::endNode()
{
	if (roads_.empty())
	{
		return nullptr;
	}

	return roads_.back()->destination();
}

}
