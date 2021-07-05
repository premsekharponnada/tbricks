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
#include "strategy/Order.h"
#include "strategy/BlockOrder.h"
#include "strategy/Carveout.h"
#include "strategy/ExPit.h"
#include "strategy/flow/PartitioningType.h"

namespace tbricks {

class AppRequestContext;
class AppResponseContext;
class BlockOrderRequestContext;
class BlockOrderResponseContext;
class CarveoutRequestContext;
class CarveoutResponseContext;
class DirectedQuote;
class DirectedQuoteRequestContext;
class DirectedQuoteResponseContext;
class ExPitRequestContext;
class ExPitResponseContext;
class OrderRequestContext;
class OrderResponseContext;
class PortfolioIdentifier;

class STRATEGY_EXPORT IFlowApp
{
public:
    /**
     * These are the pre-trade risk checking callbacks.
     * Callee has to decide whether request has to be accepted or rejected for further processing.
     *
     * Callee has to call eitherAppRequestContext::SendAcceptReply() or AppRequestContext::SendRejectReply(),
     * exactly once. Violationg this yields undefined behavior.
     *
     * @param context                   contains values extracted from the request being validated
     *
     */
    virtual void HandleAppRequest(AppRequestContext & context) = 0;
    virtual void HandleAppResponse(AppResponseContext & context) = 0;

    virtual void HandleOrderRequest(OrderRequestContext & context) = 0;
    virtual void HandleOrderResponse(OrderResponseContext & context) = 0;
    virtual void HandleOrderUpdate(const Order::Update & order) = 0;

    virtual void HandleBlockOrderRequest(BlockOrderRequestContext & context) = 0;
    virtual void HandleBlockOrderResponse(BlockOrderResponseContext & context) = 0;
    virtual void HandleBlockOrderUpdate(const BlockOrder::Update & order) = 0;

    virtual void HandleCarveoutRequest(CarveoutRequestContext & context) = 0;
    virtual void HandleCarveoutResponse(CarveoutResponseContext & context) = 0;
    virtual void HandleCarveoutUpdate(const Carveout::Update & order) = 0;

    virtual void HandleDirectedQuoteRequest(DirectedQuoteRequestContext & context) = 0;
    virtual void HandleDirectedQuoteResponse(DirectedQuoteResponseContext & context) = 0;
    virtual void HandleDirectedQuoteUpdate(const DirectedQuote & update) = 0;

    virtual void HandleExPitRequest(ExPitRequestContext & context) = 0;
    virtual void HandleExPitResponse(ExPitResponseContext & context) = 0;
    virtual void HandleExPitUpdate(const ExPit::Update & update) = 0;

public:
    virtual void HandleRecoveryCompleted() = 0;

protected:
    virtual ~IFlowApp();
};

class STRATEGY_EXPORT FlowApp : public Plugin, public IFlowApp
{
public:
    void HandleDeleteRequest() override {}
    void HandleRunRequest() override {}
    void HandlePauseRequest() override {}
    void HandleModifyRequest(const StrategyModifier & /* modifier */) override {}
    void HandleValidateRequest(tbricks::ValidationContext & /* context */) override {}

    void HandleBlockOrderRequest(BlockOrderRequestContext & /* context */) override {}
    void HandleBlockOrderResponse(BlockOrderResponseContext & /* context */) override {}
    void HandleBlockOrderUpdate(const BlockOrder::Update & /* order */) override {}

    void HandleCarveoutRequest(CarveoutRequestContext & /* context */) override {}
    void HandleCarveoutResponse(CarveoutResponseContext & /* context */) override {}
    void HandleCarveoutUpdate(const Carveout::Update & /* order */) override {}

    void HandleDirectedQuoteRequest(DirectedQuoteRequestContext & /* context */) override {}
    void HandleDirectedQuoteResponse(DirectedQuoteResponseContext & /* context */) override {}
    void HandleDirectedQuoteUpdate(const DirectedQuote & /* update */) override {}

    void HandleExPitRequest(ExPitRequestContext & /* context */) override {}
    void HandleExPitResponse(ExPitResponseContext & /* context */) override {}
    void HandleExPitUpdate(const ExPit::Update & /* update */) override {}

    PartitioningType GetPartitioningType() const;

    PortfolioIdentifier GetPartitioningPortfolio() const;
    VenueIdentifier GetPartitioningVenue() const;
    UserIdentifier GetPartitioningOwner() const;
    TreeNodeIdentifier GetClientLegalEntity() const;

    virtual std::ostream & Print(std::ostream & strm) const override;

public:
    /**
     * Get strategy parameters.
     *
     * @see StrategyParameters
     *
     * @return                          Strategy parameter container.
     */
    const StrategyInstanceParameters & GetParameters() const;

    /**
     * Get strategy parameters.
     *
     * @see StrategyInstanceParameters
     *
     * @return                          Strategy parameter container.
     */
    StrategyInstanceParameters & GetParameters();

protected:
    FlowApp();
};
};
