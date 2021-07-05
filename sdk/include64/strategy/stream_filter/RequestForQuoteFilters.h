#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in request for quote streams.
//****************************************************************************************

#include "strategy/stream/RequestForQuoteStream.h"
#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"

namespace tbricks {

class STRATEGY_EXPORT RequestForQuote::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    RequestForQuote::Stream::Filters::Filter operator||(const RequestForQuote::Stream::Filters::FilterCondition & cond) const;
    RequestForQuote::Stream::Filters::Filter operator&&(const RequestForQuote::Stream::Filters::FilterCondition & cond) const;
    RequestForQuote::Stream::Filters::Filter operator||(const RequestForQuote::Stream::Filters::Filter & cond) const;
    RequestForQuote::Stream::Filters::Filter operator&&(const RequestForQuote::Stream::Filters::Filter & cond) const;
    RequestForQuote::Stream::Filters::Filter operator!() const;
    operator RequestForQuote::Stream::Filters::Filter() const;
};

/**
 * RequestForQuote::Stream::Filters::ByExchangeCreatedDateTimeFilter matches requests for quotes made to venue from,
 * until or in a range of a specified date/time(s), inclusive.
 */
class STRATEGY_EXPORT RequestForQuote::Stream::Filters::ByExchangeCreatedDateTimeFilter : public RequestForQuote::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all requests for quote created in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    ByExchangeCreatedDateTimeFilter(const DateTime & from, const DateTime & until);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DateTime m_from;
    DateTime m_until;
};

/**
 * RequestForQuote::Stream::Filters::ByHostCreatedDateTimeFilter matches request for quotes
 * created by the host, starting from, until or in a range of a specified date/time(s), inclusive.
 */
class STRATEGY_EXPORT RequestForQuote::Stream::Filters::ByHostCreatedDateTimeFilter : public RequestForQuote::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all requests for quote created in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    ByHostCreatedDateTimeFilter(const DateTime & from, const DateTime & until) : m_impl(from, until) {}

    /**
     * %Set initial point for the search.
     *
     * Final point value remains unchanged.
     *
     * @param from                      Date/time to start the search from
     */
    void SetFromDate(const DateTime & from) { m_impl.SetFromDate(from); }

    /**
     * Get current initial search point.
     *
     * @return                          Current settings for the starting point,
     *                                  which could be empty
     */
    const DateTime & GetFromDate() const { return m_impl.GetFromDate(); }

    /**
     * %Set final position for the search.
     *
     * Initial point value remains unchanged.
     *
     * @param until                     Date/time to end the search with
     */
    void SetUntilDate(const DateTime & until) { m_impl.SetUntilDate(until); }

    /**
     * Get current final search point.
     *
     * @return                          Current settings for the final point,
     *                                  which could be empty
     */
    const DateTime & GetUntilDate() const { return m_impl.GetUntilDate(); }

    /**
     * %Set a search range.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    void SetFromUntilDate(const DateTime & from, const DateTime & until)
    {
        m_impl.SetFromDate(from);
        m_impl.SetUntilDate(until);
    }

    virtual void Clear() { m_impl.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_impl.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << "<request for quote by host created date time filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeConditionImpl m_impl;
};

/**
 * RequestForQuote::Stream::Filters::ByHostCreatedDateTimeFilter matches request for quotes
 * with direct quote expected.
 */
class STRATEGY_EXPORT RequestForQuote::Stream::Filters::DirectedQuoteExpected : public RequestForQuote::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the requests for quote isntances having
     * directed quote excepted as true.
     *
     * @param expected              bool value
     */
    DirectedQuoteExpected(bool expected);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    bool m_flag;
};

/**
 * ByRequestForQuoteIdentifierFilter matches concrete RFQ instances,
 * selected by identifier.
 */
class STRATEGY_EXPORT RequestForQuote::Stream::Filters::ByIdentifierFilter : public RequestForQuote::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter that matches the RFQ having identifier
     * as specified in the input parameter.
     *
     * @param id                  Request for quote identifier
     */
    ByIdentifierFilter(const Identifier & id);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_id;
};
}
