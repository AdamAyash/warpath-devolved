#pragma once
#include "ILayer.h"
#include "../Core/MemmoryManagement/MemmoryManagedArray.h"

namespace WCCEngine
{
	class WCC_API LayerStack final
	{
	public:
		LayerStack();
		~LayerStack();

	public:
		void PushLayer(ILayer* oLayer);
		void PushOverlay(ILayer* oLayer);

		constexpr inline size_t GetLenght() const;
		inline ILayer* GetAt(const size_t nIndex);

	private:
		MemmoryManagedArray<ILayer> m_oLayersArray;
	};
}