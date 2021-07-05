#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Carveout object
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy_generated/CarveoutBase.h"
#include "strategy_generated/CarveoutUpdateBase.h"
#include "strategy_generated/CarveoutOptionsBase.h"
#include "strategy_generated/CarveoutModifierBase.h"

namespace tbricks {

/**
 * Carveout is a way to preallocate a large chunk of a limit.
 * Set a limit chunk before starting quoting and then quoting service
 * will ensure that quotes sent are within the specified carveout.
 */
class STRATEGY_EXPORT Carveout : public CarveoutBase
{
public:
    class Update;
    class Stream;
    class Options;
    class Modifier;
    class RequestResult;

public:
    Carveout() = default;
    ~Carveout() override = default;
    Carveout(const Carveout & carveout) = default;
    Carveout(Carveout && carveout) = default;
    Carveout & operator=(const Carveout & carveout) = default;
    Carveout & operator=(Carveout && carveout) = default;

public:
    static RequestResult SendCreateRequest(const Options & options, IRequestReplyHandler & handler = IRequestReplyHandler::Default());
    static RequestResult SendModifyRequest(const Modifier & modifier, IRequestReplyHandler & handler = IRequestReplyHandler::Default());
    static RequestResult SendDeleteRequest(const CarveoutIdentifier & id, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

public:
    void Merge(const Update & update);
};

class STRATEGY_EXPORT Carveout::Update : public CarveoutUpdateBase
{
public:
    Update() = default;
    Update(const Update & update) = default;
    Update(Update && update) noexcept = default;
    Update & operator=(const Update & update) = default;
    Update & operator=(Update && update) noexcept = default;
    ~Update() override = default;

public:
    Update(std::shared_ptr<protocol::Carveout> update);
};

/**
 * Carveout::Options allows to create a large chunk of a limit
 * by setting limit on the specified parameter with required value.
 */
class STRATEGY_EXPORT Carveout::Options : public CarveoutOptionsBase
{
public:
    Options() = default;
    Options(const Options & option) = default;
    Options(Options && option) = default;
    Options & operator=(const Options & option) = default;
    Options & operator=(Options && option) = default;
    ~Options() override = default;

public:
    /**
     * %Set InstrumentVenueIdentification of the carveout.
     *
     * @param ivid          Instance of InstrumentVenueIdentification
     */
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

private:
    friend class Carveout;
    InstrumentVenueIdentification m_ivid;
};

/**
 * Carveout::Modifier allows to modify carveout
 */
class STRATEGY_EXPORT Carveout::Modifier : public CarveoutModifierBase
{
public:
    Modifier(const CarveoutIdentifier & identifier);
    Modifier(const Modifier & option) = default;
    Modifier(Modifier && option) = default;
    Modifier & operator=(const Modifier & option) = default;
    Modifier & operator=(Modifier && option) = default;
    ~Modifier() override = default;

private:
    friend class Carveout;
    CarveoutIdentifier m_carveout_identifier;
};

class STRATEGY_EXPORT Carveout::RequestResult : public Printable
{
public:
    RequestResult() = default;
    RequestResult(const Identifier & request_identifier, const CarveoutIdentifier & identifier) :
        m_request_identifier(request_identifier),
        m_carveout_identifier(identifier)
    {}

    const Identifier & GetRequestIdentifier() const { return m_request_identifier; }
    const CarveoutIdentifier & GetCarveoutIdentifier() const { return m_carveout_identifier; }

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    CarveoutIdentifier m_carveout_identifier;
};
}
