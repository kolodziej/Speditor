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

speditor::tools::Logger global_logger(std::cerr, speditor::tools::Logger::ShowType | speditor::tools::Logger::ShowType | speditor::tools::Logger::ShowTID);

class BasicTask : public st::Task
{
public:
	BasicTask(Clock& clock, int task_id, int loops, int interval) :
		st::Task(clock.timepoint()),
		task_id_{task_id},
		loops_{loops},
		interval_{interval}
	{}
	virtual bool loop(Timepoint tp)
	{
		if (loops_-- > 0)
		{
			LogInfo("#", task_id_, ": Processing loop for ", interval_, ". Left: ", loops_);
			std::this_thread::sleep_for(std::chrono::milliseconds(interval_));
			return false;
		}

		return true;
	}
private:
	int task_id_;
	int loops_;
	int interval_;
};

int main(int argc, char** argv)
{
	Clock clock(100);
	Schedule sch(clock, 5);
	
	std::random_device rd;
	const int tasks = 10;
#define SHT(id,l,i) std::make_shared<BasicTask>(clock, id, l, i)
#define RANDOM(min, max) rd() % (max - min) + min 
	for (int i = 0; i < tasks; ++i)
	{
		sch.addTask(SHT(i, RANDOM(3,5), RANDOM(100,200)));
	}
#undef SHT
#undef RANDOM
	sch.start();
	sch.wait();
	return 0;
}
