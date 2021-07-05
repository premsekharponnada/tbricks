#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Position Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Trade.h"
#include "strategy/Types.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/Position.h"

// \namespace tbricks
namespace tbricks {

namespace protocol {
class PortfolioPosition;
}

namespace test {

class STRATEGY_EXPORT PositionOptions : public Printable
{
public:
    PositionOptions();
    PositionOptions & operator=(const PositionOptions & position);
    PositionOptions(const PositionOptions & position);
    virtual ~PositionOptions();

public:
    bool HasIdentifier() const;
    Identifier GetIdentifier() const;
    void SetIdentifier(const Identifier & v);

    bool HasAggregationType() const;
    Position::AggregationType GetAggregationType() const;
    void SetAggregationType(const Position::AggregationType & v);

    void SetAggregationKeys(const std::set<Trade::AggregationKey> & aggregation_keys);

    bool HasPortfolioIdentifier() const;
    PortfolioIdentifier GetPortfolioIdentifier() const;
    void SetPortfolioIdentifier(const PortfolioIdentifier & v);

    bool HasCurrency() const;
    Currency GetCurrency() const;
    void SetCurrency(const Currency & v);

    bool HasInstrumentVenueIdentification() const;
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & v);

    bool HasCreatedDate() const;
    DateTime GetCreatedDate() const;
    void SetCreatedDate(const DateTime & v);

    bool HasSettlementDate() const;
    DateTime GetSettlementDate() const;
    void SetSettlementDate(const DateTime & v);

    bool HasTradeExchangeCreatedDatetime() const;
    DateTime GetTradeExchangeCreatedDatetime() const;
    void SetTradeExchangeCreatedDatetime(const DateTime & v);

    bool HasVolumeBought() const;
    Volume GetVolumeBought() const;
    void SetVolumeBought(const Volume & v);

    bool HasVolumeBoughtDaily() const;
    Volume GetVolumeBoughtDaily() const;
    void SetVolumeBoughtDaily(const Volume & v);

    bool HasVolumeBoughtMonthly() const;
    Volume GetVolumeBoughtMonthly() const;
    void SetVolumeBoughtMonthly(const Volume & v);

    bool HasVolumeBoughtYearly() const;
    Volume GetVolumeBoughtYearly() const;
    void SetVolumeBoughtYearly(const Volume & v);

    bool HasVolumeSold() const;
    Volume GetVolumeSold() const;
    void SetVolumeSold(const Volume & v);

    bool HasVolumeSoldDaily() const;
    Volume GetVolumeSoldDaily() const;
    void SetVolumeSoldDaily(const Volume & v);

    bool HasVolumeSoldMonthly() const;
    Volume GetVolumeSoldMonthly() const;
    void SetVolumeSoldMonthly(const Volume & v);

    bool HasVolumeSoldYearly() const;
    Volume GetVolumeSoldYearly() const;
    void SetVolumeSoldYearly(const Volume & v);

    bool HasGrossTradeAmountBought() const;
    Double GetGrossTradeAmountBought() const;
    void SetGrossTradeAmountBought(const Double & v);

    bool HasGrossTradeAmountBoughtDaily() const;
    Double GetGrossTradeAmountBoughtDaily() const;
    void SetGrossTradeAmountBoughtDaily(const Double & v);

    bool HasGrossTradeAmountBoughtMonthly() const;
    Double GetGrossTradeAmountBoughtMonthly() const;
    void SetGrossTradeAmountBoughtMonthly(const Double & v);

    bool HasGrossTradeAmountBoughtYearly() const;
    Double GetGrossTradeAmountBoughtYearly() const;
    void SetGrossTradeAmountBoughtYearly(const Double & v);

    bool HasGrossTradeAmountSold() const;
    Double GetGrossTradeAmountSold() const;
    void SetGrossTradeAmountSold(const Double & v);

    bool HasGrossTradeAmountSoldDaily() const;
    Double GetGrossTradeAmountSoldDaily() const;
    void SetGrossTradeAmountSoldDaily(const Double & v);

    bool HasGrossTradeAmountSoldMonthly() const;
    Double GetGrossTradeAmountSoldMonthly() const;
    void SetGrossTradeAmountSoldMonthly(const Double & v);

    bool HasGrossTradeAmountSoldYearly() const;
    Double GetGrossTradeAmountSoldYearly() const;
    void SetGrossTradeAmountSoldYearly(const Double & v);

    bool HasFee() const;
    Double GetFee() const;
    void SetFee(const Double & v);

    bool HasFeeDaily() const;
    Double GetFeeDaily() const;
    void SetFeeDaily(const Double & v);

    bool HasFeeMonthly() const;
    Double GetFeeMonthly() const;
    void SetFeeMonthly(const Double & v);

    bool HasFeeYearly() const;
    Double GetFeeYearly() const;
    void SetFeeYearly(const Double & v);

    bool HasLiquidityAddedCount() const;
    Integer GetLiquidityAddedCount() const;
    void SetLiquidityAddedCount(const Integer & v);

    bool HasLiquidityRemovedCount() const;
    Integer GetLiquidityRemovedCount() const;
    void SetLiquidityRemovedCount(const Integer & v);

    bool HasInvestedDaily() const;
    Double GetInvestedDaily() const;
    void SetInvestedDaily(const Double & v);

    bool HasInvestedMonthly() const;
    Double GetInvestedMonthly() const;
    void SetInvestedMonthly(const Double & v);

    bool HasInvestedYearly() const;
    Double GetInvestedYearly() const;
    void SetInvestedYearly(const Double & v);

    bool HasOpenInvested() const;
    Double GetOpenInvested() const;
    void SetOpenInvested(const Double & v);

