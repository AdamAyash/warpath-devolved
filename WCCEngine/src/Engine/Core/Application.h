#pragma once

#include "Core.h"
#include "Window.h"
#include "../Renderer/Renderer2D.h"

namespace WCCEngine
{
	class WCC_API Application
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
		virtual void Render(Ref<Renderer2D> pRenderer);

	private:
		bool m_bIsRunning;
		Scope<Window> m_pWindow;
		Ref<Renderer2D> m_pRenderer;
	};
}


