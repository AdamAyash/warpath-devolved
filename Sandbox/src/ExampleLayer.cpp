#include "ExampleLayer.h"
#include <Engine/ResourceManager/ResourceManager.h>

ExampleLayer::ExampleLayer()
{
}

ExampleLayer::~ExampleLayer()
{
}

void ExampleLayer::OnEvent(IN WCCEngine::BaseEvent& oEvent)
{
}

bool ExampleLayer::OnAttach() 
{
	return true;
}

bool ExampleLayer::OnDetach()
{
	return true;
}

void ExampleLayer::Update(const WCCEngine::GameTime& oGameTime)
{
}

void ExampleLayer::Render(WCCEngine::Ref<WCCEngine::Renderer2D> pRenderer)
{
}