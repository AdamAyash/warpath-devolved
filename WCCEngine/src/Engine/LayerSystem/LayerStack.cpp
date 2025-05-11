#include "wccpch.h"
#include "LayerStack.h"

namespace WCCEngine
{
	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
	}

	void LayerStack::PushLayer(ILayer* oLayer)
	{
		m_oLayersArray.AppendNew(oLayer);
		oLayer->OnAttach();
	}

	void LayerStack::PushOverlay(ILayer* oLayer)
	{
	}

	constexpr inline size_t LayerStack::GetLenght() const
	{
		return m_oLayersArray.GetLenght();
	}

	inline ILayer* LayerStack::GetAt(const size_t nIndex)
	{
		return m_oLayersArray.GetAt(nIndex);
	}
}