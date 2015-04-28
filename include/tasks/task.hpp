
/* Speditor
 * @author Kacper Kołodziej 2015
 * @url http://kacperkolodziej.com/
 */

#ifndef SPEDITOR_TASKS_TASK_HPP
#define SPEDITOR_TASKS_TASK_HPP
#include "timepoint.hpp"
#include "duration.hpp"

#include <mutex>

namespace speditor {

class Schedule;

namespace tasks {

class Queue;

using TaskId = unsigned long long;

class Task
{
 public:
  Task(bool strict_start = true, Duration interval = 1);
  Task(Timepoint start_time, Timepoint end_time = -1, bool strict_start = true, Duration interval = 1);

  Task(const Task&) = delete;

  TaskId id() const;
  virtual bool isReady() const;

  virtual bool running() const;
  virtual bool finished() const;

  virtual Timepoint plannedStart() const;
  virtual Timepoint startTime() const;

  virtual Timepoint plannedEnd() const;
  virtual Timepoint endTime() const;

  void plannedStart(Timepoint start_time);
  void plannedEnd(Timepoint end_time);

  void setPlan(Timepoint start_time, Timepoint end_time);

  bool strictStart() const;
  void strictStart(bool strict_start);

  virtual void start(Timepoint tp);
  virtual void finish(Timepoint tp);

  virtual void action(Timepoint tp) = 0;

 protected:
  virtual void scheduleLoop_(Timepoint tp);
  static TaskId getNextId_();

 private:
  const TaskId id_;
  Timepoint planned_start_time_;
  Timepoint planned_end_time_;
  Timepoint start_time_;
  Timepoint end_time_;
  bool strict_start_;

  static TaskId lastTaskId_;

 protected:
  Duration interval_;
  Timepoint last_run_;
  std::mutex mtx_;

  friend class speditor::Schedule;
  friend class speditor::tasks::Queue;
};

} }

#endif
