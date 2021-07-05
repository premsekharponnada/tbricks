#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PositionBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class BlockOrderLegIdentifier;
class Currency;
class DateTime;
class DirectedQuoteIdentifier;
class Double;
class ExPitIdentifier;
class Identifier;
class InstrumentIdentifier;
class Integer;
class OrderIdentifier;
class PortfolioIdentifier;
class StrategyIdentifier;
class String;
class TradeIdentifier;
class TreeNodeIdentifier;
class UserIdentifier;
class Volume;


namespace protocol { class PortfolioPosition; }

class STRATEGY_EXPORT PositionBase : public Printable
{
protected:
    PositionBase();
    PositionBase(const PositionBase & value);
    PositionBase(PositionBase && value) noexcept;
    PositionBase & operator=(const PositionBase & value);
    PositionBase & operator=(PositionBase && value) noexcept;
    virtual ~PositionBase();

public:
    /**
     * Check if field is set.
     *
     * Identifier of this position object.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get stream item identifier.
     *
     * Identifier of this position object.
     *
     *
     * @return                          stream item identifier
     */
    Identifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     * Identifier of portfolio this position is for.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPortfolioIdentifier() const;

    /**
     * Get portfolio identifier.
     *
     * Identifier of portfolio this position is for.
     *
     *
     * @return                          portfolio identifier
     */
    PortfolioIdentifier GetPortfolioIdentifier() const;

    /**
     * Check if field is set.
     *
     * Identifier of instrument this position is for.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInstrumentIdentifier() const;

    /**
     * Get instrument identifier.
     *
     * Identifier of instrument this position is for.
     *
     *
     * @return                          instrument identifier
     */
    InstrumentIdentifier GetInstrumentIdentifier() const;

    /**
     * Check if field is set.
     *
     * Position currency. Present only when aggregating by currency.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCurrency() const;

    /**
     * Get currency.
     *
     * Position currency. Present only when aggregating by currency.
     *
     *
     * @return                          currency
     */
    Currency GetCurrency() const;

    /**
     * Check if field is set.
     *
     * Exchange created time of the first trade in this position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCreatedDate() const;

    /**
     * Get exchange created date.
     *
     * Exchange created time of the first trade in this position.
     *
     *
     * @return                          exchange created date
     */
    DateTime GetCreatedDate() const;

    /**
     * Check if field is set.
     *
     * Settlement date of the trades in this position. Present only for
     * aggregation by settlement date and only for future dates.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSettlementDate() const;

    /**
     * Get settlement date.
     *
     * Settlement date of the trades in this position. Present only for
     * aggregation by settlement date and only for future dates.
     *
     *
     * @return                          settlement date
     */
    DateTime GetSettlementDate() const;

    /**
     * Check if field is set.
     *
     * The sum of volumes of all position 'buy' trades.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolumeBought() const;

    /**
     * Get volume bought.
     *
     * The sum of volumes of all position 'buy' trades.
     *
     *
     * @return                          volume bought
     */
    Volume GetVolumeBought() const;

    /**
     * Check if field is set.
     *
     * The sum of volumes of all position 'buy' trades made since the start
     * of today.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolumeBoughtDaily() const;

    /**
     * Get volume bought daily.
     *
     * The sum of volumes of all position 'buy' trades made since the start
     * of today.
     *
     *
     * @return                          volume bought daily
     */
    Volume GetVolumeBoughtDaily() const;

    /**
     * Check if field is set.
     *
     * The sum of volumes of position 'buy' trades made since the start of
     * this month.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolumeBoughtMonthly() const;

    /**
     * Get volume bought monthly.
     *
     * The sum of volumes of position 'buy' trades made since the start of
     * this month.
     *
     *
     * @return                          volume bought monthly
     */
    Volume GetVolumeBoughtMonthly() const;

