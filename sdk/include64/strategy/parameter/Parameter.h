#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Abstract strategy parameter.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/AnyType.h"
#include "strategy/parameter/StrategyParameters.h"
#include "strategy/parameter/ParameterDefinition.h"

// \namespace tbricks
namespace tbricks {

class Strategy;
class ParameterImpl;
class ExtraData;

class STRATEGY_EXPORT Parameter : public Printable
{
public:
    virtual ~Parameter();

    const String & GetName() const;
    const ParameterDefinition & GetDefinition() const;

    /**
     * Get parameter value from parameter container.
     *
     * @param parameters              Parameter container
     *
     * @return                        True if container has parameter value
     *                                tagged with given name, false otherwise
     */
    bool GetParameter(const StrategyParameters & parameters);

    /**
     * Get parameter value from parameter iterator.
     *
     * @param it                      Iterator
     *
     * @return                        True if a parameter pointed by iterator
     *                                and this parameter have the same definition
     *                                identifier, false otherwise
     */
    bool GetParameter(const StrategyParameters::const_iterator & it);

    bool Extract(StrategyParameters & parameters);

    /**
     * %Set parameter value in parameter container.
     *
     * If parameter with such name already exists in the container, its value
     * is overriden.
     *
     * @param parameters              Parameter container
     */
    void SetParameter(StrategyParameters & parameters) const;

    bool HasParameter(const StrategyParameters & parameters) const;

    /**
     * Get parameter value from extra data container.
     *
     * @param key                     Extra data value key
     * @param extra_data              Extra data container
     *
     * @return                        True if container has related value,
     *                                false otherwise
     */
    bool GetExtraData(const String & key, const ExtraData & extra_data);

    /**
     * %Set parameter value in extra data container.
     *
     * @param key                     Extra data value key
     * @param extra_data              Extra data container
     */
    void SetExtraData(const String & key, ExtraData & extra_data) const;

    /**
     * Get parameter value from extra data container.
     * Get parameter name as extra data value key
     * it is the same as: param.GetExtraData(param.GetName(), extra_data)
     *
     * @param extra_data              Extra data container
     *
     * @return                        True if container has related value,
     *                                false otherwise
     */
    bool GetExtraData(const ExtraData & extra_data);

    /**
     * %Set parameter value in extra data container.
     * Get parameter name as extra data value key
     * it is the same as: param.SetExtraData(param.GetName(), extra_data)
     *
     * @param key                     Extra data value key
     * @param extra_data              Extra data container
     */
    void SetExtraData(ExtraData & extra_data) const;

    /**
     * Get parameter value of AnyType type.
     *
     * @return                          Parameter value
     */
    const AnyType & GetAnyValue() const;

    /**
     * Check parameter for emptiness.
     *
     * @return                          "true" if parameter value is cleared
     *                                  or is not set, "false" otherwise
     */
    bool Empty() const;

    /**
     * Clear parameter value.
     */
    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

protected:
    Parameter();
    void set_impl(ParameterImpl * impl);
    ParameterImpl & get_impl() const;

private:
    Parameter(const Parameter & p) = delete;
    Parameter & operator=(const Parameter & p) = delete;
    ParameterImpl * m_impl;
};

} // \namespace tbricks
