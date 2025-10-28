#pragma once

#include  "../Core/Core.h"
#include "glm.hpp"

namespace WCCEngine
{
	class Utilities
	{
	private:
		Utilities() = delete;

	public:
		/// <summary>
		/// Transforms the given pixel coordinates to normalized device coordinates in the range [-1,1].
		/// </summary>
		/// <param name="oPixelCoordinates">The given pixel coordinates</param>
		/// <param name="fWidth">The width of the window</param>
		/// <param name="fHeight">The height of the window</param>
		/// <returns>glm::vec</returns>
		static const glm::vec2 TransformPixelCoordinatesToNDC(IN const glm::vec2& oPixelCoordinates, 
			IN const float fWidth, IN const float fHeight);
	};
};