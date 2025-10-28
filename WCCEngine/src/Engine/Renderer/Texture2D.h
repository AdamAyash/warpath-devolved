#pragma once

#include "../Core//OpenGL/OpenGLObject.h"
#include "glm.hpp"

namespace WCCEngine
{
	class WCC_API Texture2D : public OpenGLObject
	{
	public:
		Texture2D(IN unsigned int nWidth, IN unsigned int nHeight, const PBYTE pTextureData);
		~Texture2D();

	public:
		virtual void Generate();
		virtual void Bind() const override;
		virtual void UnBind() const override;
		virtual void Destroy() override;

		constexpr inline unsigned int GetWidth() const;
		constexpr inline unsigned int GetHeight() const;
		constexpr inline glm::vec2 GetSize() const;

	private:
		unsigned int m_nWidth;
		unsigned int m_nHeight;

		const PBYTE m_pTextureData;
	};
}

