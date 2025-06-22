#pragma once

#include "../../EventSystem.h"

namespace WCCEngine
{
	class WindowCloseEvent : public BaseEvent
	{
	public:
		WindowCloseEvent();
		~WindowCloseEvent();

	public:
		const virtual EventType GetEventType() const override;

		EVENT_TYPE(EventTypeWindowClose);
	};
}
