#ifndef SPEDITOR_TRAFFIC_POLICY_HPP
#define SPEDITOR_TRAFFIC_POLICY_HPP
#include "policy.hpp"

#include <initializer_list>
#include <functional>
#include <vector>

namespace speditor { namespace traffic_policy {

class Chain : public Policy
{
 public:
	Chain(std::initializer_list<std::reference_wrapper<Policy>>&&);
	virtual double traffic(Timepoint);

 private:
	std::vector<std::reference_wrapper<Policy>> policies_;
};

} }

#endif
