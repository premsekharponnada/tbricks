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
class StrategyIdentifier;
class Status;
class String;

namespace protocol {
class StrategyRequestReply;
}

/**
 * When IStrategyEventHandler::HandleAppResponse() is called, AppResponseContext object
 * contains status and status text extracted from the the RequestReply.
 *
 * @see IStrategyEventHandler::HandleAppResponse()
 */
class STRATEGY_EXPORT AppResponseContext : public Printable
{
public:
    AppResponseContext();

public:
    /**
     * Returns request identifier of the request being processed.
     */
    bool GetRequestIdentifier(Identifier & id) const;

    /**
     * Returns app's identifier
     */
    bool GetAppIdentifier(StrategyIdentifier & id) const;

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
    AppResponseContext(std::shared_ptr<protocol::StrategyRequestReply> msg);
    protocol::StrategyRequestReply * get_impl() const;

private:
    std::shared_ptr<protocol::StrategyRequestReply> m_msg;
};
}
