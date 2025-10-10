#include "wccpch.h"
#include "UIDGenerator.h"

namespace WCCEngine
{
	UIDGenerator* UIDGenerator::m_pUIDGeneratorInstance = nullptr;
	std::mutex UIDGenerator::m_oMutex;
	__int64 UIDGenerator::m_nnUID = 0;

	UIDGenerator::UIDGenerator()
	{
	}

	UIDGenerator::~UIDGenerator()
	{
	}

	UIDGenerator* const UIDGenerator::GetInstance()
	{
		std::lock_guard<std::mutex> lock(m_oMutex);
		if (m_pUIDGeneratorInstance == nullptr)
			m_pUIDGeneratorInstance = new UIDGenerator();

		return m_pUIDGeneratorInstance;
	}

	constexpr inline __int64 UIDGenerator::GetNextUniqueID() const
	{
		return m_nnUID++;
	}
};