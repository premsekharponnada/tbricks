#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByExtraDataFilter matches trades by their extra data property.
//****************************************************************************************

#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * TradeByExtraDataFilter matches trades having specified extra data.
 */
class STRATEGY_EXPORT TradeByExtraDataFilter : public TradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the trades having
     * Extra Data property name and its value as specified
     * in the respective input parameters.
     *
     * @param name                          Extra data property name
     * @param value                         Extra data property value
     */
    TradeByExtraDataFilter(const String & name, const AnyType & value);
    TradeByExtraDataFilter(const TradeByExtraDataFilter & filter);
    ~TradeByExtraDataFilter();

    TradeByExtraDataFilter & operator=(const TradeByExtraDataFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    ::tbricks::filter::ICondition * m_condition;
};
}
