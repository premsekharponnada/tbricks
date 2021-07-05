#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in ExPit streams.
//****************************************************************************************

#include "strategy/stream/ExPitStream.h"
#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"

namespace tbricks {

class STRATEGY_EXPORT ExPit::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    ExPit::Stream::Filters::Filter operator||(const ExPit::Stream::Filters::FilterCondition & cond) const;
    ExPit::Stream::Filters::Filter operator&&(const ExPit::Stream::Filters::FilterCondition & cond) const;
    ExPit::Stream::Filters::Filter operator||(const ExPit::Stream::Filters::Filter & cond) const;
    ExPit::Stream::Filters::Filter operator&&(const ExPit::Stream::Filters::Filter & cond) const;
    ExPit::Stream::Filters::Filter operator!() const;
    operator ExPit::Stream::Filters::Filter() const;
};

/**
 * ExPit::Stream::Filters::ByTypeFilter matches concrete ExPit instance updates
 * of the specified type.
 */
class STRATEGY_EXPORT ExPit::Stream::Filters::ByTypeFilter : public ExPit::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match ExPit instance updates of the
     * type as specified in the input parameter.
     *
     * @param type                  Value of ExPit::Type enumeration.
                                    Following are the type of Ex-pit:
                                    INTERBANK -> Bilateral interbank trade report
                                    TRADE_REPORT -> Unilateral trade report
                                    BLOCK -> Very large trade report
                                    CROSS -> Trade report when the instigator is both bower and seller
                                    ACCEPT -> Accept a direct request for trade
                                    GUARANTEED_CROSS -> Guaranteed cross
                                    PUBLICATION -> Post-trade publication used to report off-exchange trades to e.g.
     APA. Both sides should be filled by reporter.
    */
    ByTypeFilter(const ExPit::Type & type);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    ExPit::Type m_type;
    bool m_empty;
};

/**
 * ExPit::Stream::Filters::ByHostCreatedDateTimeFilter matches concrete
 * Expit instance updates, selected by ExPit created date and time range.
 */
class STRATEGY_EXPORT ExPit::Stream::Filters::ByHostCreatedDateTimeFilter : public ExPit::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all ExPit created in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                  Date/time to start the search from
     * @param until                 Date/time to end the search with
     */
    ByHostCreatedDateTimeFilter(const DateTime & from, const DateTime & until) : m_impl(from, until) {}

    virtual void Clear() { m_impl.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_impl.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << "<expit by host created date time filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeConditionImpl m_impl;
};

/**
 * ExPit::Stream::Filters::ByHostModifiedDateTimeFilter matches concrete
 * Expit instance updates, selected by ex-pit modified date and time range.
 */
class STRATEGY_EXPORT ExPit::Stream::Filters::ByHostModifiedDateTimeFilter : public ExPit::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all ExPit modified in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                  Date/time to start the search from
     * @param until                 Date/time to end the search with
     */
    ByHostModifiedDateTimeFilter(const DateTime & from, const DateTime & until) : m_impl(from, until) {}

    virtual void Clear() { m_impl.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_impl.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << "<expit by host modified date time filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeConditionImpl m_impl;
};

/**
 * ExPit::Stream::Filters::DeletedFilter allows to skip deleted ExPit.
 */
class STRATEGY_EXPORT ExPit::Stream::Filters::DeletedFilter : public ExPit::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all ExPit based on the specified
     * Boolean value.
     *
     * @param deleted               Boolean value.
                                    Set true to get deleted ExPit.
                                    Set false to get non deleted ExPit.
     */
    DeletedFilter(const Boolean & deleted);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Boolean m_deleted;
};

/**
 *  ExPit::Stream::Filters::ByParentFilter matches Ex-pit instances whose
 *  parent identifier is as specified.
 */
class STRATEGY_EXPORT ExPit::Stream::Filters::ByParentFilter : public ExPit::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the ExPit instance updates having
     * parent strategy as specified in the input parameter.
     *
     * @param  parent               Instance of StrategyIdentifier
     */
    ByParentFilter(const StrategyIdentifier & parent);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_parent;
};

/**
 * ExPit::Stream::Filters::ByIdentifierFilter matches ExPit with
 * specified identifier.
 */
class STRATEGY_EXPORT ExPit::Stream::Filters::ByIdentifierFilter : public ExPit::Stream::Filters::FilterCondition
{
public:
public:
    /**
     * Constructor.
     *
     * Makes a filter to matches the Expit having
     * identifier as specified in the input parameter.
     *
     * @param identifier            Instance of ExPitIdentifier
     */
    ByIdentifierFilter(const ExPitIdentifier & identifier);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    ExPitIdentifier m_identifier;
};
}
