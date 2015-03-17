#include "clock.hpp"

#include "timepoint.hpp"

namespace speditor {

Clock::Clock(int minute_duration) :
	minute_duration_{minute_duration},
	time_{0}
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

void Clock::reset()
{
	std::lock_guard<std::mutex> lock(clock_mutex_);
	start_ = clock_.now();
	time_ = 0;
}

void Clock::run()
{
	clock_thread_ = std::move(std::thread([this](std::atomic_bool* running) {
		while (*running)
		{
			updateTime();
			std::this_thread::sleep_for(std::chrono::milliseconds(minute_duration_/2));
		}
	}, &thread_running_));
}

void Clock::wait()
{
	thread_running_ = false;
	clock_thread_.join();
}

}
