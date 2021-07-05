#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceDirectedQuoteRequest is a
// system virtual Directed quote request service.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/test/IVirtualService.h"
#include "DirectedQuoteRequestOptions.h"

namespace tbricks { namespace test {
class DQRImpl;

class STRATEGY_EXPORT VirtualServiceDirectedQuoteRequest : public IVirtualService
{
public:
    /**
     * Get venue identifier of service.
     *
     * @return           Venue identifier.
     */
    VenueIdentifier GetVenueId() const;

    DirectedQuoteRequestOptions WaitDirectedQuoteRequesCreateRequest();

    DirectedQuoteRequestOptions WaitDirectedQuoteRequesModifyRequest();

    DirectedQuoteRequestOperation WaitDirectedQuoteRequesDeleteRequest();

    void UpdateDirectedQuoteRequest(const DirectedQuoteRequestOptions & options);

    void DeleteDirectedQuoteRequest(const DirectedQuoteRequestOperation & operation);

public:
    /**
     * VirtualServiceDirectedQuoteRequest constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceDirectedQuoteRequest(DQRImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceDirectedQuoteRequest();

private:
    VirtualServiceDirectedQuoteRequest() = delete;
    VirtualServiceDirectedQuoteRequest(const VirtualServiceDirectedQuoteRequest &) = delete;
    VirtualServiceDirectedQuoteRequest & operator=(const VirtualServiceDirectedQuoteRequest &) = delete;
    DQRImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks
