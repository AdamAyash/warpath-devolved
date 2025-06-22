#include "ExampleBaseGameLayer.h"

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

	AddGameObject(m_pExampleGameObject);
}

void ExampleBaseGameLayer::OnEvent(IN WCCEngine::BaseEvent& oEvent)
{
	WCCEngine::EventDispatcher oEventDispatcher(oEvent);
	oEventDispatcher.Dispatch<WCCEngine::MouseButtonPressedEvent>(WCC_BIND_EVENT(ExampleBaseGameLayer::OnMouseButtonPressedEvent));
}

void ExampleBaseGameLayer::Render(IN WCCEngine::Ref<WCCEngine::Renderer2D> pRenderer)
{
	BASE::Render(pRenderer);
}

bool ExampleBaseGameLayer::OnMouseButtonPressedEvent(const WCCEngine::MouseButtonPressedEvent& oMouseButtonEvent)
{
	m_pExampleGameObject->oTargetPosition = glm::vec2(oMouseButtonEvent.m_dMousePositionX, oMouseButtonEvent.m_dMousePositionY);
	return true;
}