#include "wccpch.h"
#include "GameObject.h"

namespace WCCEngine
{
	GameObject::GameObject()
	{
		nObjectId = UIDGenerator::GetInstance()->GetNextUniqueID();
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::SetTexture2D(IN const Ref<Texture2D> oTexture2D)
	{
		m_oTexture2D = oTexture2D;
	}

	void GameObject::SetPosition(IN const glm::vec2& oPosition)
	{
		m_oPosition = oPosition;
	}

	void GameObject::Render(IN Renderer2D& oRenderer2D)
	{
		oRenderer2D.Render(m_oTexture2D, m_oPosition);
	}
}