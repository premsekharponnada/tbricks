#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Trade object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Strategy.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/ExtraData.h"
#include "strategy/TradeParameters.h"
#include "strategy/quoting/QuoteIdentification.h"
#include "strategy/type/UniqueTradeIdentifier.h"
#include "strategy/type/DirectedQuoteIdentifier.h"
#include "strategy/type/ExecutionPolicy.h"
#include "strategy/RegulatoryParameters.h"

namespace tbricks {

class User;
class TradeModifier;
class StrategyData;
class Order;

namespace protocol {
class Trade;
}

class STRATEGY_EXPORT Trade : public Printable
{
public:
    class RequestResult;

public:
    enum class AggregationKey
    {
        CLIENT = 1611,
        COUNTERPART = 11,
        CURRENCY = 13,
        HANDLER = 1612,
        INSTRUMENT = 65,
        OWNER = 115,
        PORTFOLIO = 122,
        ROOT_STRATEGY = 471,
        SETTLEMENT_DATE = 155,
        STRATEGY = 175,
        VENUE_AND_MIC = 211,
        COUNTERPART_IDENTIFIER = 1801
    };

public:
    Trade();
    Trade(const Trade & trade);
    Trade & operator=(const Trade & trade);
    virtual ~Trade();

    /**
     * Create new trade.
     *
     * @param id         Identifier of new trade. If id is empty, identifier
     *                   will be generated automatically.
     */
    static Trade CreateNew(const TradeIdentifier & id = TradeIdentifier());

    /**
     * %Set trade values.
     *
     * Copy values of trade.
     * Copy values are comment, counter currency, counterppart, creator,
     * currency, extra_data, instrument identifier, portfolio identifier,
     * owner, price, quote set identifier, side, trade type, volume.
     *
     * @param trade      Trade
     */
    void SetTradeValues(const Trade & trade);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasCreator() const;

    /**
     * Get creator of an item.
     *
     * @return                          Creator identifier
     */
    UserIdentifier GetCreator() const;
    bool GetCreator(User & user) const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasOwner() const;

    /**
     * Get owner of an item.
     *
     * @return                          Owner identifier
     */
    UserIdentifier GetOwner() const;
    bool GetOwner(User & user) const;

    /**
     * %Set owner.
     *
     * @param owner                     Owner identifier
     */
    void SetOwner(const UserIdentifier & owner);
    void SetOwner(const User & owner);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasOperator() const;

    /**
     * Get owner of an item.
     *
     * @return                          Operator identifier
     */
    UserIdentifier GetOperator() const;
    bool GetOperator(User & user) const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasStatusText() const;

    /**
     * %Set status text.
     *
     * @param status_text               Status text
     */
    void SetStatusText(const String & status_text);

    /**
     * Get status text.
     *
     * @return                          Status text
     */
    String GetStatusText() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasTradeIdentifier() const;

    /**
     * Get trade identifier.
     *
     * @return                          Unique trade identifier.
     */
    TradeIdentifier GetTradeIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasStrategyIdentifier() const;

    /**
     * Get strategy identifier.
     *
     * Returns identifier of the strategy which created the order resulted
     * in this trade.
     *
     * @return                          Strategy identifier
     */
    StrategyIdentifier GetStrategyIdentifier() const;

    /**
     * %Set strategy identifier.
     *
     * @deprecated use SetParentApp method instead.
     *             Deprecated in 2.9.0
     *
     *
     * @param id                        Strategy identifier
     */
    [[deprecated(DEPRECATE_LINK)]] void SetStrategyIdentifier(const StrategyIdentifier & id);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasRootStrategyIdentifier() const;

    /**
     * Get root strategy identifier.
     *
     * Returns identifier of the root strategy which created the order resulted
     * in this trade.
     *
     * @return                          Strategy identifier
     */
    StrategyIdentifier GetRootStrategyIdentifier() const;

    /**
     * Get strategy identifier path.
     *
     * Returns a vector of strategy identifiers that describe the path of
     * strategies used to create this entity starting from the root strategy
     * identifier.
     *
     * @param path                      vector of StrategyIdentifier
     */
    void GetStrategyPath(std::vector<StrategyIdentifier> & path) const;

    /**
     * Get strategy definition identifier path.
     *
     * Returns a vector of strategy definition identifiers that describe the path of
     * strategie types used to create this entity starting from the root strategy
     * definition identifier.
     *
     * @param path                      vector of StrategyIdentifier
     */
    void GetStrategyDefinitionPath(std::vector<StrategyIdentifier> & path) const;

