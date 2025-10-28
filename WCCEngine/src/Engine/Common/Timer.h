#pragma once
#include <chrono>

namespace WCCEngine
{
	class Timer
	{
	public:
		Timer();
		~Timer();

	public:
		void Restart();
		float Elapsed();
		float ElapsedMilliseconds();

	private:
		std::chrono::steady_clock::time_point m_oStartInterval;
	};
}
