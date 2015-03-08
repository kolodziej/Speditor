#include "clock.hpp"

#include "timepoint.hpp"

namespace speditor {

Clock::Clock(int minute_duration) :
	minute_duration_{minute_duration}
{
	std::lock_guard<std::mutex> lock(clock_mutex_);
	start_ = clock_.now();
}

Timepoint Clock::timepoint()
{
	std::lock_guard<std::mutex> lock(clock_mutex_);
	return Timepoint(time_);
}

void Clock::updateTime()
{
	std::lock_guard<std::mutex> lock(clock_mutex_);
	auto tp = clock_.now();
	auto duration = tp - start_;
	long long ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
	time_ = static_cast<double>(ms) / minute_duration_;
}

}
