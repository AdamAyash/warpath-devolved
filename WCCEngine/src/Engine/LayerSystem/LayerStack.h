#pragma once
#include "ILayer.h"
#include "../Core/MemoryManagement/MemoryManagedArray.h"

namespace WCCEngine
{
	class WCC_API LayerStack final
	{
	public:
		LayerStack();
		~LayerStack();

	public:
		void PushLayer(ILayer* const oLayer);
		void PushOverlay(ILayer* const oLayer);

		constexpr inline size_t GetLenght() const;
		inline ILayer* GetAt(const size_t nIndex);

	private:
		MemoryManagedArray<ILayer> m_oLayersArray;
	};
}