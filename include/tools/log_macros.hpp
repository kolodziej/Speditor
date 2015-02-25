#ifndef SPEDITOR_TOOLS_LOG_MACROS_HPP
#define SPEDITOR_TOOLS_LOG_MACROS_HPP

#ifdef LOG_INFO
#define LogInfo(...) global_logger.log(speditor::tools::LogType::Info, __VA_ARGS__)
#else
#define LogInfo(...)
#endif

#ifdef LOG_WARNING
#define LogWarning(...) global_logger.log(speditor::tools::LogType::Warning, __VA_ARGS__)
#else
#define LogWarning(...)
#endif

#ifdef LOG_ERROR
#define LogError(...) global_logger.log(speditor::tools::LogType::Error, __VA_ARGS__)
#else
#define LogError(...)
#endif

#ifdef LOG_CRITICAL
#define LogCrit(...) global_logger.log(speditor::tools::LogType::Critical, __VA_ARGS__)
#else
#define LogCrit(...)
#endif

#endif
