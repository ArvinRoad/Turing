#include "Log.h"

#include <vector>
#include <stdarg.h>
#include <Windows.h>

namespace Turing
{
	void Log::FLogger(const char* target, int level, const char* file, int line, const char* function, const char* fmt, ...)
	{
		static std::pmr::vector<char> buffer;
		if (buffer.size() <= 0)
		{
			buffer.resize(1024 * 1024);
		}
		const char* slevel[] = { "INFO","DEBUG","WARNING","ERROR" };
		if (level < 0)level = 0;
		if (level > 3)level = 3;
		va_list ap;
		va_start(ap, fmt);
		char* pBufer = buffer.data();
		int ret = snprintf(pBufer, buffer.size(), "%s(%d)<%s>-<%s>[%s]", file, line, slevel[level], target, function);
		size_t len = strlen(pBufer);
		ret = _vsnprintf(pBufer + len, buffer.size() - len, fmt, ap);
		if (ret < 0)
		{
			// TODO: 错误处理 首先加倍缓冲区，然后再试一试：直接结束
		}
		OutputDebugStringA(pBufer);
		OutputDebugStringA("\r\n");

		// TODO: 输出目标 文件 控制台
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD color[] = {
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED,
			FOREGROUND_GREEN,
			FOREGROUND_RED,
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED
		};
		WORD wAttributes = color[level];
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(hConsole, &info);
		SetConsoleTextAttribute(hConsole, wAttributes);
		printf(pBufer);
		printf("\n");
		SetConsoleTextAttribute(hConsole, info.wAttributes);
	}

	void Log::Logger(const char* target, int level, const char* function, const char* fmt, ...) 
	{
		static std::pmr::vector<char> buffer;
		if (buffer.size() <= 0)
		{
			buffer.resize(1024 * 1024);
		}
		const char* slevel[] = { "INFO","DEBUG","WARNING","ERROR" };
		if (level < 0) level = 0;
		if (level > 3) level = 3;
		va_list ap;
		va_start(ap, fmt);
		char* pBufer = buffer.data();
		int ret = snprintf(pBufer, buffer.size(), "<%s>-<%s>[%s]", slevel[level], target, function);
		size_t len = strlen(pBufer);
		ret = _vsnprintf(pBufer + len, buffer.size() - len, fmt, ap);
		if (ret < 0)
		{
			
		}
		OutputDebugStringA(pBufer);
		OutputDebugStringA("\r\n");

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD color[] = {
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED,
			FOREGROUND_GREEN,
			FOREGROUND_RED,
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED
		};
		WORD wAttributes = color[level];
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(hConsole, &info);
		SetConsoleTextAttribute(hConsole, wAttributes);
		printf(pBufer);
		printf("\n");
		SetConsoleTextAttribute(hConsole, info.wAttributes);
	}

}