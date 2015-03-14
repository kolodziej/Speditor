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

#include "tools/logger.hpp"

namespace st = speditor::tasks;
using namespace speditor;

tools::Logger global_logger(std::cout, tools::Logger::Defaults | tools::Logger::ShowTID);

std::random_device rd;

class ScheduleTest : public ::testing::Test
{
protected:
	void SetUp()
	{
	
	}

};

class AccurateTask : public st::Task
{
public:
	AccurateTask(Timepoint begin, Timepoint end) :
		Task{begin, end}
	{}

	virtual bool loop(Timepoint tp)
	{
		if (tp >= endTime())
		{
			return true;
		}
		return false;
	}
};

#define RAND(min, max) rd() % (max - min) + min

/* sets 10 tasks for 2 workers - controls their begin end end time */
TEST_F(ScheduleTest, Basic)
{
	const int min = 2;
	const int max = 10;
	const int tasks_number = 10;
	const int workers_number = 2;
	const int clock_minute = 200;

	Clock clock(clock_minute);
	std::atomic_bool running_clock;
	running_clock = true;
	std::thread clock_thread([&clock, clock_minute](std::atomic_bool* running) {
		while (*running)
		{
			clock.updateTime();
			std::this_thread::sleep_for(std::chrono::milliseconds(clock_minute/10));
		}
	}, &running_clock);

	std::vector<std::tuple<Timepoint, Timepoint, TaskPtr>> tasks;

	for (int i = 0; i < tasks_number; ++i)
	{
		Timepoint begin(RAND(min, max));
		Timepoint end = begin + static_cast<long long>(RAND(min, max));
		auto tup = std::make_tuple(begin, end, std::make_shared<AccurateTask>(begin, end));
		tasks.push_back(tup);
	}

	Schedule schedule(clock, workers_number);
	for (auto task : tasks)
	{
		schedule.addTask(std::get<2>(task));
	}

	// starts tasks
	clock.reset();
	schedule.start();
	schedule.wait();
	running_clock = false;
	clock_thread.join();

	// checking test
	for (auto task : tasks)
	{
		TaskPtr t = std::get<2>(task);

		// start time
		ASSERT_EQ(t->plannedStart(), std::get<0>(task));
		ASSERT_EQ(t->plannedStart(), t->startTime());

		// end time
		ASSERT_EQ(t->plannedEnd(), std::get<1>(task));
		ASSERT_EQ(t->endTime().get(), t->plannedEnd().get());
	}
}
