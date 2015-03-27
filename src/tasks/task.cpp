#include "tasks/task.hpp"

#include "tools/logger.hpp"

namespace speditor { namespace tasks {

Task::Task(bool strict_start, unsigned long long interval) :
	strict_start_{strict_start},
	interval_{interval}
{}

Task::Task(Timepoint planned_start, Timepoint planned_end, bool strict_start, unsigned long long interval) :
	planned_start_time_{planned_start},
	planned_end_time_{planned_end},
	strict_start_{strict_start},
	interval_{interval}
{}

bool Task::running() const
{
	return (start_time_ && static_cast<bool>(end_time_) == false);
}

bool Task::finished() const
{
	return (start_time_ && end_time_);
}

Timepoint Task::plannedStart() const
{
	return planned_start_time_;
}

Timepoint Task::startTime() const
{
	return start_time_;
}

Timepoint Task::plannedEnd() const
{
	return planned_end_time_;
}

Timepoint Task::endTime() const
{
	return end_time_;
}

void Task::plannedEnd(Timepoint tp)
{
	planned_end_time_ = tp;
}

void Task::plannedStart(Timepoint tp)
{
	planned_start_time_ = tp;
}

void Task::setPlan(Timepoint start, Timepoint end)
{
	planned_start_time_ = start;
	planned_end_time_ = end;
}

bool Task::strictStart() const
{
	return strict_start_;
}

void Task::strictStart(bool strict_start)
{
	strict_start_ = strict_start;
}

void Task::start(Timepoint tp)
{
	start_time_ = tp;
}

void Task::finish(Timepoint tp)
{
	end_time_ = tp;
}

void Task::scheduleLoop_(Timepoint tp)
{
	if (running()) // started
	{
		unsigned int times = (tp - last_run_) / interval_;
		if (times > 0)
		{
			if (times > 1)
			{
				LogWarning("Schedule's worker thread has to run action ", times, " times!");
			}
			while (times-- > 0)
			{
				action(tp);
			}
			last_run_ = tp;
		}
	} else if (finished() == false) // not finished and not running = not started
	{
		if (strict_start_ || plannedStart() <= tp)
		{
			start(tp);
			action(tp);
			last_run_ = tp;
		}
	}
}

} }
