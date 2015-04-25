#ifndef SPEDITOR_TOOLS_LOG_MACROS_HPP
#define SPEDITOR_TOOLS_LOG_MACROS_HPP

#ifdef DLOG_ALL
#define LOG_DETAIL
#define LOG_DEBUG
#define LOG_WARNING
#define LOG_ERROR
#define LOG_CRITICAL
#endif

#ifdef LOG_DETAIL
#define LogDetail(...) GL.log(speditor::tools::LogType::DetailedDebug, __VA_ARGS__)
#else
#define LogDetail(...)
#endif

#ifdef LOG_DEBUG
#define LogDebug(...) GL.log(speditor::tools::LogType::Debug, __VA_ARGS__)
#else
#define LogDebug(...)
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
