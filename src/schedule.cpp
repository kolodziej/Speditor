#include "schedule.hpp"

#include <algorithm>
#include <cmath>

#include "clock.hpp"
#include "tools/logger.hpp"

namespace speditor {

Schedule::Schedule(Clock& clock, unsigned long threads) :
	clock_(clock),
	threads_num_{threads},
	threads_running_{false}
{}

void Schedule::addTask(TaskPtr task)
{
	tasks_.push_back(task);
}

void Schedule::removeTask(TaskPtr task)
{
	auto it = std::find(tasks_.begin(), tasks_.end(), task);
	if (it != tasks_.end())
	{
		tasks_.erase(it);
	}
}

void Schedule::start()
{
	threads_running_ = true;
	auto thread_body = [&](std::atomic_bool* running) {
		bool all_finished = false;
		while (*running && all_finished == false)
		{
			all_finished = true;
			for (auto task : tasks_)
			{
				if (task->finished())
				{
					continue;
				}
				if (task->mtx_.try_lock())
				{
					if (task->doLoop_(clock_.timepoint()) == false)
					{
						all_finished = false;
					}
					task->mtx_.unlock();
				}
			}
		}
	};
	for (int i = 0; i < threads_num_; ++i)
	{
		LogInfo("Starting Schedule's ", i, " thread!");
		threads_.emplace_back(thread_body, &threads_running_);
	}
}

void Schedule::wait()
{
	for (auto& t : threads_)
	{
		t.join();
	}
	LogInfo("All Schedule's workers finished their work!");
}

void Schedule::stop()
{
	LogInfo("Stopping Schedule's threads...");
	threads_running_ = false;
	for (auto& t : threads_)
	{
		t.join();
	}
	LogInfo("All Schedule's threads stopped!");
}

int Schedule::threads() const
{
	return threads_.size();
}

int Schedule::tasksPerThread() const
{
	return std::ceil(static_cast<double>(tasks_.size()) / static_cast<double>(threads()));
}

}
