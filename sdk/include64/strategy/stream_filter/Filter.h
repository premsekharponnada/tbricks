#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Abstract filter.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/String.h"

#include "strategy/Exceptions.h"

namespace tbricks {

class CalculatedPropertyFilter;

namespace filter {
class FieldFilter;
class Filter;
}

class STRATEGY_EXPORT Filter : public Printable
{
public:
    enum Relation
    {
        EQ = 0, // ==
        NE = 1, // !=
        GT = 2, // >
        LT = 3, // <
        GE = 4, // >=
        LE = 5  // <=
    };

public:
    Filter();
    Filter(const tbricks::filter::Filter & filter);
    virtual ~Filter();

    virtual void Clear() = 0;
    virtual bool Empty() const = 0;
    virtual tbricks::filter::FieldFilter GetValue() const = 0;

    const tbricks::filter::FieldFilter & get_field_filter() const;
    tbricks::filter::FieldFilter & get_field_filter();
    void clear_field_filter();

    /**
     * Convert calculated property filter to stream filter.
     * Concrete type of Filter must correspond to type of conditions properties stored in CalculatedPropertyFilter
     * (e.g. TradeFilter for calculated property filter with conditions containing calculated properties
     * of trade type).
     *
     * Unconverted part is a subtree of source filter and is formed by following algorithm:
     * 1) Filter nodes containing specific conditions (e.g. relative conditions or conditions with
     *  Lua expressions) are not converted.
     * 2) Filter nodes containing operation OR with at least one of not converted children is also
     *  not converted.
     *
     * For example, if CalculatedPropertyFilter is constructed as such:
     *
     *      InstrumentIdentifier id1 = ...;
     *      InstrumentIdentifier id2 = ...;
     *      InstrumentIdentifier id3 = ...;
     *      CalculatedProperty instrumentIdCp = ...;
     *      CalculatedProperty luaCp = ...;
     *      Integer luaValue = 42;
     *      auto condition1 = CalculatedPropertyFilter::Condition(instrumentIdCp, id1);
     *      auto condition2 = CalculatedPropertyFilter::Condition(instrumentIdCp, id2);
     *      auto condition3 = CalculatedPropertyFilter::Condition(instrumentIdCp, id3);
     *      auto condition4 = CalculatedPropertyFilter::Condition(luaCp, luaValue);
     *
     *      auto filterFrom = condition1 && condition2 && (condition3 || condition4);
     *
     *  than unconverted part would be equal to (condition3 || condition4);
     *
     * @param filterFrom                Source filter to be converted.
     * @param filterTo                  Subtree of filterFrom that is not converted to stream filter.
     *
     * @return                          True if filterFrom is converted, false otherwise.
     */
    bool Extract(const CalculatedPropertyFilter & filterFrom, CalculatedPropertyFilter & filterTo);

protected:
    virtual uint64_t get_stream_message_id() const;

private:
    // prohibited
    Filter(const Filter &);
    Filter & operator=(const Filter &);

private:
    tbricks::filter::FieldFilter * m_filter; // stores result of &=, |=
                                             // operators
};

class STRATEGY_EXPORT FilterCondition : public Printable
{
public:
    FilterCondition() {}
    virtual ~FilterCondition() {}

    virtual void Clear() = 0;
    virtual bool Empty() const = 0;
    virtual tbricks::filter::FieldFilter GetValue() const = 0;
};
}
