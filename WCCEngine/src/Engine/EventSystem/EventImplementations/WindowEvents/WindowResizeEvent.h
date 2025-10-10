#pragma once

#include "../../EventSystem.h"

namespace WCCEngine
{
	class WindowResizeEvent final : public BaseEvent
	{
	public:
		WindowResizeEvent(const int nWidth, const int nHeight);
		~WindowResizeEvent();

	public:
		const int GetWidth() const;
		const int GetHeight() const;

	public:
		EVENT_CLASS_TYPE(EventTypeWindowResize);

	private:
		int m_nWidth; 
		int m_nHeigh;
	};
}
