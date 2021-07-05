#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Market message object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/stream/Stream.h"

#include "strategy/type/Venue.h"
#include "strategy/Instrument.h"

#include <memory>

namespace tbricks {

namespace protocol {
class MarketMessage;
}

class STRATEGY_EXPORT MarketMessage : public Printable
{
public:
    class Stream;

public:
    MarketMessage();
    MarketMessage(const MarketMessage & market_message);
    MarketMessage(MarketMessage && market_message);
    virtual ~MarketMessage();
    MarketMessage & operator=(const MarketMessage & market_message);
    MarketMessage & operator=(MarketMessage && market_message);

    /**
     * Find out when message was created on an exchange.
     *
     * @return                          exchange created datetime
     */
    DateTime GetExchangeCreatedDatetime() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasExchangeCreatedDatetime() const;

    /**
     * Find out when a message was created.
     * This is the date and time a market message was created within the system.
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDatetime() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasHostCreatedDatetime() const;

    /*
     * MIME type enumeration
     */
    enum MIMEType
    {
        TEXT_HTML = 0,
        TEXT_PLAIN,
        TEXT_XML,
        INVALID
    };

    /**
     * Get MIME type of the message
     *
     * @return                          message's MIMEType
     */
    MIMEType GetMessageMIMEType() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasMessageMIMEType() const;

    /**
     * Get text message.
     *
     * @return                          message text
     */
    String GetMessageText() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasMessageText() const;

    /**
     * Get message title.
     *
     * @return                          message title
     */
    String GetMessageTitle() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasMessageTitle() const;

    enum Urgency
    {
        UrgencyLow = 1,
        UrgencyNormal = 2,
        UrgencyHigh = 3
    };

    /**
     * Get urgency of a text message
     *
     * @return                          Urgency of a text message.
     */
    bool GetMessageUrgency(Urgency & urgency) const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasMessageUrgency() const;

    /**
     * Get instrument.
     *
     * @return                          instrument identifier
     */
    Instrument GetInstrument() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasInstrument() const;

    /**
     * Get venue.
     *
     * @return                          venue identifier
     */
    Venue GetVenue() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasVenue() const;

    /**
     * Time of the first market message pertaining to the full story.
     *
     * @return                          Time of the first market message pertaining to the full story.
     */
    DateTime GetStoryDatetime() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasStoryDatetime() const;

    /**
     * The native identifier of the full story provided by the news provider.
     *
     * @return                          The native identifier of the full story provided by the news provider
     */
    String GetStoryIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasStoryIdentifier() const;

    /**
     * Boolean indicating that this message is a repetition of a previosly sent message
     *
     * @return                          Boolean indicating that this message is repetition of an already sent message.
     */
    Boolean GetDuplicateMessage() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasDuplicateMessage() const;

    /**
     * Provider of the actual message.
     *
     * @return                          Provider of the actual message.
     */
    String GetMessageProvider() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasMessageProvider() const;

    /**
     * Source of the news.
     *
     * @return                          Source of the news.
     */
    String GetMessageSource() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasMessageSource() const;

    /**
     * All classifications of the news by the provider.
     *
     * @return                          All classifications of the news by the provider.
     */
    StringDictionary GetMessageClassifications() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasMessageClassifications() const;

    /**
     * Identifier allowing to uniquely identify a message at the venue.
     *
     * @return                          Identifier allowing to uniquely identify a message at the venue.
     */
    String GetVenueMessageIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasVenueMessageIdentifier() const;

    /**
     * Boolean indicating that this message has been deleted
     *
     * @return                          Field indicating if a given item is deleted
     */
    Boolean GetDeleted() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasDeleted() const;

    /**
     * Check object for emptiness.
     *
     * @return                          True if object is empty, false otherwise.
     */
    bool Empty() const;

    /**
     * Clear object.
     *
     */
    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    MarketMessage(std::shared_ptr<protocol::MarketMessage> market_messag);

private:
    std::shared_ptr<protocol::MarketMessage> m_market_message;
};
}
