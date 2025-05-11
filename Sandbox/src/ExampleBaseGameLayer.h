#pragma once

#include "Engine/LayerSystem/BaseGameLayer.h"

class ExampleBaseGameLayer : public WCCEngine::BaseGameLayer
{
public:
	ExampleBaseGameLayer();
	~ExampleBaseGameLayer();

public:
	virtual void LoadContent() override;
};