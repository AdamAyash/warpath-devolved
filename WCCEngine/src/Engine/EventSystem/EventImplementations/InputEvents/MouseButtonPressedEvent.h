#pragma once

#include "../../EventSystem.h"
#include "MouseButtonEvent.h"
#include "../../../Input/MouseCodes.h"

namespace WCCEngine
{
	class WCC_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(IN const MouseCodes eMouseCode, IN const float fMousePositionX, IN const float fMousePositionY);
		virtual ~MouseButtonPressedEvent();


	public:
		constexpr MouseCodes GetMouseCode() const;
		EVENT_CLASS_TYPE(EventTypeMouseButtonPressed);

	private:
		MouseCodes m_eMouseCode;
	};
}
