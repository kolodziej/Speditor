#ifndef SPEDITOR_CLOCK_HPP
#define SPEDITOR_CLOCK_HPP

#include <chrono>
#include <mutex>
#include <thread>
#include <atomic>

namespace speditor {

class Timepoint;

class Clock
{
 public:
  Clock(unsigned int = 1000);
  Timepoint timepoint();
  void updateTime();
  void reset();

  void run();
  void wait();

 private:
  std::atomic_bool thread_running_;
  std::thread clock_thread_;
  std::mutex clock_mutex_;
  const unsigned int minute_duration_;
  long long time_;

  std::chrono::steady_clock clock_;
  std::chrono::time_point<std::chrono::steady_clock> start_;
};

}

#endif
