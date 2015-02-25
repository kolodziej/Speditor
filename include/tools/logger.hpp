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
	Logger(std::ostream& output, bool show_time = true, bool show_tid = true);

	template <typename... Args>
	void log(LogType, Args... r);

private:
	template <typename First, typename... Rest>
	inline void push_log_(First f, Rest... r);

	inline void push_log_();

	std::string format_now_time_();

	std::ostream& output_;
	const bool show_time_;
	const bool show_tid_;
	LogType current_log_type_;
	std::stringstream log_;
	std::mutex lock_;
	std::chrono::system_clock clock_;
};

} }

#include "impl/tools/logger.hpp"

extern speditor::tools::Logger global_logger;

#endif
