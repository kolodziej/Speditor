#ifndef SPEDITOR_TRAFFIC_POLICY_MORNING_HPP
#define SPEDITOR_TRAFFIC_POLICY_MORNING_HPP
#include "abstract.hpp"

namespace speditor { namespace traffic_policy {

class Morning : public Abstract
{
public:
	virtual double traffic(Timepoint);
};

} }

#endif
