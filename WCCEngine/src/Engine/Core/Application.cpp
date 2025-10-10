
#include "wccpch.h"
#include "Application.h"

namespace WCCEngine
{
	Application* Application::m_pApplicationInstance = nullptr;
	std::mutex Application::m_oMutex;

	Application::Application()
		: m_bIsRunning(true)
		, m_bIsMinimized(false)
	{
		WCC_ASSERT(!m_pApplicationInstance, "Application already exists");
		m_pApplicationInstance = this;
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

	Window& Application::GetWindow() const
	{
		return *m_pWindow;
	}

	Application* Application::GetInstance()
	{
		std::lock_guard<std::mutex> lock(m_oMutex);

		if (m_pApplicationInstance == nullptr)
			m_pApplicationInstance = new Application();

		return m_pApplicationInstance;
	}

	void Application::Initialize()
	{
		WCCEngine::Logger::Init();

		WindowProperties oWindowProperties;
		m_pWindow = CreateScope<Window>(oWindowProperties);
		m_pRenderer = CreateRef<Renderer2D>(oWindowProperties);
		m_pLayerStack = CreateScope<LayerStack>();
		m_pGameTime = CreateScope<GameTime>();
		m_pImGUILayer = new ImGUILayer();

		PushLayerOverlay(m_pImGUILayer);

		m_pWindow->SetEventListener(*this);
	}

	void Application::Update()
	{
		m_pWindow->OnUpdate();
		m_pGameTime->Calculate();

		for (int nIndex = 0; nIndex < m_pLayerStack->GetLenght(); ++nIndex)
		{
			ILayer* pLayer = m_pLayerStack->GetAt(nIndex);
			WCC_ASSERT(pLayer);

			pLayer->Update(*m_pGameTime);
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

	bool Application::OnWindowResize(const WindowResizeEvent& oEvent)
	{
		if (oEvent.GetWidth() == 0 && oEvent.GetHeight() == 0)
			m_bIsMinimized = true;
		else
			m_bIsMinimized = false;

		return true;
	}

	void Application::OnEvent(IN BaseEvent& oEvent)
	{
		//Application level events.
		EventDispatcher oEventDispatcher(oEvent);
		oEventDispatcher.Dispatch<WindowCloseEvent>(WCC_BIND_EVENT(Application::OnWindowClose));
		oEventDispatcher.Dispatch<WindowResizeEvent>(WCC_BIND_EVENT(Application::OnWindowResize));

		if (!m_bIsMinimized)
		{
			//Layer level events.
			for (auto nIndex = 0; nIndex < m_pLayerStack->GetLenght(); ++nIndex)
			{
				ILayer* const pLayer = m_pLayerStack->GetAt(nIndex);
				WCC_ASSERT(pLayer);

				pLayer->OnEvent(oEvent);
			}
		}
	}

	void Application::Render(Ref<Renderer2D> pRenderer)
	{
		if (!m_bIsMinimized)
		{
			m_pImGUILayer->Begin();
			{
				for (auto nIndex = 0; nIndex < m_pLayerStack->GetLenght(); ++nIndex)
				{
					ILayer* const pLayer = m_pLayerStack->GetAt(nIndex);
					WCC_ASSERT(pLayer);

					pLayer->Render(pRenderer);
					pLayer->OnImGuiRender();
				}
			}
			m_pImGUILayer->End();
		}
	}

	void Application::PushLayer(ILayer* pLayer)
	{
		m_pLayerStack->PushLayer(pLayer);
	}

	void Application::PushLayerOverlay(ILayer* pLayer)
	{
		m_pLayerStack->PushOverlay(pLayer);
	}
}

