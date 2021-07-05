#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingLimitRule
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/User.h"
#include "strategy/Types.h"
#include "strategy/ExtraData.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/type/TradingMessageType.h"

#include <memory>

namespace tbricks {

namespace protocol {
class LimitRule;
}

/**
 * TradingLimitRule.
 *
 * The TradingLimitRule object represents a single limit rule, each of which is checked for each
 * transaction.
 *
 * A TradingLimitRule object has two parts, "Filter" and "Limit", available via the corresponding
 * GetFilter() and GetLimit() accessors. The filter defines which transactions will be checked by
 * this rule based on conditions. The limit part represents the condition that will be evaluated
 * for an order.
 *
 * From the viewpoint of a limit rule provider, there is a difference between instrument-based
 * rules; those that have an instrument as part of the filter, and "general" rules; those that do
 * not have an instrument as a part of the filter
 */
class STRATEGY_EXPORT TradingLimitRule : public Printable
{
public:
    class Stream;
    class Update;

public:
    TradingLimitRule();
    TradingLimitRule(const TradingLimitRule & limitrule);
    TradingLimitRule(TradingLimitRule && limitrule) noexcept;
    TradingLimitRule & operator=(const TradingLimitRule & limitrule);
    TradingLimitRule & operator=(TradingLimitRule && limitrule) noexcept;
    virtual ~TradingLimitRule();

    TradingLimitRule(const protocol::LimitRule & limitrule);
    TradingLimitRule & operator=(const protocol::LimitRule & limitrule);

    /**
     * Compare identifiers of the rules
     *
     * @param limitrule
     * @return                          true if the identifier of this rule less than
     *                                  identifier of the \p limitrule , false otherwise
     */
    bool operator<(const TradingLimitRule & limitrule) const;

    /**
     * Set identifier
     *
     * If \p id is empty method unsets this field from the object
     *
     * @param id                       identifier
     */
    void SetIdentifier(const Identifier & id);

    /**
     * Get identifier
     *
     * @param id[out]                   identifier of the rule
     * @return                          true if value is set, false otherwise
     */
    bool GetIdentifier(Identifier & id) const;

    /**
     * Check if identifier is set
     *
     * @return                          true if value is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Set reject reason
     *
     * A text what will be shown in status text on transaction
     * when it breaches this limit rule
     *
     * If \p reason is empty method unsets this field from the object
     *
     * @param reason                    new reject reason
     */
    void SetRejectReason(const String & reason);

    /**
     * Get the Reject Reason object
     *
     * A text what will be shown in status text on transaction
     * when it breaches this limit rule
     *
     * @param reason[out]               reject reason text
     * @return                          true if value is set, false otherwise
     */
    bool GetRejectReason(String & reason) const;

    /**
     * Check if reject reason is set
     *
     * @return                          true if value is set, false otherwise
     */
    bool HasRejectReason() const;

    /**
     * Set parent limit identifier
     *
     * Identifier of the limit which is overridden by this rule.
     *
     * @param id                        Parent limit identifier
     */
    void SetParentIdentifier(const Identifier & id);

    /**
     * Get parent limit identifier
     *
     * Identifier of the limit which is overridden by this rule.
     *
     * @param id[out]                   Parent limit identifier
     * @return                          true if value is set, false otherwise
     */
    bool GetParentIdentifier(Identifier & id) const;

    /**
     * Check if parent limit identifier is set
     *
     * Identifier of the limit which is overridden by this rule.
     *
     * @return                          true if value is set, false otherwise
     */
    bool HasParentIdentifier() const;

    /**
     * Filter.
     */
    class STRATEGY_EXPORT Filter
    {
    public:
        /**
         * Set instrument identifier condition
         *
         * Defines to which instrument should a limit rule be applied.
         * Empty means that a rule applies to all instruments.
         *
         * If \p instrument_id is empty method unsets this field from the object
         *
         * @param reason                    new reject reason
         */
        void SetInstrumentIdentifier(const InstrumentIdentifier & instrument_id);

        /**
         * Get instrument identifier condition
         *
         * Defines to which instrument should a limit rule be applied.
         * Empty means that a rule applies to all instruments.
         *
         * @param instrument_id[out]        instrument identifier
         * @return                          true if value is set, false otherwise
         */
        bool GetInstrumentIdentifier(InstrumentIdentifier & instrument_id) const;

