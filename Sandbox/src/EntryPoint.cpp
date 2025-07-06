#pragma once
#include "Sandbox.h"

int main()
{
	Sandbox* pSandbox = new Sandbox();
	pSandbox->Run();

	delete pSandbox;
}