    /**
     * Check if field is set.
     *
     * The sum of volumes of position 'buy' trades made since the start of
     * this year.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolumeBoughtYearly() const;

    /**
     * Get volume bought yearly.
     *
     * The sum of volumes of position 'buy' trades made since the start of
     * this year.
     *
     *
     * @return                          volume bought yearly
     */
    Volume GetVolumeBoughtYearly() const;

    /**
     * Check if field is set.
     *
     * The sum of volumes of all position 'sell' trades.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolumeSold() const;

    /**
     * Get volume sold.
     *
     * The sum of volumes of all position 'sell' trades.
     *
     *
     * @return                          volume sold
     */
    Volume GetVolumeSold() const;

    /**
     * Check if field is set.
     *
     * The sum of volumes of position 'sell' trades made since the start of
     * today.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolumeSoldDaily() const;

    /**
     * Get volume sold daily.
     *
     * The sum of volumes of position 'sell' trades made since the start of
     * today.
     *
     *
     * @return                          volume sold daily
     */
    Volume GetVolumeSoldDaily() const;

    /**
     * Check if field is set.
     *
     * The sum of volumes of position 'sell' trades made since the start of
     * this month.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolumeSoldMonthly() const;

    /**
     * Get volume sold monthly.
     *
     * The sum of volumes of position 'sell' trades made since the start of
     * this month.
     *
     *
     * @return                          volume sold monthly
     */
    Volume GetVolumeSoldMonthly() const;

    /**
     * Check if field is set.
     *
     * The sum of volumes of position 'sell' trades made since the start of
     * this year.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolumeSoldYearly() const;

    /**
     * Get volume sold yearly.
     *
     * The sum of volumes of position 'sell' trades made since the start of
     * this year.
     *
     *
     * @return                          volume sold yearly
     */
    Volume GetVolumeSoldYearly() const;

    /**
     * Check if field is set.
     *
     * The gross trade amount bought in actual cash for this position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasGrossTradeAmountBought() const;

    /**
     * Get gross trade amount bought.
     *
     * The gross trade amount bought in actual cash for this position.
     *
     *
     * @return                          gross trade amount bought
     */
    Double GetGrossTradeAmountBought() const;

    /**
     * Check if field is set.
     *
     * The gross trade amount bought daily in actual cash for this
     * position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasGrossTradeAmountBoughtDaily() const;

    /**
     * Get gross trade amount bought daily.
     *
     * The gross trade amount bought daily in actual cash for this
     * position.
     *
     *
     * @return                          gross trade amount bought daily
     */
    Double GetGrossTradeAmountBoughtDaily() const;

    /**
     * Check if field is set.
     *
     * The gross trade amount bought monthly in actual cash for this
     * position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasGrossTradeAmountBoughtMonthly() const;

    /**
     * Get gross trade amount bought monthly.
     *
     * The gross trade amount bought monthly in actual cash for this
     * position.
     *
     *
     * @return                          gross trade amount bought monthly
     */
    Double GetGrossTradeAmountBoughtMonthly() const;

    /**
     * Check if field is set.
     *
     * The gross trade amount bought yearly in actual cash for this
     * position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasGrossTradeAmountBoughtYearly() const;

    /**
     * Get gross trade amount bought yearly.
     *
     * The gross trade amount bought yearly in actual cash for this
     * position.
     *
     *
     * @return                          gross trade amount bought yearly
     */
    Double GetGrossTradeAmountBoughtYearly() const;

    /**
     * Check if field is set.
     *
     * The gross trade amount sold in actual cash for this position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasGrossTradeAmountSold() const;

    /**
     * Get gross trade amount sold.
     *
     * The gross trade amount sold in actual cash for this position.
     *
     *
     * @return                          gross trade amount sold
     */
    Double GetGrossTradeAmountSold() const;

    /**
     * Check if field is set.
     *
     * The gross trade amount sold daily in actual cash for this position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasGrossTradeAmountSoldDaily() const;

    /**
     * Get gross trade amount sold daily.
     *
     * The gross trade amount sold daily in actual cash for this position.
     *
     *
     * @return                          gross trade amount sold daily
     */
    Double GetGrossTradeAmountSoldDaily() const;

