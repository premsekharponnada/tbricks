#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Pre-trade risk checking API.
//
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include <memory>
#include <vector>

namespace tbricks {

class Identifier;
class StrategyIdentifier;
class User;
class Boolean;
class String;
class Price;
class Volume;
class InstrumentVenueIdentification;
class PricePolicy;
class ParticipationPolicy;
class PortfolioIdentifier;
class OrderIdentifier;
class VenueInstrumentIdentifier;
class OrderCapacity;
class ExecutionPolicy;
class UserIdentifier;
class DirectedQuoteIdentifier;
class DirectedQuoteLeg;
class QuoteRequestIdentifier;
class TreeNodeIdentifier;

/**
 * This class is the primary pre-trade risk check point.
 * When IStrategyEventHandler::HandleAppRequest() is called, DirectedQuoteRequestContext object
 * contains parameter values extracted from the request, type of the request being handled,
 * request identifier, strategy identifier, etc. Callee shall check and decide whether
 * request is accepted/rejected for further processing.
 *
 * @see IStrategyEventHandler::HandleAppRequest()
 */
class STRATEGY_EXPORT DirectedQuoteRequestContext : public Printable
{
public:
    DirectedQuoteRequestContext();
    DirectedQuoteRequestContext(const DirectedQuoteRequestContext & ctx);
    DirectedQuoteRequestContext(DirectedQuoteRequestContext && ctx) noexcept;

    DirectedQuoteRequestContext & operator=(const DirectedQuoteRequestContext & ctx);
    DirectedQuoteRequestContext & operator=(DirectedQuoteRequestContext && ctx) noexcept;

    ~DirectedQuoteRequestContext();

public:
    /**
     * Returns request identifier of the request being processed.
     */
    bool GetRequestIdentifier(Identifier & id) const;

    /**
     * Type of the request
     */
    enum RequestType
    {
        CREATE_REQUEST = 0,
        MODIFY_REQUEST = 1,
        DELETE_REQUEST = 2,
    };

    /**
     * Returns type of the request being processed.
     */
    bool GetRequestType(RequestType & request_type) const;

    bool GetDirectedQuoteIdentifier(DirectedQuoteIdentifier & identifier) const;

    bool HasQuoteRequestIdentifier() const;
    bool GetQuoteRequestIdentifier(QuoteRequestIdentifier & v) const;

    bool HasLegs() const;
    bool GetLegs(std::vector<DirectedQuoteLeg> & legs) const;

    bool HasBidPrice() const;
    bool GetBidPrice(Price & v) const;

    bool HasAskPrice() const;
    bool GetAskPrice(Price & v) const;

    bool HasOwner() const;
    bool GetOwner(UserIdentifier & v) const;

    bool HasPortfolioIdentifier() const;
    bool GetPortfolioIdentifier(PortfolioIdentifier & v) const;

    bool HasBidTotalVolume() const;
    bool GetBidTotalVolume(Volume & v) const;

    bool HasAskTotalVolume() const;
    bool GetAskTotalVolume(Volume & v) const;

    bool HasBidActiveVolume() const;
    bool GetBidActiveVolume(Volume & v) const;

    bool HasAskActiveVolume() const;
    bool GetAskActiveVolume(Volume & v) const;

    bool HasBypassSoftLimits() const;
    bool GetBypassSoftLimits(Boolean & bypass_soft_limits) const;

    bool HasCounterpart() const;
    bool GetCounterpart(String & counterpart) const;

    bool HasCounterpartIdentifier() const;
    bool GetCounterpartIdentifier(TreeNodeIdentifier & counterpart) const;

    /**
     * Causes request to be accepted and forwarded for further processing.
     * Either this method or SendRejectReply must be called, exactly once per request, but not both.
     */
    void SendAcceptReply() const;

    /**
     * Causes request to be rejected.
     * Either this method or SendAcceptReply must be called, exactly once per request, but not both.
     */
    void SendRejectReply(const String & reason) const;

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    class Impl;
    DirectedQuoteRequestContext(std::shared_ptr<Impl> msg);
    Impl * get_impl() const;

private:
    std::shared_ptr<Impl> m_impl;
};

std::ostream & operator<<(std::ostream & strm, const DirectedQuoteRequestContext::RequestType & type);
}
