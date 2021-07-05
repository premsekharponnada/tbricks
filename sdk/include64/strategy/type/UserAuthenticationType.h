#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// User authentication type
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

namespace tbricks {

class STRATEGY_EXPORT UserAuthenticationType : public AnyType
{
public:
    enum Type
    {
        PlainPassword = 0, /*< Use a plain password authentication scheme. */
        WindowsDomain = 1, /*< Authenticate using a Windows domain. */
    };

public:
    UserAuthenticationType() = default;
    UserAuthenticationType(Type value);
    UserAuthenticationType(const UserAuthenticationType & value) = default;

    UserAuthenticationType & operator=(Type value);
    UserAuthenticationType & operator=(const UserAuthenticationType & value) = default;

    bool Empty() const override { return m_value.Empty(); }

    void Clear();
    Type Get() const;

    size_t GetHash() const override;
    static TypeInfo GetTypeInfo();

    operator Type() const { return Get(); }

public:
    bool operator==(Type value) const;
    bool operator!=(Type value) const;

    bool operator==(const UserAuthenticationType & value) const;
    bool operator!=(const UserAuthenticationType & value) const;

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
bool operator==(UserAuthenticationType::Type v1, const UserAuthenticationType & v2);

STRATEGY_EXPORT
bool operator!=(UserAuthenticationType::Type v1, const UserAuthenticationType & v2);

} // namespace tbricks.
