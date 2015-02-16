#ifndef SPEDITOR_NAVIGATION_CITY_HPP
#define SPEDITOR_NAVIGATION_CITY_HPP
#include "node.hpp"

#include <string>

namespace speditor { namespace navigation {

class City :
	public Node
{
public:
	City(std::string);

	std::string name();

	virtual constexpr NodeType type()
	{
		return NodeType::City;
	}
	
private:
	std::string name_;

};

} }

#endif
