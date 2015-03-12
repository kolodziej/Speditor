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
	Schedule(Clock&, int = 1);

	void addTask(TaskPtr);
	void removeTask(TaskPtr);

	int threads() const;
	int tasksPerThread() const;
	
private:
	void threadBody_(const std::atomic_bool&);
	
	Clock& clock_;
	std::list<TaskPtr> tasks_;
	std::vector<std::thread> threads_;
	std::atomic_bool threads_running_;
};

}

#endif
