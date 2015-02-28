#ifndef SPEDITOR_ROUTING_POLICY_ABSTRACT_HPP
#define SPEDITOR_ROUTING_POLICY_ABSTRACT_HPP
#include <memory>

namespace speditor {

class Road;

namespace routing_policy {

using RoadPtr = std::shared_ptr<speditor::Road>;

class Abstract
{
public:
	virtual int getRoadWeight(RoadPtr road) = 0;
};

} }

#endif
