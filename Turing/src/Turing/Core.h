#ifndef  __CORE_H__
#define  __CORE_H__

/*------ Windows ------*/
#ifdef TR_PLATFORM_WINDOWS
	#ifdef TR_BUILD_DLL
		#define TURING_API __declspec(dllexport)
	#else
		#define TURING_API __declspec(dllimport)
	#endif
#else
	#error Turing only support Windows!
#endif

/*------  Linux  ------*/
#ifdef TR_PLATFORM_UNIX

#endif

/*------   Mac   ------*/
#ifdef TR_PLATFORM_MAC

#endif

#endif