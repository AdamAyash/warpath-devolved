#pragma once

#include "../Core/Core.h"
#include "EventType.h"
#include <functional>

#define WCC_BIND_EVENT(oFucntionReference) std::bind(&oFucntionReference, this, std::placeholders::_1)

namespace WCCEngine
{
	class WCC_API BaseEvent
	{
	protected:
		BaseEvent();
		virtual ~BaseEvent();

	public:
		const virtual EventType GetEventType() const PURE;

	public:
		bool bIsHandled;
	};

	template <typename Event>
	using EventCallback = std::function<bool(const Event&)>;

	class WCC_API EventDispatcher final
	{
	public:
		EventDispatcher(IN BaseEvent& oEvent);
		~EventDispatcher();

	public:
		template <class Event>
		bool Dispatch(IN EventCallback<Event> oEventCallback)
		{
			if (m_oEvent.GetEventType() == Event::GetStaticEventType())
			{
				m_oEvent.bIsHandled |= oEventCallback(dynamic_cast<const Event&>(m_oEvent));
			}

			return true;
		}

	private:
		BaseEvent& m_oEvent;
	};

	class WCC_API IEventListener
	{
	protected:
		IEventListener()
		{
		}
		virtual ~IEventListener()
		{
		}

	public:
		virtual void OnEvent(IN BaseEvent& oEvent) PURE;
	};

	class WCC_API IEventSender
	{
	protected:
		IEventSender()
		{
		}
		virtual ~IEventSender()
		{
		}

		virtual void SetEventListener(IN IEventListener& oEventListener) PURE;
	};

}
