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
class OrderIdentifier;
class Status;
class String;

namespace protocol {
class OrderRequestReply;
}

class STRATEGY_EXPORT OrderResponseContext : public Printable
{
public:
    OrderResponseContext();

public:
    /**
     * Returns request identifier of the request being processed.
     */
    bool GetRequestIdentifier(Identifier & id) const;

    /**
     * Returns order's identifier
     */
    bool GetOrderIdentifier(OrderIdentifier & id) const;

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
    OrderResponseContext(std::shared_ptr<protocol::OrderRequestReply> msg);
    protocol::OrderRequestReply * get_impl() const;

private:
    std::shared_ptr<protocol::OrderRequestReply> m_msg;
};
}
