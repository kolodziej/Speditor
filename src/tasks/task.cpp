#include "tasks/task.hpp"

namespace speditor { namespace tasks {

Task::Task(bool strict_start, unsigned long long interval) :
	strict_start_{strict_start},
	interval_{interval},
	planned_start_{-1},
	planned_end_{-1},
	start_{-1},
	end_{-1}
{}

Task::Task(Timepoint planned_start, Timepoint planned_end, bool strict_start, unsigned long long interval) :
	strict_start_{strict_start},
	interval_{interval},
	planned_start_{planned_start},
	planned_end_{planned_end}
{}

bool Task::canStart(Timepoint tp)
{
	return (planned_start_ <= tp || strict_start_ == false);
}

bool Task::running()
{
	return start_;
}

bool Task::finished()
{
	return end_;
}

Timepoint Task::plannedStart()
{
	return planned_start_;
}

void Task::plannedStart(Timepoint tp)
{
	planned_start_ = tp;
}

Timepoint Task::plannedEnd()
{
	return planned_end_;
}

void Task::plannedEnd(Timepoint tp)
{
	planned_end_ = tp;
}

Timepoint Task::startTime()
{
	return start_;
}

Timepoint Task::endTime()
{
	return end_;
}

void Task::setPlan(Timepoint start, Timepoint end)
{
	planned_start_ = start;
	planned_end_ = end;
}

bool Task::doLoop_(Timepoint tp)
{
	if (running() == false)
	{
		if (canStart(tp))
		{
			start_ = tp;
			last_run_ = tp - static_cast<long long>(interval_);
		}
	} else if (running())
	{
		Timepoint next_run;
		while ((next_run = last_run_ + static_cast<long long>(interval_)) <= tp)
		{
			last_run_ = tp;
			if (loop(tp))
			{
				end_ = tp;
				return true;
			}
		}
	}
	
	return false;
}

} }
