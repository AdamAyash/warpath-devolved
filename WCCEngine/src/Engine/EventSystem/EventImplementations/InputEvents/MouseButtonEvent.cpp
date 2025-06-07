#include "wccpch.h"
#include "MouseButtonEvent.h"

namespace WCCEngine
{
	MouseButtonEvent::MouseButtonEvent(IN const double dMousePositionX, IN const double dMousePositionY)
		: m_dMousePositionX(dMousePositionX)
		, m_dMousePositionY(dMousePositionY)
	{
	}

	MouseButtonEvent::~MouseButtonEvent()
	{
	}

	const EventType MouseButtonEvent::GetEventType() const
	{
		return EventType::EventTypeMouseButton;
	}
}