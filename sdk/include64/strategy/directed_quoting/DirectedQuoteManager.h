#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteManager
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Strategy.h"
#include "strategy/directed_quoting/DirectedQuote.h"

namespace tbricks {

class DirectedQuoteReject;

class STRATEGY_EXPORT DirectedQuoteManager
{
public:
    class STRATEGY_EXPORT DirectedQuoteCreateRequestResult
    {
    public:
        DirectedQuoteCreateRequestResult() = default;
        DirectedQuoteCreateRequestResult(const Identifier & request_id, const DirectedQuoteIdentifier & dq_id, const MIC & mic) :
            m_request_id(request_id),
            m_dq_id(dq_id),
            m_mic(mic)
        {}

        const Identifier & GetRequestIdentifier() const { return m_request_id; }
        const DirectedQuoteIdentifier & GetDirectedQuoteIdentifier() const { return m_dq_id; }
        const MIC & GetMIC() const { return m_mic; }

        /** @deprecated Deprecated in 2.14.5 */
        [[deprecated(DEPRECATE_LINK)]] bool Empty() const { return m_request_id.Empty() && m_dq_id.Empty(); }

            /** @deprecated Deprecated in 2.14.5 */
            [[deprecated(DEPRECATE_LINK)]] void Clear()
        {
            m_request_id.Clear();
            m_dq_id.Clear();
            m_mic.Clear();
        }

    private:
        Identifier m_request_id;
        DirectedQuoteIdentifier m_dq_id;
        MIC m_mic;
    };

public:
    DirectedQuoteManager();
    virtual ~DirectedQuoteManager();

    DirectedQuoteCreateRequestResult
    SendCreateRequest(const DirectedQuoteRequestIdentifier & quote_request_id, DirectedQuote::Options & options, IRequestReplyHandler & handler);

    Identifier
    SendModifyRequest(const DirectedQuoteIdentifier & directed_quote_id, const DirectedQuote::Modifier & modifier, IRequestReplyHandler & handler);

    Identifier SendDeleteRequest(const DirectedQuoteIdentifier & directed_quote_id, IRequestReplyHandler & handler);

    Identifier RejectRequestForQuote(const DirectedQuoteReject & value, IRequestReplyHandler & handler);

public:
    virtual void HandleDirectedQuoteUpdate(const DirectedQuote & update) = 0;

    virtual void HandleRecoveryCompleted() = 0;

public:
    bool StartRecovery(const InitializationReason & reason);
    bool InRecovery() const { return m_recovery; }

    void complete_recovery();

private:
    DirectedQuoteManager(const DirectedQuoteManager & src);
    DirectedQuoteManager & operator=(const DirectedQuoteManager & src);

private:
    bool m_recovery = false;
};

} // \namespace tbricks
