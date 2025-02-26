#pragma once

#ifdef WCC_WINDOWS_PLATFORM 
	#ifdef WCC_BUILD_DLL
		#define WCC_API __declspec(dllexport)
		#else
		#define WCC_API __declspec(dllimport)
	#endif 
#endif
