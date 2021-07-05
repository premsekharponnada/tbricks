#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in expiration streams.
//****************************************************************************************

#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"
#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/ExpirationStream.h"

namespace tbricks {

class STRATEGY_EXPORT Expiration::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Expiration::Stream::Filters::Filter operator||(const Expiration::Stream::Filters::FilterCondition & cond) const;
    Expiration::Stream::Filters::Filter operator&&(const Expiration::Stream::Filters::FilterCondition & cond) const;
    Expiration::Stream::Filters::Filter operator||(const Expiration::Stream::Filters::Filter & cond) const;
    Expiration::Stream::Filters::Filter operator&&(const Expiration::Stream::Filters::Filter & cond) const;
    Expiration::Stream::Filters::Filter operator!() const;
    operator Expiration::Stream::Filters::Filter() const;
};

/**
 * Expiration::Stream::Filters::ByIdentifierFilter matches
 * expirations by expiration identifier.
 */
class STRATEGY_EXPORT Expiration::Stream::Filters::ByIdentifierFilter : public Expiration::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the instance of the expiration
     * as specified in the input parameter.
     *
     * @param instance              Instance of Expiration.
     */
    ByIdentifierFilter(const Expiration & instance);

    /**
     * Constructor.
     *
     * Makes a filter to match the expiration having
     * identifier as specified in the input parameter.
     *
     * @param instance              Instance of Identifier.
     */
    ByIdentifierFilter(const Identifier & instance);
    ByIdentifierFilter(const ByIdentifierFilter & filter);

    ByIdentifierFilter & operator=(const ByIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_instance;
};

/**
 * Expiration::Stream::Filters::ByExpirationDateFilter matches expirations
 * by expiration date.
 */
class STRATEGY_EXPORT Expiration::Stream::Filters::ByExpirationDateFilter : public Expiration::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the instance of the expiration
     * as specified in the input parameter.
     *
     * @param instance              Instance of Expiration.
     */
    ByExpirationDateFilter(const Expiration & instance);

    /**
     * Constructor.
     *
     * Makes a filter to match all the expirations having
     * date and time as specified in the input parameters.
     *
     * @param instance              Instance of DateTime
     */
    ByExpirationDateFilter(const DateTime & instance);
    ByExpirationDateFilter(const ByExpirationDateFilter & filter);

    ByExpirationDateFilter & operator=(const ByExpirationDateFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DateTime m_instance;
};

/**
 * Expiration::Stream::Filters::ByModifiedDateTimeFilter matches expirations
 * by modified date time.
 */
class STRATEGY_EXPORT Expiration::Stream::Filters::ByModifiedDateTimeFilter : public Expiration::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all expirations modified in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    ByModifiedDateTimeFilter(const DateTime & from, const DateTime & until) : m_impl(from, until) {}

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
        strm << "<expiration by host modified date time filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeConditionImpl m_impl;
};
}