    /**
     * Check if field is set.
     *
     * The gross trade amount sold monthly in actual cash for this
     * position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasGrossTradeAmountSoldMonthly() const;

    /**
     * Get gross trade amount sold monthly.
     *
     * The gross trade amount sold monthly in actual cash for this
     * position.
     *
     *
     * @return                          gross trade amount sold monthly
     */
    Double GetGrossTradeAmountSoldMonthly() const;

    /**
     * Check if field is set.
     *
     * The gross trade amount sold yearly in actual cash for this position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasGrossTradeAmountSoldYearly() const;

    /**
     * Get gross trade amount sold yearly.
     *
     * The gross trade amount sold yearly in actual cash for this position.
     *
     *
     * @return                          gross trade amount sold yearly
     */
    Double GetGrossTradeAmountSoldYearly() const;

    /**
     * Check if field is set.
     *
     * Total fee paid for all position trades.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasFee() const;

    /**
     * Get fee.
     *
     * Total fee paid for all position trades.
     *
     *
     * @return                          fee
     */
    Double GetFee() const;

    /**
     * Check if field is set.
     *
     * The sum of fees paid for position trades made since the start of
     * today.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasFeeDaily() const;

    /**
     * Get fee daily.
     *
     * The sum of fees paid for position trades made since the start of
     * today.
     *
     *
     * @return                          fee daily
     */
    Double GetFeeDaily() const;

    /**
     * Check if field is set.
     *
     * The sum of fees paid for position trades made since the start of
     * this month.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasFeeMonthly() const;

    /**
     * Get fee monthly.
     *
     * The sum of fees paid for position trades made since the start of
     * this month.
     *
     *
     * @return                          fee monthly
     */
    Double GetFeeMonthly() const;

    /**
     * Check if field is set.
     *
     * The sum of fees paid for position trades made since the start of
     * this year.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasFeeYearly() const;

    /**
     * Get fee yearly.
     *
     * The sum of fees paid for position trades made since the start of
     * this year.
     *
     *
     * @return                          fee yearly
     */
    Double GetFeeYearly() const;

    /**
     * Check if field is set.
     *
     * Number of position trades that originated from orders that added
     * liquidity before traded.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLiquidityAddedCount() const;

    /**
     * Get liquidity added count.
     *
     * Number of position trades that originated from orders that added
     * liquidity before traded.
     *
     *
     * @return                          liquidity added count
     */
    Integer GetLiquidityAddedCount() const;

    /**
     * Check if field is set.
     *
     * Number of position trades that originated from orders that removed
     * liquidity before traded.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLiquidityRemovedCount() const;

    /**
     * Get liquidity removed count.
     *
     * Number of position trades that originated from orders that removed
     * liquidity before traded.
     *
     *
     * @return                          liquidity removed count
     */
    Integer GetLiquidityRemovedCount() const;

    /**
     * Check if field is set.
     *
     * The gross amount of the position, since the start of today.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInvestedDaily() const;

    /**
     * Get invested daily.
     *
     * The gross amount of the position, since the start of today.
     *
     *
     * @return                          invested daily
     */
    Double GetInvestedDaily() const;

    /**
     * Check if field is set.
     *
     * The gross amount of the position, since the start of this month.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInvestedMonthly() const;

    /**
     * Get invested monthly.
     *
     * The gross amount of the position, since the start of this month.
     *
     *
     * @return                          invested monthly
     */
    Double GetInvestedMonthly() const;

    /**
     * Check if field is set.
     *
     * The gross amount of the position, since the start of this year.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInvestedYearly() const;

    /**
     * Get invested yearly.
     *
     * The gross amount of the position, since the start of this year.
     *
     *
     * @return                          invested yearly
     */
    Double GetInvestedYearly() const;

