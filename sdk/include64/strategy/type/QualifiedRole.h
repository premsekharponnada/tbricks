#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Qualified role.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

namespace tbricks {

class STRATEGY_EXPORT QualifiedRole : public AnyType
{
public:
    enum QualifiedRoleValue
    {
        PERSON = 1,
        FIRM = 2,
        ALGORITHM = 3
    };

public:
    QualifiedRole();
    QualifiedRole(QualifiedRoleValue value);
    QualifiedRole(const QualifiedRole & value);

    QualifiedRole & operator=(QualifiedRoleValue value);
    QualifiedRole & operator=(const QualifiedRole & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    QualifiedRoleValue Get() const;

    bool IsPerson() const { return !Empty() && (Get() == PERSON); }
    bool IsFirm() const { return !Empty() && (Get() == FIRM); }
    bool IsAlgorithm() const { return !Empty() && (Get() == ALGORITHM); }

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator QualifiedRoleValue() const { return Get(); }

public:
    bool operator==(QualifiedRoleValue value) const;
    bool operator!=(QualifiedRoleValue value) const;

    bool operator==(const QualifiedRole & value) const;
    bool operator!=(const QualifiedRole & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<QualifiedRoleValue> m_value;
};

STRATEGY_EXPORT
bool operator==(QualifiedRole::QualifiedRoleValue v1, const QualifiedRole & v2);

STRATEGY_EXPORT
bool operator!=(QualifiedRole::QualifiedRoleValue v1, const QualifiedRole & v2);

} // \namespace tbricks
