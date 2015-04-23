#ifndef SPEDITOR_TRAFFIC_POLICY_POLICY_HPP
#define SPEDITOR_TRAFFIC_POLICY_POLICY_HPP
#include <memory>

namespace speditor {

class Timepoint;

namespace traffic_policy {

class Policy
{
 public:
	virtual double traffic(Timepoint) = 0;
};

} }

#endif
