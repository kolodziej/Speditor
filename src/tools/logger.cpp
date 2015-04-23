#include "tools/logger.hpp"

#include <string>

namespace speditor { namespace tools {

Logger::Logger(std::ostream& output, unsigned int settings) :
  output_(output),
  settings_{settings},
  messages_number_{0}
{
	on(LogType::Debug);
	on(LogType::Warning);
	on(LogType::Error);
	on(LogType::Critical);
}

Logger& Logger::on(LogType type)
{
	logging_types_[static_cast<unsigned int>(type)] = true;
	return *this;
}

Logger& Logger::off(LogType type)
{
	logging_types_[static_cast<unsigned int>(type)] = false;
	return *this;
}

bool Logger::is(LogType type)
{
	return logging_types_[static_cast<unsigned int>(type)];
}

std::string Logger::format_now_time_()
{
	auto time_point = clock_.now();
	time_t time = std::chrono::system_clock::to_time_t(time_point);
	char buffer[30];
	std::strftime(buffer, 30, "%F %T", std::localtime(&time));
	return std::string(buffer);
}

} }
