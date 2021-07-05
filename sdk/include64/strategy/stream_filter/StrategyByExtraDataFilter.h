#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyByExtraDataFilter, matches strategies by their extra data property.
//****************************************************************************************

#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

namespace filter {
class ICondition;
}

class STRATEGY_EXPORT StrategyByExtraDataFilter : public StrategyFilterCondition
{
public:
    class ByKey;

    /// Default constructor.
    StrategyByExtraDataFilter();
    StrategyByExtraDataFilter(const StrategyByExtraDataFilter & filter);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategy instances having
     * Extra Data property name and its value as specified
     * in the respective input parameters.
     *
     * @param name				Extra data property name
     * @param value				Extra data property value
     */
    StrategyByExtraDataFilter(const String & name, const AnyType & value);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategy instances having
     * Extra Data property name, its value specified in the input parameters.
     *
     * @param relation                         Filter::Relation enumeration type value.
     *
     * @param name                             Extra data property name
     * @param value                            Extra data property value
     */
    StrategyByExtraDataFilter(const Filter::Relation & relation, const String & name, const AnyType & value);

    ~StrategyByExtraDataFilter();

    StrategyByExtraDataFilter & operator=(const StrategyByExtraDataFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::unique_ptr<filter::ICondition> m_condition;
};

/**
 * StrategyByExtraDataFilter::ByKey allows to filter strategies on the basis
 * of its Extra data property key, irrespective of Extra data property value.
 */
class STRATEGY_EXPORT StrategyByExtraDataFilter::ByKey : public StrategyFilterCondition
{
public:
    /// Default constructor.
    ByKey();
    ByKey(const ByKey & filter);

    /**
     * Constructor.
     *
     * Allows to filter strategies having extra data key as
     * specified in the input parameter.
     *
     * @param key               Instance of String to specify the extra
                                data key.
     */
    ByKey(const String & key);

    /**
     * Constructor.
     *
     * Allows to filter strategies having extra data key matching with any
     * key of the key vector as specified in the input parameter.
     *
     * @param keys              vector of String to specify the list of
                                extra data keys.
     */
    ByKey(const std::vector<String> & keys);
    ~ByKey();

    ByKey & operator=(const ByKey & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::unique_ptr<filter::ICondition> m_condition;
};
}
