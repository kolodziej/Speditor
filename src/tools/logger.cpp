#include "tools/logger.hpp"

#include <string>

namespace speditor { namespace tools {

Logger::Logger(std::ostream& output, bool show_time, bool show_tid) :
	output_(output),
	show_time_(show_time),
	show_tid_(show_tid)
{}

std::string Logger::format_now_time_()
{
	auto time_point = clock_.now();
	time_t time = std::chrono::system_clock::to_time_t(time_point);
	char buffer[30];
	std::strftime(buffer, 30, "%c", std::localtime(&time));
	return std::string(buffer);
}

} }
