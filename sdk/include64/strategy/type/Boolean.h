#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Boolean type.
//****************************************************************************************

#include "strategy/type/TypeWithError.h"

namespace tbricks {

/**
 * Boolean having 3 types: true, false, empty
 */
class STRATEGY_EXPORT Boolean : public TypeWithError
{
public:
    /**
     * Creates empty object
     */
    Boolean() : m_empty(true), m_value(false) {}
    /**
     * Creates object with passed value
     */
    Boolean(bool value) : m_empty(false), m_value(value) {}
    Boolean(const Boolean & value) = default;
    Boolean(Boolean && value) noexcept = default;

    Boolean & operator=(bool value)
    {
        ClearError();
        m_empty = false;
        m_value = value;
        return *this;
    }

    Boolean & operator=(const Boolean & value) = default;
    Boolean & operator=(Boolean && value) noexcept = default;

    /**
     * @return false if value is set, true otherwise
     */
    bool Empty() const override { return m_empty; }
    void Clear() override
    {
        ClearError();
        m_empty = true;
        m_value = false;
    }
    /**
     * @return boolean value. If object is empty, returns false
     */
    bool GetBool() const { return m_value; }

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_BOOLEAN; }

    /**
     * @return boolean value. If object is empty, returns false
     * @warning Be careful with comparison.
     * @code
     * Boolean a;
     * bool b = false;
     * std::cout << std::boolalpha << (a == b) << std::endl; // false
     * std::cout << std::boolalpha << (b == a) << std::endl; // true
     * @endcode
     */
    operator bool() const { return !m_empty && m_value; }

    size_t GetHash() const override { return (size_t)m_empty + (size_t)m_value; }

public:
    /**
     * compares two objects
     * @warning Be careful with comparison.
     * @code
     * Boolean a;
     * bool b = false;
     * std::cout << std::boolalpha << (a == b) << std::endl; // false
     * std::cout << std::boolalpha << (b == a) << std::endl; // true
     * @endcode
     */
    bool operator==(const Boolean & value) const { return (TypeWithError::equal(value)) && (m_value == value.m_value) && (m_empty == value.m_empty); }
    /**
     * @see "bool operator == (const Boolean & value) const"
     */
    bool operator!=(const Boolean & value) const { return !operator==(value); }

    /**
     * compares two objects
     * @warning Be careful with comparison bool and Boolean.
     */
    bool operator<(const Boolean & value) const
    {
        if (Empty()) {
            return !value.Empty();
        }
        if (value.Empty()) {
            return false;
        }
        return m_value < value.m_value;
    }

    /**
     * compares two objects
     * @warning Be careful with comparison bool and Boolean.
     */
    bool operator>(const Boolean & value) const { return value < *this; }

    /**
     * compares two objects
     * @warning Be careful with comparison bool and Boolean.
     */
    bool operator<=(const Boolean & value) const { return !(value < *this); }

    /**
     * compares two objects
     * @warning Be careful with comparison bool and Boolean.
     */
    bool operator>=(const Boolean & value) const { return !operator<(value); }

    /**
     * compares two objects
     * @return True if values are the same, false otherwise. If object is empty, returns false.
     * @warning Be careful with comparison.
     * @code
     * Boolean a;
     * bool b = false;
     * std::cout << std::boolalpha << (a == b) << std::endl; // false
     * std::cout << std::boolalpha << (b == a) << std::endl; // true
     * @endcode
     */
    bool operator==(bool value) const { return (m_value == value) && (!m_empty); }
    /**
     * @see "bool operator == (bool value) const"
     */
    bool operator!=(bool value) const { return !operator==(value); }

    /**
     * Logical conjunction
     * @exception Throws an exception, if object or value passed to this method is empty.
     */
    Boolean operator&&(const Boolean & value) const
    {
        check_empty();
        value.check_empty();
        return (m_value && value.m_value);
    }

    /**
     * Logical disjunction
     * @exception Throws an exception, if object or value passed to this method is empty.
     */
    Boolean operator||(const Boolean & value) const
    {
        check_empty();
        value.check_empty();
        return (m_value || value.m_value);
    }

    /**
     * Logical conjunction
     * @exception Throws an exception, if object is empty.
     */
    Boolean operator&&(bool value) const
    {
        check_empty();
        return (m_value && value);
    }

    /**
     * Logical disjunction
     * @exception Throws an exception, if object is empty.
     */
    Boolean operator||(bool value) const
    {
        check_empty();
        return (m_value || value);
    }

private:
    void check_empty() const
    {
        if (m_empty) {
            throw_exception();
        }
    }

    void throw_exception() const;

    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    bool m_empty;
    bool m_value;
};
}
