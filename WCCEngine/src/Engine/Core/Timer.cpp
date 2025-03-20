
#include "wccpch.h"
#include "Timer.h"

#define ONE_THOUSAND_OF_A_SECOND 1000.0f
 
namespace WCCEngine
{
	Timer::Timer()
	{
	}

	Timer::~Timer()
	{
		Restart();
	}

	void Timer::Restart()
	{
		m_oStartInterval = std::chrono::high_resolution_clock::now();
	}

	float Timer::Elapsed()
	{
		return static_cast<float>(std::chrono::duration_cast<std::chrono::seconds>
			(std::chrono::high_resolution_clock::now() - m_oStartInterval).count());
	}

	float Timer::ElapsedMilliseconds()
	{
		return Elapsed() / ONE_THOUSAND_OF_A_SECOND;
	}
}