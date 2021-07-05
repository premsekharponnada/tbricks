#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Algo label type.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

namespace tbricks {

class STRATEGY_EXPORT AlgoLabelType : public AnyType
{
public:
    enum AlgoLabelTypeValue
    {
        INTERNAL = 1,
        APP_DEFAULT = 2,
        CUSTOM = 3
    };

public:
    AlgoLabelType();
    AlgoLabelType(AlgoLabelTypeValue value);
    AlgoLabelType(const AlgoLabelType & value);

    AlgoLabelType & operator=(AlgoLabelTypeValue value);
    AlgoLabelType & operator=(const AlgoLabelType & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    AlgoLabelTypeValue Get() const;

    bool IsInternal() const { return !Empty() && (Get() == INTERNAL); }
    bool IsAppDefault() const { return !Empty() && (Get() == APP_DEFAULT); }
    bool IsCustom() const { return !Empty() && (Get() == CUSTOM); }

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator AlgoLabelTypeValue() const { return Get(); }

public:
    bool operator==(AlgoLabelTypeValue value) const;
    bool operator!=(AlgoLabelTypeValue value) const;

    bool operator==(const AlgoLabelType & value) const;
    bool operator!=(const AlgoLabelType & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<AlgoLabelTypeValue> m_value;
};

STRATEGY_EXPORT
bool operator==(AlgoLabelType::AlgoLabelTypeValue v1, const AlgoLabelType & v2);

STRATEGY_EXPORT
bool operator!=(AlgoLabelType::AlgoLabelTypeValue v1, const AlgoLabelType & v2);

} // \namespace tbricks
