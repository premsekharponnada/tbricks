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
class TreeNodeIdentifier;
class PricePolicy;
class ParticipationPolicy;
class PortfolioIdentifier;
class OrderIdentifier;
class VenueInstrumentIdentifier;
class Side;
class ExtraData;
class TransitionType;
class OrderCapacity;
class ExecutionPolicy;
class UserIdentifier;
class Validity;
class Currency;
class CFI;

/**
 * This class is the primary pre-trade risk check point.
 * When IStrategyEventHandler::HandleAppRequest() is called, OrderRequestContext object
 * contains parameter values extracted from the request, type of the request being handled,
 * request identifier, strategy identifier, etc. Callee shall check and decide whether
 * request is accepted/rejected for further processing.
 *
 * @see IStrategyEventHandler::HandleAppRequest()
 */
class STRATEGY_EXPORT OrderRequestContext : public Printable
{
public:
    OrderRequestContext();
    OrderRequestContext(const OrderRequestContext & ctx);
    OrderRequestContext(OrderRequestContext && ctx) noexcept;

    OrderRequestContext & operator=(const OrderRequestContext & ctx);
    OrderRequestContext & operator=(OrderRequestContext && ctx) noexcept;

    ~OrderRequestContext();

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

    bool GetOrderIdentifier(OrderIdentifier & identifier) const;

    bool HasInstrumentVenueIdentification() const;
    bool GetInstrumentVenueIdentification(InstrumentVenueIdentification & ivid) const;

    bool HasVenueInstrumentIdentifier() const;
    bool GetVenueInstrumentIdentifier(VenueInstrumentIdentifier & viid) const;

    bool HasSide() const;
    bool GetSide(Side & side) const;

    bool HasPrice() const;
    bool GetPrice(Price & price) const;

    bool HasActiveVolume() const;
    bool GetActiveVolume(Volume & active_volume) const;

    bool HasTotalVolume() const;
    bool GetTotalVolume(Volume & total_volume) const;

    bool HasDisclosedVolume() const;
    bool GetDisclosedVolume(Volume & disvlosed_volume) const;

    bool HasPartialFillNotAllowed() const;
    bool GetPartialFillNotAllowed(Boolean & partial_fill_not_allowed) const;

    bool HasBypassSoftLimits() const;
    bool GetBypassSoftLimits(Boolean & bypass_soft_limits) const;

    bool HasCreator() const;
    bool GetCreator(User & creator) const;
    bool GetCreator(UserIdentifier & creator) const;

    bool HasOwner() const;
    bool GetOwner(User & owner) const;
    bool GetOwner(UserIdentifier & owner) const;

    bool HasPortfolioIdentifier() const;
    bool GetPortfolioIdentifier(PortfolioIdentifier & portfolio_identifier) const;

    bool HasExtraData() const;
    bool GetExtraData(ExtraData & extra_data) const;

    bool HasComment() const;
    bool GetComment(String & comment) const;

    bool HasTargetPrice() const;
    bool GetTargetPrice(Price & target_price) const;

    bool HasStopPrice() const;
    bool GetStopPrice(Price & stop_price) const;

    bool HasTransitionType() const;
    bool GetTransitionType(TransitionType & transition_type) const;

    bool HasMinimumAcceptableVolume() const;
    bool GetMinimumAcceptableVolume(Volume & minimum_acceptable_volume) const;

    bool HasCapacity() const;
    bool GetCapacity(OrderCapacity & capacity) const;

    bool HasParticipationPolicy() const;
    bool GetParticipationPolicy(ParticipationPolicy & policy) const;

    bool HasStrategyPath() const;
    bool GetStrategyPath(std::vector<StrategyIdentifier> & path) const;

    bool HasStrategyDefinitionPath() const;
    bool GetStrategyDefinitionPath(std::vector<StrategyIdentifier> & path) const;

    bool HasPricePolicy() const;
    bool GetPricePolicy(PricePolicy & policy) const;

    bool HasHandler() const;
    bool GetHandler(TreeNodeIdentifier & handler) const;

    bool HasClient() const;
    bool GetClient(TreeNodeIdentifier & client) const;

    bool HasVolumeDelta() const;
    bool GetVolumeDelta(Volume & delta) const;

    bool HasExecutionPolicy() const;
    bool GetExecutionPolicy(ExecutionPolicy & value) const;

    bool HasCFI() const;
    bool GetCFI(CFI & value) const;

    bool HasValidity() const;
    bool GetValidity(Validity & validity) const;

    bool HasDealtCurrency() const;
    bool GetDealtCurrency(Currency & ccy) const;

    /**
     * Override execution policy in the request
     */
    void OverrideExecutionPolicy(const ExecutionPolicy & execution_policy);

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
    OrderRequestContext(std::shared_ptr<Impl> msg);
    Impl * get_impl() const;

private:
    std::shared_ptr<Impl> m_impl;
};

std::ostream & operator<<(std::ostream & strm, const OrderRequestContext::RequestType & type);
}
