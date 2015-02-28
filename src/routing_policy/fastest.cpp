#include "routing_policy/fastest.hpp"

#include "road.hpp"

namespace speditor { namespace routing_policy {

int Fastest::getRoadWeight(RoadPtr road)
{
	return road->time();
}

} }