        /**
         * Check if instrument identifier condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasInstrumentIdentifier() const;

        /**
         * Set instrument venue identifier condition
         *
         * Defines to which ivids should a limit rule be applied.
         * Empty means that a rule applies to any ivids.
         *
         * If \p ivid is empty method unsets this field from the object
         *
         * @deprecated Use SetInstrumentIdentifier(), SetVenue() and SetMIC() instead
         *             Deprecated in 2.14.6
         *
         * @param reason                    new reject reason
         */
        [[deprecated(DEPRECATE_LINK)]] bool SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

        /**
         * Get instrument venue identifier condition
         *
         * Defines to which ivids should a limit rule be applied.
         * Empty means that a rule applies to any ivids.
         *
         * @param ivid[out]               reject reason text
         * @return                        true if value is set, false otherwise
         */
        bool GetInstrumentVenueIdentification(InstrumentVenueIdentification & ivid) const;

        /**
         * Check if instrument venue identifier condition is set
         *
         * @return                        true if value is set, false otherwise
         */
        bool HasInstrumentVenueIdentification() const;

        /**
         * Set creator condition
         *
         * Defines to which creator should a limit rule be applied.
         * Empty means that a rule applies to any creator.
         *
         * If \p creator_id is empty method unsets this field from the object
         *
         * @param creator_id                creator identifier
         */
        void SetCreator(const UserIdentifier & creator_id);

        /**
         * Set creator condition
         *
         * Defines to which creator should a limit rule be applied.
         * Empty means that a rule applies to any creator.
         *
         * If \p creator is empty method unsets this field from the object
         *
         * @param creator                   creator
         */
        void SetCreator(const User & creator);

        /**
         * Get creator condition
         *
         * Defines to which creator should a limit rule be applied.
         * Empty means that a rule applies to any creator.
         *
         * @param creator_id[out]           creator identifier
         * @return                          true if value is set, false otherwise
         */
        bool GetCreator(UserIdentifier & creator_id) const;

        /**
         * Get creator condition
         *
         * Defines to which creator should a limit rule be applied.
         * Empty means that a rule applies to any creator.
         *
         * @param creator[out]              creator
         * @return                          true if value is set, false otherwise
         */
        bool GetCreator(User & creator) const;

        /**
         * Check if creator condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasCreator() const;

        /**
         * Set owner condition
         *
         * Defines to which owner should a limit rule be applied.
         * Empty means that a rule applies to any owners.
         *
         * If \p owner_id is empty method unsets this field from the object
         *
         * @param owner_id                  owner identifier
         */
        void SetOwner(const UserIdentifier & owner_id);

        /**
         * Set owner condition
         *
         * Defines to which owner should a limit rule be applied.
         * Empty means that a rule applies to any owners.
         *
         * If \p owner is empty method unsets this field from the object
         *
         * @param reason                    owner identifier
         */
        void SetOwner(const User & owner);

        /**
         * Get owner condition
         *
         * Defines to which owner should a limit rule be applied.
         * Empty means that a rule applies to any owners.
         *
         * @param owner_id[out]             owner identifier
         * @return                          true if value is set, false otherwise
         */
        bool GetOwner(UserIdentifier & owner_id) const;

        /**
         * Get owner condition
         *
         * Defines to which owner should a limit rule be applied.
         * Empty means that a rule applies to any owners.
         *
         * @param owner_id[out]             owner identifier
         * @return                          true if value is set, false otherwise
         */
        bool GetOwner(User & owner_id) const;

        /**
         * Check if owner condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasOwner() const;

        /**
         * Set side condition
         *
         * Defines to which side should a limit rule be applied.
         * Empty means that a rule applies to any side.
         *
         * If \p side is empty method unsets this field from the object
         *
         * @param side                    side
         */
        void SetSide(const Side & side);

        /**
         * Get side condition
         *
         * Defines to which side should a limit rule be applied.
         * Empty means that a rule applies to any side.
         *
         * @param side[out]                 side
         * @return                          true if value is set, false otherwise
         */
        bool GetSide(Side & side) const;

