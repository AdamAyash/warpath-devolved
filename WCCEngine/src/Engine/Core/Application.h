#pragma once

#include "Core.h"
#include "Window.h"
#include "../Renderer/Renderer2D.h"
#include "../EventSystem/EventSystem.h"
#include "../EventSystem/EventImplementations/WindowEvents/WindowCloseEvent.h"

namespace WCCEngine
{
	class WCC_API Application : public IEventListener
	{
	public:
		Application();
	protected:
		virtual ~Application();

	public:
		void Run();
		void ShutDown();

	protected:
		virtual void Initialize();
		virtual void Update();
		virtual void Load();
		virtual void OnEvent(IN BaseEvent& oEvent) override;
		virtual void Render(Ref<Renderer2D> pRenderer);

	private:
		bool OnWindowClose(const WindowCloseEvent& oEvent);

	private:
		bool m_bIsRunning;
		Scope<Window> m_pWindow;
		Ref<Renderer2D> m_pRenderer;
	};
}


