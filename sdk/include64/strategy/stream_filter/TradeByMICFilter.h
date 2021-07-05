#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByMICFilter, matches trades by MIC.
//****************************************************************************************

#include "strategy/stream_filter/TradeFilter.h"
#include "strategy/type/MIC.h"

namespace tbricks {

/**
 * TradeByMICFilter matches trades having specified Market Information Code(MIC).
 */
class STRATEGY_EXPORT TradeByMICFilter : public TradeFilterCondition
{
public:
    /// Default constructor.
    TradeByMICFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all trades having MIC as specified
     * in the input parameter.
     *
     * @param mic                              Instance of MIC on the basis of which trades will
                                               be filtered.
     */
    TradeByMICFilter(const MIC & mic);
    TradeByMICFilter(const TradeByMICFilter & filter);
    virtual ~TradeByMICFilter();

    TradeByMICFilter & operator=(const TradeByMICFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;
    virtual std::ostream & Print(std::ostream & strm) const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;

private:
    MIC m_mic;
};
}
