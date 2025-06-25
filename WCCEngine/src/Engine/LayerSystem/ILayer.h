#pragma once
#include "../Core/Core.h"
#include "../EventSystem/EventSystem.h"
#include "../Renderer/Renderer2D.h"
#include "../Core/GameTime.h"

namespace WCCEngine 
{
	class WCC_API ILayer : public IEventListener
	{
	protected:
		ILayer();
	public:
		virtual ~ILayer();

	public:
		virtual bool OnAttach() PURE;
		virtual bool OnDetach() PURE;
		virtual void Update(IN const GameTime& oGameTime) PURE;
		virtual void Render(IN Ref<Renderer2D> pRenderer) PURE;
	};
}