    /**
     * Check if field is set.
     *
     * The gross amount of the open position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOpenInvested() const;

    /**
     * Get open invested.
     *
     * The gross amount of the open position.
     *
     *
     * @return                          open invested
     */
    Double GetOpenInvested() const;

    /**
     * Check if field is set.
     *
     * The gross amount of the open position, since the start of today.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOpenInvestedDaily() const;

    /**
     * Get open invested daily.
     *
     * The gross amount of the open position, since the start of today.
     *
     *
     * @return                          open invested daily
     */
    Double GetOpenInvestedDaily() const;

    /**
     * Check if field is set.
     *
     * The gross amount of the open position, since the start of this
     * month.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOpenInvestedMonthly() const;

    /**
     * Get open invested monthly.
     *
     * The gross amount of the open position, since the start of this
     * month.
     *
     *
     * @return                          open invested monthly
     */
    Double GetOpenInvestedMonthly() const;

    /**
     * Check if field is set.
     *
     * The gross amount of the open position, since the start of this year.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOpenInvestedYearly() const;

    /**
     * Get open invested yearly.
     *
     * The gross amount of the open position, since the start of this year.
     *
     *
     * @return                          open invested yearly
     */
    Double GetOpenInvestedYearly() const;

    /**
     * Check if field is set.
     *
     * The reference price used for open invested daily.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasReferencePriceDaily() const;

    /**
     * Get reference price daily.
     *
     * The reference price used for open invested daily.
     *
     *
     * @return                          reference price daily
     */
    Double GetReferencePriceDaily() const;

    /**
     * Check if field is set.
     *
     * The reference price used for open invested monthly.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasReferencePriceMonthly() const;

    /**
     * Get reference price monthly.
     *
     * The reference price used for open invested monthly.
     *
     *
     * @return                          reference price monthly
     */
    Double GetReferencePriceMonthly() const;

    /**
     * Check if field is set.
     *
     * The reference price used for open invested yearly.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasReferencePriceYearly() const;

    /**
     * Get reference price yearly.
     *
     * The reference price used for open invested yearly.
     *
     *
     * @return                          reference price yearly
     */
    Double GetReferencePriceYearly() const;

    /**
     * Check if field is set.
     *
     * Number of position trades that were buy side.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradeBoughtCount() const;

    /**
     * Get trade bought count.
     *
     * Number of position trades that were buy side.
     *
     *
     * @return                          trade bought count
     */
    Integer GetTradeBoughtCount() const;

    /**
     * Check if field is set.
     *
     * Number of position trades that were sell side.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradeSoldCount() const;

    /**
     * Get trade sold count.
     *
     * Number of position trades that were sell side.
     *
     *
     * @return                          trade sold count
     */
    Integer GetTradeSoldCount() const;

    /**
     * Check if field is set.
     *
     * Total number of trades in the position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradeCount() const;

    /**
     * Get trade count.
     *
     * Total number of trades in the position.
     *
     *
     * @return                          trade count
     */
    Integer GetTradeCount() const;

    /**
     * Check if field is set.
     *
     * Client identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasClient() const;

    /**
     * Get client.
     *
     * Client identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          client
     */
    TreeNodeIdentifier GetClient() const;

    /**
     * Check if field is set.
     *
     * Counterpart identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpartIdentifier() const;

    /**
     * Get counterpart identifier.
     *
     * Counterpart identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          counterpart identifier
     */
    TreeNodeIdentifier GetCounterpartIdentifier() const;

    /**
     * Check if field is set.
     *
     * Handler identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandler() const;

    /**
     * Get handler.
     *
     * Handler identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          handler
     */
    TreeNodeIdentifier GetHandler() const;

    /**
     * Check if field is set.
     *
     * Owner identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOwner() const;

    /**
     * Get owner.
     *
     * Owner identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          owner
     */
    UserIdentifier GetOwner() const;

