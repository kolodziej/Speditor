#include "gtest/gtest.h"
#include "tools/logger.hpp"

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <sstream>
#include <random>

#include <cstdlib>
#include <ctime>

std::random_device rd;

TEST(Logger, Threads)
{
	std::srand(std::time(0));
	std::stringstream stream;
	std::mutex mtx;
	std::set<std::string> tokens;

	speditor::tools::Logger logger(stream, 0);
	std::vector<std::thread> threads(10);
	for (auto& thread : threads)
	{
		thread = std::move(std::thread([&logger, &tokens, &mtx]() {
			for (int i = 0; i < 10; ++i)
			{
				std::stringstream token;
#define RANDOM(min, max) rd() % (max - min) + min
				for (int j = 0; j < 100; ++j)
				{
					token << static_cast<char>(RANDOM('a', 'z'));
				}
				logger.log(speditor::tools::LogType::Debug, token.str());
				mtx.lock();
				tokens.insert(token.str());
				mtx.unlock();
			}
		}));
	}
	for (auto& t : threads)
	{
		t.join();
	}
	std::string line;
	while (std::getline(stream, line))
	{
		auto it = tokens.end();
		ASSERT_NE(it = tokens.find(line), tokens.end());
		if (it != tokens.end())
		{
			tokens.erase(it);
		}
	}

	ASSERT_TRUE(tokens.empty());
}
