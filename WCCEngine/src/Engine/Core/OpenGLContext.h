#pragma once
#include "Core.h"

namespace WCCEngine
{
	class WCC_API OpenGLContext
	{
	public:
		OpenGLContext();
		~OpenGLContext();

	public:
		const bool InitializeOpenGLContext();
		const bool InitializeGlad();
		void DisplayOpenGLContextInfo();

	private:
		const bool CheckIfClientSupportsOpenGLVersion4() const;
	};
};
