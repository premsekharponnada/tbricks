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

class BlockOrderIdentifier;
class BlockOrderLeg;
class Boolean;
class ExtraData;
class Identifier;
class InstrumentVenueIdentification;
class OrderCapacity;
class ParticipationPolicy;
class PortfolioIdentifier;
class Price;
class PricePolicy;
class Side;
class StrategyIdentifier;
class String;
class TransitionType;
class TreeNodeIdentifier;
class User;
class UserIdentifier;
class VenueInstrumentIdentifier;
class Volume;

/**
 * This class is the primary pre-trade risk check point.
 * When IStrategyEventHandler::HandleAppRequest() is called, BlockOrderRequestContext object
 * contains parameter values extracted from the request, type of the request being handled,
 * request identifier, strategy identifier, etc. Callee shall check and decide whether
 * request is accepted/rejected for further processing.
 *
 * @see IStrategyEventHandler::HandleAppRequest()
 */
class STRATEGY_EXPORT BlockOrderRequestContext : public Printable
{
public:
    BlockOrderRequestContext();
    BlockOrderRequestContext(const BlockOrderRequestContext & ctx);
    BlockOrderRequestContext(BlockOrderRequestContext && ctx) noexcept;

    BlockOrderRequestContext & operator=(const BlockOrderRequestContext & ctx);
    BlockOrderRequestContext & operator=(BlockOrderRequestContext && ctx) noexcept;

    ~BlockOrderRequestContext();

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
        DELETE_REQUEST = 2,
    };

    /**
     * Returns type of the request being processed.
     */
    bool GetRequestType(RequestType & request_type) const;

    bool GetBlockOrderIdentifier(BlockOrderIdentifier & identifier) const;

    bool HasPrice() const;
    bool GetPrice(Price & price) const;

    bool HasBypassSoftLimits() const;
    bool GetBypassSoftLimits(Boolean & bypass_soft_limits) const;

    bool HasCreator() const;
    bool GetCreator(User & creator) const;
    bool GetCreator(UserIdentifier & creator) const;

    bool HasOwner() const;
    bool GetOwner(User & owner) const;
    bool GetOwner(UserIdentifier & owner) const;

    bool HasTargetPrice() const;
    bool GetTargetPrice(Price & target_price) const;

    bool HasCapacity() const;
    bool GetCapacity(OrderCapacity & capacity) const;

    bool HasStrategyPath() const;
    bool GetStrategyPath(std::vector<StrategyIdentifier> & path) const;

    bool HasStrategyDefinitionPath() const;
    bool GetStrategyDefinitionPath(std::vector<StrategyIdentifier> & path) const;

    bool HasPricePolicy() const;
    bool GetPricePolicy(PricePolicy & policy) const;

    bool HasHandler() const;
    bool GetHandler(TreeNodeIdentifier & handler) const;

    bool HasLegs() const;
    bool GetLegs(std::vector<BlockOrderLeg> & value) const;

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
    BlockOrderRequestContext(std::shared_ptr<Impl> msg);
    Impl * get_impl() const;

private:
    std::shared_ptr<Impl> m_impl;
};

std::ostream & operator<<(std::ostream & strm, const BlockOrderRequestContext::RequestType & type);
}
