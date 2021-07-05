#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Pricing
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/Strategy.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/pricing/InstrumentCalculatedValueDefinition.h"
#include "strategy/type/Uuid.h"
#include "strategy/type/Table.h"
#include "strategy/Pair.h"
#include "strategy/stream/InstrumentStream.h"
#include "strategy/stream_throttle/CommonThrottle.h"
#include "strategy/pricing/PricingRequest.h"
#include "strategy/pricing/CalculatedValuesRequest.h"
#include "strategy/pricing/CalculatedValuesRequestUpdate.h"
#include "strategy/pricing/CalculatedValuesRequestFull.h"
#include "strategy/MemoryGuard.h"

namespace tbricks {

class STRATEGY_EXPORT Pricing : public Plugin
{
public:
    Pricing(const PricingRequest & request);
    virtual ~Pricing();

    void Update(const CalculatedValueIdentifier & value_id, const TypeWithError & value);

    bool Has(const CalculatedValueIdentifier & value_id) const;

    bool HasRow(const Uuid & row_id) const;

    bool Send();

    void SnapshotDone();

    /**
     *
     * Notifies the engine that the app has processed all of the pending modification requests.
     * If metadata of the app does not explicitly state that the app supports such a notification mechanism,
     * this method is triggered automatically upon receiving of any modification request.
     *
     */
    void SendModifyRequestDone();

    const BasicThrottle & GetMarketDataThrottle() const;
    const BasicThrottle & GetInstrumentParametersThrottle() const;

    const Identifier & GetParameterContext() const;
    const Identifier & GetParameterContextRanking() const;

    const MemoryHandler & GetTableValuesMemory() const;

    void GetLastSentMessageString(String & message) const;

    virtual void HandlePricingModifyRequest(const PricingModifyRequest & request) = 0;
    virtual bool HandlePartialPricingModifyRequest(const CalculatedValuesRequestUpdate &) { return false; }

    const CalculatedValuesRequestFull & GetFullCalculatedValuesRequest() const;

    const InstrumentStream::Filters::Filter & GetInstrumentFilter() const;

    Stream::Type GetSubscriptionType() const;

    bool DeletedShouldBePriced() const;

public:
    virtual void HandleScheduledEvent(UserData && data);

    virtual std::ostream & Print(std::ostream & strm) const;

    void GetOwner(User & user) const;
    UserIdentifier GetOwner() const;
    void SetOwner(const UserIdentifier & uid);
    void SetOwner(const User & user);
    UserIdentifier GetCreator() const;
    void GetCreator(User & user) const;

    StrategyIdentifier GetIdentifier() const;

private:
    Pricing();
    Pricing & operator=(const Pricing &);
    Pricing(const Pricing &);

private:
    class Impl;
    Impl * m_impl;
};
}
