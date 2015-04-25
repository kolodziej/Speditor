#include "gtest/gtest.h"
#include "timepoint.hpp"

using speditor::Timepoint;

#include "tools/logger.hpp"

speditor::tools::Logger global_logger(std::cout, speditor::tools::Logger::Defaults | speditor::tools::Logger::ShowTID);

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
  ASSERT_EQ(tp.day(), 3); // 3rd day of 1st week = 0*7 + 3
  ASSERT_EQ(tp.dayOfWeek(), 2); // 3rd day of week
  ASSERT_EQ(tp.week(), 1); // first week in progress
}

TEST(Timepoint, Adv2)
{
  Timepoint tp(0, 0, 4, 5);
  ASSERT_EQ(tp.minute(), 0);
  ASSERT_EQ(tp.hour(), 0);
  ASSERT_EQ(tp.day(), 32); // 4th day of 5th week = 4*7 + 4
  ASSERT_EQ(tp.dayOfWeek(), 3); // 4th day (we count from 0)
  ASSERT_EQ(tp.week(), 5);
}

TEST(Timepoint, Operators)
{
  Timepoint tp1(1);
  int interval = 2;

  Timepoint r1 = tp1 + interval;
  ASSERT_EQ(r1.get(), 3);
  
  Timepoint tp3(23,59,1,1);
  ASSERT_EQ(tp3.minute(), 59);
  ASSERT_EQ(tp3.hour(), 23);
  ASSERT_EQ(tp3.day(), 1);
  ASSERT_EQ(tp3.dayOfWeek(), 0);
  ASSERT_EQ(tp3.week(), 1);
}

TEST(Timepoint, OparatorEqual)
{
  const unsigned int time = 10;
  Timepoint tp1(time), tp2(time);
  ASSERT_EQ(tp1, tp2);
  ASSERT_TRUE(tp1 == tp2);
}

TEST(Timepoint, Comparison)
{
  Timepoint t1(1), t2(1), t3(2);
  ASSERT_EQ(t1, t2);
  ASSERT_NE(t2, t3);
  ASSERT_GT(t3, t2);
  ASSERT_GE(t3, t2);
  ASSERT_GE(t1, t2);
  ASSERT_LT(t2, t3);
  ASSERT_LE(t2, t3);
  ASSERT_LE(t1, t2);
}

TEST(Timepoint, Incrementation)
{
  Timepoint tp(23, 59, 1, 1); // 1st day of 1st week, 23:59
  Timepoint tp2 = tp++;

  ASSERT_EQ(tp2.minute(), 59);
  ASSERT_EQ(tp2.hour(), 23);
  ASSERT_EQ(tp2.day(), 1);
  ASSERT_EQ(tp2.dayOfWeek(), 0);
  ASSERT_EQ(tp2.week(), 1);

  ASSERT_EQ(tp.minute(), 0);
  ASSERT_EQ(tp.hour(), 0);
  ASSERT_EQ(tp.day(), 2);
  ASSERT_EQ(tp.dayOfWeek(), 1);
  ASSERT_EQ(tp.week(), 1);

  Timepoint tp3 = ++tp;

  ASSERT_EQ(tp3.minute(), tp.minute());
  ASSERT_EQ(tp3.hour(), tp.hour());
  ASSERT_EQ(tp3.day(), tp.day());
  ASSERT_EQ(tp3.dayOfWeek(), tp.dayOfWeek());
  ASSERT_EQ(tp3.week(), tp.week());
}

TEST(Timepoint, Decrementation)
{
  Timepoint tp(23, 59, 1, 1); // 1st day of 1st week, 23:59

  Timepoint tp2 = --tp;

  ASSERT_EQ(tp.minute(), 58);
  ASSERT_EQ(tp.hour(), 23);
  ASSERT_EQ(tp.day(), 1);
  ASSERT_EQ(tp.dayOfWeek(), 0);
  ASSERT_EQ(tp.week(), 1);

  ASSERT_EQ(tp2.minute(), tp.minute());
  ASSERT_EQ(tp2.hour(), tp.hour());
  ASSERT_EQ(tp2.day(), tp.day());
  ASSERT_EQ(tp2.dayOfWeek(), tp.dayOfWeek());
  ASSERT_EQ(tp2.week(), tp.week());

  Timepoint tp3 = tp--;

  ASSERT_EQ(tp.minute(), 57);
  ASSERT_EQ(tp.hour(), 23);
  ASSERT_EQ(tp.day(), 1);
  ASSERT_EQ(tp.dayOfWeek(), 0);
  ASSERT_EQ(tp.week(), 1);

  ASSERT_EQ(tp3.minute(), 58);
  ASSERT_EQ(tp3.hour(), 23);
  ASSERT_EQ(tp3.day(), 1);
  ASSERT_EQ(tp3.dayOfWeek(), 0);
  ASSERT_EQ(tp3.week(), 1);
}


