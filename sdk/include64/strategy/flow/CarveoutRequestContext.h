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

class StrategyIdentifier;
class Identifier;
class UserIdentifier;
class Double;
class TreeNodeIdentifier;
class CarveoutIdentifier;
class PortfolioIdentifier;
class InstrumentGroupIdentifier;
class Currency;
class Volume;
class Double;
class VenueIdentifier;
class MIC;

/**
 * This class is the primary pre-trade risk check point.
 * When IStrategyEventHandler::HandleCarveoutRequest() is called, CarveoutRequestContext object
 * contains parameter values extracted from the request, type of the request being handled,
 * request identifier, strategy identifier, etc. Callee shall check and decide whether
 * request is accepted/rejected for further processing.
 *
 */
class STRATEGY_EXPORT CarveoutRequestContext : public Printable
{
public:
    CarveoutRequestContext();
    CarveoutRequestContext(const CarveoutRequestContext & ctx);
    CarveoutRequestContext(CarveoutRequestContext && ctx) noexcept;

    CarveoutRequestContext & operator=(const CarveoutRequestContext & ctx);
    CarveoutRequestContext & operator=(CarveoutRequestContext && ctx) noexcept;

    ~CarveoutRequestContext();

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
        DELETE_REQUEST = 2
    };

    /**
     * Returns type of the request being processed.
     */
    bool GetRequestType(RequestType & request_type) const;

    bool GetCarveoutIdentifier(CarveoutIdentifier & identifier) const;

    bool GetParentStrategyIdentifier(StrategyIdentifier & value) const;
    bool HasParentStrategyIdentifier() const;

    bool GetPortfolio(PortfolioIdentifier & value) const;
    bool HasPortfolio() const;

    bool GetOwner(UserIdentifier & value) const;
    bool HasOwner() const;

    bool GetClient(TreeNodeIdentifier & value) const;
    bool HasClient() const;

    bool GetInstrumentGroupIdentifier(InstrumentGroupIdentifier & value) const;
    bool HasInstrumentGroupIdentifier() const;

    bool GetVenueIdentifier(VenueIdentifier & value) const;
    bool HasVenueIdentifier() const;

    bool GetMIC(MIC & value) const;
    bool HasMIC() const;

    bool GetCurrency(Currency & value) const;
    bool HasCurrency() const;

    bool GetBidTotalVolume(Volume & value) const;
    bool HasBidTotalVolume() const;

    bool GetAskTotalVolume(Volume & value) const;
    bool HasAskTotalVolume() const;

    bool GetBidTotalValue(Double & value) const;
    bool HasBidTotalValue() const;

    bool GetAskTotalValue(Double & value) const;
    bool HasAskTotalValue() const;

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
    CarveoutRequestContext(std::shared_ptr<Impl> msg);
    Impl * get_impl() const;

private:
    std::shared_ptr<Impl> m_impl;
};

std::ostream & operator<<(std::ostream & strm, const CarveoutRequestContext::RequestType & type);
}
