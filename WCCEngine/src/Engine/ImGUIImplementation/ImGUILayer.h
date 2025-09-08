#pragma once
#include "../LayerSystem/ILayer.h"

namespace WCCEngine 
{
	class WCC_API ImGUILayer : public ILayer
	{
	public:
		ImGUILayer();
		virtual ~ImGUILayer();

	public:
		void Begin();
		void End();

	public:
		virtual bool OnAttach() override;
		virtual bool OnDetach() override;
		virtual void OnEvent(IN BaseEvent& oEvent) override;
		virtual void Update(IN const GameTime& oGameTime) override;
		virtual void Render(IN Ref<Renderer2D> pRenderer) override;
	};
}