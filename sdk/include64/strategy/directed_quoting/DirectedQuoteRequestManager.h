#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteRequestManager
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Strategy.h"
#include "strategy/directed_quoting/DirectedQuoteRequest.h"
#include "strategy/directed_quoting/DirectedQuoteResponse.h"

namespace tbricks {

namespace pe {
class DQRCache;
}

class STRATEGY_EXPORT DirectedQuoteRequestManager
{
public:
    class STRATEGY_EXPORT DirectedQuoteRequestResult
    {
    public:
        DirectedQuoteRequestResult();
        DirectedQuoteRequestResult(const Identifier & request_id, const DirectedQuoteIdentifier & directed_quote_id) :
            m_request_id(request_id),
            m_directed_quote_id(directed_quote_id)
        {}

        const Identifier & GetRequestIdentifier() const { return m_request_id; }

        const DirectedQuoteIdentifier & GetDirectedQuoteIdentifier() const { return m_directed_quote_id; }

        /** @deprecated Deprecated in 2.14.5 */
        [[deprecated(DEPRECATE_LINK)]] bool Empty() const { return m_request_id.Empty() && m_directed_quote_id.Empty(); }

            /** @deprecated Deprecated in 2.14.5 */
            [[deprecated(DEPRECATE_LINK)]] void Clear()
        {
            m_request_id.Clear();
            m_directed_quote_id.Clear();
        }

    private:
        Identifier m_request_id;
        DirectedQuoteIdentifier m_directed_quote_id;
    };

public:
    DirectedQuoteRequestManager();
    virtual ~DirectedQuoteRequestManager();

    DirectedQuoteRequestManager(const DirectedQuoteRequestManager & src) = delete;
    DirectedQuoteRequestManager & operator=(const DirectedQuoteRequestManager & src) = delete;

public:
    /**
     * Create directed quote request.
     * Engine subscribes for request and response for passed directed quote request.
     *
     * @param options                   Directed quote request options
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          Request result
     */
    DirectedQuoteRequestResult SendCreateRequest(const DirectedQuoteRequest::Options & options,
                                                 IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Modify directed quote request.
     *
     * @param modifier                  Direcetd quote request modifier
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          RequestIdentifier
     */
    Identifier SendModifyRequest(const DirectedQuoteRequestIdentifier & id,
                                 const DirectedQuoteRequest::Modifier & request,
                                 IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Delete directed quote request and stops propagating its responses
     * (directed quote response) into the system.
     *
     * @param id                        %Identifier of directed quote request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Request identifier
     */
    Identifier SendDeleteRequest(const DirectedQuoteRequestIdentifier & request, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    //  recovery
public:
    bool StartRecovery(const InitializationReason & reason);
    bool InRecovery() const { return m_recovery; }

public:
    virtual void HandleDirectedQuoteResponseUpdate(const DirectedQuoteResponse & response) = 0;

    virtual void HandleDirectedQuoteRequestUpdate(const DirectedQuoteRequest & update) = 0;

    virtual void HandleRecoveryCompleted() = 0;

public:
    void complete_recovery();

private:
    bool m_recovery = false;
};
}
