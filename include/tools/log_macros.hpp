#ifndef SPEDITOR_TOOLS_LOG_MACROS_HPP
#define SPEDITOR_TOOLS_LOG_MACROS_HPP

#ifdef LOG_INFO
#define LogInfo(...) GL.log(speditor::tools::LogType::Info, __VA_ARGS__)
#else
#define LogInfo(...)
#endif

#ifdef LOG_WARNING
#define LogWarning(...) GL.log(speditor::tools::LogType::Warning, __VA_ARGS__)
#else
#define LogWarning(...)
#endif

#ifdef LOG_ERROR
#define LogError(...) GL.log(speditor::tools::LogType::Error, __VA_ARGS__)
#else
#define LogError(...)
#endif

#ifdef LOG_CRITICAL
#define LogCrit(...) GL.log(speditor::tools::LogType::Critical, __VA_ARGS__)
#else
#define LogCrit(...)
#endif

#endif
