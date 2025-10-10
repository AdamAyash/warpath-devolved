#pragma once

#include "Engine/LayerSystem/BaseGameLayer.h"
#include <Engine/EventSystem/EventImplementations/InputEvents/MouseButtonPressedEvent.h>
#include "ExampleGameObject.h"

class ExampleBaseGameLayer : public WCCEngine::BaseGameLayer
{
public:
	ExampleBaseGameLayer();
	~ExampleBaseGameLayer();

public:
	virtual void LoadContent() override;
	virtual void OnEvent(IN WCCEngine::BaseEvent& oEvent) override;
	virtual void OnImGuiRender() override;
	virtual void Render(IN WCCEngine::Ref<WCCEngine::Renderer2D> pRenderer) override;

private:
	bool OnMouseButtonPressedEvent(const WCCEngine::MouseButtonPressedEvent& oMouseButtonEvent);

private:
	ExampleGameObject* m_pExampleGameObject;
};