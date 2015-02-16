#ifndef SPEDITOR_NAVIGATION_MAP_HPP
#define SPEDITOR_NAVIGATION_MAP_HPP
#include <vector>
#include <memory>

namespace speditor { namespace navigation {

class Map
{
public:
	void addNode(std::shared_ptr<Node>);

private:
	std::vector<std::shared_ptr<Node>> nodes_;
};

} }

#endif
