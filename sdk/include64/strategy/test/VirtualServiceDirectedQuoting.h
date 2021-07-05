#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceDirectedQuoting is a
// system virtual Directed quoting service.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/test/IVirtualService.h"
#include "DirectedQuoteOptions.h"
#include "DirectedRequestForQuoteOptions.h"

namespace tbricks { namespace test {
class DQImpl;

class STRATEGY_EXPORT VirtualServiceDirectedQuoting : public IVirtualService
{
public:
    /**
     * Get venue identifier of service.
     *
     * @return           Venue identifier.
     */
    VenueIdentifier GetVenueId() const;

    DirectedQuoteOptions WaitDirectedQuoteCreateRequest();

    DirectedQuoteOptions WaitDirectedQuoteModifyRequest();

    DirectedQuoteOptions WaitDirectedQuoteRejectRequest();

    DirectedQuoteOperation WaitDirectedQuoteDeleteRequest();

    DirectedRequestForQuoteOptions WaitDirectedRequestForQuoteCreateRequest();

    DirectedRequestForQuoteOptions WaitDirectedRequestForQuoteModifyRequest();

    DirectedRequestForQuoteOptions WaitDirectedRequestForQuoteDeleteRequest();

    void UpdateDirectedQuote(const DirectedQuoteOptions & options);

    void DeleteDirectedQuote(const DirectedQuoteOperation & operation);

    void UpdateDirectedRequestForQuote(const DirectedRequestForQuoteOptions & options);

    void DeleteDirectedRequestForQuote(const DirectedRequestForQuoteOptions & options);

public:
    /**
     * VirtualServiceDirectedQuoting constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceDirectedQuoting(DQImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceDirectedQuoting();

private:
    VirtualServiceDirectedQuoting() = delete;
    VirtualServiceDirectedQuoting(const VirtualServiceDirectedQuoting &) = delete;
    VirtualServiceDirectedQuoting & operator=(const VirtualServiceDirectedQuoting &) = delete;
    DQImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks