#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in app type streams.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/PluginType.h"
#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/StrategyTypeStream.h"

namespace tbricks {

class STRATEGY_EXPORT StrategyType::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const StrategyType::Stream::Filters::Filter & filter);
    ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const StrategyType::Stream::Filters::Filter & filter);
    Filter & operator&=(const Filter & filter);

    Filter operator||(const Filter & filter);
    Filter operator&&(const Filter & filter);

    Filter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

class STRATEGY_EXPORT StrategyType::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Filter operator||(const FilterCondition & cond) const;
    Filter operator&&(const FilterCondition & cond) const;
    Filter operator||(const Filter & cond) const;
    Filter operator&&(const Filter & cond) const;
    Filter operator!() const;
    operator Filter() const;
};

/**
 * StrategyType::Stream::Filters::ByIdentifierFilter matches strategy by
 * identifier.
 */
class STRATEGY_EXPORT StrategyType::Stream::Filters::ByIdentifierFilter : public StrategyType::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the strategy instance ha
     * strategy identifier as specified in the input pa
     *
     * @param instance  Instance of StrategyIdentifier
     */
    ByIdentifierFilter(const StrategyIdentifier & instance);
    ByIdentifierFilter(const ByIdentifierFilter & filter);
    ByIdentifierFilter & operator=(const ByIdentifierFilter & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    StrategyIdentifier m_id;
};

/**
 * StrategyType::Stream::Filters::ByClassFilter matches strategy by
 * the plugin type.
 */
class STRATEGY_EXPORT StrategyType::Stream::Filters::ByClassFilter : public StrategyType::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the strategy instance belongs to
     * the plugin type as specified in the input parameter.
     *
     * @param v         Instance of PluginType
     */
    ByClassFilter(const PluginType & v);
    ByClassFilter(const ByClassFilter & filter);
    ByClassFilter & operator=(const ByClassFilter & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    PluginType m_type;
};

/**
 * StrategyType::Stream::Filters::DeletedFilter allows to
 * filter deleted strategy instances.
 */
class STRATEGY_EXPORT StrategyType::Stream::Filters::DeletedFilter : public StrategyType::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all strategy instances based on the specified
     * Boolean value.
     *
     * @param deleted   Boolean value.
                        Set true to get deleted strategy.
                        Set false to get non deleted strategy.
      */
    DeletedFilter(const Boolean & v);
    DeletedFilter(const DeletedFilter & filter);
    DeletedFilter & operator=(const DeletedFilter & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Boolean m_deleted;
};
}