    /**
     * Check if field is set.
     *
     * Counterpart of the position trades. Present only when aggregating by
     * this field.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpart() const;

    /**
     * Get counterpart.
     *
     * Counterpart of the position trades. Present only when aggregating by
     * this field.
     *
     *
     * @return                          counterpart
     */
    String GetCounterpart() const;

    /**
     * Check if field is set.
     *
     * Strategy identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyIdentifier() const;

    /**
     * Get strategy identifier.
     *
     * Strategy identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          strategy identifier
     */
    StrategyIdentifier GetStrategyIdentifier() const;

    /**
     * Check if field is set.
     *
     * Root strategy identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRootStrategyIdentifier() const;

    /**
     * Get root strategy identifier.
     *
     * Root strategy identifier of the position trades. Present only when
     * aggregating by this field.
     *
     *
     * @return                          root strategy identifier
     */
    StrategyIdentifier GetRootStrategyIdentifier() const;

    /**
     * Check if field is set.
     *
     * Identifier of the last trade that affected this position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastTradeIdentifier() const;

    /**
     * Get last trade identifier.
     *
     * Identifier of the last trade that affected this position.
     *
     *
     * @return                          last trade identifier
     */
    TradeIdentifier GetLastTradeIdentifier() const;

    /**
     * Check if field is set.
     *
     * Block order leg identifier from the last trade that affected this
     * position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastBlockOrderLegIdentifier() const;

    /**
     * Get last block order leg identifier.
     *
     * Block order leg identifier from the last trade that affected this
     * position.
     *
     *
     * @return                          last block order leg identifier
     */
    BlockOrderLegIdentifier GetLastBlockOrderLegIdentifier() const;

    /**
     * Check if field is set.
     *
     * Directed quote identifier from the last trade that affected this
     * position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastDirectedQuoteIdentifier() const;

    /**
     * Get last directed quote identifier.
     *
     * Directed quote identifier from the last trade that affected this
     * position.
     *
     *
     * @return                          last directed quote identifier
     */
    DirectedQuoteIdentifier GetLastDirectedQuoteIdentifier() const;

    /**
     * Check if field is set.
     *
     * ExPit identifier from the last trade that affected this position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastExPitIdentifier() const;

    /**
     * Get last expit identifier.
     *
     * ExPit identifier from the last trade that affected this position.
     *
     *
     * @return                          last expit identifier
     */
    ExPitIdentifier GetLastExPitIdentifier() const;

    /**
     * Check if field is set.
     *
     * Order identifier from the last trade that affected this position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastOrderIdentifier() const;

    /**
     * Get last order identifier.
     *
     * Order identifier from the last trade that affected this position.
     *
     *
     * @return                          last order identifier
     */
    OrderIdentifier GetLastOrderIdentifier() const;

    /**
     * Check if field is set.
     *
     * Quote identifier from the last trade that affected this position.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastQuoteIdentifier() const;

    /**
     * Get last quote identifier.
     *
     * Quote identifier from the last trade that affected this position.
     *
     *
     * @return                          last quote identifier
     */
    Identifier GetLastQuoteIdentifier() const;

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
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAccruedDaily() const;

    /**
     * Get accrued daily.
     *
     *
     * @return                          accrued daily
     */
    Double GetAccruedDaily() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAccruedMonthly() const;

    /**
     * Get accrued monthly.
     *
     *
     * @return                          accrued monthly
     */
    Double GetAccruedMonthly() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAccruedYearly() const;

    /**
     * Get accrued yearly.
     *
     *
     * @return                          accrued yearly
     */
    Double GetAccruedYearly() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    PositionBase(const protocol::PortfolioPosition & value);
    PositionBase(std::shared_ptr<protocol::PortfolioPosition> && value);

    std::shared_ptr<protocol::PortfolioPosition> & get_impl_wr() const;
    const std::shared_ptr<protocol::PortfolioPosition> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::PortfolioPosition> m_impl;
};

}
