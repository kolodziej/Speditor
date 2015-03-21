#ifndef SPEDITOR_TOOLS_LOG_TYPE_HPP
#define SPEDITOR_TOOLS_LOG_TYPE_HPP 

namespace speditor { namespace tools {

enum class LogType : unsigned short
{
	DetailedDebug = 1,
	Debug = 2,
	Warning = 4,
	Error = 8,
	Critical = 16
};

} }

#endif
