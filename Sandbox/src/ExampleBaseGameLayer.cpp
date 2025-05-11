#include "ExampleBaseGameLayer.h"
#include "ExampleGameObject.h"

ExampleBaseGameLayer::ExampleBaseGameLayer()
{
}

ExampleBaseGameLayer::~ExampleBaseGameLayer()
{
}

void ExampleBaseGameLayer::LoadContent()
{
	WCCEngine::ResourceManager& oResourceManager = WCCEngine::ResourceManager::GetResourceManagerInstance();
	WCCEngine::Ref<WCCEngine::Texture2D> oTexture = oResourceManager.GetResource<WCCEngine::Texture2D>("testTexture");

	ExampleGameObject* const pExampleGameObject = new ExampleGameObject();
	pExampleGameObject->SetTexure2D(oTexture);
	pExampleGameObject->SetPosition(glm::vec2(200, 200));

	AddGameObject(pExampleGameObject);
}