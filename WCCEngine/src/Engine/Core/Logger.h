#pragma once

#include "Core.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace WCCEngine
{
	class WCC_API Logger
	{
	public:

		static void Init();

		inline static const std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static const std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
};

//Core log macros
#define WCC_CORE_INFO(...)		::WCCEngine::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define WCC_CORE_WARN(...)		::WCCEngine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define WCC_CORE_TRACE(...)		::WCCEngine::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define WCC_CORE_ERROR(...)		::WCCEngine::Logger::GetCoreLogger()->error(__VA_ARGS__)

//Client log macros
#define WCC_CLIENT_INFO(...)	::WCCEngine::Logger::GetClientLogger()->info(__VA_ARGS__)
#define WCC_CLIENT_WARN(...)	::WCCEngine::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define WCC_CLIENT_TRACE(...)	::WCCEngine::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define WCC_CLIENT_ERROR(...)	::WCCEngine::Logger::GetClientLogger()->error(__VA_ARGS__)

