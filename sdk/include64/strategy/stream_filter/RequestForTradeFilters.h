#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in request for trade streams.
//****************************************************************************************

#include "strategy/stream/RequestForTradeStream.h"
#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"

namespace tbricks {

class STRATEGY_EXPORT RequestForTrade::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    RequestForTrade::Stream::Filters::Filter operator||(const RequestForTrade::Stream::Filters::FilterCondition & cond) const;
    RequestForTrade::Stream::Filters::Filter operator&&(const RequestForTrade::Stream::Filters::FilterCondition & cond) const;
    RequestForTrade::Stream::Filters::Filter operator||(const RequestForTrade::Stream::Filters::Filter & cond) const;
    RequestForTrade::Stream::Filters::Filter operator&&(const RequestForTrade::Stream::Filters::Filter & cond) const;
    RequestForTrade::Stream::Filters::Filter operator!() const;
    operator RequestForTrade::Stream::Filters::Filter() const;
};

/**
 * RequestForTrade::Stream::Filters::ByExPitIdentifierFilter matched request fo
 * trade by Expit identifier.
 */
class STRATEGY_EXPORT RequestForTrade::Stream::Filters::ByExPitIdentifierFilter : public RequestForTrade::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the request for trade having
     * ex-pit  (trade report) identifier as specified in the
     * input parameter.
     *
     * @param id                    Instance of ExPitIdentifier
    +        */
    ByExPitIdentifierFilter(const ExPitIdentifier & id);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    ExPitIdentifier m_id;
};

/**
 * RequestForTrade::Stream::Filters::ByAppIdentifierFilter matches request for trade
 * by app identifier.
 */
class STRATEGY_EXPORT RequestForTrade::Stream::Filters::ByAppIdentifierFilter : public RequestForTrade::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the request for trade having
     * app identifier as specified in the input parameter.
     *
     * @param id                    Instance of StrategyIdentifier
     */
    ByAppIdentifierFilter(const StrategyIdentifier & id);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_id;
};

/**
 * RequestForTrade::Stream::Filters::ByExchangeCreatedDateTimeFilter matches requests for trades made to venue from,
 * until or in a range of a specified date/time(s), inclusive.
 */
class STRATEGY_EXPORT RequestForTrade::Stream::Filters::ByExchangeCreatedDateTimeFilter : public RequestForTrade::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all requests for trade created in the specified time frame,
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
 * RequestForTrade::Stream::Filters::ByHostCreatedDateTimeFilter matches request for trades
 * created by the host, starting from, until or in a range of a specified date/time(s), inclusive.
 */
class STRATEGY_EXPORT RequestForTrade::Stream::Filters::ByHostCreatedDateTimeFilter : public RequestForTrade::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all requests for trade created in the specified
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
        strm << "<request for trade by host created date time filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeConditionImpl m_impl;
};

/**
 * RequestForTrade::Stream::Filters::ByRequestForQuoteIdentifier request for trade filter
 * by request for quote identifier identifier.
 */
class STRATEGY_EXPORT RequestForTrade::Stream::Filters::ByRequestForQuoteIdentifierFilter : public RequestForTrade::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the request for trade having
     * request for quote identifier as specified in the input parameter.
     *
     * @param id                    Instance of request for quote
     */
    ByRequestForQuoteIdentifierFilter(const Identifier & id) : m_id(id) {}

    virtual void Clear() { m_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_id;
};

class STRATEGY_EXPORT RequestForTrade::Stream::Filters::DeletedFilter : public RequestForTrade::Stream::Filters::FilterCondition
{
public:
    DeletedFilter(const Boolean & v) : m_deleted(v) {}

    void Clear() override { m_deleted.Clear(); }
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override { return m_deleted.Empty(); }

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Boolean m_deleted;
};
}
