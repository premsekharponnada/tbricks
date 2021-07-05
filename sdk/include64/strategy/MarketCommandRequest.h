#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Market command
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Strategy.h"

#include <memory>

namespace tbricks {

namespace protocol {
class MarketCommandRequest;
}

class InstrumentVenueIdentification;
class MarketCommandType;
class ExtraData;

/**
 * MarketCommandCapabilities allows to sends market command
 * to a venue
 */
class STRATEGY_EXPORT MarketCommandRequest : public Printable
{
public:
    /**
     * Default constructor
     *
     * Creates empty object
     */
    MarketCommandRequest();

    /**
     * Destructor
     */
    ~MarketCommandRequest() override;

    /**
     * Copy constructor
     *
     * @param o                  MarketCommandCapabilities
     */
    MarketCommandRequest(const MarketCommandRequest & o);

    /**
     * Copy assignment operator
     *
     * @param o                  MarketCommandCapabilities
     */
    MarketCommandRequest & operator=(const MarketCommandRequest & o);

public:
    /**
     * Send market command request.
     *
     * Method sends a market command to a venue.
     *
     * Market command create request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param options                   Request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Unique request identifier
     */
    static Identifier SendCreateRequest(const MarketCommandRequest & options, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

public:
    /**
     * Set instrument venue identification
     *
     * If value is empty, the field will be deleted from request.
     *
     * @param ivid                     Instrument venue identification
     */
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    /**
     * Set venue
     *
     * If value is empty, the field will be deleted from request.
     *
     * @param venue                    Venue
     */
    void SetVenue(const Venue & venue);

    /**
     * Set type of market command
     *
     * If value is empty, the field will be deleted from request.
     *
     * @param type                     Market command type
     */
    void SetType(const MarketCommandType & type);

    /**
     * Set extra data
     *
     * @param data                     Extra data
     */
    void SetExtraData(const ExtraData & data);

public:
    /**
     * Put string representation of MarketCommandRequest to ostream.
     *
     * @return                      ostream
     */
    std::ostream & Print(std::ostream & strm) const override;

private:
    std::unique_ptr<protocol::MarketCommandRequest> m_msg;
};
}
