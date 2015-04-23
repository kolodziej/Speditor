#ifndef SPEDITOR_ROUTING_POLICY_ECONOMICAL_HPP
#define SPEDITOR_ROUTING_POLICY_ECONOMICAL_HPP

#include "abstract.hpp"

namespace speditor { namespace routing_policy {

class Economical : public Abstract
{
 public:
	int getRoadWeight(RoadPtr);
};

} }

#endif

