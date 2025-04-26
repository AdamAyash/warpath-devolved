#include "Sandbox.h"
#include <Engine/Renderer/Shader/Shader.h>
#include <Engine/ResourceManager/ResourceManager.h>
#include "glm.hpp"

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

void Sandbox::Initialize()
{
	__super::Initialize();

	WCCEngine::ResourceManager& oResourceManager = WCCEngine::ResourceManager::GetResourceManagerInstance();
	oResourceManager.LoadTexture2D("testTexture", "assets/textures/WoodenTexture.png");
}

void Sandbox::Render(WCCEngine::Ref<WCCEngine::Renderer2D> pRenderer)
{
	WCCEngine::ResourceManager& oResourceManager = WCCEngine::ResourceManager::GetResourceManagerInstance();
	WCCEngine::Ref<WCCEngine::Texture2D> oTexture = oResourceManager.GetResource<WCCEngine::Texture2D>("testTexture");

	pRenderer->Render(oTexture, glm::vec2(200.0f, 200.0f));
}