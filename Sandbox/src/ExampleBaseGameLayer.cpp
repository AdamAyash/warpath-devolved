#include "ExampleBaseGameLayer.h"
#include "Engine/Core/RandomNumberGenerator.h"
#include <imgui.h>

ExampleBaseGameLayer::ExampleBaseGameLayer()
	: m_pExampleGameObject(nullptr)
{
}

ExampleBaseGameLayer::~ExampleBaseGameLayer()
{
}

void ExampleBaseGameLayer::LoadContent()
{
	WCCEngine::ResourceManager& oResourceManager = WCCEngine::ResourceManager::GetResourceManagerInstance();
	WCCEngine::Ref<WCCEngine::Texture2D> oTexture = oResourceManager.GetResource<WCCEngine::Texture2D>("testTexture");

	m_pExampleGameObject = new ExampleGameObject();
	m_pExampleGameObject->SetTexture2D(oTexture);
	m_pExampleGameObject->oPosition = glm::vec2(200, 200);
	m_pExampleGameObject->oTargetPosition = glm::vec2(200, 200);

	WCCEngine::RandomNumberGenerator oRandomNumberGenerator;
	for (int nInex = 0; nInex < 1000; ++nInex)
	{
		const UINT nRandomPositionX = oRandomNumberGenerator.GetNextUnsignedInt(0, 1600);
		const UINT nRandomPositionY = oRandomNumberGenerator.GetNextUnsignedInt(0, 900);

		ExampleGameObject* gameObject = new ExampleGameObject();
		gameObject->SetTexture2D(oTexture);
		gameObject->oPosition = glm::vec2(nRandomPositionX, nRandomPositionY);
		gameObject->oTargetPosition = glm::vec2(nRandomPositionX, nRandomPositionY);

		AddGameObject(gameObject);
	}

	AddGameObject(m_pExampleGameObject);
}

void ExampleBaseGameLayer::OnEvent(IN WCCEngine::BaseEvent& oEvent)
{
	WCCEngine::EventDispatcher oEventDispatcher(oEvent);
	oEventDispatcher.Dispatch<WCCEngine::MouseButtonPressedEvent>(WCC_BIND_EVENT(ExampleBaseGameLayer::OnMouseButtonPressedEvent));
}

void ExampleBaseGameLayer::OnImGuiRender()
{
	/*ImGui::Begin("Settings");
	ImGui::End();*/
}

void ExampleBaseGameLayer::Render(IN WCCEngine::Ref<WCCEngine::Renderer2D> pRenderer)
{
	BASE::Render(pRenderer);
}

bool ExampleBaseGameLayer::OnMouseButtonPressedEvent(const WCCEngine::MouseButtonPressedEvent& oMouseButtonEvent)
{
	if(oMouseButtonEvent.GetMouseCode() == WCCEngine::MouseCodes::ButtonRight)
		m_pExampleGameObject->oTargetPosition = glm::vec2(oMouseButtonEvent.m_dMousePositionX, oMouseButtonEvent.m_dMousePositionY);

	return true;
}