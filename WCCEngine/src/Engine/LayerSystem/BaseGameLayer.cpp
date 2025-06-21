#include "wccpch.h"
#include "BaseGameLayer.h"

namespace WCCEngine
{
	BaseGameLayer::BaseGameLayer()
	{
	}

	BaseGameLayer::~BaseGameLayer()
	{
	}

	void BaseGameLayer::OnEvent(IN BaseEvent& oEvent)
	{

	}

	bool BaseGameLayer::OnAttach()
	{
		this->LoadContent();
		return true;
	}

	bool BaseGameLayer::OnDetach() 
	{
		return true;
	}

	void BaseGameLayer::Update()
	{
		for (int nIndex = 0; nIndex < m_oGameObjectArray.GetLenght(); ++nIndex)
		{
			GameObject* const pGameObject = m_oGameObjectArray.GetAt(nIndex);
			if (!pGameObject)
			{
				WCC_CORE_ERROR(NULL_POINTER_EXCEPTION_MESSAGE, __FUNCTION__);
				continue;
			}

			pGameObject->Update();

		}
	}

	void BaseGameLayer::Render(IN Ref<Renderer2D> pRenderer)
	{
		for (int nIndex = 0; nIndex < m_oGameObjectArray.GetLenght(); ++nIndex)
		{
			GameObject* const pGameObject = m_oGameObjectArray.GetAt(nIndex);
			if (!pGameObject)
			{
				WCC_CORE_ERROR(NULL_POINTER_EXCEPTION_MESSAGE, __FUNCTION__);
				continue;
			}

			pGameObject->Render(*pRenderer);
		}
	}

	void BaseGameLayer::AddGameObject(IN GameObject* pGameObject) 
	{
		m_oGameObjectArray.AppendNew(pGameObject);
	}
	
	void BaseGameLayer::RemoveGameObject(IN GameObject* pGameObject)
	{
	}
}