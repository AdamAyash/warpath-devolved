#pragma once
#include <mutex>
#include "Core.h"

namespace WCCEngine
{
	class WCC_API UIDGenerator 
	{
	private:
		UIDGenerator();
		UIDGenerator(IN UIDGenerator& oUIDGenerator) = delete;

	public:
		~UIDGenerator();

	public:
		static UIDGenerator* const GetInstance();
		constexpr inline unsigned long GetNextUniqueID() const;

	public:
		void operator=(const UIDGenerator&) = delete;

	private:
		static UIDGenerator* m_pUIDGeneratorInstance;
		static std::mutex m_oMutex;
		static unsigned long m_lUID;
	};
};