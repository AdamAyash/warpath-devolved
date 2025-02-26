#include "Logger.h"

#define ENGINE_LOGGER_NAME  "Engine"
#define APPLICATION_LOGGER_NAME  "Application"

namespace Engine 
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt(ENGINE_LOGGER_NAME);
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt(APPLICATION_LOGGER_NAME);
		s_ClientLogger->set_level(spdlog::level::trace);
	}
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
 

