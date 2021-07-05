#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Side type.
//****************************************************************************************

#include "strategy/type/AnyType.h"

namespace tbricks {

/**
 * @deprecated Use Execution policy instead SHORT_SELL item.
 *             Item SHORT_SELL is deprecated in 2.12.0, will be removed in 2.13.0
 */
class STRATEGY_EXPORT Side : public AnyType
{
public:
    enum SideValue
    {
        NONE = 0,
        BUY = 1,
        SELL = 2,
        SHORT_SELL = 3
    };

public:
    /**
     * Constructor.
     *
     * Constructs an empty object, value is set to NONE.
     */
    Side() : m_value(NONE) {}
    /**
     * Constructor.
     */
    Side(SideValue value);
    /**
     * Copy constructor.
     */
    Side(const Side & value) : m_value(value.m_value) {}

    Side & operator=(SideValue value)
    {
        m_value = value;
        return *this;
    }
    Side & operator=(const Side & value)
    {
        m_value = value.m_value;
        return *this;
    }

    /**
     * Check object for emptiness.
     *
     * Object is considered empty if its value is set to NONE.
     *
     * @return                          "true" if object is empty, "false"
     *                                  otherwise
     */
    bool Empty() const override { return m_value == NONE; }

    inline bool IsBuy() const { return m_value == BUY; }

    /// return true for Sell and ShortSell
    inline bool IsSell() const { return (m_value == SELL) || (m_value == SHORT_SELL); }

    /**
     * @deprecated Use Execution policy instead SHORT_SELL item.
     *             Item SHORT_SELL is deprecated in 2.12.0, will be removed in 2.13.0
     */
    inline bool IsShortSell() const { return m_value == SHORT_SELL; }

    /**
     * Clear object.
     *
     * Object becomes empty after this call.
     */
    void Clear() { m_value = NONE; }
    /**
     * Get side.
     *
     * @return                          Current object value
     */
    SideValue GetSide() const { return m_value; }
    /**
     * Get opposite side.
     *
     * Returns side value which is opposite to the current object state.
     *
     * @return                          BUY if object value is either SELL or
     *                                  SHORT_SELL, SELL if object value is BUY,
     *                                  NONE otherwise.
     */
    Side GetOppositeSide() const;

    size_t GetHash() const override { return (size_t)m_value; }

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_SIDE; }

public:
    bool operator==(const Side & value) const { return (m_value == value.m_value); }
    bool operator!=(const Side & value) const { return !operator==(value); }

    bool operator<(const Side & value) const;
    bool operator>(const Side & value) const;

    bool operator<=(const Side & value) const;
    bool operator>=(const Side & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    SideValue m_value;
};
}
