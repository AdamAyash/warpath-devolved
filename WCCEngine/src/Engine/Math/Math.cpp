#include "wccpch.h"
#include "Math.h"

namespace WCCEngine
{
	const glm::vec2 Math::TransformPixelCoordinatesToNDC(IN const glm::vec2& oPixelCoordinates,
		IN const float fWidth, IN const float fHeight)
	{
		const float fXCoordinate = ((2.0f * oPixelCoordinates.x) / fWidth) - 1.0f;
		const float fYCoordinate = 1.0f - ((2.0f * oPixelCoordinates.y) / fHeight);

		return glm::vec2(fXCoordinate, fYCoordinate);
	}
}