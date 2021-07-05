#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceTradingReferenceData is a
// system virtual TradingReferenceData service.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/test/InstrumentTradingInformation.h"
#include "strategy/test/IVirtualService.h"

namespace tbricks { namespace test {
class TRDImpl;

class STRATEGY_EXPORT VirtualServiceTradingReferenceData : public IVirtualService
{
public:
    typedef std::vector<std::pair<Double, Double>> TickRuleItems;

    /**
     * Get venue identifier of service.
     *
     * @return           Venue identifier.
     */
    VenueIdentifier GetVenueId() const;

    /**
     * Create TRD information for VenueInstrumentIdentifier.
     *
     * @param viid       Venue instrument identifier.
     *
     * @param iti        Instrument Trading Information.
     */
    void CreateInstrumentTradingInformation(const VenueInstrumentIdentifier & viid, const test::InstrumentTradingInformation & iti);

public:
    /**
     * VirtualServiceTradingReferenceData constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceTradingReferenceData(TRDImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceTradingReferenceData();

private:
    VirtualServiceTradingReferenceData() = delete;
    VirtualServiceTradingReferenceData(const VirtualServiceTradingReferenceData &) = delete;
    VirtualServiceTradingReferenceData & operator=(const VirtualServiceTradingReferenceData &) = delete;
    TRDImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks
