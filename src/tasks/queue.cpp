#include "tasks/queue.hpp"

#include <algorithm>
#include <stdexcept>

namespace speditor { namespace tasks {

Queue::Queue(bool strict) :
	Task{strict}
{}

Queue::Queue(std::initializer_list<TaskPtr> list, bool strict) :
	Task{strict},
	tasks_{list}
{}

bool Queue::loop(Timepoint tp)
{
	if (running())
	{
		if ((*current_task_)->loop(tp))
		{
			++current_task_;
		}
	}

	if (current_task_ == tasks_.end())
	{
		return true;
	}

	return false;
}

void Queue::addTask(TaskPtr task)
{
	tasks_.push_back(task);
}

void Queue::removeTask(TaskPtr task)
{
	auto it = std::find(tasks_.begin(), tasks_.end(), task);
	if (it != tasks_.end())
	{
		if ((*it)->running() == false)
		{
			tasks_.erase(it);
		} else
		{
			throw std::runtime_error("task is currently running!");
		}
	}
}

std::vector<TaskPtr> Queue::getTasks()
{
	return tasks_;
}

} }
