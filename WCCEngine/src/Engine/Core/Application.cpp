
#include "wccpch.h"
#include "Application.h"

namespace WCCEngine
{
	Application::Application()
		: m_bIsRunning(true)
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		this->Initialize();

		while (m_bIsRunning)
		{
			Update();
			Render(m_pRenderer);
		}
	}

	void Application::ShutDown()
	{
		m_bIsRunning = false;
	}

	void Application::Initialize()
	{
		WCCEngine::Logger::Init();

		WindowProperties oWindowProperties;
		m_pWindow = CreateScope<Window>(oWindowProperties);
		m_pRenderer = CreateRef<Renderer2D>();

		m_pWindow->SetEventListener(*this);
	}

	void Application::Update()
	{
		m_pWindow->OnUpdate();
	}

	void Application::Load()
	{

	}

	bool Application::OnWindowClose(const WindowCloseEvent& oEvent)
	{
		ShutDown();
		return true;
	}

	void Application::OnEvent(IN BaseEvent& oEvent)
	{

		EventDispatcher oEventDispatcher(oEvent);
		oEventDispatcher.Dispatch<WindowCloseEvent>(WCC_BIND_EVENT(Application::OnWindowClose));
	}

	void Application::Render(Ref<Renderer2D> pRenderer)
	{
	}
}

