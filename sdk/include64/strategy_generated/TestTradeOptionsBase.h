#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestTradeOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class BlockOrderIdentifier;
class BlockOrderLegIdentifier;
class Boolean;
class CashFlow;
class Currency;
class Date;
class DateTime;
class DirectedQuoteGeneration;
class DirectedQuoteIdentifier;
class Double;
class ExPitIdentifier;
class ExecutionPolicy;
class ExtraData;
class Identifier;
class InstrumentIdentifier;
class LiquidityIndicator;
class LiquidityPoolIdentifier;
class MIC;
class MMTFlags;
class OrderCapacity;
class OrderIdentifier;
class PortfolioIdentifier;
class Price;
class RegulatoryParameters;
class Side;
class StrategyIdentifier;
class String;
class TradeIdentifier;
class TradeParameters;
class TradeType;
class TreeNodeIdentifier;
class UserIdentifier;


namespace protocol { class Trade; }

class STRATEGY_EXPORT TestTradeOptionsBase : public Printable
{
protected:
    TestTradeOptionsBase();
    TestTradeOptionsBase(const TestTradeOptionsBase & value);
    TestTradeOptionsBase(TestTradeOptionsBase && value) noexcept;
    TestTradeOptionsBase & operator=(const TestTradeOptionsBase & value);
    TestTradeOptionsBase & operator=(TestTradeOptionsBase && value) noexcept;
    virtual ~TestTradeOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradeIdentifier() const;

    /**
     * Get trade identifier.
     *
     *
     * @return                          trade identifier
     */
    TradeIdentifier GetTradeIdentifier() const;

