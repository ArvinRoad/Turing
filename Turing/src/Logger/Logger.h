#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <Core.h>
#include <memory.h>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Turing
{
	class TURING_API Logger
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetServiceLogger() { return s_ServiceLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_ServiceLogger;
	};
}

/* Core logger macros */
#define TURING_CORE_INFO(...)	::Turing::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define TURING_CORE_WARN(...)	::Turing::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define TURING_CORE_TRACE(...)	::Turing::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define TURING_CORE_ERROR(...)	::Turing::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define TURING_CORE_FATAL(...)	::Turing::Logger::GetCoreLogger()->fatal(__VA_ARGS__)

/* Client logger macros */
#define CTURING_INFO(...)		::Turing::Logger::GetClientLogger()->info(__VA_ARGS__)
#define CTURING_WARN(...)		::Turing::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define CTURING_TRACE(...)		::Turing::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define CTURING_ERROR(...)		::Turing::Logger::GetClientLogger()->error(__VA_ARGS__)
#define CTURING_FATAL(...)		::Turing::Logger::GetClientLogger()->fatal(__VA_ARGS__)

/* Service logger macros */
#define STURING_INFO(...)		::Turing::Logger::GetServiceLogger()->info(__VA_ARGS__)
#define STURING_WARN(...)		::Turing::Logger::GetServiceLogger()->warn(__VA_ARGS__)
#define STURING_TRACE(...)		::Turing::Logger::GetServiceLogger()->trace(__VA_ARGS__)
#define STURING_ERROR(...)		::Turing::Logger::GetServiceLogger()->error(__VA_ARGS__)
#define STURING_FATAL(...)		::Turing::Logger::GetServiceLogger()->fatal(__VA_ARGS__)
#endif