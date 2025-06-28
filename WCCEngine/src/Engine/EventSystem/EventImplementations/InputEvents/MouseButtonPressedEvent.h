#pragma once

#include "../../EventSystem.h"
#include "MouseButtonEvent.h"
#include "../../../Core/MouseCodes.h"

namespace WCCEngine
{
	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(IN const MouseCodes eMouseCode, IN const float fMousePositionX, IN const float fMousePositionY);
		virtual ~MouseButtonPressedEvent();

	public:
		const virtual EventType GetEventType() const override;
		EVENT_TYPE(EventTypeMouseButtonPressed);
	};
}
