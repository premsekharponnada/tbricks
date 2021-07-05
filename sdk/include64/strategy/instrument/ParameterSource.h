#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter source container.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Uuid.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/type/InstrumentGroupIdentifier.h"
#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/type/UserIdentifier.h"
#include "strategy/Value.h"

// \namespace tbricks
namespace tbricks {

class User;

namespace types {
class ParameterSource;
}

class STRATEGY_EXPORT ParameterSource : public Printable
{
public:
    ParameterSource() = default;
    ParameterSource(const types::ParameterSource & source);
    ParameterSource(const ParameterSource & source) = default;
    ParameterSource & operator=(const ParameterSource & source) = default;

    void decode(const types::ParameterSource & source);

    const Uuid & GetParameterIdentifier() const;
    const InstrumentIdentifier & GetInstrumentIdentifier() const;
    const InstrumentGroupIdentifier & GetInstrumentGroupIdentifier() const;
    const Uuid & GetContextIdentifier() const;
    const PortfolioIdentifier & GetPortfolioIdentifier() const;
    const UserIdentifier & GetUserIdentifier() const;
    User GetUser() const;

    bool HasInstrumentIdentifier() const;
    bool HasInstrumentGroupIdentifier() const;
    bool HasContextIdentifier() const;
    bool HasPortfolioIdentifier() const;
    bool HasUserIdentifier() const;

    void SetParameterIdentifier(const Uuid & id);
    void SetInstrumentIdentifier(const InstrumentIdentifier & id);
    void SetInstrumentGroupIdentifier(const InstrumentGroupIdentifier & id);
    void SetContextIdentifier(const Uuid & id);
    void SetPortfolioIdentifier(const PortfolioIdentifier & id);
    void SetUserIdentifier(const UserIdentifier & id);

    bool Empty() const;
    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Uuid m_parameter_id;
    InstrumentIdentifier m_instrument_id;
    InstrumentGroupIdentifier m_group_id;
    Uuid m_context_id;
    PortfolioIdentifier m_portfolio_id;
    UserIdentifier m_user_id;
};
}
