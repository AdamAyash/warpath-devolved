#include "wccpch.h"
#include "WindowResizeEvent.h"

namespace WCCEngine
{
	WindowResizeEvent::WindowResizeEvent(const int nWidth, const int nHeight)
		: m_nWidth(nWidth)
		, m_nHeigh(nHeight)
	{
	}

	WindowResizeEvent::~WindowResizeEvent()
	{
	}

	const int WindowResizeEvent::GetWidth() const
	{
		return m_nWidth;
	}

	const int WindowResizeEvent::GetHeight() const
	{
		return m_nHeigh;
	}
}

