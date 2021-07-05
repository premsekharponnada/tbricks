#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingAggregatedLimitRule
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Identifier.h"
#include "strategy/type/UserIdentifier.h"
#include "strategy/type/RoleIdentifier.h"
#include "strategy/type/VenueIdentifier.h"
#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/type/InstrumentGroupIdentifier.h"
#include "strategy/type/CFI.h"
#include "strategy/type/CFIMask.h"
#include "strategy/type/Volume.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/Currency.h"

#include <memory>

namespace tbricks {

namespace protocol {
class AggregatedLimitRule;
}

/**
 * TradingAggregatedLimitRule
 */

class STRATEGY_EXPORT TradingAggregatedLimitRule : public Printable
{
public:
    TradingAggregatedLimitRule();
    TradingAggregatedLimitRule(const TradingAggregatedLimitRule & limitrule);
    TradingAggregatedLimitRule(TradingAggregatedLimitRule && limitrule) noexcept;
    TradingAggregatedLimitRule & operator=(const TradingAggregatedLimitRule & limitrule);
    TradingAggregatedLimitRule & operator=(TradingAggregatedLimitRule && limitrule) noexcept;
    virtual ~TradingAggregatedLimitRule();

    TradingAggregatedLimitRule(const protocol::AggregatedLimitRule & limitrule);
    TradingAggregatedLimitRule & operator=(const protocol::AggregatedLimitRule & limitrule);

    bool operator<(const TradingAggregatedLimitRule & limitrule) const;

    /// Limit ID
    void SetIdentifier(const Identifier & id);
    bool GetIdentifier(Identifier & id) const;
    bool HasIdentifier() const;

    void SetProviderIdentifier(const Identifier & provider_id);
    bool GetProviderIdentifier(Identifier & provider_id) const;
    bool HasProviderIdentifier() const;

    void SetPortfolioIdentifier(const PortfolioIdentifier & portfolio_id);
    bool GetPortfolioIdentifier(PortfolioIdentifier & portfolio_id) const;
    bool HasPortfolioIdentifier() const;

    void SetInstrumentGroupIdentifier(const InstrumentGroupIdentifier & group_id);
    bool GetInstrumentGroupIdentifier(InstrumentGroupIdentifier & group_id) const;
    bool HasInstrumentGroupIdentifier() const;

    /// @deprecated Deprecated in 2.14.0, use SetCFIMask(const CFIMask & value)
    [[deprecated(DEPRECATE_LINK)]] void SetCFI_Mask(const CFI & cfi_mask);
    /// @deprecated Deprecated in 2.14.0, use GetCFIMask(CFIMask & value)
    [[deprecated(DEPRECATE_LINK)]] bool GetCFI_Mask(CFI & cfi_mask) const;
    /// @deprecated Deprecated in 2.14.0, use HasCFIMask()
    [[deprecated(DEPRECATE_LINK)]] bool HasCFI_Mask() const;

    void SetCFIMask(const CFIMask & value);
    bool GetCFIMask(CFIMask & value) const;
    bool HasCFIMask() const;

    void SetBidAggregatedVolumeLimit(const Volume & limit);
    bool GetBidAggregatedVolumeLimit(Volume & limit) const;
    bool HasBidAggregatedVolumeLimit() const;

    void SetAskAggregatedVolumeLimit(const Volume & limit);
    bool GetAskAggregatedVolumeLimit(Volume & limit) const;
    bool HasAskAggregatedVolumeLimit() const;

    void SetResetFilledVolumes(const Boolean & reset);
    bool GetResetFilledVolumes(Boolean & limit) const;
    bool HasResetFilledVolumes() const;

    void SetNetCashValueLimit(const Double & limit);
    bool GetNetCashValueLimit(Double & limit) const;
    bool HasNetCashValueLimit() const;

    void SetCashValueLimit(const Double & limit);
    bool GetCashValueLimit(Double & limit) const;
    bool HasCashValueLimit() const;

    void SetCurrency(const Currency & currency);
    bool GetCurrency(Currency & currency) const;
    bool HasCurrency() const;

    void SetCreator(const UserIdentifier & creator);
    bool GetCreator(UserIdentifier & creator) const;
    bool HasCreator() const;

    void SetRole(const RoleIdentifier & role);
    bool GetRole(RoleIdentifier & role) const;
    bool HasRole() const;

    void SetInstrument(const InstrumentIdentifier & instrument);
    bool GetInstrument(InstrumentIdentifier & instrument) const;
    bool HasInstrument() const;

    void SetVenue(const VenueIdentifier & venue);
    bool GetVenue(VenueIdentifier & venue) const;
    bool HasVenue() const;

    void Clear();
    std::ostream & Print(std::ostream & strm) const override;
    protocol::AggregatedLimitRule & get_value() const;

private:
    std::unique_ptr<protocol::AggregatedLimitRule> m_limitrule;
};
}
