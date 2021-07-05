#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in carveout streams.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/PluginType.h"
#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/CarveoutStream.h"

namespace tbricks {

/**
 * Default Carveout filter, matches all the messages.
 */
class STRATEGY_EXPORT Carveout::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Carveout::Stream::Filters::Filter & filter);
    ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const Carveout::Stream::Filters::Filter & filter);
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

/**
 * Convenience alias.
 */
class STRATEGY_EXPORT Carveout::Stream::Filters::FilterCondition : public tbricks::FilterCondition
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
 * Carveout::Stream::Filters::ByCarveoutIdentifierFilter matches concrete Carveout instance updates
 * having specified identifier.
 */
class STRATEGY_EXPORT Carveout::Stream::Filters::ByCarveoutIdentifierFilter : public Carveout::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the Carveout instance having
     * identifier as specified in the input parameter.
     *
     * @param instance               Instance of CarveoutIdentifier
     */
    ByCarveoutIdentifierFilter(const CarveoutIdentifier & instance);
    ByCarveoutIdentifierFilter(const ByCarveoutIdentifierFilter & filter);
    ByCarveoutIdentifierFilter & operator=(const ByCarveoutIdentifierFilter & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    CarveoutIdentifier m_id;
};

/**
 * Carveout::Stream::Filters::ByParentStrategyFilter matches concrete Carveout instance updates
 * having specified strategy identifier.
 */
class STRATEGY_EXPORT Carveout::Stream::Filters::ByParentStrategyFilter : public Carveout::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the Carveout instance having
     * strategy identifier as specified in the input parameter.
     *
     * @param instance               Instance of StrategyIdentifier
     */
    ByParentStrategyFilter(const StrategyIdentifier & v);
    ByParentStrategyFilter(const ByParentStrategyFilter & filter);
    ByParentStrategyFilter & operator=(const ByParentStrategyFilter & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    StrategyIdentifier m_type;
};

/**
 * Carveout::Stream::Filters::DeletedFilter matches all carveouts with specified state of deleted flag.
 */
class STRATEGY_EXPORT Carveout::Stream::Filters::DeletedFilter : public Carveout::Stream::Filters::FilterCondition
{
public:
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
