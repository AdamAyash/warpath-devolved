#pragma once
#include "Sandbox.h"

int main()
{
	Sandbox* application = new Sandbox();
	application->Run();

	delete application;
}