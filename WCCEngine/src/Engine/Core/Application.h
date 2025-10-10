#pragma once

#include "Core.h"
#include "Window.h"
#include "GameTime.h" 
#include "../Renderer/Renderer2D.h"
#include "../EventSystem/EventSystem.h"
#include "../EventSystem/EventImplementations/WindowEvents/WindowCloseEvent.h"
#include "../EventSystem/EventImplementations/WindowEvents/WindowResizeEvent.h"
#include "../LayerSystem/LayerStack.h"
#include "../ImGUIImplementation/ImGUILayer.h"

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
		Window& GetWindow() const;

		static Application* GetInstance();

	protected:
		virtual void Initialize();
		virtual void Update();
		virtual void Load();
		virtual void OnEvent(IN BaseEvent& oEvent) override;
		virtual void Render(Ref<Renderer2D> pRenderer);

		void PushLayer(ILayer* pLayer);
		void PushLayerOverlay(ILayer* pLayer);

	private:
		bool OnWindowClose(const WindowCloseEvent& oEvent);
		bool OnWindowResize(const WindowResizeEvent& oEvent);

	private:
		bool m_bIsRunning;
		bool m_bIsMinimized;

		Scope<Window> m_pWindow;
		Scope<LayerStack> m_pLayerStack;
		Scope<GameTime> m_pGameTime;
		Ref<Renderer2D> m_pRenderer;

		ImGUILayer* m_pImGUILayer;

		static Application* m_pApplicationInstance;
		static std::mutex m_oMutex;
	};
}
