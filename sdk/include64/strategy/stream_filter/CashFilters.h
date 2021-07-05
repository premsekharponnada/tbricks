#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in cash streams.
//****************************************************************************************

#include "strategy/stream/CashStream.h"
#include "strategy/StrategyData.h"
#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"

namespace tbricks {

namespace filter {
class ICondition;
}

class STRATEGY_EXPORT Cash::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Cash::Stream::Filters::Filter operator||(const Cash::Stream::Filters::FilterCondition & cond) const;
    Cash::Stream::Filters::Filter operator&&(const Cash::Stream::Filters::FilterCondition & cond) const;
    Cash::Stream::Filters::Filter operator||(const Cash::Stream::Filters::Filter & cond) const;
    Cash::Stream::Filters::Filter operator&&(const Cash::Stream::Filters::Filter & cond) const;
    Cash::Stream::Filters::Filter operator!() const;
    operator Cash::Stream::Filters::Filter() const;
};

//------------------------------------------------------------------------------

/**
 * Cash::Stream::Filters::ByIdentifierFilter matches the cash with the
 * specified cash identifier or cash instance.
 */

class STRATEGY_EXPORT Cash::Stream::Filters::ByIdentifierFilter : public Cash::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the cash instance as
     * specified in the input parameter.
     *
     * @param instance               Instance of Cash
     */
    ByIdentifierFilter(const Cash & instance);

    /**
     * Constructor.
     *
     * Makes a filter to match the cash having
     * identifier as specified in the input parameter.
     *
     * @param instance              Instance of Identifier
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

//------------------------------------------------------------------------------

/**
 * Cash::Stream::Filters::ByPortfolioFilter matches the cash with the
 * specified portfolio identifier or cash instance.
 */

class STRATEGY_EXPORT Cash::Stream::Filters::ByPortfolioFilter : public Cash::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the cash instance as
     * specified in the input parameter.
     *
     * @param instance               Instance of Cash
     */
    ByPortfolioFilter(const Cash & instance);

    /**
     * Constructor.
     *
     * Makes a filter to match all the cash having
     * portfolio as specified in the input parameter.
     *
     * @param instance              Instance of PortfolioIdentifier
     */
    ByPortfolioFilter(const PortfolioIdentifier & instance);
    ByPortfolioFilter(const ByPortfolioFilter & filter);

    ByPortfolioFilter & operator=(const ByPortfolioFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    PortfolioIdentifier m_instance;
};

//------------------------------------------------------------------------------

/**
 * Cash::Stream::Filters::NotDeleted allows to skip deleted cash.
 */