    /**
     * %Set root strategy identifier.
     *
     * @deprecated use SetParentApp method instead.
     *             Deprecated in 2.9.0
     *
     * @param id                        strategy identifier
     */
    [[deprecated(DEPRECATE_LINK)]] void SetRootStrategyIdentifier(const StrategyIdentifier & id);

    /**
     * %Set fields to book the trade for another app
     *
     * @param strategy                  strategy data
     */
    void SetParentApp(const StrategyData & strategy);

    /**
     * %Set fields to book the trade for another app
     *
     * @param order                     order
     */
    void SetParentApp(const Order & order);

    /**
     * %Set fields to book the trade for another app
     *
     * @param strategy                  strategy
     */
    void SetParentApp(const Strategy & strategy);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasInstrumentIdentifier() const;

    /**
     * %Set instrument identifier.
     *
     * @param id                        instrument identifier
     */
    void SetInstrumentIdentifier(const InstrumentIdentifier & id);

    /**
     * Get instrument identifier.
     *
     * @return                          instrument identifier
     */
    InstrumentIdentifier GetInstrumentIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasInstrumentVenueIdentification() const;

    /**
     * %Set instrument venue identifier.
     *
     * @param ivid                      Instrument venue identifier
     */
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    /**
     * Get instrument venue identifier.
     *
     * @return                          Instrument venue identifier
     */
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasVenueInstrumentIdentifier() const;

    /**
     * Get venue instrument identifier.
     *
     * @return                          Venue instrument identifier
     */
    VenueInstrumentIdentifier GetVenueInstrumentIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasVenue() const;

    /**
     * Get venue.
     *
     * @return                          Venue object
     */
    Venue GetVenue() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasMIC() const;

    /**
     * Get market identification code.
     *
     * @return                          Market identification code
     */
    MIC GetMIC() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasMMTFlags() const;

    /**
     * Get market model typology.
     *
     * @return                          Market model typology
     */
    MMTFlags GetMMTFlags() const;

    /**
     * %Set market model typology.
     *
     * @param id                        Market model typology
     */
    void SetMMTFlags(const MMTFlags & mmt);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasOrderIdentifier() const;

    /**
     * %Set order identifier.
     *
     * @param id                        Order identifier
     */
    void SetOrderIdentifier(const Identifier & id);

    /**
     * Get order identifier.
     *
     * @return                          Order identifier
     */
    Identifier GetOrderIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasExPitIdentifier() const;

    /**
     * %Set expit identifier.
     *
     * @param id                        ExPit identifier
     */
    void SetExPitIdentifier(const Identifier & id);

    /**
     * Get expit identifier.
     *
     * @return                          ExPit identifier
     */
    Identifier GetExPitIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasExPitDealIdentifier() const;

    /**
     * %Set expit identifier.
     *
     * @param id                        ExPit identifier
     */
    void SetExPitDealIdentifier(const ExPitDealIdentifier & id);

    /**
     * Get expit identifier.
     *
     * @return                          ExPit identifier
     */
    ExPitDealIdentifier GetExPitDealIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasExchangeTradeIdentifier() const;

    /**
     * %Set exchange trade identifier.
     *
     * Works with textual representation of the exchanges trade identifier.
     *
     * @param id                        Trade identifier
     */
    void SetExchangeTradeIdentifier(const String & id);

    /**
     * Get exchange trade identifier.
     *
     * Returns textual representation of the exchanges trade identifier.
     *
     * @return                          Exchange trade identifier
     */
    String GetExchangeTradeIdentifier() const;

    /**
     * Get quote set identifier.
     *
     * @return                          Quote set identifier
     */
    Identifier GetQuoteSetIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasQuoteSetIdentifier() const;

    /**
     * Get exchange client quote reference
     *
     * @return                          Exchange client quote reference
     */
    String GetExchangeClientQuoteReference() const;

    /**
     * Has exchange client quote reference
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasExchangeClientQuoteReference() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasPrice() const;

    /**
     * %Set trade price.
     *
     * @param price                     Price
     */
    void SetPrice(const Price & price);

    /**
     * Get trade price.
     *
     * @return                          Price
     */
    Price GetPrice() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasVolume() const;

    /**
     * %Set trade volume.
     *
     * @param volume                    Volume
     */
    void SetVolume(const Volume & volume);

    /**
     * Get trade volume.
     *
     * @return                          Volume
     */
    Volume GetVolume() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasGrossTradeAmount() const;

