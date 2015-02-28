#include "routing_policy/shortest.hpp"

#include "road.hpp"

namespace speditor { namespace routing_policy {

int Shortest::getRoadWeight(RoadPtr road)
{
	return road->length();
}

} }
