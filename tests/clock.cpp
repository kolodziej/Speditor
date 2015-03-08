#include "clock.hpp"
#include "timepoint.hpp"

#include <iostream>
#include <iomanip>
#include <thread>
#include <atomic>
#include <chrono>
#include <functional>

#include "tools/logger.hpp"

speditor::tools::Logger global_logger(std::cerr, true, true);

using speditor::Clock;
using speditor::Timepoint;

int main()
{
	const int minute = 50;
	const int interval = 30;

	std::cout << "To stop application use Ctrl+C combination\n";
	std::cout << "One minute lasts " << static_cast<double>(minute)/1000.0 << " seconds\n";
	Clock c(minute);

	std::thread clock_thread([&c]() {
		while (true)
		{
			c.updateTime();
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
		}
	});

	while (true)
	{
		Timepoint t = c.timepoint();
		std::cout << "\r" << "Week: " << std::setw(2) << t.week() << " "
							<< "Day: " << std::setw(2) << t.day() << " "
							<< "Hour: " << std::setw(2) << t.hour() << " "
							<< "Minute: " << std::setw(2) << t.minute() << std::flush;

		std::this_thread::sleep_for(std::chrono::milliseconds(interval));
	}
	clock_thread.join();
	return 0;
}