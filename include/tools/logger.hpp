#ifndef SPEDITOR_TOOLS_LOGGER_HPP
#define SPEDITOR_TOOLS_LOGGER_HPP
#include <string>
#include <sstream>
#include <mutex>
#include <chrono>

#include "log_type.hpp"

#define GL global_logger

#include "log_macros.hpp"

namespace speditor { namespace tools {

class Logger
{
 public:
  enum Settings : unsigned int
  {
    Defaults = 1 | 4 | 8,
    ShowTime = 1,
    ShowTID = 2,
    ShowType = 4,
    ShowMessageNumber = 8
  };
  Logger(std::ostream& output, unsigned int settings = Defaults);

  Logger& on(LogType type);
  Logger& off(LogType type);
  bool is(LogType type);

  template <typename... Args>
  void log(LogType, Args... r);

 private:
  template <typename First, typename... Rest>
  inline void push_log_(First f, Rest... r);

  inline void push_log_();

  std::string format_now_time_();

  std::ostream& output_;
  unsigned int settings_;
  unsigned long long messages_number_;
  bool logging_types_[log_type_counter()];
  LogType current_log_type_;
  std::stringstream log_;
  std::mutex lock_;
  std::chrono::system_clock clock_;
};

} }

#include "impl/tools/logger.hpp"

extern speditor::tools::Logger global_logger;

#endif
