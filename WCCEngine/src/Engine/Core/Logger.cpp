
#include "wccpch.h"
#include "Logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <spdlog/sinks/basic_file_sink.h>

#define ENGINE_LOGGER_NAME			"WCC Engine"
#define APPLICATION_LOGGER_NAME		"Application"

#define DEFAULT_LOGGER_PATTERN		"%^[%T] %n: %v%$"

namespace WCCEngine 
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	void Logger::Init()
	{
		spdlog::set_pattern(DEFAULT_LOGGER_PATTERN);

		s_CoreLogger = spdlog::stdout_color_mt(ENGINE_LOGGER_NAME);
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt(APPLICATION_LOGGER_NAME);
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}
