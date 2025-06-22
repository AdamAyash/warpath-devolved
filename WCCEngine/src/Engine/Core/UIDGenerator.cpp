#include "wccpch.h"
#include "UIDGenerator.h"

namespace WCCEngine
{
	UIDGenerator* UIDGenerator::m_pUIDGeneratorInstance = nullptr;
	std::mutex UIDGenerator::m_oMutex;
	unsigned long UIDGenerator::m_lUID = 0;

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

	constexpr inline unsigned long UIDGenerator::GetNextUniqueID() const
	{
		return m_lUID++;
	}
};