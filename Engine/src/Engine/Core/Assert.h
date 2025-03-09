#pragma once

#ifdef WCC_DEBUG
#define WCC_ASSERT(expression) \
    if (!(expression)) { \
        WCC_CORE_ERROR("Assertion failed: {0}, file {1}, line {2}", #expression, __FILE__, __LINE__); \
        __debugbreak(); \
    }
#else 
    #define WCC_ASSERT(expression)
#endif 
