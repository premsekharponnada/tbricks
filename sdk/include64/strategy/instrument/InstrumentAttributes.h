#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentAttributes
//****************************************************************************************

#include <map>
#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/instrument/InstrumentAttributeDefinition.h"
#include "strategy/Value.h"
#include "strategy/type/InstrumentIdentifier.h"

namespace tbricks {

namespace types {
class ParametersRef;
class Parameters;
}

class STRATEGY_EXPORT InstrumentAttributes : public Printable
{
public:
    enum AttributeType
    {
        AttributeTypeInstrument = 0,
        AttributeTypeLeg = 1,
        AttributeTypeUnderlying = 2
    };

public:
    class STRATEGY_EXPORT const_iterator
    {
    public:
        bool operator==(const const_iterator & iter) const;
        bool operator!=(const const_iterator & iter) const;

        const_iterator & operator++();
        const_iterator & operator*();

        InstrumentAttributeDefinition GetDefinition() const;
        bool GetValue(AnyType & type) const;

    private:
        friend STRATEGY_EXPORT class InstrumentAttributes;
        const void * m_data = nullptr;
        size_t m_size = 0;
        size_t m_pos = 0;
    };

    const_iterator begin() const;
    const_iterator end() const;

    const_iterator Find(const InstrumentAttributeDefinition & definition) const;

public:
    InstrumentAttributes() = default;
    InstrumentAttributes(const InstrumentAttributes & other);
    InstrumentAttributes(InstrumentAttributes && other) noexcept;
    ~InstrumentAttributes();

    InstrumentAttributes & operator=(const InstrumentAttributes & other);
    InstrumentAttributes & operator=(InstrumentAttributes && other) noexcept;

public:
    bool GetAttribute(const InstrumentAttributeDefinition & definition, AnyType & type) const;
    bool HasAttribute(const InstrumentAttributeDefinition & definition) const;
    void SetAttribute(const InstrumentAttributeDefinition & definition, const AnyType & type);
    void ClearAttribute(const InstrumentAttributeDefinition & definition);

    void SetMaturityDate(const CalendarDate & date);
    void SetMaturityMonthYear(const CalendarDate & date);
    void SetMaturityMonthYear(const tbricks::String & mmy);

    /**
     * @return true if attributes are empty false otherwise
     */
    bool Empty() const;

    /**
     * Clear attributes
     */
    void Clear();

    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const InstrumentAttributes & value);
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    InstrumentAttributes(types::Parameters && value) noexcept;
    types::ParametersRef get_impl() const;

private:
    unsigned char * m_data = nullptr;
    size_t m_size = 0;
    size_t m_reserved_size = 0;
};
}
