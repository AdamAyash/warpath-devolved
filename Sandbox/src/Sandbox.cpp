#include "Sandbox.h"
#include <Engine/Renderer/Shader/Shader.h>
#include <Engine/ResourceManager/ResourceManager.h>
#include "glm.hpp"
#include "ExampleLayer.h"
#include "ExampleBaseGameLayer.h"
#include <Engine/ImGUI/ImGUILayer.h>

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

void Sandbox::Initialize()
{
	BASE::Initialize();

	WCCEngine::ResourceManager& oResourceManager = WCCEngine::ResourceManager::GetResourceManagerInstance();
	oResourceManager.LoadTexture2D("testTexture", "assets/textures/WoodenTexture.png");

	PushLayer(new ExampleLayer());
	PushLayer(new ExampleBaseGameLayer());
	//PushLayerOverlay(new WCCEngine::ImGUILayer());
}

void Sandbox::Render(WCCEngine::Ref<WCCEngine::Renderer2D> pRenderer)
{
	__super::Render(pRenderer);
}