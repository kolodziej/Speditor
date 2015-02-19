#include "clock.hpp"

namespace speditor {

Clock::Clock(int minute_duration) :
	minute_duration_(minute_duration)
{}

Timepoint Clock::timepoint() const
{
	Timepoint tp(*this);
	return tp;
}

}
