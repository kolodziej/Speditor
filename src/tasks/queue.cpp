#include "tasks/queue.hpp"

namespace speditor { namespace tasks {

Queue::Queue(std::initializer_list<TaskPtr> list) :
	tasks_{list}
{}

bool Queue::loop(Timepoint tp)
{
	if (isRunning())
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
		if ((*it)->isRunning() == false)
		{
			tasks_.erase(it);
		} else
		{
			// throw proper exception
		}
	}
}

std::vector<TaskPtr> Queue::getTasks()
{
	return tasks_;
}

bool Queue::runTask_(Timepoint tp)
{
	TaskPtr task = *current_task_;
	return task->loop(tp);
}

} }
