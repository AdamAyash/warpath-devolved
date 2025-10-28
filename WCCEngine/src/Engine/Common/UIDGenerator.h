#pragma once
#include <mutex>
#include "../Core/Core.h"

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
		constexpr inline __int64 GetNextUniqueID() const;

	public:
		void operator=(const UIDGenerator&) = delete;

	private:
		static UIDGenerator* m_pUIDGeneratorInstance;
		static std::mutex m_oMutex;
		static __int64 m_nnUID;
	};
};