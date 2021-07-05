#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingLimitRule stream.
//****************************************************************************************

#include "strategy/stream/Stream.h"
#include "strategy/Linkage.h"
#include "strategy/limit/TradingLimitRule.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/StreamOptions.h"
#include "strategy/stream_throttle/TradingLimitRuleThrottle.h"

namespace tbricks {

namespace strategy {
class TradingLimitRuleStreamImpl;
}

class STRATEGY_EXPORT TradingLimitRule::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByLimitProviderFilter;
    };

    typedef StreamOptions<TradingLimitRule::Stream::Filters::Filter, TradingLimitRuleThrottle> Options;

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open(Type type, const InstrumentIdentifier & instrument, const TradingLimitRule::Stream::Filters::Filter & filter);
    void Open(Type type, const InstrumentIdentifier & instrument, const Options & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    strategy::TradingLimitRuleStreamImpl * m_stream;
};

class STRATEGY_EXPORT TradingLimitRule::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleTradingLimitRule(const StreamIdentifier & stream, const TradingLimitRule::Update & rule) = 0;

    /**
     * TradingLimitRule stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated TradingLimitRule
     */
    virtual void HandleTradingLimitRuleInvalidate(const StreamIdentifier & stream, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};

typedef TradingLimitRule::Stream::Filters::Filter AnyTradingLimitRuleFilter;
}
