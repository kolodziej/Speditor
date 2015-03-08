#ifndef SPEDITOR_TRAFFIC_POLICY_SINUS_HPP
#define SPEDITOR_TRAFFIC_POLICY_SINUS_HPP
#include "policy.hpp"

namespace speditor { namespace traffic_policy {

class Sinus : public Policy
{
public:
	Sinus(short rush_hour, double a = 1.0, double b = 1.0);
	virtual double traffic(Timepoint);
private:
	double calcX_(short);

	short rush_hour_;
	double a_;
	double b_;
};

} }

#endif
