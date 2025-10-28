#pragma once

#include "../Core/Core.h"

namespace WCCEngine
{
	class WCC_API RandomNumberGenerator final
	{
	public:
		RandomNumberGenerator();
		~RandomNumberGenerator();

	public:
		const UINT GetNextUnsignedInt(IN const UINT nBeginRange, IN const UINT nEndRange);
	};
}
