#include "gtest/gtest.h"
#include "timepoint.hpp"
#include "traffic_policy/chain.hpp"
#include "traffic_policy/sinus.hpp"

namespace tp = speditor::traffic_policy;
using speditor::Timepoint;

TEST(TrafficPolicy, SinusBasic)
{
	tp::Sinus policy(8);

	double eps = 0.001;
	ASSERT_NEAR(policy.traffic(Timepoint(7,0)), 0.991, eps); 
	ASSERT_NEAR(policy.traffic(Timepoint(8,0)), 1.0, eps);
	ASSERT_NEAR(policy.traffic(Timepoint(17,0)), 0.383, eps);
}

TEST(TrafficPolicy, SimpleChain)
{
	tp::Sinus sinus1(6);
	tp::Sinus sinus2(12);
	tp::Chain chain({ sinus1, sinus2 });
	
	double eps = 0.001;
	Timepoint tp(1,0);
	ASSERT_NEAR(sinus1.traffic(tp), 0.793, eps);
	ASSERT_NEAR(sinus2.traffic(tp), 0.131, eps);
	ASSERT_NEAR(chain.traffic(tp), 0.462, eps);

	ASSERT_NEAR(chain.traffic(Timepoint(12,0)), 0.854, eps);
	ASSERT_NEAR(chain.traffic(Timepoint(16,0)), 0.562, eps);
	ASSERT_NEAR(chain.traffic(Timepoint(5,0)), 0.800, eps);
}
