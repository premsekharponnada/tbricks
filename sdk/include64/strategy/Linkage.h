#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Linkage definitions.
//****************************************************************************************

// Library linkage.
#if defined(_WIN32)
#if defined(BUILDING_STRATEGY_DLL)
#pragma warning(disable : 4251 4355)
#define STRATEGY_EXPORT __declspec(dllexport)
#else
#define STRATEGY_EXPORT __declspec(dllimport)
#endif
#elif defined(__GNUC__) && __GNUC__ >= 4
#define STRATEGY_EXPORT __attribute__((visibility("default")))
#define STRATEGY_LOCAL __attribute__((visibility("hidden")))
#elif defined(__SUNPRO_CC)
#define STRATEGY_EXPORT __global
#define STRATEGY_LOCAL __hidden
#else
#define STRATEGY_EXPORT
#define STRATEGY_LOCAL
#endif

// User strategy linkage.
#if defined(_WIN32)
#define USER_STRATEGY_EXPORT __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#define USER_STRATEGY_EXPORT __attribute__((visibility("default")))
#elif defined(__SUNPRO_CC)
#define USER_STRATEGY_EXPORT __global
#else
#define USER_STRATEGY_EXPORT
#endif

#ifndef TB_LIKELY
#if defined(__GNUC__) || defined(__clang__)

#define TB_LIKELY(e) __builtin_expect(!!(e), 1)
#define TB_UNLIKELY(e) __builtin_expect(!!(e), 0)

#else

#define TB_LIKELY(e) e
#define TB_UNLIKELY(e) e

#endif
#endif

#define DEPRECATE_LINK "https://portal.orc-group.com/confluence/docs/doc.php"

// Experimental APIs
#ifdef TB_ALLOW_EXPERIMENTAL_API
#define TB_EXPERIMENTAL
#endif

#ifndef TB_EXPERIMENTAL
#if defined(__clang__)
#define TB_EXPERIMENTAL \
    __attribute__((deprecated("This is an experimental API. \
        Do not use this as it might be changed, removed or may lead to unstable \
        operation of the Plugin Engine service.")))
#else
#define TB_EXPERIMENTAL
#endif
#endif

// Windows legacy
#if defined(_WIN32)
#include <Windows.h>
#undef GetMessage
#undef Yield
#endif
