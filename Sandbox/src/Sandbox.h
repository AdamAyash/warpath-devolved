#pragma once

#include <Engine/Core/Application/Application.h>
#include <Engine/Renderer/Renderer2D.h>

class Sandbox final : public WCCEngine::Application
{
public:
	Sandbox();
	~Sandbox();

public:
	virtual void Initialize() override;
	virtual void Render(WCCEngine::Ref<WCCEngine::Renderer2D> pRenderer) override;
};