#include "tasks/queue.hpp"

namespace speditor { namespace tasks {

Queue::Queue(std::initializer_list<TaskPtr> list) :
	tasks_{list}
{}

void Queue::begin()
{
}

void Queue::loop(Timepoint tp)
{
}

void Queue::addTask(TaskPtr task)
{
}

void Queue::removeTask(TaskPtr task)
{
}

std::vector<TaskPtr>&& Queue::getTasks()
{
}

} }
