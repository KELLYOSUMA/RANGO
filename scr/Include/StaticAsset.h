#pragma once 
#include <iostream>

#ifdef  __cplusplus
    #if __cplusplus >= 201103L
        #define STATIC_ASSERT(expr) \
            static_assert(expr,\
                          "static assert failed: " \
                          #expr)
    #else
    template<bool>  class TStaticAssert(expr);
    template<>  class TstaticAssert(true) {};
    #define STATISTATIC_ASSERT(expr) \
        enum \
        {   \
            ASSERT_GLUE(g_assert_fail_,__LINE__)    \
            =   sizeof(TstaticAssert<!!(expr)>)
        }
    #endif
#endif
    
                