#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// IMatchingEngine is an interface for matching apps testing.
// It's a providing and an intercepting interaction of matching apps
// and trading framework.
// Note, there is no relation between IMatchingEngine interface and
// virtual system. For example, at trade creation, it should be intercepted
// with IMatchingEngine interface and manually added to virtual trade persistence.
//
//****************************************************************************************

#include "strategy/test/DirectedQuoteRequestOptions.h"
#include "strategy/test/DirectedQuoteResponse.h"
#include "strategy/test/DirectedQuoteOptions.h"
#include "strategy/test/DirectedRequestForQuoteOptions.h"
#include "strategy/test/OrderOptions.h"
#include "strategy/test/RequestForTrade.h"
#include "strategy/trading/Trading.h"
#include "strategy/Trade.h"

namespace tbricks { namespace test {
class MatchingEngineInterface;

class IMatchingEngine
{
public:
    //****************************************************************************//
    // Providing to app.                                                          //
    //****************************************************************************//

    /**
     * Resolve app for the specified viid.
     *If some app accepts this viid in HandleIsSupported callback,
     * all next requests for this viid will be routed to the resolved app.
     * This method should be called before any other.
     *
     * @param viid       VenueInstrumentIdentifier.
     *
     * @return           Identifier of resolved app.
     *                   Empty in case of no resolved app.
     */
    StrategyIdentifier Resolve(const VIID & viid);

    /**
     * Provide OrderAddRequest to initiate
     * HandleOrder call at matching app.
     *
     * @param options    VenueInstrumentIdentifier.
     *                   Should contain resolved viid and order id.
     */
    void SendOrderAddRequest(const OrderOptions & options);

    /**
     * Provide OrderModifyRequest to initiate
     * HandleOrderModify call at matching app.
     *
     * @param options    VenueInstrumentIdentifier.
     *                   Should contain order id.
     */
    void SendOrderModifyRequest(const OrderOptions & options);

    /**
     * Provide OrderDeleteRequest to initiate
     * HandleOrderDelete call at matching app.
     *
     * @param id         Order identifier.
     */
    void SendOrderDeleteRequest(const OrderIdentifier & id);

    /**
     * Provide OrdersMassDeleteRequest to initiate
     * HandleOrdersMassDelete call at matching app.
     *
     * @param ivid        Instrument venue identification
     */
    void SendOrdersMassDeleteRequest(const InstrumentVenueIdentification & ivid);

    /**
     * Provide Quotes to initiate
     * HandleQuotes call at matching app.
     *
     * @param viid       Resolved viid.
     *
     * @param quotes     Quotes container.
     */
    void SendQuotes(const Trading::Quotes & quotes, const VIID & viid);

    /**
     * Provide orders to initiate
     * HandleRecovery call at matching app.
     *
     * @param orders     Orders container.
     *
     * @param viid       Resolved viid.
     */
    void SendRecovery(const std::vector<OrderOptions> & orders, const VIID & viid);

    /**
     * Provide Directed Quote Request to initiate
     * HandleDirectedQuoteRequest call at matching app.
     *
     * @param dqr        Directed Quote Request.
     */
    void SendDirectedQuoteRequest(const DirectedQuoteRequestOptions & dqr);

    /**
     * Provide Directed Quote Request Modify Request to initiate
     * HandleDirectedQuoteRequestModify call at matching app.
     *
     * @param dqr        Directed Quote Request.
     */
    void ModifyDirectedQuoteRequest(const DirectedQuoteRequestOptions & dqr);

    /**
     * Provide Directed Quote Request Modify Request to initiate
     * HandleDirectedQuoteRequestDelete call at matching app.
     *
     * @param dqr_id      Directed Quote Request identifier.
     */
    void DeleteDirectedQuoteRequest(const DirectedQuoteRequestIdentifier & dqr_id);

    /**
     * Provide ExPitOptions to initiate
     * HandleExPit call at matching app.
     *
     * @param expit        ExPitOptions.
     */
    void SendExPit(const ExPitOptions & expit);

    /**
     * Provide ExPitIdentifier to initiate
     * HandleExPitDelete call at matching app.
     *
     * @param expit_id      ExPit identifier.
     */
    void DeleteExPit(const ExPitIdentifier & expit_id);

    /**
     * Provide RequestForTradeIdentifier to initiate
     * HandleRequestForTradeDecline call at matching app.
     *
     * @param rft_id      RequestForTrade identifier.
     */
    void DeclineRequestForTrade(const RequestForTradeIdentifier & rft_id);

    /**
     * Provide DirectedQuoteOptions to initiate
     * HandleDirectedQuote call at matching app.
     *
     * @param dq         Directed Quote Options.
     */
    void SendDirectedQuote(const DirectedQuoteOptions & dq);

    /**
     * Provide DirectedQuoteOptions to initiate
     * HandleDirectedQuoteModify call at matching app.
     *
     * @param dq        Directed Quote Options.
     */
    void ModifyDirectedQuote(const DirectedQuoteOptions & dq);

    /**
     * Provide Directed Quote Identifier to initiate
     * HandleDirectedQuoteDelete call at matching app.
     *
     * @param dq_id      Directed Quote identifier.
     */
    void DeleteDirectedQuote(const DirectedQuoteIdentifier & dq_id);

    /**
     * Provide DirectedQuoteOptions to initiate
     * HandleDirectedQuoteReject call at matching app.
     *
     * @param dq        Directed Quote Options.
     */
    void RejectDirectedQuote(const DirectedQuoteOptions & dq);

    //****************************************************************************//
    // Waiting for app actions.                                                   //
    //****************************************************************************//

