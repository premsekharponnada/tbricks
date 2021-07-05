#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of RankingIdentifier type.
//****************************************************************************************

#include "strategy/type/RankingIdentifier.h"
#include "strategy/parameter/Parameter.h"
#include "strategy/parameter/IdentifierParameter.h"

// \namespace tbricks
namespace tbricks {

/**
 * Ranking parameter of an app instance.
 *
 * It associated with strategy instance parameters
 * and can be used to read and modify from it.
 */
class STRATEGY_EXPORT RankingParameter : public Parameter
{
public:
    using ValueType = RankingIdentifier;

public:
    /**
     * Create new parameter and associate it with app instance
     *
     * @param definition   parameter definition
     */
    RankingParameter(const ParameterDefinition & definition);

    RankingParameter(const RankingParameter & parameter);
    RankingParameter & operator=(const RankingParameter & parameter);

    /**
     * Assigne a new value to the parameter
     *
     * @return            new value of parameter
     */
    RankingParameter & operator=(const RankingIdentifier & value);

    /**
     * Get current value of parameter
     *
     * @return            value of parameter
     */
    RankingIdentifier GetIdentifier() const;

    /**
     * Get current value of parameter
     *
     * @return            value of parameter
     */
    operator RankingIdentifier() const;

private:
    using Impl = IdentifierParameter::Impl;

private:
    IdentifierParameter::Impl * const m_impl;
};

} // \namespace tbricks
