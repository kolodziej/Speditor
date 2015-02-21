#include "route.hpp"

#include <algorithm>

namespace speditor {

Route::Route(std::shared_ptr<Node> start_node, std::shared_ptr<Node> end_node) :
	start_node_(start_node),
	end_node_(end_node)
{}

std::vector<std::shared_ptr<Node>> Route::getAllNodes()
{
	std::vector<std::shared_ptr<Node>> v = middle_nodes_;
	v.insert(v.begin(), start_node_);
	v.push_back(end_node_);

	return v;
}

void Route::addMiddleNode(std::shared_ptr<Node> node)
{
	middle_nodes_.push_back(node);
}

bool Route::removeMiddleNode(std::shared_ptr<Node> node)
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
