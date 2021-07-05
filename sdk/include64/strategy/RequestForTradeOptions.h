#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForTradeOptions
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/RequestForTradeLeg.h"
#include "strategy_generated/RequestForTradeOptionsBase.h"

namespace tbricks {

class STRATEGY_EXPORT RequestForTradeOptions : public RequestForTradeOptionsBase
{
public:
    RequestForTradeOptions();
    ~RequestForTradeOptions() = default;

public:
    /**
     * This ctor is supposed to be used as constructor.
     *
     * @throws Exceptions if Instrument does not exist
     * @param  InstrumentVenueIdentification        ivid
     */
    RequestForTradeOptions(const InstrumentVenueIdentification & ivid);

    /**
     * This method is supposed to be used to set side.
     *
     * @param Side                                  side
     */
    void SetSide(const Side & side);

    /**
     * This method is supposed to be used to set set price.
     *
     * @throws Exception if price is empty
     * @param Price                                price
     */
    void SetPrice(const Price & price);

    /**
     * This method is supposed to be used to set set volume.
     *
     * @throws Exception if volume is empty
     * @param Volume                               volume
     */
    void SetVolume(const Volume & volume);

    RequestForTradeIdentifier GetIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend class Trading;
    protocol::RequestForTrade get_rft() const;
    void set_rft_id();

private:
    RequestForTradeLeg m_leg;
};
}
