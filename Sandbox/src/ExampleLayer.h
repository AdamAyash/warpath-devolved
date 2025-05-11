#pragma once
#include "Engine/LayerSystem/ILayer.h"
#include <Engine/EventSystem/EventSystem.h>

class ExampleLayer : public WCCEngine::ILayer
{
public:
	ExampleLayer();
	~ExampleLayer();

public:
	virtual void OnEvent(IN WCCEngine::BaseEvent& oEvent) override;
	virtual bool OnAttach() override;
	virtual bool OnDetach() override;
	virtual void Update() override;
	virtual void Render(WCCEngine::Ref<WCCEngine::Renderer2D> pRenderer) override;
};