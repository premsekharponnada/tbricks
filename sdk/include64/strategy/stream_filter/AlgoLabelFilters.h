#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in algo identification streams.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/PluginType.h"
#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/AlgoLabelStream.h"

namespace tbricks {

class STRATEGY_EXPORT AlgoLabel::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const AlgoLabel::Stream::Filters::Filter & filter);
    ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const AlgoLabel::Stream::Filters::Filter & filter);
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

class STRATEGY_EXPORT AlgoLabel::Stream::Filters::FilterCondition : public tbricks::FilterCondition
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
 * AlgoLabel::Stream::Filters::ByIdentifierFilter matches concrete AlgoLabel instance updates
 * having specified identifier.
 */
class STRATEGY_EXPORT AlgoLabel::Stream::Filters::ByIdentifierFilter : public AlgoLabel::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the AlgoLabel instance having
     * identifier as specified in the input parameter.
     *
     * @param instance               Instance of Identifier
     */
    ByIdentifierFilter(const Identifier & instance);
    ByIdentifierFilter(const ByIdentifierFilter & filter);
    ByIdentifierFilter & operator=(const ByIdentifierFilter & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Identifier m_id;
};

/**
 * AlgoLabel::Stream::Filters::ByStrategyDefinitionFilter matches concrete AlgoLabel instance updates
 * having specified strategy definition.
 */
class STRATEGY_EXPORT AlgoLabel::Stream::Filters::ByStrategyDefinitionFilter : public AlgoLabel::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the AlgoLabel instance having
     * strategy identifier as specified in the input parameter.
     *
     * @param instance               Instance of StrategyIdentifier
     */
    ByStrategyDefinitionFilter(const StrategyIdentifier & v);
    ByStrategyDefinitionFilter(const ByStrategyDefinitionFilter & filter);
    ByStrategyDefinitionFilter & operator=(const ByStrategyDefinitionFilter & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    StrategyIdentifier m_type;
};

/**
 * AlgoLabel::Stream::Filters::DeletedFilter allows to skip deleted algo labels.
 */
class STRATEGY_EXPORT AlgoLabel::Stream::Filters::DeletedFilter : public AlgoLabel::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all algo labels based on the
     * specified Boolean value.
     *
     * @param deleted                Boolean value.
                                     Set true to get deleted algo labels.
                                     Set false to get non deleted algo labels.
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
