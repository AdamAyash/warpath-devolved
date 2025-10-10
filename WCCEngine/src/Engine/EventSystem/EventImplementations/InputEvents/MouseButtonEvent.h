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
		const virtual EventTypes GetEventType() const override;

	public:
		double m_dMousePositionX;
		double m_dMousePositionY;
	};
}
