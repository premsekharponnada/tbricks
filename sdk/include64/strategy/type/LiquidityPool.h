#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Liquidity Pool type.
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/LiquidityPoolIdentifier.h"

namespace tbricks {

namespace venue {
class Pool;
}

class STRATEGY_EXPORT LiquidityPool : public Printable
{
public:
    LiquidityPool();
    LiquidityPool(const LiquidityPool & pool);
    LiquidityPool(LiquidityPool && pool) noexcept;
    ~LiquidityPool() override;

    LiquidityPool & operator=(const LiquidityPool & pool);
    LiquidityPool & operator=(LiquidityPool && pool) noexcept;

    bool operator==(const LiquidityPool & value) const;
    bool operator!=(const LiquidityPool & value) const;

    /**
     * @return true if both name and identifier are empty.
     */
    bool Empty() const;

    /**
     * Clear name and identifier.
     */
    void Clear();

public:
    /**
     * Get liquidity pool name.
     *
     * @return                          name of liquidity pool
     */
    String GetName() const;

    /**
     * Get liquidity pool identifier.
     *
     * @return                          identifier of liquidity pool.
     */
    LiquidityPoolIdentifier GetIdentifier() const;

    /**
     * @return true if pool is default.
     */
    bool IsDefault() const;

    std::ostream & Print(std::ostream & strm) const override;

public:
    LiquidityPool(const venue::Pool & pool);

private:
    std::unique_ptr<venue::Pool> m_impl;
};
}
