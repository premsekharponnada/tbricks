#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Alert type
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

namespace tbricks {

class STRATEGY_EXPORT AlertType : public AnyType
{
public:
    enum Type
    {
        MAR = 1,   // Market Abuse Regulation
        MMC = 2,   // Market Maker Compliance
        AM = 3,    // Algo Monitoring
        BestX = 4, // Best Execution
    };

public:
    AlertType();
    AlertType(Type value);
    AlertType(const AlertType & value);

    AlertType & operator=(Type value);
    AlertType & operator=(const AlertType & value);

    bool Empty() const override { return m_value.Empty(); }

    void Clear();
    Type Get() const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator Type() const { return Get(); }

public:
    bool operator==(Type value) const;
    bool operator!=(Type value) const;

    bool operator==(const AlertType & value) const;
    bool operator!=(const AlertType & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<Type> m_value;
};

STRATEGY_EXPORT
bool operator==(AlertType::Type v1, const AlertType & v2);

STRATEGY_EXPORT
bool operator!=(AlertType::Type v1, const AlertType & v2);

} // namespace tbricks.
