#include "gtest/gtest.h"
#include "tools/logger.hpp"

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include <cstdlib>
#include <ctime>

TEST(Logger, Threads)
{
	std::srand(std::time(0));
	speditor::tools::Logger logger(std::cout);
	std::vector<std::thread> threads(10);
	char c = 'a';
	int k = 0;
	for (auto& thread : threads)
	{
		std::string str(30, c++);
		thread = std::move(std::thread([&logger, str, &k, c]() {
			for (int i = 0; i < 10; ++i)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 500));
				logger.log(speditor::tools::LogType::Critical, str, c, k++);
			}
		}));
	}
	for (auto& t : threads)
	{
		t.join();
	}
}
