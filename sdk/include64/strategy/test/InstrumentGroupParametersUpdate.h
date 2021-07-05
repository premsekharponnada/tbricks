#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentGroupParametersUpdate can be used to work
// with instrument group parameters via VirtualServiceInstrument
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/instrument/InstrumentGroupParameters.h"
#include "strategy/Value.h"
#include "strategy/instrument/ParameterSource.h"

namespace tbricks {

namespace protocol {
class InstrumentGroupParametersUpdateRequest;
}

namespace types {
class ParameterInformation;
}

namespace test {
class VirtualServiceInstrument;

/**
 * InstrumentGroupParametersUpdate object stores a collection of instrument
 * group parameters. Instrument group identifier and parameters should be
 * configured to be able use it with VirtualServiceInstrument interface.
 */
class STRATEGY_EXPORT InstrumentGroupParametersUpdate : public Printable
{
public:
    InstrumentGroupParametersUpdate();
    InstrumentGroupParametersUpdate(const InstrumentGroupIdentifier & id);

    InstrumentGroupParametersUpdate(const InstrumentGroupParametersUpdate & update);
    InstrumentGroupParametersUpdate & operator=(const InstrumentGroupParametersUpdate & options);

    virtual ~InstrumentGroupParametersUpdate();

private:
    friend class VirtualServiceInstrument;
    InstrumentGroupParametersUpdate(const protocol::InstrumentGroupParametersUpdateRequest & update);

public:
    bool HasInstrumentGroupIdentifier() const;
    InstrumentGroupIdentifier GetInstrumentGroupIdentifier() const;
    void SetInstrumentGroupIdentifier(const InstrumentGroupIdentifier & id);

    bool HasParameter(const InstrumentParameterDefinition & definition) const;
    bool GetParameter(const InstrumentParameterDefinition & definition, AnyType & value) const;
    void SetParameter(const InstrumentParameterDefinition & definition, const AnyType & value);

    bool HasInstrumentGroupParameters() const;
    InstrumentGroupParameters GetInstrumentGroupParameters() const;
    void SetInstrumentGroupParameters(const InstrumentGroupParameters & params);

    bool HasContextIdentifier() const;
    Identifier GetContextIdentifier() const;

    /**
     * Set parameters context.
     *
     * Ranking identifier can be used as context to
     * create aggregated parameters update.
     *
     * If identifier is empty, parameters will be used
     * as default parameters (if required context/ranking
     * hasn't configured).
     *
     * @param context_id                 Context/Ranking identifier
     */
    void SetContextIdentifier(const Identifier & context_id);

    bool HasSource(const InstrumentParameterDefinition & definition) const;
    ParameterSource GetSource(const InstrumentParameterDefinition & definition) const;

    /**
     * Set source value of the specified parameter from the parameter information container.
     * Can be used for manual parameters aggregation.
     *
     * @param source                    Parameter source value to be set.
     */
    void SetSource(const ParameterSource & source);

    /**
     * Set default source value which will be used for all parameters.
     * It overrides previously set sources.
     *
     * @param source                    Parameter source value to be set.
     */
    void SetDefaultSource(const ParameterSource & source);

    bool HasPortfolioIdentifier() const;
    PortfolioIdentifier GetPortfolioIdentifier() const;
    void SetPortfolioIdentifier(const PortfolioIdentifier & portfolio_id);

    bool HasUserIdentifier() const;
    UserIdentifier GetUserIdentifier() const;
    void SetUserIdentifier(const UserIdentifier & user_id);

public:
    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    const protocol::InstrumentGroupParametersUpdateRequest & get_update() const;
    const types::ParameterInformation & get_sources() const;

private:
    std::unique_ptr<protocol::InstrumentGroupParametersUpdateRequest> m_update;
    std::unique_ptr<types::ParameterInformation> m_sources;
};

} // \namespace test
} // \namespace tbricks
