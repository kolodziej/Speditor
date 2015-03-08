#include "gtest/gtest.h"
#include "timepoint.hpp"

using speditor::Timepoint;

TEST(Timepoint, Basic)
{
	Timepoint tp(3*60);
	ASSERT_EQ(tp.minute(), 0);
	ASSERT_EQ(tp.hour(), 3);
	ASSERT_EQ(tp.day(), 1);
	ASSERT_EQ(tp.dayOfWeek(), 0);
	ASSERT_EQ(tp.week(), 1);
}

TEST(Timepoint, Adv1)
{
	Timepoint tp(2*1440+3*60+42);
	ASSERT_EQ(tp.minute(), 42);
	ASSERT_EQ(tp.hour(), 3);
	ASSERT_EQ(tp.day(), 3);
	ASSERT_EQ(tp.dayOfWeek(), 2);
	ASSERT_EQ(tp.week(), 1);
}
