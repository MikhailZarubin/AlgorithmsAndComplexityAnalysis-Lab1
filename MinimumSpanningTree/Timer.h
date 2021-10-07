#pragma once

#include <iostream>
#include <chrono>

namespace GrafTest {

	class Timer
	{
		using clock_t = std::chrono::high_resolution_clock;
		using second_t = std::chrono::duration<double, std::ratio<1> >;

		std::chrono::time_point<clock_t> startTime;

	public:
		Timer() :startTime(clock_t::now()) {}
		~Timer() = default;
		void resetTimer();
		double getTime() const;
	};
}

