#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Core.h"
#include "Utilities.h"

#define DEFAULT_WINDOW_WIDTH 1600
#define DEFAULT_WINDOW_HEIGHT 900

namespace WCCEngine
{
	struct WindowProperties
	{
		WindowProperties(const std::string& strTitle = "Warcraft Clone"
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

	class Window
	{
	public:
		Window(IN const WindowProperties& oWindowProperties);
		~Window();

	public:
		void OnUpdate();

	private:
		void Initialize(IN const WindowProperties& oWindowProperties);
		void ShutDown();

	private:
		GLFWwindow* m_pWindow;
	};
};