        /**
         * Check if side condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasSide() const;

        /**
         * Set portfolio condition
         *
         * Defines to which portfolio should a limit rule be applied.
         * Empty means that a rule applies to any portfolio.
         *
         * If \p portfolio_id is empty method unsets this field from the object
         *
         * @param portfolio_id              portfolio identifier
         */
        void SetPortfolioIdentifier(const PortfolioIdentifier & portfolio_id);

        /**
         * Get portfolio condition
         *
         * Defines to which portfolio should a limit rule be applied.
         * Empty means that a rule applies to any portfolio.
         *
         * @param portfolio_id[out]         portfolio identifier
         * @return                          true if value is set, false otherwise
         */
        bool GetPortfolioIdentifier(PortfolioIdentifier & portfolio_id) const;

        /**
         * Check if portfolio condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasPortfolioIdentifier() const;

        /**
         * Set client condition
         *
         * Defines to which client should a limit rule be applied.
         * Empty means that a rule applies to any client.
         *
         * If \p client is empty method unsets this field from the object
         *
         * @param client                    client identifier
         */
        void SetClient(const TreeNodeIdentifier & client);

        /**
         * Get client condition
         *
         * Defines to which client should a limit rule be applied.
         * Empty means that a rule applies to any client.
         *
         * @param client[out]               client identifier
         * @return                          true if value is set, false otherwise
         */
        bool GetClient(TreeNodeIdentifier & client) const;

        /**
         * Check if client condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasClient() const;

        /**
         * Set currency condition
         *
         * Defines to which currency should a limit rule be applied.
         * Empty means that a rule applies to any currency.
         *
         * If \p currency is empty method unsets this field from the object
         *
         * @param currency                  currency
         */
        void SetCurrency(const Currency & currency);

        /**
         * Get currency condition
         *
         * Defines to which currency should a limit rule be applied.
         * Empty means that a rule applies to any currency.
         *
         * @param currency[out]             currency
         * @return                          true if value is set, false otherwise
         */
        bool GetCurrency(Currency & currency) const;

        /**
         * Check if currency condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasCurrency() const;

        /**
         * Set venue condition
         *
         * Defines to which venue should a limit rule be applied.
         * Empty means that a rule applies to any venue.
         *
         * If \p venue_id is empty method unsets this field from the object
         *
         * @param venue_id                  venue identifier
         */
        void SetVenueIdentifier(const VenueIdentifier & venue_id);

        /**
         * Get venue condition
         *
         * Defines to which venue should a limit rule be applied.
         * Empty means that a rule applies to any venue.
         *
         * @param venue_id[out]             venue identifier
         * @return                          true if value is set, false otherwise
         */
        bool GetVenueIdentifier(VenueIdentifier & venue_id) const;

        /**
         * Check if venue condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasVenueIdentifier() const;

        /**
         * Set role condition
         *
         * Defines to which role of owner should a limit rule be applied.
         * Empty means that a rule applies to any roles.
         *
         * If \p role_id is empty method unsets this field from the object
         *
         * @param role_id                    role identifier
         */
        void SetRoleIdentifier(const RoleIdentifier & role_id);

        /**
         * Get role condition
         *
         * Defines to which role of owner should a limit rule be applied.
         * Empty means that a rule applies to any roles.
         *
         * @param role_id[out]              role identifier
         * @return                          true if value is set, false otherwise
         */
        bool GetRoleIdentifier(RoleIdentifier & role_id) const;

        /**
         * Check if role condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasRoleIdentifier() const;

        /**
         * Set strategy definition conditon
         *
         * Defines to which strategy type should a limit rule be applied.
         * Empty means that a rule applies to any strategy definitions.
         *
         * If \p id is empty method unsets this field from the object
         *
         * @param id                        strategy definition identifier
         */
        void SetStrategyDefinitionIdentifier(const Identifier & id);

        /**
         * Get strategy definition conditon
         *
         * Defines to which strategy type should a limit rule be applied.
         * Empty means that a rule applies to any strategy definitions.
         *
         * @param id[out]                   strategy definition identifier
         * @return                          true if value is set, false otherwise
         */
        bool GetStrategyDefinitionIdentifier(Identifier & id) const;

