#pragma once

#ifdef FI_PLATFORM_WINDOWS
	#ifdef FITA_BUILD_DLL
		#define FITA_API __declspec(dllexport)
	#else
		#define FITA_API __declspec(dllimport)
	#endif
#else
	#error Fita only supports Windows!
#endif