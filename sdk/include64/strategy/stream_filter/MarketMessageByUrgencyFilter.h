#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filtering based on market message urgency.
//****************************************************************************************

#include "strategy/stream_filter/MarketMessageFilter.h"

namespace tbricks {

/**
 * Allows to improve stream granularity by filtering out messages with certain urgency.
 *
 * NOTE: Filters of this kind can never be used on their own, rather they
 * must be a part of expression with other strategy filters.
 */
class STRATEGY_EXPORT MarketMessage::Stream::Filters::ByUrgency : public MarketMessage::Stream::Filters::FilterCondition
{
public:
    /// Default constructor.
    ByUrgency();

    /**
     * Constructor.
     *
     * Allows to filter market messages on the bases of its urgency level.
     *
     * @param set			Value of MarketMessage::Urgency enumeration type
     */
    ByUrgency(const MarketMessage::Urgency & set);

    virtual void Clear();
    virtual filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    bool m_empty;
    MarketMessage::Urgency m_urgency;
};
}
