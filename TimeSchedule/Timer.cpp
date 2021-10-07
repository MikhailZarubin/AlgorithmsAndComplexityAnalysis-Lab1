#include "Timer.h"

void GrafTest::Timer::resetTimer()
{
	startTime = clock_t::now();
}

double GrafTest::Timer::getTime() const
{
	return std::chrono::duration_cast<second_t>(clock_t::now() - startTime).count();
}