    /**
     * %Set trade identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     trade identifier
     */
    void SetTradeIdentifier(const TradeIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCreator() const;

    /**
     * Get creator.
     *
     *
     * @return                          creator
     */
    UserIdentifier GetCreator() const;

    /**
     * %Set creator.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     creator
     */
    void SetCreator(const UserIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOwner() const;

    /**
     * Get owner.
     *
     *
     * @return                          owner
     */
    UserIdentifier GetOwner() const;

    /**
     * %Set owner.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     owner
     */
    void SetOwner(const UserIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOperator() const;

    /**
     * Get operator.
     *
     *
     * @return                          operator
     */
    UserIdentifier GetOperator() const;

    /**
     * %Set operator.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     operator
     */
    void SetOperator(const UserIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStatusText() const;

    /**
     * Get status text.
     *
     *
     * @return                          status text
     */
    String GetStatusText() const;

    /**
     * %Set status text.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     status text
     */
    void SetStatusText(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInstrumentIdentifier() const;

    /**
     * Get instrument identifier.
     *
     *
     * @return                          instrument identifier
     */
    InstrumentIdentifier GetInstrumentIdentifier() const;

    /**
     * %Set instrument identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     instrument identifier
     */
    void SetInstrumentIdentifier(const InstrumentIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMMTFlags() const;

    /**
     * Get market model typology.
     *
     *
     * @return                          market model typology
     */
    MMTFlags GetMMTFlags() const;

    /**
     * %Set market model typology.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     market model typology
     */
    void SetMMTFlags(const MMTFlags & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOrderIdentifier() const;

    /**
     * Get order identifier.
     *
     *
     * @return                          order identifier
     */
    OrderIdentifier GetOrderIdentifier() const;

    /**
     * %Set order identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     order identifier
     */
    void SetOrderIdentifier(const OrderIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExPitIdentifier() const;

    /**
     * Get expit identifier.
     *
     *
     * @return                          expit identifier
     */
    ExPitIdentifier GetExPitIdentifier() const;

    /**
     * %Set expit identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expit identifier
     */
    void SetExPitIdentifier(const ExPitIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOrderCapacity() const;

    /**
     * Get order capacity.
     *
     *
     * @return                          order capacity
     */
    OrderCapacity GetOrderCapacity() const;

    /**
     * %Set order capacity.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     order capacity
     */
    void SetOrderCapacity(const OrderCapacity & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeTradeIdentifier() const;

    /**
     * Get exchange trade identifier.
     *
     *
     * @return                          exchange trade identifier
     */
    String GetExchangeTradeIdentifier() const;

    /**
     * %Set exchange trade identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange trade identifier
     */
    void SetExchangeTradeIdentifier(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPrice() const;

    /**
     * Get price.
     *
     *
     * @return                          price
     */
    Price GetPrice() const;

    /**
     * %Set price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     price
     */
    void SetPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolume() const;

    /**
     * Get volume.
     *
     *
     * @return                          volume
     */
    Double GetVolume() const;

    /**
     * %Set volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     volume
     */
    void SetVolume(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasFee() const;

    /**
     * Get fee.
     *
     *
     * @return                          fee
     */
    Double GetFee() const;

    /**
     * %Set fee.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     fee
     */
    void SetFee(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSide() const;

    /**
     * Get side.
     *
     *
     * @return                          side
     */
    Side GetSide() const;

    /**
     * %Set side.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     side
     */
    void SetSide(const Side & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCurrency() const;

    /**
     * Get currency.
     *
     *
     * @return                          currency
     */
    Currency GetCurrency() const;

    /**
     * %Set currency.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     currency
     */
    void SetCurrency(const Currency & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasFeeCurrency() const;

    /**
     * Get fee currency.
     *
     *
     * @return                          fee currency
     */
    Currency GetFeeCurrency() const;

    /**
     * %Set fee currency.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     fee currency
     */
    void SetFeeCurrency(const Currency & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeleted() const;

    /**
     * Get deleted.
     *
     *
     * @return                          deleted
     */
    Boolean GetDeleted() const;

    /**
     * %Set deleted.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     deleted
     */
    void SetDeleted(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasModifiedSinceCreation() const;

    /**
     * Get modified since creation.
     *
     *
     * @return                          modified since creation
     */
    Boolean GetModifiedSinceCreation() const;

    /**
     * %Set modified since creation.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     modified since creation
     */
    void SetModifiedSinceCreation(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostCreatedDatetime() const;

    /**
     * Get host created datetime.
     *
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDatetime() const;

    /**
     * %Set host created datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host created datetime
     */
    void SetHostCreatedDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostModifiedDatetime() const;

    /**
     * Get host modified datetime.
     *
     *
     * @return                          host modified datetime
     */
    DateTime GetHostModifiedDatetime() const;

    /**
     * %Set host modified datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host modified datetime
     */
    void SetHostModifiedDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeCreatedDatetime() const;

    /**
     * Get exchange created datetime.
     *
     *
     * @return                          exchange created datetime
     */
    DateTime GetExchangeCreatedDatetime() const;

    /**
     * %Set exchange created datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange created datetime
     */
    void SetExchangeCreatedDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeModifiedDatetime() const;

    /**
     * Get exchange modified datetime.
     *
     *
     * @return                          exchange modified datetime
     */
    DateTime GetExchangeModifiedDatetime() const;

    /**
     * %Set exchange modified datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange modified datetime
     */
    void SetExchangeModifiedDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExtraData() const;

    /**
     * Get extra data.
     *
     *
     * @return                          extra data
     */
    ExtraData GetExtraData() const;

    /**
     * %Set extra data.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     extra data
     */
    void SetExtraData(const ExtraData & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVenueTradeConditions() const;

    /**
     * Get venue trade conditions.
     *
     *
     * @return                          venue trade conditions
     */
    ExtraData GetVenueTradeConditions() const;

    /**
     * %Set venue trade conditions.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     venue trade conditions
     */
    void SetVenueTradeConditions(const ExtraData & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSettlementDate() const;

    /**
     * Get settlement date.
     *
     *
     * @return                          settlement date
     */
    DateTime GetSettlementDate() const;

    /**
     * %Set settlement date.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     settlement date
     */
    void SetSettlementDate(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPortfolioIdentifier() const;

    /**
     * Get portfolio identifier.
     *
     *
     * @return                          portfolio identifier
     */
    PortfolioIdentifier GetPortfolioIdentifier() const;

    /**
     * %Set portfolio identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     portfolio identifier
     */
    void SetPortfolioIdentifier(const PortfolioIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterCurrency() const;

    /**
     * Get counter currency.
     *
     *
     * @return                          counter currency
     */
    Currency GetCounterCurrency() const;

    /**
     * %Set counter currency.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     counter currency
     */
    void SetCounterCurrency(const Currency & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpart() const;

    /**
     * Get counterpart.
     *
     *
     * @return                          counterpart
     */
    String GetCounterpart() const;

    /**
     * %Set counterpart.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     counterpart
     */
    void SetCounterpart(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpartIdentifier() const;

    /**
     * Get counterpart identifier.
     *
     *
     * @return                          counterpart identifier
     */
    TreeNodeIdentifier GetCounterpartIdentifier() const;

    /**
     * %Set counterpart identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     counterpart identifier
     */
    void SetCounterpartIdentifier(const TreeNodeIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComment() const;

    /**
     * Get comment.
     *
     *
     * @return                          comment
     */
    String GetComment() const;

    /**
     * %Set comment.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     comment
     */
    void SetComment(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExpirationIdentifier() const;

    /**
     * Get expiration identifier.
     *
     *
     * @return                          expiration identifier
     */
    Identifier GetExpirationIdentifier() const;

    /**
     * %Set expiration identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expiration identifier
     */
    void SetExpirationIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradingServiceTradeIdentifier() const;

    /**
     * Get trading service trade identifier.
     *
     *
     * @return                          trading service trade identifier
     */
    String GetTradingServiceTradeIdentifier() const;

    /**
     * %Set trading service trade identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     trading service trade identifier
     */
    void SetTradingServiceTradeIdentifier(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOriginatingInstrumentIdentifier() const;

    /**
     * Get originating instrument identifier.
     *
     *
     * @return                          originating instrument identifier
     */
    InstrumentIdentifier GetOriginatingInstrumentIdentifier() const;

    /**
     * %Set originating instrument identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     originating instrument identifier
     */
    void SetOriginatingInstrumentIdentifier(const InstrumentIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandler() const;

    /**
     * Get handler.
     *
     *
     * @return                          handler
     */
    TreeNodeIdentifier GetHandler() const;

    /**
     * %Set handler.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     handler
     */
    void SetHandler(const TreeNodeIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasClient() const;

    /**
     * Get client.
     *
     *
     * @return                          client
     */
    TreeNodeIdentifier GetClient() const;

    /**
     * %Set client.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     client
     */
    void SetClient(const TreeNodeIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRegulatoryParameters() const;

    /**
     * Get regulatory parameters.
     *
     *
     * @return                          regulatory parameters
     */
    RegulatoryParameters GetRegulatoryParameters() const;

    /**
     * %Set regulatory parameters.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     regulatory parameters
     */
    void SetRegulatoryParameters(const RegulatoryParameters & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMatchIdentifier() const;

    /**
     * Get match identifier.
     *
     *
     * @return                          match identifier
     */
    Identifier GetMatchIdentifier() const;

    /**
     * %Set match identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     match identifier
     */
    void SetMatchIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangePackageIdentifier() const;

    /**
     * Get exchange package identifier.
     *
     *
     * @return                          exchange package identifier
     */
    String GetExchangePackageIdentifier() const;

    /**
     * %Set exchange package identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange package identifier
     */
    void SetExchangePackageIdentifier(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteIdentifier() const;

    /**
     * Get directed quote identifier.
     *
     *
     * @return                          directed quote identifier
     */
    DirectedQuoteIdentifier GetDirectedQuoteIdentifier() const;

    /**
     * %Set directed quote identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote identifier
     */
    void SetDirectedQuoteIdentifier(const DirectedQuoteIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteGeneration() const;

    /**
     * Get directed quote generation.
     *
     *
     * @return                          directed quote generation
     */
    DirectedQuoteGeneration GetDirectedQuoteGeneration() const;

    /**
     * %Set directed quote generation.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote generation
     */
    void SetDirectedQuoteGeneration(const DirectedQuoteGeneration & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAccrued() const;

    /**
     * Get accrued.
     *
     *
     * @return                          accrued
     */
    Double GetAccrued() const;

    /**
     * %Set accrued.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     accrued
     */
    void SetAccrued(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLiquidityPool() const;

    /**
     * Get liquidity pool identifier.
     *
     *
     * @return                          liquidity pool identifier
     */
    LiquidityPoolIdentifier GetLiquidityPool() const;

    /**
     * %Set liquidity pool identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     liquidity pool identifier
     */
    void SetLiquidityPool(const LiquidityPoolIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExpirationDeliveryIdentifier() const;

    /**
     * Get expiration delivery identifier.
     *
     *
     * @return                          expiration delivery identifier
     */
    Identifier GetExpirationDeliveryIdentifier() const;

    /**
     * %Set expiration delivery identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expiration delivery identifier
     */
    void SetExpirationDeliveryIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasQuoteIdentifier() const;

    /**
     * Get quote identifier.
     *
     *
     * @return                          quote identifier
     */
    Identifier GetQuoteIdentifier() const;

    /**
     * %Set quote identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote identifier
     */
    void SetQuoteIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasQuoteSetIdentifier() const;

    /**
     * Get quote set identifier.
     *
     *
     * @return                          quote set identifier
     */
    Identifier GetQuoteSetIdentifier() const;

    /**
     * %Set quote set identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote set identifier
     */
    void SetQuoteSetIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeClientQuoteReference() const;

    /**
     * Get exchange client quote reference.
     *
     *
     * @return                          exchange client quote reference
     */
    String GetExchangeClientQuoteReference() const;

    /**
     * %Set exchange client quote reference.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange client quote reference
     */
    void SetExchangeClientQuoteReference(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasQuoteUnderlyingBid() const;

    /**
     * Get quote underlying bid.
     *
     *
     * @return                          quote underlying bid
     */
    Price GetQuoteUnderlyingBid() const;

    /**
     * %Set quote underlying bid.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote underlying bid
     */
    void SetQuoteUnderlyingBid(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasQuoteUnderlyingAsk() const;

    /**
     * Get quote underlying ask.
     *
     *
     * @return                          quote underlying ask
     */
    Price GetQuoteUnderlyingAsk() const;

    /**
     * %Set quote underlying ask.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote underlying ask
     */
    void SetQuoteUnderlyingAsk(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOperatingServiceInstanceIdentifier() const;

    /**
     * Get operating service instance identifier.
     *
     *
     * @return                          operating service instance identifier
     */
    Identifier GetOperatingServiceInstanceIdentifier() const;

    /**
     * %Set operating service instance identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     operating service instance identifier
     */
    void SetOperatingServiceInstanceIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSourceServiceInstanceIdentifier() const;

    /**
     * Get source service instance identifier.
     *
     *
     * @return                          source service instance identifier
     */
    Identifier GetSourceServiceInstanceIdentifier() const;

    /**
     * %Set source service instance identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     source service instance identifier
     */
    void SetSourceServiceInstanceIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOperatingStrategyIdentifier() const;

    /**
     * Get operating strategy identifier.
     *
     *
     * @return                          operating strategy identifier
     */
    StrategyIdentifier GetOperatingStrategyIdentifier() const;

    /**
     * %Set operating strategy identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     operating strategy identifier
     */
    void SetOperatingStrategyIdentifier(const StrategyIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBlockOrderIdentifier() const;

    /**
     * Get block order identifier.
     *
     *
     * @return                          block order identifier
     */
    BlockOrderIdentifier GetBlockOrderIdentifier() const;

    /**
     * %Set block order identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     block order identifier
     */
    void SetBlockOrderIdentifier(const BlockOrderIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBlockOrderLegIdentifier() const;

    /**
     * Get block order leg identifier.
     *
     *
     * @return                          block order leg identifier
     */
    BlockOrderLegIdentifier GetBlockOrderLegIdentifier() const;

    /**
     * %Set block order leg identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     block order leg identifier
     */
    void SetBlockOrderLegIdentifier(const BlockOrderLegIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSegmentMIC() const;

    /**
     * Get segment mic.
     *
     *
     * @return                          segment mic
     */
    MIC GetSegmentMIC() const;

    /**
     * %Set segment mic.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     segment mic
     */
    void SetSegmentMIC(const MIC & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradeParameters() const;

    /**
     * Get trade parameters.
     *
     *
     * @return                          trade parameters
     */
    TradeParameters GetTradeParameters() const;

    /**
     * %Set trade parameters.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     trade parameters
     */
    void SetTradeParameters(const TradeParameters & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasType() const;

    /**
     * Get trade type.
     *
     *
     * @return                          trade type
     */
    TradeType GetType() const;

    /**
     * %Set trade type.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     trade type
     */
    void SetType(const TradeType & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLiquidityIndicator() const;

    /**
     * Get liquidity indicator.
     *
     *
     * @return                          liquidity indicator
     */
    LiquidityIndicator GetLiquidityIndicator() const;

    /**
     * %Set liquidity indicator.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     liquidity indicator
     */
    void SetLiquidityIndicator(const LiquidityIndicator & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExecutionPolicy() const;

    /**
     * Get execution policy.
     *
     *
     * @return                          execution policy
     */
    ExecutionPolicy GetExecutionPolicy() const;

    /**
     * %Set execution policy.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     execution policy
     */
    void SetExecutionPolicy(const ExecutionPolicy & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyIdentifier() const;

    /**
     * Get strategy identifier.
     *
     *
     * @return                          strategy identifier
     */
    StrategyIdentifier GetStrategyIdentifier() const;

    /**
     * %Set strategy identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     strategy identifier
     */
    void SetStrategyIdentifier(const StrategyIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyIdentifierPath() const;

    /**
     * Get strategy identifier path.
     *
     *
     * @return                          strategy identifier path
     */
    std::vector<StrategyIdentifier> GetStrategyIdentifierPath() const;

    /**
     * %Set strategy identifier path.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     strategy identifier path
     */
    void SetStrategyIdentifierPath(const std::vector<StrategyIdentifier> & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyDefinitionIdentifierPath() const;

    /**
     * Get strategy definition identifier path.
     *
     *
     * @return                          strategy definition identifier path
     */
    std::vector<StrategyIdentifier> GetStrategyDefinitionIdentifierPath() const;

    /**
     * %Set strategy definition identifier path.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     strategy definition identifier path
     */
    void SetStrategyDefinitionIdentifierPath(const std::vector<StrategyIdentifier> & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRootStrategyIdentifier() const;

    /**
     * Get root strategy identifier.
     *
     *
     * @return                          root strategy identifier
     */
    StrategyIdentifier GetRootStrategyIdentifier() const;

    /**
     * %Set root strategy identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     root strategy identifier
     */
    void SetRootStrategyIdentifier(const StrategyIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCashFlows() const;

    /**
     * Get cash flows.
     *
     *
     * @return                          cash flows
     */
    std::vector<CashFlow> GetCashFlows() const;

    /**
     * %Set cash flows.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     cash flows
     */
    void SetCashFlows(const std::vector<CashFlow> & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBusinessDate() const;

    /**
     * Get business date.
     *
     *
     * @return                          business date
     */
    Date GetBusinessDate() const;

    /**
     * %Set business date.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     business date
     */
    void SetBusinessDate(const Date & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    TestTradeOptionsBase(const protocol::Trade & value);
    TestTradeOptionsBase(std::shared_ptr<protocol::Trade> && value);

    std::shared_ptr<protocol::Trade> & get_impl_wr() const;
    const std::shared_ptr<protocol::Trade> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Trade> m_impl;
};

}