    bool HasOpenInvestedDaily() const;
    Double GetOpenInvestedDaily() const;
    void SetOpenInvestedDaily(const Double & v);

    bool HasOpenInvestedMonthly() const;
    Double GetOpenInvestedMonthly() const;
    void SetOpenInvestedMonthly(const Double & v);

    bool HasOpenInvestedYearly() const;
    Double GetOpenInvestedYearly() const;
    void SetOpenInvestedYearly(const Double & v);

    bool HasReferencePriceDaily() const;
    Double GetReferencePriceDaily() const;
    void SetReferencePriceDaily(const Double & v);

    bool HasReferencePriceMonthly() const;
    Double GetReferencePriceMonthly() const;
    void SetReferencePriceMonthly(const Double & v);

    bool HasReferencePriceYearly() const;
    Double GetReferencePriceYearly() const;
    void SetReferencePriceYearly(const Double & v);

    bool HasTradeBoughtCount() const;
    Integer GetTradeBoughtCount() const;
    void SetTradeBoughtCount(const Integer & v);

    bool HasTradeSoldCount() const;
    Integer GetTradeSoldCount() const;
    void SetTradeSoldCount(const Integer & v);

    bool HasTradeCount() const;
    Integer GetTradeCount() const;
    void SetTradeCount(const Integer & v);

    bool HasLastTradeIdentifier() const;
    TradeIdentifier GetLastTradeIdentifier() const;
    void SetLastTradeIdentifier(const TradeIdentifier & v);

    bool HasSummation() const;
    Boolean GetSummation() const;
    void SetSummation(const Boolean & v);

    bool HasClient() const;
    TreeNodeIdentifier GetClient() const;
    void SetClient(const TreeNodeIdentifier & v);

    bool HasHandler() const;
    TreeNodeIdentifier GetHandler() const;
    void SetHandler(const TreeNodeIdentifier & v);

    bool HasCounterpartIdentifier() const;
    TreeNodeIdentifier GetCounterpartIdentifier() const;
    void SetCounterpartIdentifier(const TreeNodeIdentifier & v);

    bool HasOwner() const;
    UserIdentifier GetOwner() const;
    void SetOwner(const UserIdentifier & v);

    bool HasCounterpart() const;
    String GetCounterpart() const;
    void SetCounterpart(const String & v);

    bool HasStrategyIdentifier() const;
    StrategyIdentifier GetStrategyIdentifier() const;
    void SetStrategyIdentifier(const StrategyIdentifier & v);

    bool HasRootStrategyIdentifier() const;
    StrategyIdentifier GetRootStrategyIdentifier() const;
    void SetRootStrategyIdentifier(const StrategyIdentifier & v);

    bool HasLastBlockOrderLegIdentifier() const;
    BlockOrderLegIdentifier GetLastBlockOrderLegIdentifier() const;
    void SetLastBlockOrderLegIdentifier(const BlockOrderLegIdentifier & v);

    bool HasLastDirectedQuoteIdentifier() const;
    DirectedQuoteIdentifier GetLastDirectedQuoteIdentifier() const;
    void SetLastDirectedQuoteIdentifier(const DirectedQuoteIdentifier & v);

    bool HasLastExPitIdentifier() const;
    ExPitIdentifier GetLastExPitIdentifier() const;
    void SetLastExPitIdentifier(const ExPitIdentifier & v);

    bool HasLastOrderIdentifier() const;
    OrderIdentifier GetLastOrderIdentifier() const;
    void SetLastOrderIdentifier(const OrderIdentifier & v);

    /**
     * Check if field is set.
     *
     *
     * @return                  True if field is set, false otherwise
     */
    bool HasAccrued() const;

    /**
     * Get accrued.
     *
     *
     * @return                  accrued
     */
    Double GetAccrued() const;

    /**
     * %Set accrued.
     *
     *
     * If the passed value is empty, the field in the options
     * will be deleted.
     *
     * @param v                 accrued
     */
    void SetAccrued(const Double & v);

    /**
     * Check if field is set.
     *
     *
     * @return                  True if field is set, false otherwise
     */
    bool HasAccruedDaily() const;

    /**
     * Get accruedi daily.
     *
     *
     * @return                  accrued daily
     */
    Double GetAccruedDaily() const;

    /**
     * %Set accrued daily.
     *
     *
     * If the passed value is empty, the field in the options
     * will be deleted.
     *
     * @param v                 accrued daily
     */
    void SetAccruedDaily(const Double & v);

    /**
     * Check if field is set.
     *
     *
     * @return                  True if field is set, false otherwise
     */
    bool HasAccruedMonthly() const;

    /**
     * Get accrued monthly.
     *
     *
     * @return                  accrued monthly
     */
    Double GetAccruedMonthly() const;

    /**
     * %Set accrued monthly.
     *
     *
     * If the passed value is empty, the field in the options
     * will be deleted.
     *
     * @param v                 accrued monthly
     */
    void SetAccruedMonthly(const Double & v);

    /**
     * Check if field is set.
     *
     *
     * @return                  True if field is set, false otherwise
     */
    bool HasAccruedYearly() const;

    /**
     * Get accrued yearly.
     *
     *
     * @return                  accrued yearly
     */
    Double GetAccruedYearly() const;

    /**
     * %Set accrued yearly.
     *
     *
     * If the passed value is empty, the field in the options
     * will be deleted.
     *
     * @param v                 accrued yearly
     */
    void SetAccruedYearly(const Double & v);

public:
    bool Empty() const;

    virtual std::ostream & Print(std::ostream & strm) const;

    void Merge(const PositionOptions & options);

public:
    const protocol::PortfolioPosition & get_impl() const;

private:
    std::unique_ptr<protocol::PortfolioPosition> m_msg;
};

} // \namespace test

} // \namespace tbricks
