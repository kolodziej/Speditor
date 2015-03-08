#include "timepoint.hpp"

#include <cmath>
#include "clock.hpp"

namespace speditor {

Timepoint::Timepoint(long long time) :
	time_{time}
{}

void Timepoint::set(long long time)
{
	time_ = time;
}

long long Timepoint::get() const
{
	return time_;
}

short Timepoint::minute() const
{
	return time_ % 60;
}

short Timepoint::hour() const
{
	return static_cast<short>(static_cast<int>(time_ / 60) % 24);
}

int Timepoint::day() const
{
	return std::ceil(static_cast<double>(time_) / 1440.0);
}

short Timepoint::dayOfWeek() const
{
	return static_cast<short>((day()-1) % 7);
}

int Timepoint::week() const
{
	return std::ceil(static_cast<double>(time_) / 10080.0);
}

}
