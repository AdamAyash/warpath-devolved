#pragma once
#include "../Core/Core.h"
#include "ILayer.h"
#include "../Core/MemmoryManagement/MemmoryManagedArray.h"
#include "../GameObjects/GameObject.h"
#include "../ResourceManager/ResourceManager.h"

namespace WCCEngine
{
	class WCC_API BaseGameLayer : public ILayer
	{
	protected:
		BaseGameLayer();
	public:
		virtual ~BaseGameLayer();

	public:
		virtual void OnEvent(IN BaseEvent& oEvent) override;
		virtual bool OnAttach() override;
		virtual bool OnDetach() override;
		virtual void Update() override;
		virtual void Render(IN Ref<Renderer2D> pRenderer) override;

	protected:
		void AddGameObject(IN GameObject* pGameObject);
		void RemoveGameObject(IN GameObject* pGameObject);

	private:
		virtual void LoadContent() PURE;

	private:
		MemmoryManagedArray<GameObject> m_oGameObjectArray;
	};
}