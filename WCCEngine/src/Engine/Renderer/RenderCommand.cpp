#include "wccpch.h"
#include "RenderCommand.h"
#include <glad/glad.h>

namespace WCCEngine
{
	RenderCommand::RenderCommand()
	{
	}

	RenderCommand::~RenderCommand()
	{
	}

	void RenderCommand::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}