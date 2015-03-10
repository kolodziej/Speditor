#include "tasks/task.hpp"

namespace speditor { namespace tasks {

bool Task::isRunning()
{
	return start_;
}

bool Task::isFinished()
{
	return end_;
}

Timepoint Task::plannedStart()
{
	return planned_start_;
}

Timepoint Task::plannedEnd()
{
	return planned_end_;
}

Timepoint Task::startTime()
{
	return start_;
}

Timepoint Task::endTime()
{
	return end_;
}

} }
