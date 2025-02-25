#pragma once

#ifdef WCC_PLATFORM_WINDOWS 
	#ifdef WCC_BUILD_DLL
		#define WCC_API __declspec(dllexport)
	#else
#define WCC_API __declspec(dllimport)
	#endif
#else 
	#error Warcraft clone only supports Windows!
#endif 