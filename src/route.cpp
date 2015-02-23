#include "route.hpp"

#include <algorithm>

namespace speditor {

Route::Route(NodePtr start_node, NodePtr end_node) :
	start_node_(start_node),
	end_node_(end_node)
{}

std::vector<NodePtr> Route::getAllNodes()
{
	std::vector<NodePtr> v = middle_nodes_;
	v.insert(v.begin(), start_node_);
	v.push_back(end_node_);

	return v;
}

void Route::addMiddleNode(NodePtr node)
{
	middle_nodes_.push_back(node);
}

bool Route::removeMiddleNode(NodePtr node)
{
	auto it = std::find(middle_nodes_.begin(), middle_nodes_.end(), node);
	if (it != middle_nodes_.end())
	{
		middle_nodes_.erase(it);
		return true;
	}

	return false;
}

}
