#include "wccpch.h"
#include "MouseButtonPressedEvent.h"

namespace WCCEngine
{
	MouseButtonPressedEvent::MouseButtonPressedEvent(IN const MouseCodes eMouseCode, IN const float fMousePositionX, IN const float fMousePositionY)
		: MouseButtonEvent(fMousePositionX, fMousePositionY)
	{
	}

	MouseButtonPressedEvent::~MouseButtonPressedEvent()
	{
	}

	const EventType MouseButtonPressedEvent::GetEventType() const
	{
		return EventType::EventTypeMouseButtonPressed;
	}
}