    /**
     * %Set gross trade amount.
     *
     * @param value                     Gross trade amount
     */
    void SetGrossTradeAmount(const Double & value);

    /**
     * Get gross trade amount.
     *
     * The gross trade amount in actual cash for a trade.
     *
     * @return                          Gross trade amount
     */
    Double GetGrossTradeAmount() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasFee() const;

    /**
     * %Set trade fee.
     *
     * @param value                     Trade fee
     */
    void SetFee(const Double & value);

    /**
     * Get trade fee.
     *
     * The trade fee.
     *
     * @return                          Trade fee
     */
    Double GetFee() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasSide() const;

    /**
     * %Set trade side.
     *
     * @param side                      Trade side
     */
    void SetSide(const Side & side);

    /**
     * Get trade side.
     *
     * @return                          Trade side
     */
    Side GetSide() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasCurrency() const;

    /**
     * %Set trade currency.
     *
     * @param currency                  Trade currency
     */
    void SetCurrency(const Currency & currency);

    /**
     * Get trade currency.
     *
     * @return                          Trade currency
     */
    Currency GetCurrency() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasFeeCurrency() const;

    /**
     * %Set trade fee currency.
     *
     * @param currency                  Trade currency
     */
    void SetFeeCurrency(const Currency & currency);

    /**
     * Get trade fee currency.
     *
     * @return                          Trade currency
     */
    Currency GetFeeCurrency() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasDeleted() const;

    /**
     * Mark trade as (not) deleted.
     *
     * @param deleted                   If set to "true", will mark trade
     *                                  as deleted
     */
    void SetDeleted(const Boolean & deleted);

    /**
     * Check if trade is marked as deleted.
     *
     * @return                          Deleted flag
     */
    Boolean GetDeleted() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasHostCreatedDatetime() const;

    /**
     * Find out when a trade was created.
     *
     * This is the date and time a trade was created within the system.
     *
     * @return                          Timestamp
     */
    DateTime GetHostCreatedDatetime() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasHostModifiedDatetime() const;

    /**
     * Find out when a trade was modified.
     *
     * This is the date and time of last modification to a trade in
     * the system.
     *
     * @return                          Timestamp
     */
    DateTime GetHostModifiedDatetime() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasModifiedSinceCreation() const;

    /**
     * Check if a trade was modified.
     *
     * @return                          "true" if trade was modified
     */
    Boolean GetModifiedSinceCreation() const;

    /**
     * %Set trade as modified
     *
     * @param modified                  If set to "true", will mark trade
     *                                  as modified
     */
    void SetModifiedSinceCreation(const Boolean & modified);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasExchangeCreatedDatetime() const;

    /**
     * Find out when a trade was created on an exchange.
     *
     * This is the date and time a trade originating from the exchange was
     * created.
     *
     * @return                          Timestamp
     */
    DateTime GetExchangeCreatedDatetime() const;

    /**
     * %Set exchange created date time
     *
     * @param datetime                  Timestamp
     */
    void SetExchangeCreatedDatetime(const DateTime & datetime);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasExchangeModifiedDatetime() const;

    /**
     * Find out when a trade was modified on an exchange.
     *
     * This is the date and time a trade originating from the exchange was
     * created.
     *
     * @return                          Timestamp
     */
    DateTime GetExchangeModifiedDatetime() const;

    /**
     * %Set exchange modified date time
     *
     * @param datetime                  Timestamp
     */
    void SetExchangeModifiedDatetime(const DateTime & datetime);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasBusinessDate() const;

    /**
     * Returns date when a trade is considered to have happened by
     * the exchange system. For after hours trading sessions,
     * this can typically be the next day.
     *
     * %Set by gateway according to rules provided by the exchange.
     *
     * @return                          Date
     */
    Date GetBusinessDate() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasExtraData() const;

    /**
     * %Set extra data.
     *
     * Associates a set of additional fields with the trade.
     *
     * @param data                      Set of associated fields
     */
    void SetExtraData(const ExtraData & data);

    /**
     * Get extra data.
     *
     * @return                          Set of associated fields
     */
    ExtraData GetExtraData() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasTradeParameters() const;

    /**
     * %Set ranking parameters.
     *
     * Associates a set of additional fields with the trade.
     *
     * @param data                      Set of associated fields
     */
    void SetTradeParameters(const TradeParameters & rparams);

