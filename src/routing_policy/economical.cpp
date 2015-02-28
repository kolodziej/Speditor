#include "routing_policy/economical.hpp"

#include "road.hpp"

namespace speditor { namespace routing_policy {

int Economical::getRoadWeight(RoadPtr road)
{
	return static_cast<int>(road->length() * (1.00 - road->traffic()));
}

} }


