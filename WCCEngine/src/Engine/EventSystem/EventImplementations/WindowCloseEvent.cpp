#include "wccpch.h"
#include "WindowCloseEvent.h"

namespace WCCEngine
{
	WindowCloseEvent::WindowCloseEvent()
	{
	}

	WindowCloseEvent::~WindowCloseEvent()
	{
	}

	const EventType WindowCloseEvent::GetEventType() const
	{
		return EventTypeWindowClose;
	}
}
