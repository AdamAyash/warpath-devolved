#include "wccpch.h"
#include "Window.h"
#include <iostream>
#include "OpenGL/OpenGLContext.h"
#include "../EventSystem/EventImplementations/WindowEvents/WindowCloseEvent.h"

namespace WCCEngine
{
	Window::Window(IN const WindowProperties& oWindowProperties)
		: m_oEventListener(nullptr)
	{
		Initialize(oWindowProperties);
	}

	Window::~Window()
	{
		ShutDown();
	}

	void Window::Initialize(IN const WindowProperties& oWindowProperties)
	{
		OpenGLContext oOpenGLContext;
		if (!oOpenGLContext.InitializeOpenGLContext())
		{
			WCC_CORE_ERROR("Failed to initalize OpenGL context.");
		}

		m_pWindow = glfwCreateWindow(oWindowProperties.m_nWidth, oWindowProperties.m_nHeight,
			oWindowProperties.m_strTitle.c_str()
			, nullptr, nullptr);

		WCC_ASSERT(m_pWindow);

		WCC_CORE_INFO("Creating window {0} ({1}, {2})", oWindowProperties.m_strTitle, oWindowProperties.m_nWidth, oWindowProperties.m_nHeight);

		glfwMakeContextCurrent(m_pWindow);
		glfwSetWindowUserPointer(m_pWindow, reinterpret_cast<void*>(this));


		oOpenGLContext.InitializeGlad();
		oOpenGLContext.DisplayOpenGLContextInfo();

		glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* pWindow)
		{
				const Window& oWindow = *reinterpret_cast<const Window*>(glfwGetWindowUserPointer(pWindow));
				WindowCloseEvent oEvent;
				oWindow.m_oEventListener->OnEvent(oEvent);
		});
	}

	void Window::ShutDown()
	{
		glfwDestroyWindow(m_pWindow);
		glfwTerminate();
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_pWindow);
	}

	void Window::SetEventListener(IN IEventListener& oEventListener)
	{
		m_oEventListener = &oEventListener;
	}
}