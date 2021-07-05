#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Trading block condition
//
//****************************************************************************

#include "strategy_generated/TradingBlockConditionBase.h"
#include "strategy/type/CFI.h"

namespace tbricks {

enum class BlockedTradingMessageType;

/**
 * Representing a condition what kind of requests should be blocked by trading block
 */
class STRATEGY_EXPORT TradingBlockCondition : public TradingBlockConditionBase
{
public:
    TradingBlockCondition();
    TradingBlockCondition(const TradingBlockCondition & condition);
    TradingBlockCondition(TradingBlockCondition && condition) noexcept;
    TradingBlockCondition & operator=(const TradingBlockCondition & condition);
    TradingBlockCondition & operator=(TradingBlockCondition && condition) noexcept;
    ~TradingBlockCondition() override;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMessageTypes() const;

    /**
     * Get blocked trading message types.
     *
     * @return                          blocked trading message types
     */
    std::vector<BlockedTradingMessageType> GetMessageTypes() const;

    /**
     * %Set blocked trading message types.
     * If the value is empty field will delete from options.
     *
     * @param value                     blocked trading message types
     */
    void SetMessageTypes(const std::vector<BlockedTradingMessageType> & value);

    /**
     * @deprecated Deprecated in 2.14.0, use HasCFIMask
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasCFI() const;

    /**
     * @deprecated Deprecated in 2.14.0, use GetCFIMask
     */
    [[deprecated(DEPRECATE_LINK)]] CFI GetCFI() const;

    /**
     * @deprecated Deprecated in 2.14.0, use SetCFIMask
     */
    [[deprecated(DEPRECATE_LINK)]] void SetCFI(const CFI & value);

private:
    TradingBlockCondition(const protocol::TradingBlockCondition & condition);
    friend class Converter;
};
}
