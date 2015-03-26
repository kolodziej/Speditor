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
	Task(bool strict_start = true, unsigned long long interval = 1);
	Task(Timepoint, Timepoint = -1, bool strict_start = true, unsigned long long interval = 1);
	Task(const Task&) = delete;
	virtual bool canStart(Timepoint);
	virtual bool running();
	virtual bool finished();

	Timepoint plannedStart();
	void plannedStart(Timepoint);
	Timepoint plannedEnd();
	void plannedEnd(Timepoint);
	Timepoint startTime();
	Timepoint endTime();

	void setPlan(Timepoint, Timepoint);

	virtual bool loop(Timepoint) = 0;

protected:
	virtual bool commonLoop(Timepoint);

private:
	bool strict_start_;
	unsigned long long interval_;

	Timepoint planned_start_;
	Timepoint planned_end_;
	Timepoint start_;
	Timepoint end_;

	Timepoint last_run_;

	std::mutex mtx_;

friend class speditor::Schedule;
};

} }

#endif
