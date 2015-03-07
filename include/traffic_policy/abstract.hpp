#ifndef SPEDITOR_TRAFFIC_POLICY_ABSTRACT_HPP
#define SPEDITOR_TRAFFIC_POLICY_ABSTRACT_HPP
#include <memory>

namespace speditor {

class Timepoint;

namespace traffic_policy {

class Abstract
{
public:
	virtual double traffic(Timepoint) = 0;
};

} }

#endif
