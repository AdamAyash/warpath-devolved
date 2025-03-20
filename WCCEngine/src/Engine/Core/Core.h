#pragma once

#include "memory"

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
//Describes an optional function parameter
#define OPTIONAL

#ifdef WCC_WINDOWS_PLATFORM 
	#define WCCSecureZeroMemory SecureZeroMemory(this, sizeof(this))
#endif

#include "Logger.h"
#include "Assert.h"

namespace WCCEngine 
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}
