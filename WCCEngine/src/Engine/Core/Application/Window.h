#pragma once 
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../Core.h"
#include "../../EventSystem/EventSystem.h"

#define DEFAULT_WINDOW_WIDTH 1600
#define DEFAULT_WINDOW_HEIGHT 900

#define DEFAULT_TITLE "Application"

namespace WCCEngine
{
	struct WindowProperties
	{
		WindowProperties(const std::string& strTitle = DEFAULT_TITLE
			, int nWidth = DEFAULT_WINDOW_WIDTH, int nHeight = DEFAULT_WINDOW_HEIGHT)
			: m_strTitle(strTitle), m_nWidth(nWidth), m_nHeight(nHeight)
		{
		}

		~WindowProperties()
		{
		}

		int m_nWidth;
		int m_nHeight;

		std::string m_strTitle;
	};

	class WCC_API Window final : public IEventPublisher
	{
	public:
		Window(IN const WindowProperties& oWindowProperties);
		~Window();

	public:
		void OnUpdate();
		void SetEventListener(IN IEventListener& oventListener) override;
		constexpr GLFWwindow* GetNativeWindow() const;

	private:
		void Initialize(IN const WindowProperties& oWindowProperties);
		void ShutDown();

	private:
		GLFWwindow* m_pWindow;
	};
};
