#include "clock.hpp"

#include "timepoint.hpp"

namespace speditor {

Clock::Clock(int minute_duration) :
	minute_duration_(minute_duration)
{}

Timepoint Clock::timepoint() const
{
	Timepoint tp(*this);
	return tp;
}

long long Clock::get() const
{
	return time_;
}

}
