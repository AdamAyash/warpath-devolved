#include "wccpch.h"
#include "MouseButtonPressedEvent.h"

namespace WCCEngine
{
	MouseButtonPressedEvent::MouseButtonPressedEvent(IN const MouseCodes eMouseCode, IN const float fMousePositionX, IN const float fMousePositionY)
		: MouseButtonEvent(fMousePositionX, fMousePositionY)
		, m_eMouseCode(eMouseCode)
	{
	}

	MouseButtonPressedEvent::~MouseButtonPressedEvent()
	{
	}

	constexpr MouseCodes MouseButtonPressedEvent::GetMouseCode() const
	{
		return m_eMouseCode;
	}
}