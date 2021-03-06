#pragma once

#ifdef FI_PLATFORM_WINDOWS
	#ifdef FI_BUILD_DLL
		#define FITA_API __declspec(dllexport)
	#else
		#define FITA_API __declspec(dllimport)
	#endif
#else
	#error Fita only supports Windows!
#endif

#ifdef FI_ENABLE_ASSERTS
	#define FI_ASSERT(x, ...) { if (!(x)) { FI_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FI_CORE_ASSERT(x, ...) { if (!(x)) { FI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FI_ASSERT(x, ...) 
	#define FI_CORE_ASSERT(x, ...) 
#endif

#define BIT(x) (1 << x)