#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Interface between strategy binary loadable and Strategy Engine.
//****************************************************************************************

#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include "strategy/Linkage.h"
#include "strategy/Strategy.h"
#include "strategy/parameter/ParameterDefinition.h"
#include "strategy/type/StdInt.h"
#include "strategy/pricing/PricingRequest.h"
#include "version/StrategyVersion.h"
#include "strategy/APIVersion.h"

namespace tbricks {

#define TBRICKS_API_VERSION (TBRICKS_API_BRANCH_VERSION << 32) | ((uint32_t)TBRICKS_API_FRAMEWORK_VERSION)

class IDllInterface;
using CreateAppCall = tbricks::Plugin * (*)(const InitializationReason &, const StrategyParameters &);
using CreatePricingCall = tbricks::Plugin * (*)(const PricingRequest &);
using DestroyAppCall = void (*)(tbricks::Plugin *);

STRATEGY_EXPORT IDllInterface * CreateDllInterface(CreateAppCall create, CreatePricingCall create_pricing, DestroyAppCall destroy);
}

#define DEFINE_DLL_INTERFACE(create_app, create_pricing)                                \
    template <typename T, typename... Ts>                                               \
    static tbricks::Plugin * CreateApp(const Ts &... params)                            \
    {                                                                                   \
        if constexpr (std::is_constructible_v<T, Ts...>) {                              \
            return new T(params...);                                                    \
        } else {                                                                        \
            return new T();                                                             \
        }                                                                               \
    }                                                                                   \
                                                                                        \
    static void DestroyApp(tbricks::Plugin * app) { delete app; }                       \
                                                                                        \
    extern "C" USER_STRATEGY_EXPORT void GetVersionString(std::string & version_string) \
    {                                                                                   \
        uint64_t version = TBRICKS_API_VERSION;                                         \
        std::ostringstream sstrm;                                                       \
        uint64_t head = ((version >> 56) & 0xff);                                       \
        uint64_t major = ((version >> 48) & 0xff);                                      \
        uint64_t minor = ((version >> 40) & 0xff);                                      \
        sstrm << head << '.' << major << '.' << minor;                                  \
        uint64_t fwv = (version & 0xffffffff);                                          \
        if (fwv != 0) {                                                                 \
            sstrm << ".v" << fwv;                                                       \
        }                                                                               \
        version_string = std::move(sstrm).str();                                        \
    }                                                                                   \
                                                                                        \
    extern "C" USER_STRATEGY_EXPORT tbricks::IDllInterface * GetDllInterface()          \
    {                                                                                   \
        return tbricks::CreateDllInterface(create_app, create_pricing, DestroyApp);     \
    }

/**
 * DEFINE_STRATEGY_ENTRY, DEFINE_PRICING_ENTRY macro
 * define an entry point in an app.
 * Every TB App have to define one of given macor in its code
 *
 * In case of normal operation (reason != RECOVERED) the app has
 * Paused state and pending state set to "Ok".
 *
 * On Engine startup reason is set to RECOVERED.
 * In this mode, it is user code responsibility to check app state,
 * open up needed streams, analyze state of all child strategies, if any,
 * and to assign proper strategy state depending on results of these
 * operations.
 */
#define DEFINE_STRATEGY_ENTRY(AppName) \
    DEFINE_DLL_INTERFACE((CreateApp<AppName, const tbricks::InitializationReason &, const tbricks::StrategyParameters &>), nullptr)

#define DEFINE_PRICING_ENTRY(AppName) DEFINE_DLL_INTERFACE(nullptr, (CreateApp<AppName, const tbricks::PricingRequest &>))

/// @deprecated Deprecated in 2.14.5 use DEFINE_STRATEGY_ENTRY instead
#define DEFINE_FLOW_ENTRY(AppName) DEFINE_STRATEGY_ENTRY(AppName)

/// @deprecated Deprecated in 2.14.5 use DEFINE_STRATEGY_ENTRY instead
#define DEFINE_VISUALIZATION_ENTRY(AppName) DEFINE_STRATEGY_ENTRY(AppName)

/// @deprecated Deprecated in 2.14.5 use DEFINE_STRATEGY_ENTRY instead
#define DEFINE_EMPTYAPP_ENTRY(AppName) DEFINE_STRATEGY_ENTRY(AppName)
