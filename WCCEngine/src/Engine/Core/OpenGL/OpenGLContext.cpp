#include "wccpch.h"
#include "OpenGLContext.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace WCCEngine
{
	OpenGLContext::OpenGLContext()
	{
	}

	OpenGLContext::~OpenGLContext()
	{
	}

	const bool OpenGLContext::InitializeOpenGLContext()
	{
		const int nIsGLFWInitialized = glfwInit();
		WCC_ASSERT(nIsGLFWInitialized);
		
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		return true;
	}

	const bool OpenGLContext::InitializeGlad()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			WCC_CORE_ERROR("Failed to initialize glad!");
			return false;
		}

		WCC_ASSERT(CheckIfClientSupportsOpenGLVersion4());

		return true;
	}

	void OpenGLContext::DisplayOpenGLContextInfo()
	{
		WCC_CORE_INFO("OpenGL Vendor: {0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
		WCC_CORE_INFO("OpenGL Renderer:{0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
		WCC_CORE_INFO("OpenGL Version: {0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
		WCC_CORE_INFO("OpenGL Shading Language Version: {0}", reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)));
	}

	const bool OpenGLContext::CheckIfClientSupportsOpenGLVersion4() const
	{
		return GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 3);
	}
}
