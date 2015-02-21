#include <thread>
#include <ctime>

namespace speditor { namespace tools {

template <typename... Args>
inline void Logger::log(LogType type, Args... args)
{
	lock_.lock();
	log_.str("");

	switch (type)
	{
		case LogType::Info:
			log_ << "I ";
			break;

		case LogType::Warning:
			log_ << "W ";
			break;

		case LogType::Error:
			log_ << "E ";
			break;

		case LogType::Critical:
			log_ << "CRIT! ";
			break;
	}

	if (show_time_)
	{
		log_ << format_now_time_() << " ";
	}

	if (show_tid_)
	{
		log_ << "TID=" << std::this_thread::get_id() << " ";
	}

	push_log_(args...);
}

template <typename First, typename... Rest>
inline void Logger::push_log_(First f, Rest... r)
{
	log_ << f;
	push_log_(r...);
}

inline void Logger::push_log_()
{
	log_ << "\n";
	output_ << log_.str();
	lock_.unlock();
}

} } 
