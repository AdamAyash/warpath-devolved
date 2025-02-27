#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Engine
{
	class WCC_API Logger
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() 
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Core log macros
#define WCC_CORE_INFO(...)		::Engine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define WCC_CORE_WARN(...)		::Engine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define WCC_CORE_TRACE(...)		::Engine::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define WCC_CORE_ERROR(...)		::Engine::Logger::GetCoreLogger()->error(__VA_ARGS__)

//Client log macros
#define WCC_CLIENT_INFO(...)	::Engine::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define WCC_CLIENT_WARN(...)	::Engine::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define WCC_CLIENT_TRACE(...)	::Engine::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define WCC_CLIENT_ERROR(...)	::Engine::Logger::GetClientLogger()->error(__VA_ARGS__)

