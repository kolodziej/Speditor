#ifndef SPEDITOR_TOOLS_LOG_MACROS_HPP
#define SPEDITOR_TOOLS_LOG_MACROS_HPP

#ifndef OFF_LOG_DETAIL
#define LogDetail(...) GL.log(speditor::tools::LogType::DetailedDebug, __VA_ARGS__)
#else
#define LogDetail(...)
#endif

#ifndef OFF_LOG_DEBUG
#define LogDebug(...) GL.log(speditor::tools::LogType::Debug, __VA_ARGS__)
#else
#define LogDebug(...)
#endif

#ifndef OFF_LOG_WARNING
#define LogWarning(...) GL.log(speditor::tools::LogType::Warning, __VA_ARGS__)
#else
#define LogWarning(...)
#endif

#ifndef OFF_LOG_ERROR
#define LogError(...) GL.log(speditor::tools::LogType::Error, __VA_ARGS__)
#else
#define LogError(...)
#endif

#ifndef OFF_LOG_CRITICAL
#define LogCrit(...) GL.log(speditor::tools::LogType::Critical, __VA_ARGS__)
#else
#define LogCrit(...)
#endif

#endif
