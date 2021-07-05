#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Attribute defintion base.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Uuid.h"
#include "strategy/type/String.h"
#include "strategy/type/TypeInfo.h"

#include <memory>

namespace tbricks {

namespace protocol {
class ParameterDefinition;
}

class EnumDefinition;
class CalculatedPropertyDefinition;

class STRATEGY_EXPORT DefinitionBase : public Printable
{
public:
    /**
     * Default constructor and destructor
     */
    DefinitionBase() = default;
    ~DefinitionBase() override = default;

    /**
     * Get parameter definition identifier
     *
     * @return Identifier of the parameter definition
     */
    const Uuid & GetIdentifier() const { return m_id; }

    /**
     * Get parameter display name
     *
     * @return String with parameter's display name
     * @throws InvalidParameterDefinitionException if definition is empty
     */
    const String & GetDisplayName() const;

    /**
     * Get parameter's underlying type information
     *
     * @return type information for the parameter
     * @throws InvalidParameterDefinitionException if definition is empty
     */
    const TypeInfo & GetTypeInfo() const;

    /**
     * Get parameter's corresponding enumeration definition
     *
     * @return enumeration definition for the parameter
     * @throws InvalidParameterDefinitionException if definition is empty
     */
    EnumDefinition GetEnumDefinition() const;

    /**
     * Get parameter's hash
     *
     * @return hash value
     */
    size_t GetHash() const { return m_id.GetHash(); }

    /**
     * Less operator for the parameter. Used to comply to container requirements
     *
     * @param [in] definition Object to compare to
     *
     * @return true if this definition is less than compared object
     */
    bool operator<(const DefinitionBase & definition) const { return m_id < definition.m_id; }

    /**
     * Equality operator for the parameter. Used to comply to container requirements
     *
     * @param [in] definition Object to compare to
     *
     * @return true if this definition is equal to compared object
     */
    bool operator==(const DefinitionBase & definition) const { return m_id == definition.m_id; }

    /**
     * Non equality operator for the parameter
     *
     * @param [in] definition Object to compare to
     *
     * @return true if this definition is not equal to compared object
     */
    bool operator!=(const DefinitionBase & definition) const { return !operator==(definition); }

    /**
     * Casts parameter definition to the calculated property definition.
     *
     * @return calculated property definition if the identifier is a valid parameter.
               Empty object if calculated property definition is casted to itself
     * @throws InvalidParameterDefinitionException if definition is empty
     */
    explicit operator CalculatedPropertyDefinition() const;

    /**
     * Check if this definition is empty. This method will try to resolve it's content
     *
     * @return true if empty, false if otherwise
     */
    virtual bool Empty() const;

    /**
     * Prints contents of this object ot the stream
     *
     * @param [in] stream Where to write data
     *
     * @return std::ostream populated with data
     */
    virtual std::ostream & Print(std::ostream & strm) const override;

public:
    void resolve(std::shared_ptr<protocol::ParameterDefinition> def) const;

protected:
    /**
     * Constructor with id of parameter definition
     *
     * @param [in]  id holds identifier of the parameter definition
     */
    DefinitionBase(const Uuid & id) : m_id(id) {}

    virtual bool resolve() const = 0;

protected:
    Uuid m_id;
    String m_display_name;
    TypeInfo m_type_info = TypeInfo::SFT_NONE;
    std::shared_ptr<protocol::ParameterDefinition> m_impl;
};

inline size_t hash_value(const DefinitionBase & value)
{
    return value.GetHash();
}
}
