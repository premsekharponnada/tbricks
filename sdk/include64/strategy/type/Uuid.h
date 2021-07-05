#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Uuid type.
//****************************************************************************************

#include <utility>

#include "strategy/type/AnyType.h"
#include "strategy/type/String.h"
#include "strategy/type/DateTime.h"

// \namespace tbricks
namespace tbricks {

namespace types {
class UUID;
}

class STRATEGY_EXPORT Uuid : public AnyType
{
public:
    Uuid() : m_first(0), m_second(0) {}
    Uuid(const Uuid & uuid) : m_first(uuid.m_first), m_second(uuid.m_second) {}
    Uuid(const std::pair<uint64_t, uint64_t> & value) : m_first(value.first), m_second(value.second) {}
    Uuid(const char * value);
    Uuid(const char * value, size_t size);
    Uuid(const types::UUID & value);
    ~Uuid() override {}

    void Generate();

    Uuid & operator=(const Uuid & uuid)
    {
        m_first = uuid.m_first;
        m_second = uuid.m_second;
        return *this;
    }
    Uuid & operator=(const types::UUID & value);

    static Uuid Create();

    bool Empty() const override { return (m_first == 0 && m_second == 0); }
    void Clear()
    {
        m_first = 0;
        m_second = 0;
    }
    std::pair<uint64_t, uint64_t> GetIntPair() const;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_IDENTIFIER; }

    operator types::UUID() const;

    size_t GetHash() const override;

    /// return creation datetime for time-based Uuid
    bool GetDateTime(DateTime & dt) const;

public:
    bool operator==(const Uuid & value) const { return (m_first == value.m_first) && (m_second == value.m_second); }
    bool operator!=(const Uuid & value) const { return !operator==(value); }

    bool operator<(const Uuid & value) const;
    bool operator>(const Uuid & value) const { return value < *this; }

    bool operator<=(const Uuid & value) const { return !(value < *this); }
    bool operator>=(const Uuid & value) const { return !operator<(value); }

    /// Printable
    std::ostream & Print(std::ostream & strm) const override;
    String ToString() const override;

    /**
     * Get compact UUID string.
     *
     * Returns 22-characters UUID representation.
     * The string satisfies regular expression: [0-9a-zA-Z@#]{22}
     *
     * @return                          Compact UUID string
     */
    String ToCompactString() const;

    /**
     * Get compact URL-safe UUID string.
     *
     * Returns 22-characters URL-safe UUID representation.
     * The string satisfies regular expression: [0-9a-zA-Z_\-]{22}.
     *
     * @return                          Compact URL-safe UUID string
     */
    String ToCompactUrlString() const;

public:
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    uint64_t m_first;
    uint64_t m_second;
};

} // \namespace tbricks