    /**
     * Wait until AcceptOrder is called from app.
     *
     * @return           Order options.
     *                   It can be empty or contain venue ExtraData
     *                   in the dependence of which method was called.
     */
    OrderOptions WaitOrderAddAccept();

    /**
     * Wait until ModifyOrder is called from app.
     *
     * @return           Order options.
     */
    OrderOptions WaitOrderModify();

    /**
     * Wait until DeleteOrder is called from app.
     *
     * @return           String with reason.
     */
    String WaitOrderDelete();

    /**
     * Wait until FailOrder is called from app.
     *
     * @return           String with reason.
     */
    String WaitOrderFail();

    /**
     * Wait until SendMatch with orders is called from app.
     *
     * @return           Trade options for each Fill.
     */
    Trade WaitOrderFill();

    /**
     * Wait until AcceptOrderModify with orders is called from app.
     *
     * @return           Order options.
     */
    OrderOptions WaitOrderModifyAccept();

    /**
     * Wait until RejectOrderModify is called from app.
     *
     * @return           String with reason.
     */
    String WaitOrderModifyReject();

    /**
     * Wait until AcceptOrderDelete is called from app.
     */
    void WaitOrderDeleteAccept();

    /**
     * Wait until RejectOrderDelete is called from app.
     *
     * @return           String with reason.
     */
    String WaitOrderDeleteReject();

    /**
     * Wait until AcknowledgeQuotes is called from app.
     *
     * @return           Vector of QuoteAcknowledgements.
     */
    std::vector<Trading::QuoteAcknowledgement> WaitQuoteAcknowledgements();

    /**
     * Wait until AcknowledgeQuotes is called from app.
     *
     * @return           Pair of quote id and reason for each fail.
     */
    std::pair<Uuid, String> WaitQuoteError();

    /**
     * Wait until SendMatch with quotes is called from app.
     *
     * @return           Trade options for each Fill.
     */
    Trade WaitQuoteFill();

    /**
     * Wait until DirectedQuoteRequestAccept is called from app.
     *
     * @return           Directed Quote Request options.
     */
    DirectedQuoteRequestOptions WaitDirectedQuoteRequestAccept();

    /**
     * Wait until DirectedQuoteRequestReject is called from app.
     *
     * @return           Reject reason string
     */
    String WaitDirectedQuoteRequestReject();

    /**
     * Wait until DirectedQuoteRequestModifyAccept is called from app.
     *
     * @return           Directed Quote Request options.
     */
    DirectedQuoteRequestOptions WaitDirectedQuoteRequestModifyAccept();

    /**
     * Wait until DirectedQuoteRequestReject is called from app.
     *
     * @return           Reject reason string
     */
    String WaitDirectedQuoteRequestModifyReject();

    /**
     * Wait until DirectedQuoteRequestDeleteAccept is called from app.
     *
     * @return           Directed Quote Request options.
     */
    void WaitDirectedQuoteRequestDeleteAccept();

    /**
     * Wait until DirectedQuoteRequestDeleteReject is called from app.
     *
     * @return           Reject reason string
     */
    String WaitDirectedQuoteRequestDeleteReject();

    /**
     * Wait until SendMatch with quotes is called from app.
     *
     * @return           Trade options for each Fill.
     */
    Trade WaitDirectedQuoteFill();

    /**
     * Wait until CreateDirectedQuoteResponse is called from app.
     *
     * @return           DirectedQuoteResponceOptions.
     */
    DirectedQuoteResponse WaitDirectedResponse();

    /**
     * Wait until ModifyDirectedQuoteResponse is called from app.
     *
     * @return           DirectedQuoteResponseOptions.
     */
    DirectedQuoteResponse WaitDirectedResponseModify();

    /**
     * Wait until ModifyDirectedQuoteResponse is called from app.
     *
     * @return           Reason for DirectedQuoteResponse deletion.
     */
    String WaitDirectedQuoteResponseDelete();

    /**
     * Wait until SendRequestForTrade is called from app.
     *
     * @return           RequestForTrade object.
     */
    RequestForTrade WaitRequestForTrade();

    /**
     * Wait until DeleteRequestForTrade is called from app.
     *
     * @return          RequestForTradeIdentifier
     */
    RequestForTradeIdentifier WaitRequestForTradeDelete();

    /**
     * Wait until RequestForTradeDeclineAccept is called from app.
     *
     */
    void WaitRequestForTradeDeclineAccept();

    /**
     * Wait until RequestForTradeDeclineReject is called from app.
     *
     */
    String WaitRequestForTradeDeclineReject();

    /**
     * Wait until AcceptExPit is called from app.
     *
     */
    void WaitAcceptExPit();

    /**
     * Wait until RejectExPit is called from app.
     *
     * @return          Reject reason
     */
    String WaitRejectExPit();

    /**
     * Wait until DeleteExPit is called from app.
     *
     * @return          Delete reason
     */
    String WaitExPitDelete();

    /**
     * Wait until SendMatch with expits is called from app.
     *
     * @return           Trade options for each Fill.
     */
    Trade WaitExPitFill();

    /**
     * Wait until CreateDirectedRequestForQuote is called from app.
     *
     * @return           DirectedRequestForQuote.
     */
    DirectedRequestForQuoteOptions WaitDirectedRequestForQuote();

public:
    IMatchingEngine(MatchingEngineInterface & ime);
    IMatchingEngine(const IMatchingEngine &) = default;

private:
    IMatchingEngine() = delete;
    MatchingEngineInterface & m_impl;
};

} // namespace pe
} // namespace tbricks
