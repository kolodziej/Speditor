#ifndef SPEDITOR_TASKS_TASK_HPP
#define SPEDITOR_TASKS_TASK_HPP
#include "timepoint.hpp"

#include <mutex>

namespace speditor {

class Schedule;

namespace tasks {

class Task
{
public:
	Task();
	Task(Timepoint, Timepoint = -1);
	virtual bool loop(Timepoint) = 0;
	virtual bool isRunning();
	virtual bool isFinished();

	Timepoint plannedStart();
	Timepoint plannedEnd();
	Timepoint startTime();
	Timepoint endTime();

private:
	virtual void doLoop_(Timepoint);

	Timepoint planned_start_;
	Timepoint planned_end_;
	Timepoint start_;
	Timepoint end_;

	std::mutex mtx_;

friend class speditor::Schedule;
};

} }

#endif
