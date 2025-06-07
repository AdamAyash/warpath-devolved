#pragma once

#include "../../EventSystem.h"

namespace WCCEngine
{
	class MouseButtonEvent : public BaseEvent
	{
	protected:
		MouseButtonEvent(IN const double dMousePositionX, IN const double dMousePositionY);
		virtual ~MouseButtonEvent();

	public:
		const virtual EventType GetEventType() const override;

	protected:
		double m_dMousePositionX;
		double m_dMousePositionY;
	};
}
