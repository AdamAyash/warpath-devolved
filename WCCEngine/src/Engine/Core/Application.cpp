
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
		this->Load();

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
		m_pRenderer = CreateRef<Renderer2D>(oWindowProperties);
		m_pLayerStack = CreateScope<LayerStack>();
		m_pWindow->SetEventListener(*this);
	}

	void Application::Update()
	{
		m_pWindow->OnUpdate();
		for (int nIndex = 0; nIndex < m_pLayerStack->GetLenght(); ++nIndex)
		{
			ILayer* pLayer = m_pLayerStack->GetAt(nIndex);
			WCC_ASSERT(pLayer);

			pLayer->Update();
		}
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
		//Application level events.
		EventDispatcher oEventDispatcher(oEvent);
		oEventDispatcher.Dispatch<WindowCloseEvent>(WCC_BIND_EVENT(Application::OnWindowClose));
	}

	void Application::Render(Ref<Renderer2D> pRenderer)
	{
		for (auto nIndex = 0; nIndex < m_pLayerStack->GetLenght(); ++nIndex)
		{
			ILayer* const pLayer = m_pLayerStack->GetAt(nIndex);
			WCC_ASSERT(pLayer);

			pLayer->Render(pRenderer);
		}
	}

	void Application::PushLayer(ILayer* pLayer)
	{
		m_pLayerStack->PushLayer(pLayer);
	}

	void Application::PushLayerOverlay(ILayer* pLayer)
	{
	}
}