        /**
         * Check if strategy definition conditon is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasStrategyDefinitionIdentifier() const;

        /**
         * Set extra data condition
         *
         * Defines to which extra data key-values should a limit rule be applied.
         * Empty means that a rule applies to any key-values.
         *
         * If \p instrument_id is empty method unsets this field from the object
         *
         * @param extra_data                extra data
         */
        void SetExtraData(const ExtraData & extra_data);

        /**
         * Get extra data condition
         *
         * Defines to which extra data key-values should a limit rule be applied.
         * Empty means that a rule applies to any key-values.
         *
         * @param extra_data[out]           extra data
         * @return                          true if value is set, false otherwise
         */
        bool GetExtraData(ExtraData & extra_data) const;

        /**
         * Check if extra data condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasExtraData() const;

        /**
         * Set MIC condition
         *
         * Defines to which MIC should a limit rule be applied.
         * Empty means that a rule applies to any MICs.
         *
         * If \p mic is empty method unsets this field from the object
         *
         * @param mic                       mic
         */
        void SetMIC(const MIC & mic);

        /**
         * Get MIC condition
         *
         * Defines to which MIC should a limit rule be applied.
         * Empty means that a rule applies to any MICs.
         *
         * @param mic[out]                  mic
         * @return                          true if value is set, false otherwise
         */
        bool GetMIC(MIC & mic) const;

        /**
         * Check if MIC condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasMIC() const;

        /// @deprecated Deprecated in 2.14.0, use SetCFIMask(const CFIMask & value)
        [[deprecated(DEPRECATE_LINK)]] void SetCFI(const CFI & cfi);
        /// @deprecated Deprecated in 2.14.0, use GetCFIMask(CFIMask & value)
        [[deprecated(DEPRECATE_LINK)]] bool GetCFI(CFI & cfi) const;
        /// @deprecated Deprecated in 2.14.0, use HasCFIMask()
        [[deprecated(DEPRECATE_LINK)]] bool HasCFI() const;

        /**
         * Set CFI mask condition
         *
         * Defines to which CFI codes should a limit rule be applied.
         * Empty means that a rule applies to any CFI codes.
         *
         * If \p mask is empty method unsets this field from the object
         *
         * @param mask                      cfi mask
         */
        void SetCFIMask(const CFIMask & mask);

        /**
         * Get CFI mask condition
         *
         * Defines to which CFI codes should a limit rule be applied.
         * Empty means that a rule applies to any CFI codes.
         *
         * @param mask[out]                 cfi mask
         * @return                          true if value is set, false otherwise
         */
        bool GetCFIMask(CFIMask & mask) const;

        /**
         * Check if CFI mask condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasCFIMask() const;

        /**
         * Set trading message type condition
         *
         * Defines to which trading message type should a limit rule be applied.
         * Empty means that a rule applies to any trading message types.
         *
         * If \p value is empty method unsets this field from the object
         *
         * @param value                     trading message type
         */
        void SetTradingMessageType(const std::optional<TradingMessageType> & value);

        /**
         * Get trading message type condition
         *
         * Defines to which trading message type should a limit rule be applied.
         * Empty means that a rule applies to any trading message types.
         *
         * @param value[out]                trading message type
         * @return                          true if value is set, false otherwise
         */
        bool GetTradingMessageType(std::optional<TradingMessageType> & value) const;

        /**
         * Check if trading message type condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasTradingMessageType() const;

        /**
         * Set counterpart condition
         *
         * Defines to which counterpart should a limit rule be applied.
         * Empty means that a rule applies to any counterparts.
         *
         * If \p counterpart_id is empty method unsets this field from the object
         *
         * @param counterpart_id            counterpart identifier
         */
        void SetCounterpartIdentifier(const TreeNodeIdentifier & client);

        /**
         * Get counterpart condition
         *
         * Defines to which counterpart should a limit rule be applied.
         * Empty means that a rule applies to any counterparts.
         *
         * @param counterpart_id[out]       counterpart identifier
         * @return                          true if value is set, false otherwise
         */
        bool GetCounterpartIdentifier(TreeNodeIdentifier & counterpart_id) const;

        /**
         * Check if counterpart condition is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasCounterpartIdentifier() const;

        /**
         * Clear all filter fields
         */
        void Clear();

