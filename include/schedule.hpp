#ifndef SPEDITOR_SCHEDULE_HPP
#define SPEDITOR_SHCEDULE_HPP
#include "tasks/task.hpp"

#include <list>
#include <vector>
#include <thread>
#include <memory>
#include <atomic>

namespace speditor {

class Clock;
using TaskPtr = std::shared_ptr<tasks::Task>;

class Schedule
{
 public:
  Schedule(Clock&, unsigned long = 0);

  bool addTask(TaskPtr);
  void removeTask(TaskPtr);

  void start();
  void wait();
  void stop();
  int threads() const;
  int changeThreadsNumber(unsigned long);
  int tasksPerThread() const;
  
 private:
  Clock& clock_;
  std::list<TaskPtr> tasks_;
  size_t threads_num_;
  std::vector<std::thread> threads_;
  std::atomic_bool threads_running_;
};

}

#endif
