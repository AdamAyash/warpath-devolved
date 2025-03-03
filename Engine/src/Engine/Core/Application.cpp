
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
			Render();
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
	}

	void Application::Update()
	{
		m_pWindow->OnUpdate();
	}

	void Application::Load()
	{
	}

	void Application::Render()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}

