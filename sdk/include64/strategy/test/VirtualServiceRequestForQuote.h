#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceRequestForQuote is a
// system virtual Request for quote service.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/test/IVirtualService.h"
#include "RequestForQuoteOptions.h"

namespace tbricks { namespace test {
class RFQImpl;

class STRATEGY_EXPORT VirtualServiceRequestForQuote : public IVirtualService
{
public:
    /**
     * Get venue identifier of service.
     *
     * @return           Venue identifier.
     */
    VenueIdentifier GetVenueId() const;

    RequestForQuoteOptions WaitRequestForQuoteCreateRequest();

    RequestForQuoteOperation WaitRequestForQuoteDeleteRequest();

    void UpdateRequestForQuote(const RequestForQuoteOptions & options);

    void DeleteRequestForQuote(const RequestForQuoteOperation & operation);

public:
    /**
     * VirtualServiceDirectedQuoteRequest constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceRequestForQuote(RFQImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceRequestForQuote();

private:
    VirtualServiceRequestForQuote() = delete;
    VirtualServiceRequestForQuote(const VirtualServiceRequestForQuote &) = delete;
    VirtualServiceRequestForQuote & operator=(const VirtualServiceRequestForQuote &) = delete;
    RFQImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks