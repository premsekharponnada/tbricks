#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// String type.
//****************************************************************************************

#include "strategy/type/TypeWithError.h"

namespace tbricks {

class STRATEGY_EXPORT String : public TypeWithError
{
public:
    String() : m_size(0), m_mem_value(nullptr) {}
    String(const String & value);
    String(String && value) noexcept;
    String(const std::string & value);
    String(const char * value);
    String(const char * value, size_t size);
    ~String() override;

    String & operator=(const String & value);
    String & operator=(String && value) noexcept;
    String & operator=(const std::string & value);
    String & operator=(const char * value);

    bool Empty() const override { return (m_size == 0); }
    void Clear() override;

    size_t GetSize() const;
    const char * GetCString() const;
    char operator[](size_t pos) const;

    void SetString(const char * value, size_t size);
    void AppendString(const char * value, size_t size);

    String ToLower() const;
    String ToUpper() const;

    String Trim() const;

    void Split(const String & delimiters, std::vector<String> & splitParts) const;
    void Split(const char delimiter, std::vector<String> & splitParts) const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_TEXT; }

public:
    /**
     * Comparing the first character of each string.
     * If they are equal to each other, it continues with the following
     * pairs until the characters differ or until exists.
     * If strings have different size, false will be returned.
     */
    bool operator==(const String & value) const;
    /**
     * @return True if strings are not equals
     */
    bool operator!=(const String & value) const { return !operator==(value); }

    /**
     * @return True if the first character that does not match has
     *         a lower value in this string than in value.
     *         Empty string less then not empty string.
     */
    bool operator<(const String & value) const;

    /**
     * @return True if the first character that does not match has
     *         a greater value in this string than in value.
     *         Empty string less then not empty string.
     */
    bool operator>(const String & value) const { return value < *this; }

    /**
     * @return True if the first character that does not match has
     *         a lower value in this string than in value
     *         or strings are the same.
     *         Empty string less then not empty string.
     */
    bool operator<=(const String & value) const { return !operator>(value); }

    /**
     * @return True if the first character that does not match has
     *         a greater value in this string than in value.
     *         or strings are the same.
     *         Empty string less then not empty string.
     */
    bool operator>=(const String & value) const { return !operator<(value); }

    String operator+(const String & value) const;
    String & operator+=(const String & value);

public:
    /// @see "bool operator == (const String & value) const"
    bool operator==(const std::string & value) const { return operator==(String(value)); }
    /// @see "bool operator != (const String & value) const"
    bool operator!=(const std::string & value) const { return operator!=(String(value)); }

    /// @see "bool operator < (const String & value) const"
    bool operator<(const std::string & value) const { return operator<(String(value)); }
    /// @see "bool operator > (const String & value) const"
    bool operator>(const std::string & value) const { return operator>(String(value)); }

    /// @see "bool operator <= (const String & value) const"
    bool operator<=(const std::string & value) const { return operator<=(String(value)); }
    /// @see "bool operator >= (const String & value) const"
    bool operator>=(const std::string & value) const { return operator>=(String(value)); }

    String operator+(const std::string & value) const { return operator+(String(value)); }
    String & operator+=(const std::string & value) { return operator+=(String(value)); }

public:
    /// @see "bool operator == (const String & value) const"
    bool operator==(const char * value) const { return operator==(String(value)); }
    /// @see "bool operator != (const String & value) const"
    bool operator!=(const char * value) const { return operator!=(String(value)); }

    /// @see "bool operator < (const String & value) const"
    bool operator<(const char * value) const { return operator<(String(value)); }
    /// @see "bool operator > (const String & value) const"
    bool operator>(const char * value) const { return operator>(String(value)); }

    /// @see "bool operator <= (const String & value) const"
    bool operator<=(const char * value) const { return operator<=(String(value)); }
    /// @see "bool operator >= (const String & value) const"
    bool operator>=(const char * value) const { return operator>=(String(value)); }

    String operator+(const char * value) const { return operator+(String(value)); }
    String & operator+=(const char * value) { return operator+=(String(value)); }

    std::ostream & Print(std::ostream & strm) const override;
    String ToString() const override;

private:
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

    void clear_mem_value();

private:
    enum
    {
        BufSize = 16
    };
    size_t m_size;
    char m_buf_value[BufSize];
    char * m_mem_value;
};

STRATEGY_EXPORT bool operator==(const std::string & v1, const String & v2);
STRATEGY_EXPORT bool operator!=(const std::string & v1, const String & v2);
STRATEGY_EXPORT bool operator<(const std::string & v1, const String & v2);
STRATEGY_EXPORT bool operator>(const std::string & v1, const String & v2);
STRATEGY_EXPORT bool operator<=(const std::string & v1, const String & v2);
STRATEGY_EXPORT bool operator>=(const std::string & v1, const String & v2);
STRATEGY_EXPORT String operator+(const std::string & v1, const String & v2);
}
