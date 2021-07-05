#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Calculated property.
//****************************************************************************************

#include "strategy/calculated_property/CalculatedPropertyDefinition.h"
#include "strategy/parameter/StrategyParameters.h"
#include "strategy/StringDictionary.h"

namespace tbricks {

namespace types {
class CalculatedProperty;
}

class STRATEGY_EXPORT CalculatedProperty : public AnyType
{
public:
    CalculatedProperty() = default;
    ~CalculatedProperty() override = default;
    CalculatedProperty(const CalculatedProperty & src) = default;
    CalculatedProperty(CalculatedProperty && src) = default;

    CalculatedProperty(const CalculatedPropertyDefinition & def);
    explicit CalculatedProperty(const types::CalculatedProperty & src);

    CalculatedProperty & operator=(const CalculatedProperty & src) = default;
    CalculatedProperty & operator=(CalculatedProperty && src) = default;

    bool operator<(const CalculatedProperty & src) const;
    bool operator>(const CalculatedProperty & src) const;
    bool operator<=(const CalculatedProperty & src) const;
    bool operator>=(const CalculatedProperty & src) const;
    bool operator==(const CalculatedProperty & src) const;
    bool operator!=(const CalculatedProperty & src) const { return !operator==(src); }

    bool Empty() const override;
    void Clear();

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_CALCULATED_PROPERTY; }

    const StrategyParameters & GetParameters() const;
    const CalculatedPropertyDefinition & GetDefinition() const;
    const StringDictionary & GetNamedParameters() const;

    void SetParameters(const StrategyParameters & value) { m_parameters = value; }
    void SetDefinition(const CalculatedPropertyDefinition & value) { m_definition = value; }
    void SetNamedParameters(const StringDictionary & value) { m_named_parameters = value; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] StrategyParameters & GetParameters();

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] CalculatedPropertyDefinition & GetDefinition();

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] StringDictionary & GetNamedParameters();

    operator types::CalculatedProperty() const;

private:
    void GetCalculatedProperty(types::CalculatedProperty & value) const;

    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

    CalculatedPropertyDefinition m_definition;
    StrategyParameters m_parameters;
    StringDictionary m_named_parameters;
};
}
