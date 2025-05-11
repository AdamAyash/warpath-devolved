#pragma once
#include "../Core.h"

namespace WCCEngine
{
	template<typename DataType>
	class WCC_API MemoryManagedArray
	{
	public:
		MemoryManagedArray()
		{
		}

		~MemoryManagedArray() 
		{
			Clear();
		}

	public:
		void AppendNew(DataType* pElement)
		{
			WCC_ASSERT(pElement);
			m_oInternalArray.push_back(pElement);
		}

		void Add(DataType& oElement)
		{
			DataType* pNewElement = new DataType();
			*pNewElement = oElement;
			m_oInternalArray.push_back(pNewElement);
		}

		constexpr size_t GetLenght() const
		{
			return m_oInternalArray.size();
		}

		inline DataType* GetAt(const int nIndex) const
		{
			return m_oInternalArray[nIndex];
		}

	private:
		void Clear() 
		{
			for (int nIndex = 0; nIndex < m_oInternalArray.size(); ++nIndex)
			{
				const DataType* const pElement = m_oInternalArray[nIndex];
				if (!pElement)
				{
					WCC_CORE_ERROR(NULL_POINTER_EXCEPTION_MESSAGE, __FUNCTION__);
					continue;
				}

				delete pElement;
			}
			m_oInternalArray.clear();
		}

	private:
		std::vector<DataType*> m_oInternalArray;
	};
};