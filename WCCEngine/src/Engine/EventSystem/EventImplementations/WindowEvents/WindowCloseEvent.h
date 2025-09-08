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
		EVENT_CLASS_TYPE(EventTypeWindowClose);
	};
}