    /**
     * Get ranking parameters.
     *
     * @return                          Set of associated fields
     */
    TradeParameters GetTradeParameters() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasPortfolioIdentifier() const;

    /**
     * %Set portfolio identfier.
     *
     * @param id                        Portfolio identifier
     */
    void SetPortfolioIdentifier(const PortfolioIdentifier & id);

    /**
     * Get portfolio identifier.
     *
     * @return                          Portfolio identifier
     */
    PortfolioIdentifier GetPortfolioIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasSettlementDate() const;

    /**
     * %Set settlement date.
     *
     * @param datetime                  Timestamp
     */
    void SetSettlementDate(const DateTime & datetime);

    /**
     * Get settlement date.
     *
     * @return                          Timestamp
     */
    DateTime GetSettlementDate() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasLiquidityIndicator() const;

    /**
     * %Set liquidity indicator.
     *
     * @param value                     New value
     */
    void SetLiquidityIndicator(const LiquidityIndicator & value);

    /**
     * Get liquidity indicator.
     *
     * @return                          Liquidity indicator value
     */
    LiquidityIndicator GetLiquidityIndicator() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasType() const;

    /**
     * Get trade type.
     *
     * @return                          Trade type value
     */
    TradeType GetType() const;

    /**
     * %Set trade type.
     *
     * @param type                  Trade type
     */
    void SetType(TradeType type) const;

    /**
     * Check if counter currency field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasCounterCurrency() const;

    /**
     * %Set trade counter currency.
     *
     * @param currency                  Trade counter currency
     */
    void SetCounterCurrency(const Currency & currency);

    /**
     * Get trade counter currency.
     *
     * @return                          Trade counter currency
     */
    Currency GetCounterCurrency() const;

    /**
     * Check if counterpart field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasCounterpart() const;

    /**
     * %Set trade counterpart.
     *
     * @param string                  Trade counterpart
     */
    void SetCounterpart(const String & counterpart);

    /**
     * Get trade counterpart.
     *
     * @return                          Trade counterpart
     */
    String GetCounterpart() const;

    /**
     * Check if counterpart field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasCounterpartIdentifier() const;

    /**
     * %Set trade counterpart.
     *
     * @param string                  Trade counterpart
     */
    void SetCounterpartIdentifier(const TreeNodeIdentifier & counterpart);

    /**
     * Get trade counterpart.
     *
     * @return                          Trade counterpart
     */
    TreeNodeIdentifier GetCounterpartIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasComment() const;

    /**
     * %Set comment.
     *
     */
    void SetComment(const String & comment);

    /**
     * Get comment.
     *
     */
    String GetComment() const;

    /**
     * Check expiration identifier is set.
     *
     */
    bool HasExpirationIdentifier() const;

    /**
     * %Set expiration identifier.
     *
     */
    void SetExpirationIdentifier(const Identifier & id);

    /**
     * Get expiration identifier.
     *
     */
    Identifier GetExpirationIdentifier() const;

    /**
     * Check expiration delivery identifier is set.
     *
     */
    bool HasExpirationDeliveryIdentifier() const;

    /**
     * Get expiration delivery identifier.
     *
     */
    Identifier GetExpirationDeliveryIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasQuoteMode() const;

    /**
     * %Set quote mode.
     *
     * @param value                     New value
     */
    void SetQuoteMode(const QuoteMode & value);

    /**
     * Get quote mode.
     *
     * @return                          Quote mode value
     */
    QuoteMode GetQuoteMode() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasQuoteUnderlyingBid() const;

    /**
     * Get quote underlying bid.
     *
     * @return                          Quote underlying bid
     */
    Price GetQuoteUnderlyingBid() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasQuoteUnderlyingAsk() const;

    /**
     * Get quote underlying ask.
     *
     * @return                          Quote underlying ask
     */
    Price GetQuoteUnderlyingAsk() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasTradingServiceTradeIdentifier() const;

    /**
     * Get trading service trade identifier.
     *
     * Returns identifier of the trade specified by trading service of integration plugin
     *
     * @return                          Trading service trade identifier
     */
    String GetTradingServiceTradeIdentifier() const;

    /**
     * %Set trading service trade identifier.
     *
     * @param id                        Trading service trade identifier
     */
    void SetTradingServiceTradeIdentifier(const String & id);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasOriginatingInstrumentIdentifier() const;

    /**
     * Get instrument identifier.
     *
     * Populated for trades when the trade is executed on another instrument
     * than the trade actually is on.
     *
     * @return                          Instrument identifier
     */
    InstrumentIdentifier GetOriginatingInstrumentIdentifier() const;

