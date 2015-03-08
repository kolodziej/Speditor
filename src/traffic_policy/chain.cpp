#include "traffic_policy/chain.hpp"

#include <stdexcept>
#include "timepoint.hpp"

namespace speditor { namespace traffic_policy {

Chain::Chain(std::initializer_list<std::reference_wrapper<Policy>>&& policies) :
	policies_{policies}
{}

double Chain::traffic(Timepoint tp)
{
	if (policies_.empty())
	{
		throw std::runtime_error("no policies in chain!");
	}

	double t = 0.0;
	int all = 0;
	for (auto p : policies_)
	{
		t += p.get().traffic(tp);
		++all;
	}

	return t / static_cast<double>(all);
}

} }
