#ifndef SPEDITOR_TOOLS_LOG_TYPE_HPP
#define SPEDITOR_TOOLS_LOG_TYPE_HPP 

namespace speditor { namespace tools {

enum class LogType : unsigned short
{
	Info = 0,
	Warning,
	Error,
	Critical
};

} }

#endif