    /**
     * %Set originating instrument identifier.
     *
     * @param id                        Originating instrument identifier
     */
    void SetOriginatingInstrumentIdentifier(const InstrumentIdentifier & id);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasUniqueTradeIdentifier() const;

    /**
     * %Set UTI.
     *
     * If UTI argument is not valid, an exception is thrown.
     *
     */
    void SetUniqueTradeIdentifier(const UniqueTradeIdentifier & uti);

    /**
     * Get UTI.
     *
     */
    UniqueTradeIdentifier GetUniqueTradeIdentifier() const;

    /**
     * Check whether trade is valid.
     */
    bool IsValid(String & error_text) const;

    Uuid GetOperatingServiceInstanceIdentifier() const;
    Uuid GetSourceServiceInstanceIdentifier() const;
    StrategyIdentifier GetOperatingStrategyIdentifier() const;

    /**
     * Get trade capacity
     */
    bool HasOrderCapacity() const;
    OrderCapacity GetOrderCapacity() const;

    /**
     * Set order capacity
     *
     * @param                           order capacity
     */
    void SetOrderCapacity(const OrderCapacity & capacity);

    /**
     * Get liquidity source
     */
    bool HasLiquiditySource() const;
    LiquiditySource GetLiquiditySource() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasVenueTradeConditions() const;

    /**
     * %Set venue trade conditions
     *
     * @param venueTradeConditions      Dictionary with desired venue conditions
     */
    void SetVenueTradeConditions(const StringDictionary & venueTradeConditions);

    /**
     * Get venue trade conditions
     *
     * @return                          Dictionary of venue trade conditions
     */
    StringDictionary GetVenueTradeConditions() const;

    bool HasHandler() const;

    /**
     * Node in a tree that represent the managing entity of strategy and/or orders.
     *
     * @return                          TreeNodeIdentifier
     */
    TreeNodeIdentifier GetHandler() const;
    void SetHandler(const TreeNodeIdentifier & id);

    bool HasClient() const;

    /**
     * Node in a tree that represent the managed entity for a strategy and/or orders.
     *
     * @return                          TreeNodeIdentifier
     */
    TreeNodeIdentifier GetClient() const;
    void SetClient(const TreeNodeIdentifier & id);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasBlockOrderIdentifier() const;

    /**
     * Get block order identifier.
     *
     * @return                          block order identifier
     */
    Identifier GetBlockOrderIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasBlockOrderLegIdentifier() const;

    /**
     * Get block order leg identifier.
     *
     * @return                          block order leg identifier
     */
    Identifier GetBlockOrderLegIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasRegulatoryParameters() const;

    /**
     * Get regulatory audit parameters.
     *
     * @return                          %Set of associated fields
     */
    RegulatoryParameters GetRegulatoryParameters() const;

    /**
     * Set regulatory audit parameters.
     *
     * @param status_text               Regulatory parameters
     */
    void SetRegulatoryParameters(const RegulatoryParameters & params);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasMatchIdentifier() const;

    /**
     * %Set match identifier.
     *
     * @param status_text               Match Identifier
     */
    void SetMatchIdentifier(const Identifier & identifier);

    /**
     * Get match identifier.
     *
     * @return                          MatchIdentifier
     */
    Identifier GetMatchIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasLiquidityPool() const;

    /**
     * Get liquidity pool.
     *
     * @return                          liquidity pool identifier
     */
    LiquidityPoolIdentifier GetLiquidityPool() const;

    /**
     * @deprecated Deprecated in 2.13.0, use HasExchangePackageIdentifier instead
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasExchangeMatchIdentifier() const;

    /**
     * @deprecated Deprecated in 2.13.0, use SetExchangePackageIdentifier instead
     */
    [[deprecated(DEPRECATE_LINK)]] void SetExchangeMatchIdentifier(const String & identifier);

    /**
     * @deprecated Deprecated in 2.13.0, use GetExchangePackageIdentifier instead
     */
    [[deprecated(DEPRECATE_LINK)]] String GetExchangeMatchIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasExchangePackageIdentifier() const;

    /**
     * %Set exchange package identifier.
     *
     * @param status_text               Exchange Match Identifier
     */
    void SetExchangePackageIdentifier(const String & identifier);

    /**
     * Get exchange package identifier.
     *
     * @return                          Exchange Match Identifier
     */
    String GetExchangePackageIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasCashFlows() const;

