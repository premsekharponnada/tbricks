#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in trading limit rule streams.
//****************************************************************************************

#include "strategy/stream/TradingLimitRuleStream.h"

namespace tbricks {

namespace filter {
class ICondition;
}

class STRATEGY_EXPORT TradingLimitRule::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Filter & filter);
    ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const Filter & filter);
    Filter & operator&=(const Filter & filter);

    Filter operator||(const Filter & filter);
    Filter operator&&(const Filter & filter);

    Filter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

/**
 * TradingLimitRule::Stream::Filters::ByLimitProviderFilter allows to filter TradingLimitRule of the requested strategy
 */
class STRATEGY_EXPORT TradingLimitRule::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    TradingLimitRule::Stream::Filters::Filter operator||(const TradingLimitRule::Stream::Filters::FilterCondition & cond) const;
    TradingLimitRule::Stream::Filters::Filter operator&&(const TradingLimitRule::Stream::Filters::FilterCondition & cond) const;
    TradingLimitRule::Stream::Filters::Filter operator||(const TradingLimitRule::Stream::Filters::Filter & cond) const;
    TradingLimitRule::Stream::Filters::Filter operator&&(const TradingLimitRule::Stream::Filters::Filter & cond) const;
    TradingLimitRule::Stream::Filters::Filter operator!() const;
    operator TradingLimitRule::Stream::Filters::Filter() const;
};

class STRATEGY_EXPORT TradingLimitRule::Stream::Filters::ByLimitProviderFilter : public TradingLimitRule::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the TradingLimitRule having
     * Strategy identifier as specified in the input parameter.
     *
     * @param provider                      Instance of StrategyIdentifier
     */
    ByLimitProviderFilter(const StrategyIdentifier & provider);
    ByLimitProviderFilter(const ByLimitProviderFilter & filter);

    ByLimitProviderFilter & operator=(const ByLimitProviderFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_provider;
};
}
