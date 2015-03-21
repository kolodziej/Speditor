#ifndef SPEDITOR_TOOLS_LOG_TYPE_HPP
#define SPEDITOR_TOOLS_LOG_TYPE_HPP 

namespace speditor { namespace tools {

enum class LogType : unsigned short
{
	DetailedDebug = 0,
	Debug,
	Warning,
	Error,
	Critical
};

constexpr size_t log_type_counter()
{
	return 5;
}

} }

#endif
