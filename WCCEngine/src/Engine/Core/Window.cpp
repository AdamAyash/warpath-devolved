#include "wccpch.h"
#include "Window.h"
#include <iostream>
#include "OpenGL/OpenGLContext.h"
#include "../EventSystem/EventImplementations/WindowEvents/WindowCloseEvent.h"
#include "../EventSystem/EventImplementations/InputEvents/MouseButtonPressedEvent.h"
#include "../EventSystem/EventImplementations/WindowEvents/WindowResizeEvent.h"

namespace WCCEngine
{
	Window::Window(IN const WindowProperties& oWindowProperties)
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
			WindowCloseEvent oWindowCloseEvent;
			oWindow.m_oEventListener->OnEvent(oWindowCloseEvent);
		});

		glfwSetFramebufferSizeCallback(m_pWindow, [](GLFWwindow * pWindow, int nWidth, int nHeight)
		{
			glViewport(0, 0, nWidth, nHeight);

			const Window& oWindow = *reinterpret_cast<const Window*>(glfwGetWindowUserPointer(pWindow));

			WindowResizeEvent oWindowResizeEvent(nWidth, nHeight);
			oWindow.m_oEventListener->OnEvent(oWindowResizeEvent);
		});

		glfwSetMouseButtonCallback(m_pWindow, [](GLFWwindow* pWindow, int nButton, int nAction, int nMods)
		{
			const Window& oWindow = *reinterpret_cast<const Window*>(glfwGetWindowUserPointer(pWindow));
			if (nAction == GLFW_PRESS)
			{
				double dMousePositionX = 0;
				double dMousePositionY = 0;
					
				glfwGetCursorPos(oWindow.m_pWindow, &dMousePositionX, &dMousePositionY);

				MouseButtonPressedEvent oMouseButtonPressedEvent(static_cast<MouseCodes>(nButton), dMousePositionX, dMousePositionY);
				oWindow.m_oEventListener->OnEvent(oMouseButtonPressedEvent);
			}
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

	constexpr GLFWwindow* Window::GetNativeWindow() const
	{
		return m_pWindow;
	}
}