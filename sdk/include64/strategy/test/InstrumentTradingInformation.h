#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentTradingInformation is used to setup additional
// instrument information. Includes InstrumentTradingInformation
// and TickRule.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/VenueInstrumentIdentifier.h"
#include "strategy/type/Volume.h"
#include "strategy/type/Currency.h"
#include "strategy/type/Price.h"

namespace tbricks {

namespace protocol {
class InstrumentTradingInformation;
}
namespace types {
class TickRule;
}

namespace test {

class STRATEGY_EXPORT InstrumentTradingInformation : public Printable
{
public:
    typedef std::vector<std::pair<Double, Double>> TickRuleItems;
    /**
     * Constructor.
     *
     * Constructs an empty object.
     */
    InstrumentTradingInformation();

    /**
     * Copy constructor.
     */
    InstrumentTradingInformation(const test::InstrumentTradingInformation & info);

    virtual ~InstrumentTradingInformation();

    InstrumentTradingInformation & operator=(const test::InstrumentTradingInformation & info);

public:
    /**
     * Fields acceptors.
     */
    bool HasCurrency() const;
    Currency GetCurrency() const;
    void SetCurrency(const Currency & currency);

    bool HasVolumeIncrement() const; // used to be LotSize
    Volume GetVolumeIncrement() const;
    void SetVolumeIncrement(const Volume & volume);

    bool HasLotVolume() const;
    Volume GetLotVolume() const;
    void SetLotVolume(const Volume & volume);

    bool HasMaximumPrice() const;
    Price GetMaximumPrice() const;
    void SetMaximumPrice(const Price & price);

    bool HasMinimumPrice() const;
    Price GetMinimumPrice() const;
    void SetMinimumPrice(const Price & price);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMaximumMatchPrice() const;

    /**
     * Get maximum match price.
     *
     *
     * @return                          maximum match price
     */
    Price GetMaximumMatchPrice() const;

    /**
     * %Set maximum match price.
     *
     *
     * If the passed value is empty, the field in the request
     * will be deleted.
     *
     * @param price                     maximum match price
     */
    void SetMaximumMatchPrice(const Price & price);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMinimumMatchPrice() const;

    /**
     * Get minimum match price.
     *
     *
     * @return                          minimum match price
     */
    Price GetMinimumMatchPrice() const;

    /**
     * %Set minimum match price.
     *
     *
     * If the passed value is empty, the field in the request
     * will be deleted.
     *
     * @param price                     minimum match price
     */
    void SetMinimumMatchPrice(const Price & price);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMaximumAllowedPrice() const;

    /**
     * Get maximum allowed price.
     *
     *
     * @return                          maximum allowed price
     */
    Price GetMaximumAllowedPrice() const;

    /**
     * %Set maximum allowed price.
     *
     *
     * If the passed value is empty, the field in the request
     * will be deleted.
     *
     * @param price                     maximum allowed price
     */
    void SetMaximumAllowedPrice(const Price & price);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMinimumAllowedPrice() const;

    /**
     * Get minimum allowed price.
     *
     *
     * @return                          minimum allowed price
     */
    Price GetMinimumAllowedPrice() const;

    /**
     * %Set minimum allowed price.
     *
     *
     * If the passed value is empty, the field in the request
     * will be deleted.
     *
     * @param price                     minimum allowed price
     */
    void SetMinimumAllowedPrice(const Price & price);

    bool HasMinimumVolume() const;
    Volume GetMinimumVolume() const;
    void SetMinimumVolume(const Volume & volume);

    bool HasMinimumDisclosedVolume() const;
    Volume GetMinimumDisclosedVolume() const;
    void SetMinimumDisclosedVolume(const Volume & volume);

    bool HasPriceCorrectionFactor() const;
    Price GetPriceCorrectionFactor() const;
    void SetPriceCorrectionFactor(const Price & factor);

    bool HasCircuitBreakerPrice() const;
    Price GetCircuitBreakerPrice() const;
    void SetCircuitBreakerPrice(const Price & price);

    bool HasMinimumBookOrCancelVolume() const;
    Volume GetMinimumBookOrCancelVolume() const;
    void SetMinimumBookOrCancelVolume(const Volume & volume);

    /**
     * TickRule fileds.
     */
    Price GetDefaultTick(Price & price) const;
    void SetDefaultTick(const Price & price);

    Price GetPrecision() const;
    void SetPrecision(const Price & price);

    void GetTickRuleItems(TickRuleItems & items) const;
    void SetTickRuleItems(const TickRuleItems & items);

public:
    /**
     * Clear object.
     *
     * Object is considered empty after this call.
     */
    void Clear();

    bool Empty() const;

    const protocol::InstrumentTradingInformation & get_iti() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    types::TickRule * m_tick_rule;
    protocol::InstrumentTradingInformation * m_msg;
};

} // \namespace test
} // \namespace tbricks
