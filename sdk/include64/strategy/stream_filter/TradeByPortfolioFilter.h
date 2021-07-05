#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByPortfolioFilter, matches trades by portfolio identifier and
// optionally, by instrument identifier.
//****************************************************************************************

#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/type/InstrumentIdentifier.h"

#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

/**
 * TradeByPortfolioFilter matches all trades with trade identifier provided
 * as filter argument.
 */
class STRATEGY_EXPORT TradeByPortfolioFilter : public TradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all trades having portfolio identifier
     * as specified in the input parameter.
     * To match the trades of the children portfolios (whole subtree of the portfolio identifier specified as the input
     parameter),
     * set child_portfolios_trades = true. By default, no trades which belongs to the children portfolios will be
     filtered.
     *
     * @param portfolio_id                          Instance of PortfolioIdentifier.
     *  @param child_portfolios_trades              bool instance, to specify if trades belonging to any of the children
                                                    portfolios should be filtered or not.
                                                    Set to true, if trades belongs to any of the children portfolios
     should be filtered.

                                                    NOTE: children portfolios refers to the whole subtree of the
     portfolio identifier specified as the input parameter.
     */
    TradeByPortfolioFilter(const PortfolioIdentifier & portfolio_id, bool child_portfolios_trades = false);

    /**
     * Constructor.
     *
     * Makes a filter to match all trades having portfolio identifier
     * as specified in the input parameter.
     * To match the trades of the children portfolios (whole subtree of the portfolio identifier specified as the input
     parameter),
     * set child_portfolios_trades = true. By default, no trades which belongs to the children portfolios will be
     filtered.
     *
     * @param portfolio_id                     Instance of PortfolioIdentifier.
     *  @param child_portfolios_trades         bool instance, to specify if trades belonging to any of the children
                                               portfolios should be filtered or not.
                                               Set to true, if trades belongs to any of the children portfolios should
     be filtered.

                                               NOTE: children portfolios refers to the whole subtree of the portfolio
     identifier specified as the input parameter.
     */
    TradeByPortfolioFilter(const PortfolioIdentifier & portfolio_id,
                           const InstrumentIdentifier & instrument_id,
                           bool child_portfolios_trades = false);

    TradeByPortfolioFilter(const TradeByPortfolioFilter & filter) = default;
    TradeByPortfolioFilter & operator=(const TradeByPortfolioFilter & filter) = default;

    /**
     * %Set the instrument identifier for the filter.
     * Allows to filter trades on the basis of its instrument identifier.
     *
     * @param instrument_id                   Instance of InstrumentIdentifier.
     */
    void SetInstrumentIdentifier(const InstrumentIdentifier & instrument_id);

    /**
     * %Set filtering condition to decide whether
     * trades of the child portfolio should be filtered or not.
     *
     * @param child_portfolios_trades          bool instance, to specify if trades belonging to any of the children
                                               portfolios should be filtered or not.
                                               Set to true, if trades belongs to any of the children portfolios should
     be filtered.

                                               NOTE: children portfolios refers to the whole subtree of the portfolio
     identifier specified as the input parameter.
     */
    void SetChildPortfoliosTrades(bool child_portfolios_trades);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    PortfolioIdentifier m_portfolio_id;
    InstrumentIdentifier m_instrument_id;
    bool m_child_portfolios_trades;
};
}
