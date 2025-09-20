#pragma once
#include "../Core.h"
 
#define ARRAY_ELEMENT_NOT_FOUND -1

namespace WCCEngine
{
	template<typename DataType>
	class MemoryManagedArray
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
		 
		template<typename Key>
		const int LinearSearchSimple(IN Key oKey, IN size_t nnMemberOffset)
		{
			for (int nIndex = 0; nIndex < GetLenght(); ++nIndex)
			{
				DataType* const pElement = GetAt(nIndex);
				if (!pElement)
				{
					WCC_CORE_ERROR(NULL_POINTER_EXCEPTION_MESSAGE, __FUNCTION__);
					continue;
				}

				 const void* pCurrentKey = reinterpret_cast<const void*>
					 (reinterpret_cast<PBYTE>(pElement) + nnMemberOffset);
				
				 if (memcmp(pCurrentKey, &oKey, sizeof(Key)) == 0)
					 return nIndex;
			}

			return ARRAY_ELEMENT_NOT_FOUND;
		}

		constexpr size_t GetLenght() const
		{
			return m_oInternalArray.size();
		}

		inline DataType* GetAt(const int nIndex) const
		{
			return m_oInternalArray[nIndex];
		}

		void Clear() 
		{
			for (int nIndex = 0; nIndex < m_oInternalArray.size(); ++nIndex)
			{
				const DataType* pElement = m_oInternalArray[nIndex];
				if (!pElement)
				{
					WCC_CORE_ERROR(NULL_POINTER_EXCEPTION_MESSAGE, __FUNCTION__);
					continue;
				}

				pElement = nullptr;
				delete pElement;
			}
			m_oInternalArray.clear();
		}

	private:
		std::vector<DataType*> m_oInternalArray;
	};
};