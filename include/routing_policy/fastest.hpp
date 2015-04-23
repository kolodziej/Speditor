#ifndef SPEDITOR_ROUTING_POLICY_FASTEST_HPP
#define SPEDITOR_ROUTING_POLICY_FASTEST_HPP

#include "abstract.hpp"

namespace speditor { namespace routing_policy {

class Fastest : public Abstract
{
 public:
	int getRoadWeight(RoadPtr);
};

} }

#endif

