#include "tasks/task.hpp"

namespace speditor { namespace tasks {

Task::Task() :
	planned_start_{-1},
	planned_end_{-1},
	start_{-1},
	end_{-1}
{}

Task::Task(Timepoint planned_start, Timepoint planned_end) :
	planned_start_{planned_start},
	planned_end_{planned_end}
{}

bool Task::isRunning()
{
	return start_;
}

bool Task::isFinished()
{
	return end_;
}

bool Task::loop(Timepoint tp)
{
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

void Timepoint::doLoop_(Timepoint tp)
{
	if (isRunning() == false && planned_start_ <= tp)
	{
		start_ = tp;
	}

	if (loop(tp))
	{
		end_ = tp;
	}
}

} }
