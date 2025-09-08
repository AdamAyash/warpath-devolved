#include "wccpch.h"
#include "GameObject.h"

namespace WCCEngine
{
	GameObject::GameObject()
		: fRotation(0)
	{
		m_nnObjectId = UIDGenerator::GetInstance()->GetNextUniqueID();
	}

	GameObject::~GameObject()
	{
	}

	constexpr inline __int64 GameObject::GetObjectId() const
	{
		return m_nnObjectId;
	}

	void GameObject::SetTexture2D(IN const Ref<Texture2D> oTexture2D)
	{
		m_oTexture2D = oTexture2D;
	}

	void GameObject::Render(IN Renderer2D& oRenderer2D)
	{
		oRenderer2D.RenderTexture(m_oTexture2D, oPosition, nullptr, fRotation);
	}
}