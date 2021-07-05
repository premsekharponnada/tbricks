#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingLimitRuleRequest
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Identifier.h"
#include "strategy/type/VenueIdentifier.h"

namespace tbricks {

/*
 * TradingLimitRuleRequest class represents a request
 * for trading limit rules.
 *
 * To indicate a situation when the limit provider
 * has sent all rules, Completed() must be called.
 *
 * @see TradingLimitRuleProvider
 */
class STRATEGY_EXPORT TradingLimitRuleRequest : public Printable
{
public:
    TradingLimitRuleRequest();

    /**
     * Constructor
     *
     * @param request_id                Identifier of the request
     * @param warmup_request_id         Identifier of warmup related to
     *                                  this request
     * @param venue_id                  Identifier of a venue for which
     *                                  limits should be provided
     */
    TradingLimitRuleRequest(const Identifier & request_id, const Identifier & warmup_request_id = {}, const VenueIdentifier & venue_id = {});

    TradingLimitRuleRequest(const TradingLimitRuleRequest & request);
    TradingLimitRuleRequest & operator=(const TradingLimitRuleRequest & request);

    ~TradingLimitRuleRequest() override;

    /**
     * Get request identifier
     *
     * @return                          request identifier
     */
    const Identifier & GetIdentifier() const;

    /**
     * Get venue identifier
     *
     * Return venue identifier of a service
     * requested limit rules.
     *
     * If venue identifier empty limit provider
     * should send rules for all venues.
     *
     * @return                          venue identifier
     */
    const VenueIdentifier & GetVenueIdentifier() const;

    /**
     * Get warmup identifier
     *
     * Retruns identifier of warmup related to
     * this request.
     *
     * @return                          warmup identifier
     */
    const Identifier & GetWarmupIdentifier() const;

    /*
     * Mark request as complited
     *
     * A limit provider must call this method after
     * it sent all rules for this request.
     */
    void Completed() const;

    bool operator<(const TradingLimitRuleRequest & request) const;

    std::ostream & Print(std::ostream & strm) const override;

private:
    Identifier m_request_id;
    VenueIdentifier m_venue_id;
    Identifier m_warmup_request_id;
};
}
