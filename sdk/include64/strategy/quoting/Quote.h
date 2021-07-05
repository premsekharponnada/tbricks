#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Quote object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"

namespace tbricks {

class STRATEGY_EXPORT Quote : public Printable
{
public:
    Quote() = default;
    Quote(const Price & bid, const Price & ask) : m_bid(bid), m_ask(ask) {}

    Quote(const Quote & quote) = default;
    Quote & operator=(const Quote & quote) = default;

    ~Quote() override = default;

public:
    void SetBidPrice(const Price & price) { m_bid = price; }
    void SetAskPrice(const Price & price) { m_ask = price; }
    void SetOuterBidPrice(const Price & price) { m_outer_bid = price; }
    void SetOuterAskPrice(const Price & price) { m_outer_ask = price; }

    /**
     * Setting the inner bid price. Inner price is used in pressure convention 3 as an inner end of the quote prices range.
     * It must be set to non-empty value if pressure convention 3 is used.
     *
     * @param price                     The price to set
     */
    void SetInnerBidPrice(const Price & price) { m_inner_bid = price; }
    /**
     * Setting the inner ask price. Inner price is used in pressure convention 3 as an inner end of the quote prices range.
     * It must be set to non-empty value if pressure convention 3 is used.
     *
     * @param price                     The price to set
     */
    void SetInnerAskPrice(const Price & price) { m_inner_ask = price; }

    void SetQuoteBidThreshold(const Double & threshold) { m_quote_bid_threshold = threshold; }
    void SetQuoteAskThreshold(const Double & threshold) { m_quote_ask_threshold = threshold; }
    void SetBidMargin(const Double & margin) { m_bid_margin = margin; }
    void SetAskMargin(const Double & margin) { m_ask_margin = margin; }
    void SetQuoteMaxSpread(const Double & spread) { m_quote_max_spread = spread; }
    void SetPriority(const Double & priority) { m_priority = priority; }

    const Price & GetBidPrice() const { return m_bid; }
    const Price & GetAskPrice() const { return m_ask; }
    const Price & GetOuterBidPrice() const { return m_outer_bid; }
    const Price & GetOuterAskPrice() const { return m_outer_ask; }

    /**
     * Getting the inner bid price. Inner price is used in pressure convention 3 as an inner end of the quote prices range.
     *
     * @return                          The inner bid price
     */
    const Price & GetInnerBidPrice() const { return m_inner_bid; }
    /**
     * Getting the inner ask price. Inner price is used in pressure convention 3 as an inner end of the quote prices range.
     *
     * @return                          The inner ask price
     */
    const Price & GetInnerAskPrice() const { return m_inner_ask; }

    const Double & GetQuoteBidThreshold() const { return m_quote_bid_threshold; }
    const Double & GetQuoteAskThreshold() const { return m_quote_ask_threshold; }
    const Double & GetBidMargin() const { return m_bid_margin; }
    const Double & GetAskMargin() const { return m_ask_margin; }
    const Double & GetQuoteMaxSpread() const { return m_quote_max_spread; }
    const Double & GetPriority() const { return m_priority; }

    bool HasBidPrice() const { return !m_bid.Empty(); }
    bool HasAskPrice() const { return !m_ask.Empty(); }
    bool HasOuterBidPrice() const { return !m_outer_bid.Empty(); }
    bool HasOuterAskPrice() const { return !m_outer_ask.Empty(); }

    /**
     * Checking is the inner bid price set or not. Inner price is used in pressure convention 3 as an inner end of the quote prices range.
     *
     * @return                          'true' if the inner bid price is set, 'false' otherwise
     */
    bool HasInnerBidPrice() const { return !m_inner_bid.Empty(); }
    /**
     * Checking is the inner ask price set or not. Inner price is used in pressure convention 3 as an inner end of the quote prices range.
     *
     * @return                          'true' if the inner ask price is set, 'false' otherwise
     */
    bool HasInnerAskPrice() const { return !m_inner_ask.Empty(); }

    bool HasValidPrices() const { return (!HasBidPrice() || !HasAskPrice() || GetBidPrice() < GetAskPrice()); }
    bool HasQuoteBidThreshold() const { return !m_quote_bid_threshold.Empty(); }
    bool HasQuoteAskThreshold() const { return !m_quote_ask_threshold.Empty(); }
    bool HasBidMargin() const { return !m_bid_margin.Empty(); }
    bool HasAskMargin() const { return !m_ask_margin.Empty(); }
    bool HasQuoteMaxSpread() const { return !m_quote_max_spread.Empty(); }
    bool HasPriority() const { return !m_priority.Empty(); }

public:
    bool Empty() const { return m_bid.Empty() && m_ask.Empty(); }

    void Clear()
    {
        m_bid.Clear();
        m_ask.Clear();
        m_outer_bid.Clear();
        m_outer_ask.Clear();
        m_inner_bid.Clear();
        m_inner_ask.Clear();
        m_quote_bid_threshold.Clear();
        m_quote_ask_threshold.Clear();
        m_bid_margin.Clear();
        m_ask_margin.Clear();
        m_quote_max_spread.Clear();
        m_priority.Clear();
    }

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Price m_bid;
    Price m_ask;
    Price m_outer_bid;
    Price m_outer_ask;
    Price m_inner_bid;
    Price m_inner_ask;
    Double m_quote_bid_threshold;
    Double m_quote_ask_threshold;
    Double m_bid_margin;
    Double m_ask_margin;
    Double m_quote_max_spread;
    Double m_priority;
};

} // namespace tbricks
