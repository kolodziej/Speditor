#ifndef SPEDITOR_TRAFFIC_POLICY_SINUS_HPP
#define SPEDITOR_TRAFFIC_POLICY_SINUS_HPP
#include "policy.hpp"

namespace speditor { namespace traffic_policy {

class Sinus : public Policy
{
public:
	virtual double traffic(Timepoint);
private:
	constexpr double calcX_(short);
};

} }

#endif
