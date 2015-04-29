#include "tasks/queue.hpp"

#include <algorithm>
#include <stdexcept>

#include "tools/logger.hpp"

namespace speditor { namespace tasks {

Queue::Queue(bool strict) :
  Task{strict}
{}

Queue::Queue(std::initializer_list<TaskPtr> list, bool strict) :
  Task{strict},
  tasks_{list}
{}

bool Queue::isReady() const
{
  return true;
}

Timepoint Queue::plannedStart() const
{
  return tasks_.front()->plannedStart();
}

Timepoint Queue::plannedEnd() const
{
  return tasks_.back()->plannedEnd();
}

Timepoint Queue::startTime() const
{
  return tasks_.front()->startTime();
}

Timepoint Queue::endTime() const
{
  return tasks_.back()->endTime();
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

void Queue::start(Timepoint tp)
{
  Task::start(tp);
  current_task_ = tasks_.begin();
}

void Queue::action(Timepoint tp)
{
  TaskPtr task = *current_task_;
  task->scheduleLoop_(tp);

  if (task->finished())
  {
    ++current_task_;
  }
 
  if (current_task_ == tasks_.end())
  {
    finish(tp);
  }
}

} }
