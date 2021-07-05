#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PricingRequest
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Types.h"
#include "strategy/SafePointer.h"
#include "strategy/parameter/StrategyParameters.h"
#include "strategy/pricing/InstrumentCalculatedValueDefinition.h"
#include "strategy/pricing/CalculatedValuesRequest.h"
#include "strategy/pricing/CalculatedValuesRequestFull.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/Hash.h"
#include "strategy/Printable.h"
#include <vector>
#include <memory>

namespace tbricks {

namespace subscription {
class Stream;
}
namespace types {
class CalculatedValuesRequest;
}

class Pricing;

class STRATEGY_EXPORT PricingRequest : public Printable
{
public:
    PricingRequest();
    PricingRequest(const PricingRequest & request);
    PricingRequest(subscription::Stream * stream);
    virtual ~PricingRequest();

    PricingRequest & operator=(const PricingRequest & request);

    void GetIVIDs(Hash<Uuid, InstrumentVenueIdentification> & rows) const;

    const CalculatedValuesRequestFull & GetFullCalculatedValuesRequest() const;

    virtual std::ostream & Print(std::ostream & strm) const;

    friend class Pricing;

private:
    tbricks::subscription::Stream * get_stream() const;

private:
    class Impl;
    mutable std::unique_ptr<Impl> m_impl;
};

namespace subscription {
class StreamOpenRequest;
class StreamModifyRequest;
}

class STRATEGY_EXPORT PricingModifyRequest : public Printable
{
public:
    PricingModifyRequest();
    PricingModifyRequest(const PricingModifyRequest & request);
    PricingModifyRequest(const subscription::StreamOpenRequest & open_request, const subscription::StreamModifyRequest & modify_request);
    virtual ~PricingModifyRequest();

    PricingModifyRequest & operator=(const PricingModifyRequest & request);

    Uuid HasValue(const InstrumentCalculatedValueDefinition & definition) const;

    void GetIVIDs(Hash<Uuid, InstrumentVenueIdentification> & rows) const;

    const SafePointer<types::CalculatedValuesRequest> & get_request() const;

    const Hash<Uuid, std::pair<Uuid, StrategyParameters>> & get_values() const;

    const CalculatedValuesRequestFull & GetFullCalculatedValuesRequest() const;

    virtual std::ostream & Print(std::ostream & strm) const;

    friend class Pricing;

private:
    class Impl;
    mutable std::unique_ptr<Impl> m_impl;
};
}
