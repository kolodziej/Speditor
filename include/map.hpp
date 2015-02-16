#ifndef SPEDITOR_MAP_HPP
#define SPEDITOR_MAP_HPP
#include <vector>
#include <memory>

namespace speditor {

class Map
{
public:
	void addNode(std::shared_ptr<Node>);

private:
	std::vector<std::shared_ptr<Node>> nodes_;
};

}

#endif
