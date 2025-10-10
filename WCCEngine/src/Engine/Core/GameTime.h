#pragma once

#include "Core.h"

namespace WCCEngine
{
	class WCC_API GameTime final
	{
	public:
		GameTime();
		~GameTime();

	public:
		/// <summary>
		/// Calculates diffrent time variables.
		/// </summary>
		/// <returns>double</returns>
		void Calculate();

		/// <summary>
		/// Returns delta time in seconds.
		/// </summary>
		/// <returns>double</returns>
		constexpr double inline GetDeltaTtime() const;

		/// <summary>
		/// Returns the total game time in seconds since glfw was initialized.
		/// </summary>
		/// <returns>double</returns>
		constexpr double inline GetTotalGameTime() const;

	private:
		double m_dCurrentTime;
		double m_dLastFrame;
		double m_dDeltaTime;
	};
}