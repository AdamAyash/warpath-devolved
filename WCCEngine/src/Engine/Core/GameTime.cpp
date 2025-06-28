#include "wccpch.h"
#include "GameTime.h"
#include <GLFW/glfw3.h>

namespace WCCEngine
{
	GameTime::GameTime()
		: m_dCurrentTime(0)
		, m_dLastFrame(0)
		, m_dDeltaTime(0)
	{
	}

	GameTime::~GameTime()
	{
	}

	void GameTime::Calculate()
	{
		m_dCurrentTime = glfwGetTime();
		m_dDeltaTime = m_dCurrentTime - m_dLastFrame;

		m_dLastFrame = m_dCurrentTime;
	}

	constexpr double inline GameTime::GetDeltaTtime() const
	{
		return m_dDeltaTime;
	}
}