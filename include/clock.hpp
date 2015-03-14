#ifndef SPEDITOR_CLOCK_HPP
#define SPEDITOR_CLOCK_HPP

#include <chrono>
#include <mutex>

namespace speditor {

class Timepoint;

class Clock
{
public:
	Clock(int);
	Timepoint timepoint();
	void updateTime();
	void reset();

private:

	const int minute_duration_;
	long long time_;
	std::mutex clock_mutex_;

	std::chrono::steady_clock clock_;
	std::chrono::time_point<std::chrono::steady_clock> start_;
};

}

#endif
