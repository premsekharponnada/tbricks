#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceExpitTrading is a system virtual Expit Trading service.
//****************************************************************************************

#include "strategy/test/IVirtualService.h"
#include "strategy/test/ExPitOptions.h"
#include "strategy/test/RequestForTradeOptions.h"
#include "strategy/ExPit.h"

namespace tbricks { namespace test {
class ETImpl;

class STRATEGY_EXPORT VirtualServiceExpitTrading : public IVirtualService
{
public:
    /**
     * Get venue identifier of service.
     *
     * @return           Venue identifier.
     */
    VenueIdentifier GetVenueId() const;

    /**
     * Wait until an expit is created or modified.
     *
     * @return           ExPitOptions.
     */
    ExPitOptions WaitExpitRequest();

    /**
     * Wait until an expit is deleted or declined.
     *
     * @return           ExPitOptions.
     */
    ExPitOptions WaitExpitDeleteRequest();

    /**
     * Wait until an request for trade is created or modified.
     *
     * @return           RequestForTradeOptions.
     */
    RequestForTradeOptions WaitRequestForTradeRequest();

    /**
     * Wait until an request for trade is deleted or declined.
     *
     * @return           RequestForTradeOperation.
     */
    RequestForTradeOperation WaitRequestForTradeDeleteRequest();

    /**
     * Send expit update.
     *
     * @param update     ExPit Update.
     */
    void UpdateExpit(const ExPitOptions & update);

    /**
     * Send request for trade update.
     *
     * @param update     RequestForTrade Update.
     */
    void UpdateRequestForTrade(const test::RequestForTradeOptions & update);

    /**
     * Send request for trade delete.
     *
     * @param operation     RequestForTrade Operation.
     */
    void DeleteRequestForTrade(const test::RequestForTradeOperation & operation);

    enum UpdateTypeValue
    {
        ExpitRequestType = 1,
        ExpitDeleteRequestType = 2
    };

public:
    /**
     * VirtualServiceExpitTrading constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceExpitTrading(ETImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceExpitTrading();

private:
    VirtualServiceExpitTrading() = delete;
    VirtualServiceExpitTrading(const VirtualServiceExpitTrading & is) = delete;
    VirtualServiceExpitTrading & operator=(const VirtualServiceExpitTrading &) = delete;
    ETImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks
