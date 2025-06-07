#pragma once
#include "../Core/Core.h"
#include "../Renderer/Texture2D.h"
#include "../Renderer/Renderer2D.h"
#include "../Core/UIDGenerator.h"

namespace WCCEngine
{
	class WCC_API GameObject
	{
	protected:
		GameObject();
	public:
		virtual ~GameObject();

	public:
		virtual void Update() PURE;
		virtual void Render(IN Renderer2D& oRenderer2D);

		void SetTexture2D(IN const Ref<Texture2D> oTexture2D);
		void SetPosition(IN const glm::vec2& oPosition);

	public:
		unsigned long nObjectId;

	protected:
		Ref<Texture2D> m_oTexture2D;
		glm::vec2 m_oPosition;
	};
};