#pragma once

#include "Engine/Core/Logger.h"

int main()
{
	Engine::Logger::Init();
	WCC_CLIENT_INFO("Hello world");
}