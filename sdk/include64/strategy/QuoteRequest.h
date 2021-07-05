#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteRequest
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/User.h"
#include "strategy/Types.h"
#include "strategy/Strategy.h"
#include <vector>

namespace tbricks {

namespace protocol {
class QuoteRequestRequest;
class QuoteRequestLeg;
}

//****************************************************************************
// QuoteRequest class
//****************************************************************************

class STRATEGY_EXPORT QuoteRequest : public Printable
{
public:
    class Leg;
    class RequestResult;

public:
    enum Type
    {
        QUOTE_REQUEST = 0,
        INTENTION_TO_CROSS = 1
    };

public:
    QuoteRequest();
    QuoteRequest(const QuoteRequest & rfq);
    QuoteRequest(const protocol::QuoteRequestRequest & request);
    QuoteRequest & operator=(const QuoteRequest & rfq);
    virtual ~QuoteRequest();

    QuoteRequestIdentifier GetQuoteRequestIdentifier() const;

    void SetType(const Type & type);
    Type GetType() const;

    void GetQuoteRequestLegs(std::vector<QuoteRequest::Leg> & legs) const;
    void SetQuoteRequestLegs(const std::vector<QuoteRequest::Leg> & legs);

    void SetValidUntilDatetime(const DateTime & valid_until_datetime);
    DateTime GetValidUntilDatetime() const;

    void SetLiquidityPool(const LiquidityPoolIdentifier & lp_id);
    LiquidityPoolIdentifier GetLiquidityPool() const;

    void SetClient(const TreeNodeIdentifier & client);
    TreeNodeIdentifier GetClient() const;

    bool HasStrategyParameters() const;
    bool GetStrategyParameters(StrategyParameters & strategyParameters) const;
    void SetStrategyParameters(const StrategyParameters & strategyParameters);

    bool HasRegulatoryParameters() const;
    bool GetRegulatoryParameters(RegulatoryParameters & regulatoryParameters) const;
    void SetRegulatoryParameters(const RegulatoryParameters & regulatoryParameters);

    UserIdentifier GetCreator() const;

public:
    bool Empty() const;

public:
    static RequestResult SendCreateRequest(const QuoteRequest & options, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Delete quote request and stops propagating its responses
     * (directed quote response) into the system.
     *
     * @param id                        %Identifier of quote request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Request identifier
     */
    static Identifier SendDeleteRequest(const QuoteRequestIdentifier & id, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::unique_ptr<protocol::QuoteRequestRequest> m_quote_request;
};

class STRATEGY_EXPORT QuoteRequest::Leg : public Printable
{
public:
    Leg() = delete;
    Leg(const QuoteRequest::Leg & other);

    Leg(const tbricks::InstrumentVenueIdentification & ivid);
    Leg(const protocol::QuoteRequestLeg & message);
    ~Leg();

    const InstrumentVenueIdentification & GetInstrumentVenueIdentification() const;

    Side GetSide() const;
    Volume GetVolume() const;
    String GetCounterpart() const;

    void SetVolume(const Volume & volume);
    void SetSide(const Side & side);
    void SetCounterpart(const String & counterpart);

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend class QuoteRequest;
    tbricks::InstrumentVenueIdentification m_ivid;
    std::unique_ptr<protocol::QuoteRequestLeg> m_leg;
};

//****************************************************************************
// QuoteRequest::RequestResult class
//****************************************************************************
class STRATEGY_EXPORT QuoteRequest::RequestResult : public Printable
{
public:
    RequestResult();
    RequestResult(const Identifier & request_identifier, const Identifier & instance_identifier);

    const Identifier & GetRequestIdentifier() const;
    const Identifier & GetInstanceIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    Identifier m_instance_identifier;
};
}
