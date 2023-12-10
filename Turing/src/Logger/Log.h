#ifndef __LOG_H__
#define __LOG_H__

#include <Core.h>

namespace Turing
{
	class TURING_API Log
	{
	public:
		static void FLogger(const char* target, int level, const char* file, int line, const char* function, const char* fmt, ...);
		static void Logger (const char* target, int level, const char* function, const char* fmt, ...);
	};
}

/* FLOG logger macros  */
#define FLOG(tag,...)			::Turing::Log::FLogger(tag,0,__FILE__,__LINE__,__FUNCTION__,__VA_ARGS__)
#define FLOG_INFO(tag,...)		::Turing::Log::FLogger(tag,0,__FILE__,__LINE__,__FUNCTION__,__VA_ARGS__)
#define FLOG_DEBUG(tag,...)		::Turing::Log::FLogger(tag,1,__FILE__,__LINE__,__FUNCTION__,__VA_ARGS__)
#define FLOG_WARNING(tag,...)	::Turing::Log::FLogger(tag,2,__FILE__,__LINE__,__FUNCTION__,__VA_ARGS__)
#define FLOG_ERROR(tag,...)		::Turing::Log::FLogger(tag,3,__FILE__,__LINE__,__FUNCTION__,__VA_ARGS__)

/* LOG logger macros */
#define LOG(tag,...)			::Turing::Log::Logger(tag,0,__FUNCTION__,__VA_ARGS__)
#define LOG_INFO(tag,...)		::Turing::Log::Logger(tag,0,__FUNCTION__,__VA_ARGS__)
#define LOG_DEBUG(tag,...)		::Turing::Log::Logger(tag,1,__FUNCTION__,__VA_ARGS__)
#define LOG_WARNING(tag,...)	::Turing::Log::Logger(tag,2,__FUNCTION__,__VA_ARGS__)
#define LOG_ERROR(tag,...)		::Turing::Log::Logger(tag,3,__FUNCTION__,__VA_ARGS__)

#endif