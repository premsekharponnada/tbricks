#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Reference price object
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Strategy.h"

namespace tbricks {

class Instrument;

namespace protocol {
class ReferencePrice;
}

class STRATEGY_EXPORT ReferencePrice : public Printable
{
public:
    class Options;
    class Update;
    class Stream;

public:
    class RequestResult;

public:
    ReferencePrice();
    ReferencePrice(const ReferencePrice & price);
    ReferencePrice(ReferencePrice && price) noexcept;
    ReferencePrice & operator=(const ReferencePrice & price);
    ReferencePrice & operator=(ReferencePrice && price) noexcept;
    virtual ~ReferencePrice() override;

    Identifier GetIdentifier() const;

    InstrumentIdentifier GetInstrumentIdentifier() const;
    Date GetReferencePriceDate() const;

    Price GetReferencePrice() const;

    Currency GetCurrency() const;

    /**
     * Get parameter context identifier.
     *
     * @return             parameter context identifier
     */
    Identifier GetParameterContextIdentifier() const;

    void Merge(const ReferencePrice::Update & update);

    void Clear();
    bool Empty() const;

public:
    static RequestResult SendModifyRequest(const ReferencePrice::Options & options, IRequestReplyHandler & handler);
    static RequestResult SendDeleteRequest(const InstrumentIdentifier & instrument_identifier,
                                           const Date & reference_price_date,
                                           const Identifier & parameter_context_id,
                                           IRequestReplyHandler & handler = IRequestReplyHandler::Default());
    static RequestResult SendDeleteRequest(const InstrumentIdentifier & instrument_identifier,
                                           const Date & reference_price_date,
                                           IRequestReplyHandler & handler = IRequestReplyHandler::Default());

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    std::unique_ptr<protocol::ReferencePrice> m_impl;
};

//****************************************************************************
// RequestResult class
//****************************************************************************
class STRATEGY_EXPORT ReferencePrice::RequestResult : public Printable
{
public:
    RequestResult() = default;
    RequestResult(const Identifier & request_id, const Identifier & reference_price_id);

    const Identifier & GetRequestIdentifier() const { return m_request_id; }

    const Identifier & GetReferencePriceIdentifier() const { return m_reference_price_id; }

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    Identifier m_request_id;
    Identifier m_reference_price_id;
};

//****************************************************************************
// ReferencePrice::Update class
//****************************************************************************
class STRATEGY_EXPORT ReferencePrice::Update : public Printable
{
public:
    Update();
    Update(const Update & update) = default;
    Update(Update && update) noexcept;
    virtual ~Update() override = default;

    Update & operator=(const Update & update) = default;
    Update & operator=(Update && update) noexcept;

    Identifier GetIdentifier() const;

    InstrumentIdentifier GetInstrumentIdentifier() const;
    Date GetReferencePriceDate() const;

    Price GetReferencePrice() const;

    Currency GetCurrency() const;

    /**
     * Get parameter context identifier.
     *
     * @return             parameter context identifier
     */
    Identifier GetParameterContextIdentifier() const;

    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

public:
    Update(std::shared_ptr<protocol::ReferencePrice> msg);

private:
    friend class ReferencePrice;

private:
    std::shared_ptr<protocol::ReferencePrice> m_impl;
};

//****************************************************************************
// ReferencePrice::Options class
//****************************************************************************
class STRATEGY_EXPORT ReferencePrice::Options : public Printable
{
public:
    Options() = default;
    Options(const Options & options) = default;
    virtual ~Options() override = default;

    Options & operator=(const Options & options) = default;

    void SetInstrumentIdentifier(const InstrumentIdentifier & value) { m_instrument_id = value; }

    const InstrumentIdentifier & GetInstrumentIdentifier() const { return m_instrument_id; }

    void SetInstrument(const Instrument & instrument);

    void SetReferencePriceDate(const Date & value) { m_reference_date = value; }

    const Date & GetReferencePriceDate() const { return m_reference_date; }

    void SetReferencePrice(const Price & value) { m_reference_price = value; }

    const Price & GetReferencePrice() const { return m_reference_price; }

    /**
     * Sets parameter context identifier
     *
     * @param              new value
     */
    void SetParameterContextIdentifier(const Identifier & value) { m_parameter_context_id = value; }

    /**
     * Get parameter context identifier.
     *
     * @return             parameter context identifier
     */
    const Identifier & GetParameterContextIdentifier() const { return m_parameter_context_id; }

    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    friend class ReferencePrice;

private:
    InstrumentIdentifier m_instrument_id;
    Date m_reference_date;
    Identifier m_parameter_context_id;
    Price m_reference_price;
    Currency m_currency;
};
}
