#pragma once

#include "Core.h"

namespace WCCEngine
{
	class GameTime final
	{
	public:
		GameTime();
		~GameTime();

	public:
		void Calculate();
		constexpr double inline GetDeltaTtime() const;

	private:
		double m_dCurrentTime;
		double m_dLastFrame;
		double m_dDeltaTime;
	};
}