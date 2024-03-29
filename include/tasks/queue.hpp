#ifndef SPEDITOR_TASKS_QUEUE_HPP
#define SPEDITOR_TASKS_QUEUE_HPP
#include "task.hpp"

#include <vector>
#include <memory>
#include <functional>

namespace speditor { namespace tasks {

using TaskPtr = std::shared_ptr<Task>;

class Queue : public Task
{
 public:
  Queue(bool strict = true);
  Queue(std::initializer_list<TaskPtr>, bool strict = true);

  bool isReady() const;

  Timepoint plannedStart() const;
  Timepoint plannedEnd() const;
  Timepoint startTime() const;
  Timepoint endTime() const;

  void addTask(TaskPtr);
  void removeTask(TaskPtr);
  std::vector<TaskPtr> getTasks();

  void start(Timepoint);

  virtual void action(Timepoint);

 private:
  std::vector<TaskPtr> tasks_;
  std::vector<TaskPtr>::iterator current_task_;  
};

} }

#endif