    private:
        friend class TradingLimitRule;
        Filter(TradingLimitRule & rule);
        TradingLimitRule & m_rule;
    };

    /**
     * Get filter
     *
     * @return                          reference to the filter
     */
    Filter & GetFilter();

    /**
     * Get filter
     *
     * @return                          reference to the filter
     */
    const Filter & GetFilter() const;

    /// Limit
    class STRATEGY_EXPORT Limit
    {
    public:
        /**
         * Set max price
         *
         * Maximum allowed price of a single transaction.
         *
         * If \p price is empty method unsets this field from the object
         *
         * @param price                     max price
         */
        void SetMaxPrice(const Price & price);

        /**
         * Get max price
         *
         * Maximum allowed price of a single transaction.
         *
         * @param price[out]                max price
         * @return                          true if value is set, false otherwise
         */
        bool GetMaxPrice(Price & price) const;

        /**
         * Check if max price is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasMaxPrice() const;

        /**
         * Set soft max price
         *
         * Maximum allowed price of a single transaction.
         * This limit can be bypassed if "Bypass soft limits" flag is present
         * in the transaction.
         *
         * If \p price is empty method unsets this field from the object
         *
         * @param price                     max price
         */
        void SetSoftMaxPrice(const Price & price);

        /**
         * Get soft max price
         *
         * Maximum allowed price of a single transaction.
         * This limit can be bypassed if "Bypass soft limits" flag is present
         * in the transaction.
         *
         * @param price[out]                max price
         * @return                          true if value is set, false otherwise
         */
        bool GetSoftMaxPrice(Price & price) const;

        /**
         * Check if soft max price is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasSoftMaxPrice() const;

        /**
         * Set min price
         *
         * Minimum allowed price of a single transaction.
         *
         * If \p price is empty method unsets this field from the object
         *
         * @param price                     min price
         */
        void SetMinPrice(const Price & price);

        /**
         * Get min price
         *
         * Minimum allowed price of a single transaction.
         *
         * @param price[out]                min price
         * @return                          true if value is set, false otherwise
         */
        bool GetMinPrice(Price & price) const;

        /**
         * Check if min price is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasMinPrice() const;

        /**
         * Set soft min price
         *
         * Minimum allowed price of a single transaction.
         * This limit can be bypassed if "Bypass soft limits" flag is present
         * in the transaction.
         *
         * If \p price is empty method unsets this field from the object
         *
         * @param price                     min price
         */
        void SetSoftMinPrice(const Price & price);

        /**
         * Get soft min price
         *
         * Minimum allowed price of a single transaction.
         * This limit can be bypassed if "Bypass soft limits" flag is present
         * in the transaction.
         *
         * @param price[out]                min price
         * @return                          true if value is set, false otherwise
         */
        bool GetSoftMinPrice(Price & price) const;

        /**
         * Check if soft min price is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasSoftMinPrice() const;

        /**
         * Set volume
         *
         * Maximum allowed volume of a single transaction.
         *
         * If \p volume is empty method unsets this field from the object
         *
         * @param volume                    volume
         */
        void SetVolume(const Volume & volume);

        /**
         * Get volume
         *
         * Maximum allowed volume of a single transaction.
         *
         * @param volume[out]               volume
         * @return                          true if value is set, false otherwise
         */
        bool GetVolume(Volume & volume) const;

        /**
         * Check volume is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasVolume() const;

        /**
         * Set soft volume
         *
         * Maximum allowed volume of a single transaction.
         * This limit can be bypassed if "Bypass soft limits" flag is present
         * in the transaction.
         *
         * If \p volume is empty method unsets this field from the object
         *
         * @param volume                    volume
         */
        void SetSoftVolume(const Volume & volume);

        /**
         * Get soft volume
         *
         * Maximum allowed volume of a single transaction.
         * This limit can be bypassed if "Bypass soft limits" flag is present
         * in the transaction.
         *
         * @param reason[out]               reject reason text
         * @return                          true if value is set, false otherwise
         */
        bool GetSoftVolume(Volume & volume) const;

