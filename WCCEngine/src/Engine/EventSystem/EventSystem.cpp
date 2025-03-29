#include "wccpch.h"
#include "EventSystem.h"

namespace WCCEngine
{
	BaseEvent::BaseEvent()
		: bIsHandled(false)
	{
	}

	BaseEvent::~BaseEvent()
	{
	}

	EventDispatcher::EventDispatcher(IN BaseEvent& oEvent)
		: m_oEvent(oEvent)
	{
	}

	EventDispatcher::~EventDispatcher()
	{
	}
}
