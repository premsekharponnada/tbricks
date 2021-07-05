#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingLimitRuleUpdate
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/limit/TradingLimitRule.h"
#include "strategy/User.h"
#include "strategy/Types.h"
#include "strategy/ExtraData.h"
#include "strategy/InstrumentVenueIdentification.h"

namespace tbricks {

namespace protocol {
class LimitRule;
}

/**
 * Update.
 */
class STRATEGY_EXPORT TradingLimitRule::Update : public Printable
{
public:
    Update();
    Update(const TradingLimitRule::Update & limitrule);
    Update(std::shared_ptr<protocol::LimitRule> limitrule);
    Update & operator=(const TradingLimitRule::Update & limitrule);
    virtual ~Update();

    bool GetIdentifier(Identifier & id) const;
    bool HasIdentifier() const;

    class STRATEGY_EXPORT Filter
    {
    public:
        bool GetInstrumentIdentifier(InstrumentIdentifier & instrument_id) const;
        bool HasInstrumentIdentifier() const;

        bool GetInstrumentVenueIdentification(InstrumentVenueIdentification & ivid) const;
        bool HasInstrumentVenueIdentification() const;

        bool GetCreator(UserIdentifier & creator_id) const;
        bool GetCreator(User & creator_id) const;
        bool HasCreator() const;

        bool GetOwner(UserIdentifier & owner_id) const;
        bool GetOwner(User & owner_id) const;
        bool HasOwner() const;

        bool GetSide(Side & side) const;
        bool HasSide() const;

        bool GetPortfolioIdentifier(PortfolioIdentifier & portfolio_id) const;
        bool HasPortfolioIdentifier() const;

        bool GetCurrency(Currency & currency) const;
        bool HasCurrency() const;

        bool GetVenueIdentifier(VenueIdentifier & venue_id) const;
        bool HasVenueIdentifier() const;

        bool GetRoleIdentifier(RoleIdentifier & id) const;
        bool HasRoleIdentifier() const;

        bool GetStrategyDefinitionIdentifier(Identifier & id) const;
        bool HasStrategyDefinitionIdentifier() const;

        bool GetExtraData(ExtraData & extra_data) const;
        bool HasExtraData() const;

        /**
         * Get mic condition
         *
         * This field is not a part of InstrumentVenueIdentification field
         * and should be handled separately
         *
         * @param mic[out]                  MIC
         * @return                          True if mic is set, false otherwise
         */
        bool GetMIC(MIC & mic) const;

        /**
         * Check if MIC condition is set
         *
         * This field is not a part of InstrumentVenueIdentification field
         * and should be handled separately
         *
         * @return                          True if mic is set, false otherwise
         */
        bool HasMIC() const;

        void Clear();

    private:
        friend class Update;
        Filter(std::shared_ptr<protocol::LimitRule> msg);
        std::shared_ptr<protocol::LimitRule> m_msg;
    };

    Filter GetFilter() const;

    class STRATEGY_EXPORT Limit
    {
    public:
        bool GetMaxPrice(Price & price) const;
        bool HasMaxPrice() const;

        bool GetSoftMaxPrice(Price & price) const;
        bool HasSoftMaxPrice() const;

        bool GetMinPrice(Price & price) const;
        bool HasMinPrice() const;

        bool GetSoftMinPrice(Price & price) const;
        bool HasSoftMinPrice() const;

        bool GetVolume(Volume & volume) const;
        bool HasVolume() const;

        bool GetSoftVolume(Volume & volume) const;
        bool HasSoftVolume() const;

        bool GetAtMarketVolume(Volume & volume) const;
        bool HasAtMarketVolume() const;

        /**
         * Get soft volume limit for at market orders
         *
         * Returns maximum allowed volume for at market orders.
         *
         * @param [out]                     Maximum volume
         * @return                          True if field is set, false otherwise
         */
        bool GetAtMarketSoftVolume(Volume & volume) const;

        /**
         * Check soft volume limit for at market orders is set
         *
         * @return                          True if field is set, false otherwise
         */
        bool HasAtMarketSoftVolume() const;

        bool GetShortSellVolume(Volume & cash_value) const;
        bool HasShortSellVolume() const;

        bool GetCashValue(Double & cash_value) const;
        bool HasCashValue() const;

        bool GetSoftCashValue(Double & cash_value) const;
        bool HasSoftCashValue() const;

        bool GetNetPosition(Volume & net_position) const;
        bool HasNetPosition() const;

        void Clear();

    private:
        friend class Update;
        Limit(std::shared_ptr<protocol::LimitRule> msg);
        std::shared_ptr<protocol::LimitRule> m_msg;
    };

    Limit GetLimit() const;

    void Clear();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    bool GetProviderIdentifier(Identifier & provider_id) const;
    bool HasProviderIdentifier() const;

private:
    friend class TradingLimitRule;
    const std::shared_ptr<protocol::LimitRule> & get_value() const;

private:
    std::shared_ptr<protocol::LimitRule> m_msg;
};
}
