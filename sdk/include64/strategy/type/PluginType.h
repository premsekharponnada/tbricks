#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Plugin type.
//****************************************************************************************

#include "strategy/type/AnyType.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT PluginType : public AnyType
{
public:
    enum Value
    {
        NONE = 0,
        STRATEGY = 1,
        LIMIT = 2,
        CALCULATION = 3,
        ACCESSORY = 5,
        REPORT = 6,
        INTEGRATION = 7,
        FLOW = 8,
        MATCHING = 9,
        PACKAGE = 10,
        VISUALIZATION = 11,
        DISTRIBUTION = 12
    };

public:
    PluginType();
    PluginType(Value value);
    PluginType(const PluginType & value);

    PluginType & operator=(Value value);
    PluginType & operator=(const PluginType & value);

    bool Empty() const override { return m_value == NONE; }
    void Clear();
    Value GetPluginType() const;
    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

public:
    bool operator==(const PluginType & value) const;
    bool operator!=(const PluginType & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value m_value;
};

} // \namespace tbricks
