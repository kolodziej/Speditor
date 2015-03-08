#ifndef SPEDITOR_TRAFFIC_POLICY_SINUS_HPP
#define SPEDITOR_TRAFFIC_POLICY_SINUS_HPP
#include "policy.hpp"

namespace speditor { namespace traffic_policy {

class Sinus : public Policy
{
public:
	Sinus(short);
	virtual double traffic(Timepoint);
private:
	constexpr double calcX_(short);

	short rush_hour_;
};

} }

#endif
