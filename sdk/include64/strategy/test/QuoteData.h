#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteData.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Strategy.h"
#include "strategy/Hash.h"

#include <iomanip>

namespace tbricks { namespace test {

class STRATEGY_EXPORT QuoteData : public Printable
{
public:
    enum class QuoteStatus
    {
        OK = 0,
        NO_TICK_RULE = 1,
        TRADING_NOT_ALLOWED = 2,
        NOT_ENOUGH_VOLUME = 3,
        TOO_MUCH_VOLUME = 4,
        EXPOSURE_LIMIT_CHECK_FAILED = 5,
        DESIRED_VOLUME_LESS_THAN_MINIMUM = 6,
        DISABLED = 7,
        COALESCING = 8
    };

public:
    QuoteData(const Identifier & id, const Price & bid, const Price & ask, const Volume & bid_volume, const Volume & ask_volume);

    QuoteData();

    Identifier GetQuoteIdentifier() const;

    Price GetBidPrice() const;

    Price GetAskPrice() const;

    Volume GetBidVolume() const;

    Volume GetAskVolume() const;

    QuoteStatus GetBidStatus() const;

    QuoteStatus GetAskStatus() const;

    void SetQuoteIdentifier(const Identifier & identifier);

    void SetBidPrice(const Price & bid_price);

    void SetAskPrice(const Price & ask_price);

    void SetBidVolume(const Volume & bid_volume);

    void SetAskVolume(const Volume & ask_volume);

    void SetBidStatus(const QuoteStatus & bid_status);

    void SetAskStatus(const QuoteStatus & ask_status);

    std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

private:
    Identifier m_identifier;
    Price m_bid_price;
    Price m_ask_price;
    Volume m_bid_volume;
    Volume m_ask_volume;
    QuoteStatus m_bid_status = QuoteStatus::OK;
    QuoteStatus m_ask_status = QuoteStatus::OK;
};

using CurrentQuotesData = Hash<Identifier, QuoteData>;

}}