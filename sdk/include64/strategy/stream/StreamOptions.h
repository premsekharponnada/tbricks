#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Stream options.
//****************************************************************************************

#include "strategy/type/LiquidityPoolIdentifier.h"

namespace tbricks {

template <typename Filter_T, typename Throttle_T>
class StreamOptions
{
public:
    typedef Filter_T filter_type;
    typedef Throttle_T throttle_type;

    StreamOptions() : m_coalescing(true) {}
    ~StreamOptions() {}

    void SetFilter(const filter_type & filter) { m_filter = filter; }
    const filter_type & GetFilter() const { return m_filter; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] filter_type & GetFilter() { return m_filter; }

    void SetCoalescing(bool coalescing)
    {
        m_coalescing = coalescing;
    }
    bool GetCoalescing() const { return m_coalescing; }

    void SetThrottle(const throttle_type & throttle) { m_throttle = throttle; }
    const throttle_type & GetThrottle() const { return m_throttle; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] throttle_type & GetThrottle() { return m_throttle; }

    void SetLiquidityPool(const LiquidityPoolIdentifier & identifier)
    {
        m_liquidity_pool = identifier;
    }
    const LiquidityPoolIdentifier & GetLiquidityPool() const { return m_liquidity_pool; }

private:
    bool m_coalescing;
    filter_type m_filter;
    throttle_type m_throttle;
    LiquidityPoolIdentifier m_liquidity_pool;
};
}
