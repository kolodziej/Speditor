#include "gtest/gtest.h"
#include "schedule.hpp"
#include "tasks/task.hpp"
#include "tasks/queue.hpp"
#include "clock.hpp"

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <chrono>
#include <random>
#include <vector>
#include <utility>
#include <stdexcept>

#include "tools/logger.hpp"

namespace st = speditor::tasks;
using namespace speditor;

tools::Logger global_logger(std::cout, tools::Logger::Defaults | tools::Logger::ShowTID);

std::random_device rd;

class ScheduleTest : public ::testing::Test
{
 protected:
  ScheduleTest() :
      clock{30}
  {}

  void SetUp()
  {
    min = 5;
    max = 10;
    tasks_number = 100;
    workers_number = 5;
    clock_minute = 20;
  }

  void TearDown()
  {
    tasks.clear();
  }

  int min;
  int max;
  int tasks_number;
  int workers_number;
  int clock_minute;

  std::vector<std::tuple<Timepoint, Timepoint, TaskPtr>> tasks;
  Clock clock;
};

struct TooFastClock : public std::runtime_error
{
  TooFastClock(const char* what) :
      std::runtime_error(what)
  {}
};

class EmptyTask : public st::Task
{
 public:
  EmptyTask(Timepoint begin) :
      Task{begin, begin}
  {}

  virtual void action(Timepoint tp)
  {
    finish(tp);
  }
};

class AccurateTask : public st::Task
{
 public:
  AccurateTask(Timepoint begin, Timepoint end) :
      Task{begin, end}
  {}

  virtual void action(Timepoint tp)
  {
    if (plannedEnd() == tp)
    {
      finish(tp);
    } else if (plannedEnd() < tp && running())
    {
      throw TooFastClock("AccurateTask");
    }
  }
};

class InAccurateTask : public st::Task
{
 public:
  InAccurateTask(Timepoint begin, Timepoint end, Duration late):
    Task{begin, end},
    late_{late}
  {}

  virtual void action(Timepoint tp)
  {
    if (plannedEnd() + late_ == tp)
    {
      finish(tp);
    } else if (plannedEnd() + late_ < tp && running())
    {
      throw TooFastClock("InAccurateTask");
    }
  }

 private:
  Duration late_;
};

#define RAND(min, max) rd() % (max - min + 1) + min

TEST_F(ScheduleTest, EmptySchedule)
{
  Schedule schedule(clock, 10);
  clock.run();
  schedule.start();
  schedule.wait();
  clock.wait();
}

TEST_F(ScheduleTest, EmptyTask)
{
  Schedule schedule(clock, 2);
  for (int i = 0; i < tasks_number; ++i)
  {
    Timepoint begin(0);
    TaskPtr ptr = std::make_shared<EmptyTask>(begin);
    auto tup = std::make_tuple(begin, begin, ptr);
    tasks.push_back(tup);
    if (schedule.addTask(ptr) == false)
    {
      LogError("Task ", ptr->id(), " has not been added to Schedule!");
    }
  }
  clock.run();
  schedule.start();
  schedule.wait();
  clock.wait();

  for (auto task : tasks)
  {
    ASSERT_EQ(std::get<0>(task), std::get<2>(task)->plannedStart());
    ASSERT_EQ(std::get<1>(task), std::get<2>(task)->plannedEnd());

    ASSERT_EQ(std::get<0>(task), std::get<2>(task)->startTime());
    ASSERT_EQ(std::get<1>(task), std::get<2>(task)->endTime());
  }
}

TEST_F(ScheduleTest, BasicAccurate)
{
  Schedule schedule(clock, workers_number);
  for (int i = 0; i < tasks_number; ++i)
  {
    Timepoint begin(RAND(min, max));
    Timepoint end = begin + Duration(RAND(min, max));
    TaskPtr ptr = std::make_shared<AccurateTask>(begin, end);
    auto tup = std::make_tuple(begin, end, ptr);
    tasks.push_back(tup);
    if (schedule.addTask(ptr) == false)
    {
      LogError("Task ", ptr->id(), " has not been added to Schedule!");
    }
  }

  // starts tasks
  clock.run();
  schedule.start();
  schedule.wait();
  clock.wait();

  // checking test
  for (auto task : tasks)
  {
    TaskPtr t = std::get<2>(task);

    // start time
    ASSERT_EQ(t->plannedStart(), std::get<0>(task));
    ASSERT_EQ(t->plannedStart(), t->startTime());

    // end time
    ASSERT_EQ(t->plannedEnd(), std::get<1>(task));
    ASSERT_EQ(t->endTime(), t->plannedEnd());
  }
}

TEST_F(ScheduleTest, BasicInAccurate)
{
  Schedule schedule(clock, workers_number);
  for (int i = 0; i < tasks_number; ++i)
  {
    Timepoint begin{RAND(min, max)};
    Timepoint end{begin + Duration(RAND(min, max))};
    Duration late{RAND(1,min)};
    TaskPtr ptr = std::make_shared<InAccurateTask>(begin, end, late);
    auto tup = std::make_tuple(begin, end+late, ptr);
    tasks.push_back(tup);
    if (schedule.addTask(ptr) == false)
    {
      LogError("Task ", ptr->id(), " has not been added to Schedule!");
    }
  }

  clock.run();
  schedule.start();
  schedule.wait();
  clock.wait();

  // checking test
  for (auto task : tasks)
  {
    TaskPtr t = std::get<2>(task);

    // start time
    ASSERT_EQ(t->plannedStart(), std::get<0>(task));
    ASSERT_EQ(t->plannedStart(), t->startTime());

    // end time
    ASSERT_EQ(t->endTime(), std::get<1>(task));
  }
}

TEST_F(ScheduleTest, Queues)
{
  
}
