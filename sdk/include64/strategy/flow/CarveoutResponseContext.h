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
class CarveoutIdentifier;
class Status;
class String;

namespace protocol {
class CarveoutRequestReply;
}

/**
 * When IStrategyEventHandler::HandleCarveoutResponse() is called, CarveoutResponseContext object
 * contains status and status text extracted from the the RequestReply.
 *
 * @see IStrategyEventHandler::HandleCarveoutResponse()
 */
class STRATEGY_EXPORT CarveoutResponseContext : public Printable
{
public:
    CarveoutResponseContext();

public:
    /**
     * Returns request identifier of the request being processed.
     */
    bool GetRequestIdentifier(Identifier & id) const;

    /**
     * Returns carveouts's identifier
     */
    bool GetCarveoutIdentifier(CarveoutIdentifier & id) const;

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
    CarveoutResponseContext(std::shared_ptr<protocol::CarveoutRequestReply> msg);
    protocol::CarveoutRequestReply * get_impl() const;

private:
    std::shared_ptr<protocol::CarveoutRequestReply> m_msg;
};
}
