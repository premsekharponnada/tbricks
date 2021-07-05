#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Order book stream options.
//****************************************************************************************

#include "strategy/type/LiquidityPoolIdentifier.h"

namespace tbricks {

/**
 * PriceLevelOrderBookStreamOption class, used for setting options for PriceLevelOrderBookStream stream.
 * @deprecated use PriceLevelOrderBook::Stream::Options instead. Deprecated in 2.12.0, will be removed in 2.13.0
 */
template <typename Filter_T, typename Throttle_T>
class PriceLevelOrderBookStreamOptions
{
public:
    PriceLevelOrderBookStreamOptions() : m_coalescing(true) {}
    ~PriceLevelOrderBookStreamOptions() {}

    /**
     * Sets filter for stream
     */
    void SetFilter(const Filter_T & filter) { m_filter = filter; }
    const Filter_T & GetFilter() const { return m_filter; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] Filter_T & GetFilter() { return m_filter; }

    /**
     * Sets coalescing property for stream
     */
    void SetCoalescing(bool coalescing)
    {
        m_coalescing = coalescing;
    }
    bool GetCoalescing() const { return m_coalescing; }

    /**
     * Sets throttling property for stream
     */
    void SetThrottle(const Throttle_T & throttle) { m_throttle = throttle; }
    const Throttle_T & GetThrottle() const { return m_throttle; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] Throttle_T & GetThrottle() { return m_throttle; }

    /**
     * Aggregate levels by price,
     * set the maximum number of levels returned,
     * i.e if number of levels is specified, count of returned
     * levels will not more then @p level.
     * @param level -  number of depth levels
     *
     * <b>Example</b>
     *
     * There are bid orders 10@@10, 5@@10, 12@@10, 20@@9.90, 50@@9.80, 100@@9.70.
     *
     * If number of levels was specified:
     *   Level |  Bid ID  |   #Bid   |   Bid   |   Ask   |   #Ask   |  Ask ID
     * --------|----------|----------|---------|---------|----------|-----------
     *       1 |        7 |       16 |      10 |         |          |  <empty>
     *       2 |        8 |       20 |     9.9 |         |          |  <empty>
     *       3 |        9 |       50 |     9.8 |         |          |  <empty>
     *
     *  otherwise:
     *   Level |  Bid ID  |   #Bid   |   Bid   |   Ask   |   #Ask   |  Ask ID
     * --------|----------|----------|---------|---------|----------|-----------
     *       1 |       23 |        1 |      10 |         |          |  <empty>
     *       2 |       26 |        5 |      10 |         |          |  <empty>
     *       3 |       28 |       10 |      10 |         |          |  <empty>
     *       4 |        4 |       20 |     9.9 |         |          |  <empty>
     *       5 |        6 |       50 |     9.8 |         |          |  <empty>
     *       6 |       12 |      100 |     9.7 |         |          |  <empty>
     */
    void SetLevel(const Integer & level)
    {
        m_level = level;
    }
    const Integer & GetLevel() const { return m_level; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] Integer & GetLevel() { return m_level; }

    /**
     * Sets parameters for market data contextualization
     */
    void SetParameters(const StrategyParameters & parameters)
    {
        m_parameters = parameters;
    }
    const StrategyParameters & GetParameters() const { return m_parameters; }

    /**
     * Sets liquidity pool identifier
     */
    void SetLiquidityPool(const LiquidityPoolIdentifier & identifier) { m_liquidity_pool = identifier; }
    const LiquidityPoolIdentifier & GetLiquidityPool() const { return m_liquidity_pool; }

private:
    bool m_coalescing;
    Filter_T m_filter;
    Throttle_T m_throttle;
    Integer m_level;
    StrategyParameters m_parameters;
    LiquidityPoolIdentifier m_liquidity_pool;
};
}
