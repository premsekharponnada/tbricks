#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyByInstrumentIdentifierFilter, matches updates of related strategy
// instance.
//
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/StrategyData.h"
#include "strategy/type/Identifier.h"
#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

/**
 * StrategyByInstrumentIdentifierFilter matches concrete strategy instance updates,
 * selected by instrument identifiers.
 */
class STRATEGY_EXPORT StrategyByInstrumentIdentifiersFilter : public StrategyFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the strategy instance by instrument identifiers.
     *
     * @param id              Instrument identifier
     */
    StrategyByInstrumentIdentifiersFilter(const InstrumentIdentifier & id);

    StrategyByInstrumentIdentifiersFilter(const StrategyByInstrumentIdentifiersFilter & filter);

    StrategyByInstrumentIdentifiersFilter & operator=(const StrategyByInstrumentIdentifiersFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentIdentifier m_instrument;
};
}
