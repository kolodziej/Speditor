#include "schedule.hpp"

#include <algorithm>
#include <cmath>

#include "clock.hpp"

namespace speditor {

Schedule::Schedule(Clock& clock, int threads) :
	clock_(clock),
	threads_(threads),
	threads_running_{true}
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

int Schedule::threads() const
{
	return threads_.size();
}

int Schedule::tasksPerThread() const
{
	return std::ceil(static_cast<double>(tasks_.size()) / static_cast<double>(threads()));
}

void Schedule::threadBody_(const std::atomic_bool& running)
{
	while (running)
	{
		for (auto task : tasks_)
		{
			if (task->mtx_.try_lock())
			{
				task->doLoop_(clock_.timepoint());
				task->mtx_.unlock();
			}
		}
	}
}

}
