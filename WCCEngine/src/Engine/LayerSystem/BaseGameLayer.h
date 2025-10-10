#pragma once
#include "../Core/Core.h"
#include "ILayer.h"
#include "../Core/MemoryManagement/MemoryManagedArray.h"
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
		virtual void OnEvent(IN BaseEvent& oEvent) PURE;
		virtual bool OnAttach() override;
		virtual bool OnDetach() override;
		virtual void Update(IN const GameTime& oGameTime) override;
		virtual void Render(IN Ref<Renderer2D> pRenderer) override;

	protected:
		void AddGameObject(IN GameObject* const pGameObject);
		void RemoveGameObject(IN GameObject* pGameObject);

	private:
		virtual void LoadContent() PURE;

	private:
		MemoryManagedArray<GameObject> m_oGameObjectArray;
	};
}