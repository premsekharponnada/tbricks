#pragma once

#if defined (_WIN32)
#if defined(BUILDING_QUOTEDATA_DLL)
    #define QUOTEDATA_EXPORT __declspec(dllexport)
#else
    #define QUOTEDATA_EXPORT __declspec(dllimport)
#endif
#else
#if defined(__GNUC__) && __GNUC__ >= 4
    #define QUOTEDATA_EXPORT __attribute__ ((visibility("default")))
    #define QUOTEDATA_LOCAL  __attribute__ ((visibility("hidden")))
#else
#if defined(__SUNPRO_CC)
    #define QUOTEDATA_EXPORT __global
    #define QUOTEDATA_LOCAL  __hidden
#else
    #define QUOTEDATA_EXPORT
    #define QUOTEDATA_LOCAL
#endif
#endif
#endif
