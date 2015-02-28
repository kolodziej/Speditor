#ifndef SPEDITOR_CROSSROADS_HPP
#define SPEDITOR_CROSSROADS_HPP
#include "node.hpp"

namespace speditor {

class Crossroads :
	public Node
{
public:
	virtual NodeType type()
	{
		return NodeType::Crossroads;
	}
};

}

#endif
