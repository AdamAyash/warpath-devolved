#include "Sandbox.h"
#include <Engine/Renderer/Shader/Shader.h>

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

void Sandbox::Initialize()
{
	__super::Initialize();

	WCCEngine::Shader oShaderTest("assets/shaders/ExampleVertexShader.glsl",
		"assets/shaders/ExampleFragmentShader.glsl");

	oShaderTest.Bind();
}

void Sandbox::Render(WCCEngine::Ref<WCCEngine::Renderer2D> pRenderer)
{
	pRenderer->Render();
}