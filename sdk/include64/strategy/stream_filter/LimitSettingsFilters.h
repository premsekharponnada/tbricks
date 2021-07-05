#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Limit settings stream filters
//
//****************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/LimitSettingsStream.h"
#include "strategy/stream_filter/AnyFilter.h"

namespace tbricks {

namespace filter {
class ICondition;
}

class STRATEGY_EXPORT LimitSettings::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const LimitSettings::Stream::Filters::Filter & filter);
    ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const LimitSettings::Stream::Filters::Filter & filter);
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

class STRATEGY_EXPORT LimitSettings::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Filter operator||(const FilterCondition & cond) const;
    Filter operator&&(const FilterCondition & cond) const;
    Filter operator||(const Filter & cond) const;
    Filter operator&&(const Filter & cond) const;
    Filter operator!() const;
    operator Filter() const;
};

class STRATEGY_EXPORT LimitSettings::Stream::Filters::ByIdentifier : public LimitSettings::Stream::Filters::FilterCondition
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

class STRATEGY_EXPORT LimitSettings::Stream::Filters::ByDefinition : public LimitSettings::Stream::Filters::FilterCondition
{
public:
    ByDefinition(const Identifier & definition);
    ByDefinition(const ByDefinition & filter);
    ByDefinition & operator=(const ByDefinition & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Identifier m_definition;
};

/**
 * @deprecated Deprecated in 2.14.0
 */
class STRATEGY_EXPORT[[deprecated(DEPRECATE_LINK)]] LimitSettings::Stream::Filters::ByFilterCondition
    : public LimitSettings::Stream::Filters::FilterCondition
{
public:
    ByFilterCondition();
    ByFilterCondition(const ByFilterCondition & filter);

    ByFilterCondition(const ParameterDefinition & definition, const AnyType & value, Filter::Relation relation = Filter::EQ);

    ~ByFilterCondition();

    ByFilterCondition & operator=(const ByFilterCondition & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::unique_ptr<filter::ICondition> m_condition;
};

/**
 * @deprecated Deprecated in 2.14.0
 */
class STRATEGY_EXPORT[[deprecated(DEPRECATE_LINK)]] LimitSettings::Stream::Filters::ByValue : public LimitSettings::Stream::Filters::FilterCondition
{
public:
    ByValue();
    ByValue(const ByValue & filter);

    ByValue(const ParameterDefinition & definition, const AnyType & value, Filter::Relation relation = Filter::EQ);

    ~ByValue();

    ByValue & operator=(const ByValue & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::unique_ptr<filter::ICondition> m_condition;
};

class STRATEGY_EXPORT LimitSettings::Stream::Filters::ByParameter : public LimitSettings::Stream::Filters::FilterCondition
{
public:
    ByParameter();
    ByParameter(const ByParameter & filter);

    ByParameter(const ParameterDefinition & definition, const AnyType & value, Filter::Relation relation = Filter::EQ);

    ~ByParameter();

    ByParameter & operator=(const ByParameter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::unique_ptr<filter::ICondition> m_condition;
};

class STRATEGY_EXPORT LimitSettings::Stream::Filters::DeletedFilter : public LimitSettings::Stream::Filters::FilterCondition
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
