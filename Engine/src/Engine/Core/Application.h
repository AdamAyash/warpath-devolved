#pragma once

#include "Core.h"
#include "Window.h"

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
		virtual void Render();

	private:
		bool m_bIsRunning;
		Scope<Window> m_pWindow;
	};
}


