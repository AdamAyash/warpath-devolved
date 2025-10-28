#pragma once
#include "../Core/Core.h"
#include "../Core/GameTime.h"
#include "../Renderer/Texture2D.h"
#include "../Renderer/Renderer2D.h"
#include "../Common/UIDGenerator.h"

namespace WCCEngine
{
	class WCC_API GameObject
	{
	protected:
		GameObject();
	public:
		virtual ~GameObject();

	public:
		constexpr inline __int64 GetObjectId() const;
		void SetTexture2D(IN const Ref<Texture2D> oTexture2D);

		virtual void Update(IN const GameTime& oGameTime) PURE;
		virtual void Render(IN Renderer2D& oRenderer2D);

	public:
		glm::vec2 oPosition;
		float fRotation;

	protected:
		Ref<Texture2D> m_oTexture2D;
		__int64 m_nnObjectId;
	};
};