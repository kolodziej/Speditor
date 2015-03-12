#include "schedule.hpp"
#include "tasks/task.hpp"
#include "tasks/queue.hpp"
#include "clock.hpp"

#include <iostream>
#include <thread>
#include <memory>
#include <chrono>
#include <random>

#include "tools/logger.hpp"

namespace st = speditor::tasks;
using namespace speditor;

speditor::tools::Logger global_logger(std::cerr, true, true);

class BasicTask : public st::Task
{
public:
	BasicTask(Clock& clock, int loops, int interval) :
		st::Task(clock.timepoint()),
		loops_{loops},
		interval_{interval}
	{}
	virtual bool loop(Timepoint tp)
	{
		if (loops_-- > 0)
		{
			LogInfo("Processing loop for ", interval_);
			std::this_thread::sleep_for(std::chrono::milliseconds(interval_));
			return false;
		}

		return true;
	}
private:
	int loops_;
	int interval_;
};

int main(int argc, char** argv)
{
	Clock clock(100);
	Schedule sch(clock, 1);
	
	std::random_device rd;
	const int tasks = 10;
#define SHT(l,i) std::make_shared<BasicTask>(clock, l, i)
#define RANDOM(min, max) rd() % (max - min) + min 
	for (int i = 0; i < tasks; ++i)
	{
		sch.addTask(SHT(RANDOM(3,5), RANDOM(100,500)));
	}
#undef SHT
#undef RANDOM
	sch.start();
	std::this_thread::sleep_for(std::chrono::seconds(10));
	sch.stop();
}
