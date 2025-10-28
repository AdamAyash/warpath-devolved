#include "wccpch.h"
#include "Texture2D.h"

namespace WCCEngine
{
	Texture2D::Texture2D(IN unsigned int nWidth, IN unsigned int nHeight, const PBYTE pTextureData)
		: m_nWidth(nWidth)
		, m_nHeight(nHeight)
		, m_pTextureData(pTextureData)
	{
		Generate();
	}

	Texture2D::~Texture2D()
	{
		Destroy();
	}

	void Texture2D::Generate()
	{
		glGenTextures(1, &this->m_nObjectID);
		Bind();

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_nWidth, m_nHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_pTextureData);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	void Texture2D::Bind() const
	{
		glBindTexture(GL_TEXTURE_2D, this->m_nObjectID);
	}

	void Texture2D::UnBind() const
	{
	}

	void Texture2D::Destroy()
	{
	}

	constexpr inline unsigned int Texture2D::GetWidth() const
	{
		return m_nWidth;
	}

	constexpr inline unsigned int Texture2D::GetHeight() const
	{
		return m_nHeight;
	}

	constexpr inline glm::vec2 Texture2D::GetSize() const
	{
		return glm::vec2(GetWidth(), GetHeight());
	}
}