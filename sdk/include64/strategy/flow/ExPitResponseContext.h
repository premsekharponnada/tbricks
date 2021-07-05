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
class ExPitIdentifier;
class Status;
class String;

namespace protocol {
class ExpitRequestReply;
}

/**
 * When IStrategyEventHandler::HandleExPitResponse() is called, ExPitResponseContext object
 * contains status and status text extracted from the the RequestReply.
 *
 * @see IStrategyEventHandler::HandleExPitResponse()
 */
class STRATEGY_EXPORT ExPitResponseContext : public Printable
{
public:
    ExPitResponseContext();

public:
    /**
     * Returns request identifier of the request being processed.
     */
    bool GetRequestIdentifier(Identifier & id) const;

    /**
     * Returns carveouts's identifier
     */
    bool GetExPitIdentifier(ExPitIdentifier & id) const;

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
    ExPitResponseContext(std::shared_ptr<protocol::ExpitRequestReply> msg);
    protocol::ExpitRequestReply * get_impl() const;

private:
    std::shared_ptr<protocol::ExpitRequestReply> m_msg;
};
}
