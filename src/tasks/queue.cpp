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

void Queue::action(Timepoint tp)
{
  TaskPtr t = *current_task_;
  bool do_action = false;

  if (t->running())
  {
    if (t->last_run_ + t->interval_ <= tp)
    {
      do_action = true;
    }

    if (t->finished())
    {
      ++current_task_;

      if (current_task_ == tasks_.end())
      {
        t->finish(tp);
      }
    }
  } else if (t->finished() == false)
  {
    if (t->strictStart() || t->plannedStart() >= tp)
    {
      t->start(tp);
      do_action = true;
    }
  }

  if (do_action)
  {
    t->action(tp);
    t->last_run_ = tp;
  }
}

} }
