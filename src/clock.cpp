#include "clock.hpp"

#include "timepoint.hpp"

namespace speditor {

Clock::Clock(int minute_duration) :
	minute_duration_(minute_duration)
{}

Timepoint Clock::timepoint() const
{
	Timepoint tp;
	tp.set(time_);
	return tp;
}

}
