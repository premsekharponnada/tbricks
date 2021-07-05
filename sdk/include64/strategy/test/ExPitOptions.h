#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExPit Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Strategy.h"

#include "strategy/ExPit.h"
#include "strategy/type/AnyType.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/TransactionState.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/InstrumentTradingInformation.h"

#include "strategy_generated/TestExPitOptionsBase.h"

namespace tbricks { namespace test {

/**
 * ExPitOptions
 */
class STRATEGY_EXPORT ExPitOptions : public TestExPitOptionsBase
{
public:
    typedef protocol::Expit expit_t;

public:
    ExPitOptions() = default;
    ExPitOptions(const protocol::Expit & expit) : TestExPitOptionsBase(expit) {}

public:
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasAgreementDatetime() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] DateTime GetAgreementDatetime() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetAgreementDatetime(const DateTime & agreement_datetime);

    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasAveragePaid() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] Double GetAveragePaid() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetAveragePaid(const Double & average_paid);

    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasCurrency() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] Currency GetCurrency() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetCurrency(const Currency & value);

    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasExPitRegulation() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] ExPit::Regulation GetExPitRegulation() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetExPitRegulation(const ExPit::Regulation & regulation);

    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasExPitSides() const;
    /// @deprecated Deprecated in 2.14.6, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] std::vector<ExPit::Side> GetExPitSides() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetExPitSides(const std::vector<ExPit::Side> & sides);

    bool HasExPitType() const;
    ExPit::Type GetExPitType() const;
    void SetExPitType(const ExPit::Type & type);

    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasFilledVolume() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] Volume GetFilledVolume() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetFilledVolume(const Volume & filled_volume);

    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasInstrumentVenueIdentification() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] InstrumentVenueIdentification GetInstrumentVenueIdentification() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasMMTFlags() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] MMTFlags GetMMTFlags() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetMMTFlags(const MMTFlags & value);

    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasPrice() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] Price GetPrice() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetPrice(const Price & price);

    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasSettlementDate() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] DateTime GetSettlementDate() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetSettlementDate(const DateTime & datetime);

    bool HasTradingCapacity() const;
    ExPit::TradingCapacity GetTradingCapacity() const;
    void SetTradingCapacity(const ExPit::TradingCapacity & capacity);

    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasVenueInstrumentIdentifier() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] VenueInstrumentIdentifier GetVenueInstrumentIdentifier() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetVenueInstrumentIdentifier(const VenueInstrumentIdentifier & viid);

    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] bool HasVolume() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] Volume GetVolume() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] void SetVolume(const Volume & volume);

    void SetRequestForTradeIdentifier(const RequestForTradeIdentifier & id);

    /**
     * Check expit options for emptiness.
     *
     * @return                          True if expit options is empty, false otherwise.
     */
    bool Empty() const;

    virtual std::ostream & Print(std::ostream & strm) const;

    void Merge(const ExPitOptions & options);

public:
    expit_t get_expit() const;

private:
    expit_t * m_expit;
    ExPitDeal m_deal;
};

} // namespace test

} // namespace tbricks
