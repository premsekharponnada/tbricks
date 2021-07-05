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
#include "strategy/ExPit.h"

#include <memory>
#include <vector>

namespace tbricks {

/**
 * This class is the primary pre-trade risk check point.
 * When IStrategyEventHandler::HandleAppRequest() is called, ExPitRequestContext object
 * contains parameter values extracted from the request, type of the request being handled,
 * request identifier, strategy identifier, etc. Callee shall check and decide whether
 * request is accepted/rejected for further processing.
 *
 * @see IStrategyEventHandler::HandleAppRequest()
 */
class STRATEGY_EXPORT ExPitRequestContext : public Printable
{
public:
    ExPitRequestContext();
    ExPitRequestContext(const ExPitRequestContext & ctx);
    ExPitRequestContext(ExPitRequestContext && ctx) noexcept;

    ExPitRequestContext & operator=(const ExPitRequestContext & ctx);
    ExPitRequestContext & operator=(ExPitRequestContext && ctx) noexcept;

    ~ExPitRequestContext();

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
        DELETE_REQUEST = 1,
    };

    /**
     * Returns type of the request being processed.
     */
    bool GetRequestType(RequestType & request_type) const;

    bool GetExPitIdentifier(ExPitIdentifier & identifier) const;

    bool HasQuoteRequestIdentifier() const;
    bool GetQuoteRequestIdentifier(QuoteRequestIdentifier & v) const;

    bool HasCreator() const;
    bool GetCreator(UserIdentifier & creator) const;

    bool HasDeals() const;
    bool GetDeals(std::vector<ExPitDeal> & sides) const;

    bool HasType() const;
    bool GetType(ExPit::Type & type) const;

    bool HasOwner() const;
    bool GetOwner(UserIdentifier & owner) const;

    bool HasParentStrategyIdentifier() const;
    bool GetParentStrategyIdentifier(StrategyIdentifier & parent_strategy_identifier) const;

    bool HasRootStrategyIdentifier() const;
    bool GetRootStrategyIdentifier(StrategyIdentifier & root_strategy_identifier) const;

    bool HasTradingCapacity() const;
    bool GetTradingCapacity(ExPit::TradingCapacity & trading_capacity) const;

    bool HasHandler() const;
    bool GetHandler(TreeNodeIdentifier & handler) const;

    bool HasBypassSoftLimits() const;
    bool GetBypassSoftLimits(Boolean & bypass_soft_limits) const;

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
    ExPitRequestContext(std::shared_ptr<Impl> msg);
    Impl * get_impl() const;

private:
    std::shared_ptr<Impl> m_impl;
};

std::ostream & operator<<(std::ostream & strm, const ExPitRequestContext::RequestType & type);
}