class STRATEGY_EXPORT Cash::Stream::Filters::NotDeleted : public Cash::Stream::Filters::FilterCondition
{
public:
    /// Default Constructor.
    NotDeleted();
    NotDeleted(const NotDeleted & filter);
    ~NotDeleted();
    NotDeleted & operator=(const NotDeleted & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

//------------------------------------------------------------------------------

/**
 * Cash::Stream::Filters::ByCashDateTimeFilter matches cash with the specified time frame, including the boundaries.
 */
class STRATEGY_EXPORT Cash::Stream::Filters::ByCashDateTimeFilter : public Cash::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all cashes having cash date time in the specified time frame,
     * including the boundaries.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    ByCashDateTimeFilter(const DateTime & from, const DateTime & until);
    ByCashDateTimeFilter(const ByCashDateTimeFilter & filter);

    ByCashDateTimeFilter & operator=(const ByCashDateTimeFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DateTime m_from;
    DateTime m_until;
};

//------------------------------------------------------------------------------

/**
 * Cash::Stream::Filters::ByExtraDataFilter matches cash with the
 * specified extra data name and value.
 */
class STRATEGY_EXPORT Cash::Stream::Filters::ByExtraDataFilter : public Cash::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all cashes having extra data with the
     * specified name and value.
     *
     * @param name						extra data name
     * @param value						extra data value
     */
    ByExtraDataFilter(const String & name, const AnyType & value);
    ByExtraDataFilter(const ByExtraDataFilter & filter);
    ~ByExtraDataFilter();

    ByExtraDataFilter & operator=(const ByExtraDataFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    ::tbricks::filter::ICondition * m_condition;
};

//------------------------------------------------------------------------------

/**
 * Cash::Stream::Filters::ByModifiedDateTimeFilter matches cashes modified
 * in the specified time frame, including the boundaries.
 */
class STRATEGY_EXPORT Cash::Stream::Filters::ByModifiedDateTimeFilter : public Cash::Stream::Filters::FilterCondition
{
public:
    /**
     *  Constructor
     *
     *  Makes a filter to match all cashes modified in the specified time frame,
     *  including the boundaries.
     *
     *  Setting one of the parameters empty creates an interval filter with
     *  one end open.
     *
     *   @param from                      Date/time to start the search from
     *   @param until                     Date/time to end the search with
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
        strm << "<cash by host modified date time filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeConditionImpl m_impl;
};

//------------------------------------------------------------------------------

/**
 * Cash::Stream::Filters::ByStrategyIdentifierFilter matches cash instance
 * updates, selected by strategy identifier.
 */

class STRATEGY_EXPORT Cash::Stream::Filters::ByStrategyIdentifierFilter : public Cash::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the cash instance as
     * specified in the input parameter.
     *
     * @param instance              Instance of Cash
     */
    ByStrategyIdentifierFilter(const Cash & instance);

    /**
     * Constructor.
     *
     * Makes a filter to match all the cash having
     * strategy as specified in the input parameter.
     *
     * @param instance              Instance of StrategyIdentifier
     */
    ByStrategyIdentifierFilter(const StrategyIdentifier & instance);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_instance;
};

//------------------------------------------------------------------------------

/**
 * Cash::Stream::Filters::ByRootFilter matches cash instance having
 * root strategy as the specified strategy identifier.
 */

class STRATEGY_EXPORT Cash::Stream::Filters::ByRootFilter : public Cash::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the cash having
     * root strategy as specified in the input parameter.
     *
     * @param root                   Instance of Strategy
     */
    ByRootFilter(const Strategy & root);

    /**
     * Constructor.
     *
     * Makes a filter to match all cash having StrategyData
     * as specified in the input parameter.
     *
     * @param root                  Instance of StrategyData
     */
    ByRootFilter(const StrategyData & root);
    ByRootFilter(const StrategyIdentifier & root);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_root;
};

//------------------------------------------------------------------------------

/**
 * Cash::Stream::Filters::ByAncestorFilter matches cash instance having
 * ancestor strategy and root strategy as the specified strategy identifiers respectively.
 */
class STRATEGY_EXPORT Cash::Stream::Filters::ByAncestorFilter : public Cash::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the cash having
     * strategy a specified in the input parameter.
     *
     * @param ancestor               Instance of Strategy
     */
    ByAncestorFilter(const Strategy & ancestor);

    /**
     * Constructor.
     *
     * Makes a filter to match all cashes with the specified
     * ancestor strategy and root strategy.
     *
     * @param ancestor_id           ancestor strategy identifier
     * @param root_id               root strategy identifier
     */
    ByAncestorFilter(const StrategyIdentifier & ancestor_id, const StrategyIdentifier & root_id);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_root;
    StrategyIdentifier m_ancestor;
};

//============================================================================

/**
 * Cash::Stream::Filters::ByClientFilter matches cash instance having
 * client node as the specified tree node identifier.
 */
class STRATEGY_EXPORT Cash::Stream::Filters::ByClientFilter : public Cash::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the cash instances having
     * client node as specified tree node identifier in the input parameter.
     *
     * @param client                        Instance of TreeNodeIdentifier
     */
    ByClientFilter(const TreeNodeIdentifier & client);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    TreeNodeIdentifier m_client;
};

//============================================================================
}
