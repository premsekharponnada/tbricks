#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Value type.
//****************************************************************************************

#include "strategy/Printable.h"

#include "strategy/instrument/InstrumentParameterDefinition.h"
#include "strategy/instrument/InstrumentParameters.h"
#include "strategy/instrument/InstrumentAggregateParameters.h"
#include "strategy/instrument/InstrumentGroupParameters.h"
#include "strategy/instrument/InstrumentGroupAggregateParameters.h"

#include "strategy/Value.h"

namespace tbricks {

template <typename Type>
class OverrideValue
{
public:
    OverrideValue() : m_override_value(NULL) {}

    OverrideValue(const OverrideValue & override_value) : m_value(override_value.m_value), m_override_value(NULL)
    {
        if (override_value.IsOverride()) {
            SetOverride(*override_value.m_override_value);
        } else {
            ClearOverride();
        }
    }

    OverrideValue & operator=(const OverrideValue & override_value)
    {
        if (this != &override_value) {
            m_value = override_value.m_value;
            if (override_value.IsOverride()) {
                SetOverride(*override_value.m_override_value);
            } else {
                ClearOverride();
            }
        }
        return *this;
    }

    ~OverrideValue() { Clear(); }

    OverrideValue & operator=(const Type & value)
    {
        Set(value);
        return *this;
    }

    bool IsOverride() const { return m_override_value != NULL; }

    template <typename UpdateT>
    bool Merge(const InstrumentParameterDefinition & definition, const UpdateT & update)
    {
        Type value;
        if (!update.GetParameter(definition, value)) {
            return false;
        }
        m_value.Merge(value);
        return !IsOverride();
    }

    template <typename UpdateT>
    bool Update(const InstrumentParameterDefinition & definition, const UpdateT & update)
    {
        Type value;
        if (!update.GetParameter(definition, value)) {
            return false;
        }
        if (m_value == value) {
            return false;
        }
        m_value = value;
        return !IsOverride();
    }

    template <typename ParametersT>
    bool Override(const InstrumentParameterDefinition & definition, const ParametersT & parameters)
    {
        Type value;
        if (!parameters.GetParameter(definition, value)) {
            return false;
        }
        return SetOverride(value);
    }

    bool ClearOverride()
    {
        if (!IsOverride()) {
            return false;
        }
        delete m_override_value;
        m_override_value = NULL;
        return true;
    }

    void ClearValue() { m_value.Clear(); }

    operator const Type &() const { return Get(); }

    const Type * operator->() const { return &Get(); }

    const Type & operator*() const { return Get(); }

public:
    bool operator==(const Type & value) const { return (Get() == value); }

    bool operator!=(const Type & value) const { return !operator==(value); }

    bool operator<(const Type & value) const { return (Get() < value); }

    bool operator>(const Type & value) const { return value < *this; }

    bool operator<=(const Type & value) const { return !(value < *this); }

    bool operator>=(const Type & value) const { return !operator<(value); }

    bool operator==(const OverrideValue & src) const { return (Get() == src.Get()); }

    bool operator!=(const OverrideValue & src) const { return !operator==(src); }

    bool operator<(const OverrideValue & src) const { return Get() < src.Get(); }

    bool operator>(const OverrideValue & src) const { return src < *this; }

    bool operator<=(const OverrideValue & src) const { return !(src < *this); }

    bool operator>=(const OverrideValue & src) const { return !operator<(src); }

    const Type & GetValue() const { return m_value; }

    Type & GetValue() { return m_value; }

    Type & GetOverrideValue()
    {
        if (IsOverride()) {
            return *m_override_value;
        }
        m_override_value = new Type;
        return *m_override_value;
    }

    const Type & Get() const
    {
        if (IsOverride()) {
            return *m_override_value;
        }
        return m_value;
    }

    bool SetOverride(const Type & value)
    {
        if (IsOverride() && *m_override_value == value) {
            return false;
        }
        if (!IsOverride()) {
            m_override_value = new Type;
        }
        *m_override_value = value;
        return true;
    }

    bool Set(const Type & value)
    {
        if (m_value != value) {
            m_value = value;
            return true;
        }
        return false;
    }

    bool Empty() const { return Get().Empty(); }

    void Clear()
    {
        m_value.Clear();
        if (IsOverride()) {
            delete m_override_value;
            m_override_value = NULL;
        }
    }

    friend std::ostream & operator<<(std::ostream & strm, const OverrideValue & value) { return value.Print(strm); }

    std::ostream & Print(std::ostream & strm) const
    {
        strm << Get();
        return strm;
    }

private:
    Type m_value;
    Type * m_override_value;
};

} // namespace tbricks
