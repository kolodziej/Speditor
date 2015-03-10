#ifndef SPEDITOR_TASKS_TASK_HPP
#define SPEDITOR_TASKS_TASK_HPP
#include "timepoint.hpp"

namespace speditor { namespace tasks {

class Task
{
public:
	virtual void begin() = 0;
	virtual void loop(Timepoint) = 0;
	virtual bool isRunning();
	virtual bool isFinished();

	Timepoint plannedStart();
	Timepoint plannedEnd();
	Timepoint startTime();
	Timepoint endTime();

private:
	Timepoint planned_start_;
	Timepoint planned_end_;
	Timepoint start_;
	Timepoint end_;
};

} }

#endif
