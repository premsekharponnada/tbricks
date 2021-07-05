#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2017 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Trading block stream filters
//
//****************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/TradingBlockStream.h"
#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/Identifier.h"

namespace tbricks {

class STRATEGY_EXPORT TradingBlock::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const TradingBlock::Stream::Filters::Filter & filter);
    ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const TradingBlock::Stream::Filters::Filter & filter);
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

class STRATEGY_EXPORT TradingBlock::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Filter operator||(const FilterCondition & cond) const;
    Filter operator&&(const FilterCondition & cond) const;
    Filter operator||(const Filter & cond) const;
    Filter operator&&(const Filter & cond) const;
    Filter operator!() const;
    operator Filter() const;
};

class STRATEGY_EXPORT TradingBlock::Stream::Filters::ByIdentifier : public TradingBlock::Stream::Filters::FilterCondition
{
public:
    ByIdentifier(const Identifier & instance);
    ByIdentifier(const ByIdentifier & filter);
    ByIdentifier & operator=(const ByIdentifier & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Identifier m_id;
};

class STRATEGY_EXPORT TradingBlock::Stream::Filters::ByAncestorStrategyDefinition : public TradingBlock::Stream::Filters::FilterCondition
{
public:
    ByAncestorStrategyDefinition(const StrategyIdentifier & instance);
    ByAncestorStrategyDefinition(const ByAncestorStrategyDefinition & filter);
    ByAncestorStrategyDefinition & operator=(const ByAncestorStrategyDefinition & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    StrategyIdentifier m_id;
};

class STRATEGY_EXPORT TradingBlock::Stream::Filters::ByAncestorStrategy : public TradingBlock::Stream::Filters::FilterCondition
{
public:
    ByAncestorStrategy(const StrategyIdentifier & instance);
    ByAncestorStrategy(const ByAncestorStrategy & filter);
    ByAncestorStrategy & operator=(const ByAncestorStrategy & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    StrategyIdentifier m_id;
};

class STRATEGY_EXPORT TradingBlock::Stream::Filters::ByBlockedInstrument : public TradingBlock::Stream::Filters::FilterCondition
{
public:
    ByBlockedInstrument(const InstrumentIdentifier & identifier);
    ByBlockedInstrument(const ByBlockedInstrument & filter);
    ByBlockedInstrument & operator=(const ByBlockedInstrument & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    InstrumentIdentifier m_id;
};

class STRATEGY_EXPORT TradingBlock::Stream::Filters::ByBlockedInstrumentGroup : public TradingBlock::Stream::Filters::FilterCondition
{
public:
    ByBlockedInstrumentGroup(const InstrumentGroupIdentifier & identifier);
    ByBlockedInstrumentGroup(const ByBlockedInstrumentGroup & filter);
    ByBlockedInstrumentGroup & operator=(const ByBlockedInstrumentGroup & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    InstrumentGroupIdentifier m_id;
};

class STRATEGY_EXPORT TradingBlock::Stream::Filters::ByBlockedVenue : public TradingBlock::Stream::Filters::FilterCondition
{
public:
    ByBlockedVenue(const VenueIdentifier & identifier);
    ByBlockedVenue(const ByBlockedVenue & filter);
    ByBlockedVenue & operator=(const ByBlockedVenue & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    VenueIdentifier m_id;
};

class STRATEGY_EXPORT TradingBlock::Stream::Filters::DeletedFilter : public TradingBlock::Stream::Filters::FilterCondition
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
