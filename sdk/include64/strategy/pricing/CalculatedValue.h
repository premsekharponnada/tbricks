#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument calculated value.
//****************************************************************************

#include "strategy/pricing/Pricing.h"
#include "strategy/pricing/InstrumentCalculatedValueDefinition.h"
#include "strategy/Logger.h"

// \namespace tbricks
namespace tbricks {

template <typename ValueT>
class CalculatedValue
{
public:
    CalculatedValue(Pricing & pricing, const CalculatedValueIdentifier & id) : m_pricing(pricing), m_id(id), m_skip_update(false)
    {
        m_active = !m_id.second.Empty();
    }

    CalculatedValue(Pricing & pricing, const CalculatedValueIdentifier & id, const InstrumentCalculatedValueDefinition & definition) :
        m_pricing(pricing),
        m_id(id),
        m_definition(definition),
        m_skip_update(false)
    {
        m_active = !m_id.second.Empty();
    }

    CalculatedValue & operator=(const ValueT & value)
    {
        if (m_active && (m_value != value)) {
            m_value = value;
            Update();
        }
        return *this;
    }

    void SetError(const String & error)
    {
        if (m_active && !m_value.CheckError(error)) {
            m_value.SetError(error);
            Update();
        }
    }

    bool Active() const { return m_active; }

    void SetActive(bool active = true) { m_active = active; }

    const CalculatedValueIdentifier & GetIdentifier() const { return m_id; }

    const InstrumentCalculatedValueDefinition & GetDefinition() const { return m_definition; }

    bool Update(const ValueT & value)
    {
        if (m_active && (m_value != value)) {
            m_value = value;
            Update();
            return true;
        }
        return false;
    }

    CalculatedValue & operator+=(const ValueT & value)
    {
        if (m_active && !value.Empty()) {
            if (m_value.Empty()) {
                m_value = value;
            } else {
                m_value += value;
            }
            Update();
        }
        return *this;
    }

    virtual void Clear()
    {
        if (m_active && (!m_value.Empty() || m_value.HasError())) {
            m_value.Clear();
            Update();
        }
    }

    const ValueT & GetValue() const { return m_value; }

    void set_skip_update(bool skip = true) { m_skip_update = skip; }

private:
    void Update()
    {
        if (!m_skip_update)
            m_pricing.Update(m_id, m_value);
    }

private:
    Pricing & m_pricing;
    CalculatedValueIdentifier m_id;
    InstrumentCalculatedValueDefinition m_definition;

    bool m_active;
    ValueT m_value;
    bool m_skip_update;
};

} // \namespace tbricks
