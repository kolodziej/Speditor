#include "timepoint.hpp"

namespace speditor {

Timepoint::Timepoint(Clock& clock) :
	clock_(clock),
	time_(clock.get())
{}

void Timepoint::set(long long time)
{
	time_ = time;
}

long long Timepoint::get() const
{
	return time_;
}

short Timepoint::minute()
{
	return time_ % 60;
}

short Timepoint::hour()
{
	return static_cast<short>(static_cast<int>(time_ / 60) % 24);
}

int Timepoint::day()
{
	return static_cast<int>(time_ / 1440);
}

short Timepoint::dayOfWeek()
{
	return static_cast<short>(day() % 7);
}

int Timepoint::week()
{
	return static_cast<int>(time_ / 10080);
}

}
