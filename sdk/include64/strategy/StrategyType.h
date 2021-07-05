#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyType object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/parameter/ParameterDefinition.h"

#include <memory>
#include <vector>

namespace tbricks {

namespace protocol {
class Plugin;
}

class String;
class PluginType;
class StrategyIdentifier;
class Boolean;
class AlgoType;

/**
 * StrategyType object.
 *
 * Represents type of strategy instance.
 *
 * @since 2.11
 *
 */
class STRATEGY_EXPORT StrategyType : public Printable
{
public:
    class Update;
    class Stream;

public:
    StrategyType();
    ~StrategyType() override;

    /**
     * Constructor.
     *
     * Creates new StrategyType instance with specified strategy type
     * identifier and immediately tries to resolve it.
     *
     * @see Resolve
     *
     * @param si                     StrategyType identifier
     */
    StrategyType(const StrategyIdentifier & si);

    StrategyType(const StrategyType & strategyType);
    StrategyType(StrategyType && strategyType) noexcept;

    StrategyType & operator=(const StrategyType & strategyType);
    StrategyType & operator=(StrategyType && strategyType) noexcept;

public:
    /**
     * Resolve strategy type
     *
     * Synchronously fetches full description of the strategy type
     * identified by the parameter.
     *
     * @param si                         StrategyType identifier
     *
     * @return                          'true' if strategy type is available,
     *                                  'false' otherwise
     */
    bool Resolve(const StrategyIdentifier & si);

    /**
     * Get all strategy types
     *
     * Synchronously fetches all strategy types
     *
     * @since 2.12
     *
     * @param[out] types                 vector of strategy types
     *
     */
    static void GetAllTypes(std::vector<StrategyType> & types);

    void Merge(const StrategyType::Update & update);

    bool Empty() const;

    void Clear();

public:
    StrategyIdentifier GetIdentifier() const;
    String GetName() const;
    String GetDescription() const;
    PluginType GetClass() const;
    Boolean GetDeleted() const;

    /**
     * Get display data permission
     *
     * @return                          'true' if client has permission to use data only for display purpose,
     *                                  'false' otherwise
     */
    Boolean GetDisplayDataAllowed() const;

    /**
     * Get derived data permission
     *
     * @return                          'true' if client has permission to use data for further calculations (like fair
     * prices, quotes etc), 'false' otherwise
     */
    Boolean GetDerivedDataAllowed() const;

    AlgoType GetAlgoType() const;
    bool HasAlgoType() const;

    std::vector<ParameterDefinition> GetParameters() const;
    bool HasParameters() const;

    std::vector<ParameterDefinition> GetAffectAlgoLabelParameters() const;
    bool HasAffectAlgoLabelParameters() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    StrategyType(std::unique_ptr<protocol::Plugin> plugin);

private:
    std::unique_ptr<protocol::Plugin> m_msg;
};
}
