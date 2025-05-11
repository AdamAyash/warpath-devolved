#pragma once
#include "../Core/Core.h"
#include "../Renderer/Texture2D.h"
#include "../Renderer/Renderer2D.h"

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

		const Ref<Texture2D> GetTexure2D() const;
		void SetTexure2D(IN const Ref<Texture2D> oTexture2D);

		void SetPosition(IN const glm::vec2& oPosition);

	protected:
		Ref<Texture2D> m_oTexture2D;
		glm::vec2 m_oPosition;
	};
};