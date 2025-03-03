#pragma once

#ifdef WCC_WINDOWS_PLATFORM 
	#ifdef WCC_BUILD_DLL
		#define WCC_API __declspec(dllexport)
	#else
		#define WCC_API __declspec(dllimport)
	#endif 
#endif

//Used for pure virtula functions
#define PURE  = 0

//Describes an input function parameter
#define IN
//Describes an output function parameter
#define OUT

#ifdef WCC_WINDOWS_PLATFORM 
	#define WCCSecureZeroMemory(x) SecureZeroMemory(x, sizeof(x))
#endif