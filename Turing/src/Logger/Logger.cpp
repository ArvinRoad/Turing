#include "trpch.h"
#include "Logger.h"

namespace Turing
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ServiceLogger;
	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("Turing");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);

		s_ServiceLogger = spdlog::stdout_color_mt("Service");
		s_ServiceLogger->set_level(spdlog::level::trace);

	}

}