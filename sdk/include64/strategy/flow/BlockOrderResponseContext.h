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
class BlockOrderIdentifier;
class Status;
class String;

namespace protocol {
class BlockOrderRequestReply;
}

class STRATEGY_EXPORT BlockOrderResponseContext : public Printable
{
public:
    BlockOrderResponseContext();

public:
    /**
     * Returns request identifier of the request being processed.
     */
    bool GetRequestIdentifier(Identifier & id) const;

    /**
     * Returns order's identifier
     */
    bool GetBlockOrderIdentifier(BlockOrderIdentifier & id) const;

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
    BlockOrderResponseContext(std::shared_ptr<protocol::BlockOrderRequestReply> msg);
    protocol::BlockOrderRequestReply * get_impl() const;

private:
    std::shared_ptr<protocol::BlockOrderRequestReply> m_msg;
};
}