    /**
     * Get cash flows.
     *
     * @return                          vector of cash flow
     */
    std::vector<CashFlow> GetCashFlows() const;

    /**
     * %Set cash flows.
     *
     * @param                           vector of cash flow
     */
    void SetCashFlows(const std::vector<CashFlow> & value) const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasQuoteIdentifier() const;

    /**
     * Get quote identifier.
     *
     * @return                          quote identifier
     */
    QuoteIdentifier GetQuoteIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasDirectedQuoteIdentifier() const;

    /**
     * Get directed quote identifier.
     *
     * @return                          Directed quote identifier
     */
    DirectedQuoteIdentifier GetDirectedQuoteIdentifier() const;

    /**
     * %Set directed quote identifier.
     *
     * @param                           directed quote identifier
     */
    void SetDirectedQuoteIdentifier(const DirectedQuoteIdentifier & identifier);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set,
     *                                  "false" otherwise
     */
    bool HasDirectedQuoteGeneration() const;

    /**
     * Get directed quote generation.
     *
     * @return                          directed quote generation
     */
    DirectedQuoteGeneration GetDirectedQuoteGeneration() const;

    /**
     * %Set directed quote generation.
     *
     * @param                           directed quote generation
     */
    void SetDirectedQuoteGeneration(const DirectedQuoteGeneration & generation);

    /**
     * Get warmup option.
     *
     * @return                          Warmup option
     */
    bool GetWarmup() const;

    /**
     * Get execution policy
     *
     * @return                          Warmup option
     */
    ExecutionPolicy GetExecutionPolicy() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasExecutionPolicy() const;

    /**
     * Set execution policy.
     *
     * @param                           Execution policy
     */
    void SetExecutionPolicy(const ExecutionPolicy & value);

    /**
     * Get segment mic
     *
     * @return                          segment mic
     */
    MIC GetSegmentMIC() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasSegmentMIC() const;

    /**
     * Get accrued interest paid.
     *
     * @return                          accrued
     */
    Double GetAccrued() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasAccrued() const;

    /**
     * Set accrued interest paid.
     *
     * @param                           accrued
     */
    void SetAccrued(const Double & value);

public:
    /**
     * Resolve short codes
     *
     * Client and regulatory parameters fields must be setted before this call
     *
     */
    bool ResolveShortCodes(const UserIdentifier & execution_decision_user, const UserIdentifier & investment_decision_user);

    /**
     * Send trade create request.
     *
     * Interface allows to insert a manual trade into Trade Persistence
     * service. Strategy identifier is set to the identifier of the calling
     * strategy, creator, owner and strategy root identifiers fields are
     * inherited from the caller as well.
     *
     * If trade argument does not have trade identifier set (i.e. it was
     * not created with Trade::CreateNew()), an exception is thrown.
     *
     * Trade create request is a remote operation and its status is delivered
     * to HandleRequestReply() as soon as the operation result is available.
     *
     * @param trade                     Filled trade entry
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Trade::RequestResult object
     */
    static RequestResult SendCreateRequest(const Trade & trade, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send trade modify request.
     *
     * Method allows to modify a set of properties represented by "modifier"
     * argument in an already existing trade entry.
     *
     * Trade modify request is a remote operation and its status is delivered
     * to HandleRequestReply() as soon as the operation result is available.
     *
     * @param modifier                  Modification request
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Trade::RequestResult object
     */
    static RequestResult SendModifyRequest(const TradeModifier & modifier, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send trade delete request.
     *
     * Method sends a request to remove already existing trade entry.
     *
     * Trade delete request is a remote operation and its status is delivered
     * to HandleRequestReply() as soon as the operation result is available.
     *
     * @param identifier                Trade identifier
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Trade::RequestResult object
     */
    static RequestResult SendDeleteRequest(const TradeIdentifier & identifier, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

public:
    void Merge(const Trade & update);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    Trade(protocol::Trade & trade);

public:
    protocol::Trade & get_trade() const;

    void SetBusinessDate(Date date);

private:
    bool m_alloc;
    protocol::Trade * m_msg;
};

class STRATEGY_EXPORT Trade::RequestResult : public Printable
{
public:
    RequestResult();
    RequestResult(const Identifier & request_identifier, const TradeIdentifier & trade_identifier);
    const Identifier & GetRequestIdentifier() const;
    const TradeIdentifier & GetTradeIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    TradeIdentifier m_trade_identifier;
};
}
