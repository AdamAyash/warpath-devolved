#pragma once
#include "../LayerSystem/ILayer.h"

namespace WCCEngine 
{
	class WCC_API ImGUILayer : public ILayer
	{
	protected:
		ImGUILayer();
		virtual ~ImGUILayer();

	public:
		virtual void OnEvent(IN BaseEvent& oEvent) override;
		virtual bool OnAttach() override;
		virtual bool OnDetach() override;
		virtual void Update(IN const GameTime& oGameTime) override;
		virtual void Render(IN Ref<Renderer2D> pRenderer) override;
	};
}