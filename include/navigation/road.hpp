#ifndef SPEDITOR_NAVIGATION_ROAD_HPP
#define SPEDITOR_NAVIGATION_ROAD_HPP
#include <memory>

namespace speditor { namespace navigation {

class Road
{
public:
	Road();

private:
	int length_;
	int max_speed_;
	int avarage_speed_;
	double traffic_;
	std::shared_ptr<Node> destination_;
};

} }

#endif
