#include <thread>
#include <ctime>

namespace speditor { namespace tools {

template <typename... Args>
inline void Logger::log(LogType type, Args... args)
{
	lock_.lock();
	log_.str("");

	if (settings_ & ShowMessageNumber)
	{
		log_ << ++messages_number_ << " ";
	}

	if (settings_ & ShowTime)
	{
		log_ << format_now_time_() << " ";
	}

	if (settings_ & ShowTID)
	{
		log_ << "TID=" << std::this_thread::get_id() << " ";
	}
	
	if (settings_ & ShowType)
	{
		switch (type)
		{
			case LogType::DetailedDebug:
				log_ << "[Detail] ";
			case LogType::Debug:
				log_ << "[Debug] ";
				break;

			case LogType::Warning:
				log_ << "[Warning] ";
				break;

			case LogType::Error:
				log_ << "[Error] ";
				break;

			case LogType::Critical:
				log_ << "[CRITICAL!] ";
				break;
		}
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
