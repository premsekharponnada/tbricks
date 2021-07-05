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

namespace tbricks {

class Identifier;
class DirectedQuoteIdentifier;
class Status;
class String;

namespace protocol {
class DirectedQuoteRequestReply;
}

/**
 * When IStrategyEventHandler::HandleDirectedQuoteResponse() is called, DirectedQuoteResponseContext object
 * contains status and status text extracted from the the RequestReply.
 *
 * @see IStrategyEventHandler::HandleDirectedQuoteResponse()
 */
class STRATEGY_EXPORT DirectedQuoteResponseContext : public Printable
{
public:
    DirectedQuoteResponseContext();

public:
    /**
     * Returns request identifier of the request being processed.
     */
    bool GetRequestIdentifier(Identifier & id) const;

    /**
     * Returns carveouts's identifier
     */
    bool GetDirectedQuoteIdentifier(DirectedQuoteIdentifier & id) const;

    /**
     * Get Status code
     */
    bool GetStatus(Status & status) const;

    /**
     * Get Status text
     */
    bool GetStatusText(String & status_text) const;

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    DirectedQuoteResponseContext(std::shared_ptr<protocol::DirectedQuoteRequestReply> msg);
    protocol::DirectedQuoteRequestReply * get_impl() const;

private:
    std::shared_ptr<protocol::DirectedQuoteRequestReply> m_msg;
};
}