        /**
         * Check if soft volume is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasSoftVolume() const;

        /**
         * Set at market volume
         *
         * Maximum allowed volume of a single at market order
         *
         * If \p volume is empty method unsets this field from the object
         *
         * @param volume                    volume
         */
        void SetAtMarketVolume(const Volume & volume);

        /**
         * Get at market volume
         *
         * Maximum allowed volume of a single at market order
         *
         * @param volume[out]               volume
         * @return                          true if value is set, false otherwise
         */
        bool GetAtMarketVolume(Volume & volume) const;

        /**
         * Check if at market volume is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasAtMarketVolume() const;

        /**
         * Set at market soft volume limit
         *
         * Sets maximum allowed volume for at market orders.
         *
         * If \p volume is empty method unsets this field from the object
         *
         * @param volume                    Maximum volume
         */
        void SetAtMarketSoftVolume(const Volume & volume);

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

        /**
         * Set short sell volume
         *
         * If \p volume is empty method unsets this field from the object
         *
         * @param volume                    volume
         */
        void SetShortSellVolume(const Volume & volume);

        /**
         * Get short sell volume
         *
         * @param volume[out]               volume
         * @return                          true if value is set, false otherwise
         */
        bool GetShortSellVolume(Volume & volume) const;

        /**
         * Get short sell volume
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasShortSellVolume() const;

        /**
         * Set cash value
         *
         * Maximum allowed cash value of a single transaction.
         *
         * @param cash_value                cash value
         */
        void SetCashValue(const Double & cash_value);

        /**
         * Get cash value
         *
         * Maximum allowed cash value of a single transaction.
         *
         * @param cash_value[out]           cash value
         * @return                          true if value is set, false otherwise
         */
        bool GetCashValue(Double & cash_value) const;

        /**
         * Check if cash value is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasCashValue() const;

        /**
         * Set soft cash value
         *
         * Maximum allowed cash value of a single transaction.
         * This limit can be bypassed if "Bypass soft limits" flag is present
         * in the transaction.
         *
         * If \p cash_value is empty method unsets this field from the object
         *
         * @param cash_value                cash value
         */
        void SetSoftCashValue(const Double & cash_value);

        /**
         * Get soft cash value
         *
         * Maximum allowed cash value of a single transaction.
         * This limit can be bypassed if "Bypass soft limits" flag is present
         * in the transaction.
         *
         * @param cash_value[out]           cash value
         * @return                          true if value is set, false otherwise
         */
        bool GetSoftCashValue(Double & cash_value) const;

        /**
         * Check soft cash value is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasSoftCashValue() const;

        /**
         * Set net position
         *
         * If \p net_position is empty method unsets this field from the object
         *
         * @param net_position              new reject reason
         */
        void SetNetPosition(const Volume & net_position);

        /**
         * Get net position
         *
         * @param net_position[out]         net position
         * @return                          true if value is set, false otherwise
         */
        bool GetNetPosition(Volume & net_position) const;

        /**
         * Check if net position is set
         *
         * @return                          true if value is set, false otherwise
         */
        bool HasNetPosition() const;

        /**
         * Clear all filter fields
         */
        void Clear();

    private:
        friend class TradingLimitRule;
        Limit(TradingLimitRule & rule);
        TradingLimitRule & m_rule;
    };

    friend class TradingLimitRule::Limit;

    /**
     * Get limit
     *
     * @return                          reference to the limit
     */
    Limit & GetLimit();

    /**
     * Get limit
     *
     * @return                          reference to the limit
     */
    const Limit & GetLimit() const;

    /**
     * Clear all contents from the limit rule.
     */
    void Clear();

    /**
     * Merge limit rule update.
     *
     * @param update                limit rule update
     */
    void Merge(const Update & update);

private:
    void PrintLimit(std::ostream & strm) const;
    void PrintFilter(std::ostream & strm) const;

public:
    std::ostream & Print(std::ostream & strm) const override;

public:
    void SetProviderIdentifier(const Identifier & provider_id);
    bool GetProviderIdentifier(Identifier & provider_id) const;
    bool HasProviderIdentifier() const;

    protocol::LimitRule & get_value();
    const protocol::LimitRule & get_value() const;

private:
    std::unique_ptr<protocol::LimitRule> m_limitrule;
    Filter m_filter;
    Limit m_limit;
};
}
