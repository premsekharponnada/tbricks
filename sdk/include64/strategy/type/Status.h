#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Status type.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

// \namespace tbricks
namespace tbricks {
class STRATEGY_EXPORT Status : public AnyType
{
public:
    enum StatusValue
    {
        FAIL = 0,
        OK = 1,
        SERVICE_WENT_DOWN = 2
    };

public:
    Status();
    Status(StatusValue status);
    Status(const Status & value);

    Status & operator=(StatusValue value);
    Status & operator=(const Status & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    StatusValue GetStatus() const;
    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

public:
    bool operator==(const Status & value) const;
    bool operator!=(const Status & value) const;

public:
    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const Status & status);

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<StatusValue> m_value;
};

} // \namespace tbricks
