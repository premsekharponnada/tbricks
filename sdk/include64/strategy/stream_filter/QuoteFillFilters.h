#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in QuoteFill streams.
//****************************************************************************************

#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/QuoteFillStream.h"
#include "strategy/quoting/QuoteSet.h"
#include "strategy/quoting/QuoteSetProxy.h"

namespace tbricks {

class STRATEGY_EXPORT QuoteFill::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    QuoteFill::Stream::Filters::Filter operator||(const QuoteFill::Stream::Filters::FilterCondition & cond) const;
    QuoteFill::Stream::Filters::Filter operator&&(const QuoteFill::Stream::Filters::FilterCondition & cond) const;
    QuoteFill::Stream::Filters::Filter operator||(const QuoteFill::Stream::Filters::Filter & cond) const;
    QuoteFill::Stream::Filters::Filter operator&&(const QuoteFill::Stream::Filters::Filter & cond) const;
    QuoteFill::Stream::Filters::Filter operator!() const;
    operator QuoteFill::Stream::Filters::Filter() const;
};

/**
 * Filter, matches by quote set identifier.
 */
class STRATEGY_EXPORT QuoteFill::Stream::Filters::ByQuoteSetFilter : public QuoteFill::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match QuoteFill having QuoteSet
     * as specified in the input parameter.
     *
     * @param quote_set                       Instance of QuoteSet
     */
    ByQuoteSetFilter(const QuoteSet & quote_set);

    /**
     * Constructor.
     *
     * Makes a filter to match QuoteFill having QuoteSetProxy
     * as specified in the input parameter.
     *
     * @param quote_set_proxy                 Instance of QuoteSetProxy
     */
    ByQuoteSetFilter(const QuoteSetProxy & quote_set_proxy);

    /**
     * Constructor.
     *
     * Makes a filter to match QuoteFill having Quote set identifier
     * and quoting service identifier as specified in the input parameters.
     *
     * @param quote_set_identifier            Instance of Identifier
     * @pram quoting_service_identifier       Instance of quoting_service_identifier
     */
    ByQuoteSetFilter(const Identifier & quote_set_identifier, const ServiceIdentifier & quoting_service_identifier);

    /**
     * Constructor.
     *
     * Makes a filter to match QuoteFill having quote set identifier
     * as specified in the input parameter.
     *
     * @param quote_set_identifier            Instance of Identifier
     */
    ByQuoteSetFilter(const Identifier & quote_set_identifier);
    ByQuoteSetFilter(const ByQuoteSetFilter & filter);

    ByQuoteSetFilter & operator=(const ByQuoteSetFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

    /**
     * Returns quoting service identifier set for the
     * filter.
     *
     * @return                                Instance of ServiceIdentifier
     */
    const ServiceIdentifier & GetQuotingServiceIdentifier() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_quote_set_identifier;
    ServiceIdentifier m_quoting_service_identifier;
};
}
