#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InitializationReason
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/StrategyState.h"

namespace tbricks {

class STRATEGY_EXPORT InitializationReason : public Printable
{
public:
    enum Reason
    {
        CREATED,   /**< New strategy created from scratch      */
        RECOVERED, /**< Strategy is being recovered            */
        DUPLICATED /**< Strategy is a copy of another instance */
    };

    InitializationReason(Reason reason);
    InitializationReason(Reason reason, const StrategyState & state);
    InitializationReason(const InitializationReason & reason);

    InitializationReason & operator=(const InitializationReason & reason);

    /**
     * Initialization reason.
     *
     * @return                          Initialization reason
     */
    Reason GetReason() const;

    bool IsCreated() const;
    bool IsDuplicated() const;
    bool IsRecovered() const;

    /**
     * Get previous state.
     *
     * When called in recovery mode, returns strategy state recorded at
     * SE shutdown time, i.e. the state where the strategy being
     * recovered should try to go to.
     *
     * If strategy is created by regular means (that is, it is not
     * a recovery case), method returns "false" and does not modify
     * its argument.
     *
     * @param state                     Previous state
     * @return                          "true" if strategy is being recovered,
     *                                  "false" otherwise
     */
    bool GetPreviousState(StrategyState & state) const;

public:
    bool operator==(Reason value) const;
    bool operator!=(Reason value) const;

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Reason m_reason;
    StrategyState m_previous_state;
};
}
