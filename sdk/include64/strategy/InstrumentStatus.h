#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument Status object.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Value.h"
#include "strategy/MarketDataParameters.h"

namespace tbricks {

namespace protocol {
class InstrumentStatus;
}

class STRATEGY_EXPORT InstrumentStatus : public Printable
{
public:
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"
#endif
    enum InstrumentMarketDataStatus
    {
        InstrumentMarketDataStatusUnknown = 1,
        InstrumentMarketDataStatusStale = 2,
        InstrumentMarketDataStatusOk = 3
    };

    enum InstrumentTradingStatus
    {
        InstrumentTradingStatusUnknown = 1,
        InstrumentTradingStatusTradingNotAllowed = 2,
        InstrumentTradingStatusTradingTemporarilyNotAllowed = 3,
        InstrumentTradingStatusTradingAllowed = 4
    };

    enum InstrumentTradingPhase
    {
        InstrumentTradingPhasePreOpen =
            0, ///< Phase prior to opening with limited interaction and visibility, no matching (same meaning as "Pre trading").
        InstrumentTradingPhaseOpening =
            1, ///< Transition phase to commence regular trading, possibly with limited interaction and visibility, matching occurs.
        InstrumentTradingPhaseOpeningAuction = 2,  ///< Transition phase to commence regular trading by using an auction.
        InstrumentTradingPhaseTrading = 3,         ///< Phase for normal trading (also called continuous or regular trading).
        InstrumentTradingPhaseIntradayAuction = 4, ///< @deprecated Deprecated in 2.14.3, use InstrumentTradingPhaseUnscheduledIntradayAuction and
                                                   ///< InstrumentTradingPhaseScheduledIntradayAuction instead
        InstrumentTradingPhaseUnscheduledIntradayAuction = 4, ///< Unscheduled temporary interruption of regular trading to conduct an auction,
                                                              ///< typically a result of exchange circuit breaker or resuming trading after.
        InstrumentTradingPhasePreClose = 5,                   ///< Phase prior to closing with limited interaction and visibility, no matching.
        InstrumentTradingPhaseClosing =
            6, ///< Transition phase to end regular trading, possibly with limited interaction and visibility, matching occurs.
        InstrumentTradingPhaseClosingAuction = 7, ///< Transition phase to end regular trading by using an auction.
        InstrumentTradingPhaseLastAuction =
            8, ///< Transition phase to end regular trading, possibly with limited interaction and visibility, matching occurs only on last.
        InstrumentTradingPhasePostTrading = 9,        ///< Phase after closing with limited interaction and visibility, no matching.
        InstrumentTradingPhaseClosed = 10,            ///< Market closed.
        InstrumentTradingPhaseHalted = 11,            ///< Market halted, technical reasons normally, no interaction or matching.
        InstrumentTradingPhaseSuspended = 12,         ///< Normal phase suspended due to regulatory reasons, limited interaction and no matching.
        InstrumentTradingPhaseFast = 13,              ///< Accelerated trading, different matching, different trading rules and reduced visibility.
        InstrumentTradingPhaseUnknown = 14,           ///< Unknown market phase, only set when there is lack of information or N/A status.
        InstrumentTradingPhaseBuyback = 15,           ///< Buyback status of issuer managed derivatives, restrictions on orders and quotes may apply.
        InstrumentTradingPhaseContinuousAuction = 16, ///< Continuous auction trading phase.
        InstrumentTradingPhaseScheduledIntradayAuction = 17 ///< Scheduled temporary interruption of regular trading to conduct an auction.
    };
#ifdef __clang__
#pragma clang diagnostic pop
#endif

public:
    InstrumentStatus();
    InstrumentStatus(const InstrumentStatus & instrument_status);
    InstrumentStatus & operator=(const InstrumentStatus & instrument_status);
    virtual ~InstrumentStatus();

    bool IsMarketDataStatusUnknown() const;
    bool IsMarketDataStatusStale() const;
    bool IsMarketDataStatusOk() const;
    bool IsTradingStatusUnknown() const;
    bool IsTradingNotAllowed() const;
    bool IsTradingTemporarilyNotAllowed() const;
    bool IsTradingAllowed() const;
    bool IsTradingPhasePreOpen() const;
    bool IsTradingPhaseOpening() const;
    bool IsTradingPhaseClosed() const;
    bool IsTradingPhaseHalted() const;
    bool IsTradingPhaseSuspended() const;
    bool IsTradingPhaseFast() const;
    bool IsTradingPhaseUnknown() const;
    bool IsTradingPhaseBuyback() const;
    bool IsTradingPhaseOpeningAuction() const;
    bool IsTradingPhaseTrading() const;

    /**
     * @deprecated Deprecated in 2.14.3,
     * use IsTradingPhaseScheduledIntradayAuction() and IsTradingPhaseUnscheduledIntradayAuction() instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool IsTradingPhaseIntradayAuction() const;

    bool IsTradingPhasePreClose() const;
    bool IsTradingPhaseClosing() const;
    bool IsTradingPhaseClosingAuction() const;
    bool IsTradingPhaseLastAuction() const;
    bool IsTradingPhasePostTrading() const;
    bool IsTradingPhaseContinuousAuction() const;
    bool IsTradingPhaseScheduledIntradayAuction() const;
    bool IsTradingPhaseUnscheduledIntradayAuction() const;

    bool IsAuction() const;
    bool IsNormalAuction() const;
    bool IsContinuousMatching() const;
    bool CanEnterOrder() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasInstrumentMarketDataStatus() const;

    /**
     * Get instrument market data status.
     *
     * Specifies the unified instrument market data status. Many venue specific
     * states will have to be mapped into these simple and interpretable
     * generic states.
     *
     * @return                          Instrument market data status
     */
    InstrumentMarketDataStatus GetInstrumentMarketDataStatus() const;

    /**
     * %Set instrument market data status.
     *
     * @param status                    Instrument market data status
     */
    void SetInstrumentMarketDataStatus(InstrumentMarketDataStatus status);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasInstrumentTradingStatus() const;

    /**
     * Get instrument trading status.
     *
     * Specifies the unified instrument trading status. Many venue specific
     * states will have to be mapped into these simple and interpretable
     * generic states.
     *
     * @return                          Instrument trading status
     */
    InstrumentTradingStatus GetInstrumentTradingStatus() const;

    /**
     * %Set instrument trading status.
     *
     * @param status                    Instrument trading status
     */
    void SetInstrumentTradingStatus(InstrumentTradingStatus status);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasInstrumentTradingPhase() const;

    /**
     * Get instrument trading phase.
     *
     * Specifies the instrument trading phase.
     *
     * @return                          Instrument trading phase
     */
    InstrumentTradingPhase GetInstrumentTradingPhase() const;

    /**
     * %Set instrument trading phase.
     *
     * @param status                    Instrument trading phase
     */
    void SetInstrumentTradingPhase(InstrumentTradingPhase phase);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasVenueInstrumentMarketDataStatus() const;

    /**
     * Get venue instrument market data status.
     *
     * Market specific textual description of the instrument market data status
     * where venue specific interpretation can be used.
     *
     * @return                          Instrument venue market data status
     */
    String GetVenueInstrumentMarketDataStatus() const;

    /**
     * %Set venue instrument market data status.
     *
     * @param status                    Instrument venue market data status
     */
    void SetVenueInstrumentMarketDataStatus(const String & status);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasVenueInstrumentTradingStatus() const;

    /**
     * Get venue instrument trading status.
     *
     * Market specific textual description of the instrument market data status
     * where venue specific interpretation can be used.
     *
     * @return                          Instrument venue instrument trading status
     */
    String GetVenueInstrumentTradingStatus() const;

    /**
     * %Set venue instrument trading status.
     *
     * @param status                    Instrument venue instrument trading status
     */
    void SetVenueInstrumentTradingStatus(const String & status);

    /**
     * Get datetime of last modification.
     *
     * Returns datetime of last instrument status modification.
     *
     * @return                          Modified datetime
     */
    DateTime GetHostModifiedDatetime() const;

    /**
     * %Set datetime of last modification.
     *
     * @param datetime                   Datetime of last instrument status modification.
     */
    void SetHostModifiedDateTime(const DateTime & datetime);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasAuctionExtension() const;

    /**
     * Get auction extension flag.
     *
     * @return                          Instrument auction extension flag
     */
    Boolean GetAuctionExtension() const;

    /**
     * %Set auction extension flag
     *
     * @param auction_extension                    Instrument auction extension flag
     */
    void SetAuctionExtension(const Boolean & auction_extension);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasInstrumentTradingPhaseEndingTime() const;

    /**
     * Get instrument trading phase ending time.
     *
     * @return                          Instrument trading phase ending time
     */
    Time GetInstrumentTradingPhaseEndingTime() const;

    /**
     * %Set instrument trading phase ending time.
     *
     * @param time                      Instrument trading phase ending time
     */
    void SetInstrumentTradingPhaseEndingTime(const Time & time) const;

    /**
     * Get market data parameters.
     *
     * @return                          Market data parameters
     */
    MarketDataParameters GetMarketDataParameters() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasMarketDataParameters() const;

    /**
     * %Set market data parameters.
     *
     * If parameters are empty, then field will be cleared.
     *
     * @param                           Market data parameters
     */
    void SetMarketDataParameters(const MarketDataParameters & param);

    void Merge(const InstrumentStatus & instrument_status);

    bool Empty() const;
    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

    static std::ostream & PrintTradingStatus(std::ostream & strm, InstrumentTradingStatus status);
    static std::ostream & PrintTradingPhase(std::ostream & strm, InstrumentTradingPhase phase);
    static InstrumentTradingStatus GetTradingStatusByPhase(InstrumentTradingPhase phase);

public:
    tbricks::protocol::InstrumentStatus & get_instrument_status() const;
    InstrumentStatus(protocol::InstrumentStatus & status);

private:
    protocol::InstrumentStatus * m_instrument_status;
};

inline std::ostream & operator<<(std::ostream & strm, InstrumentStatus::InstrumentTradingStatus status)
{
    return InstrumentStatus::PrintTradingStatus(strm, status);
}

inline std::ostream & operator<<(std::ostream & strm, InstrumentStatus::InstrumentTradingPhase phase)
{
    return InstrumentStatus::PrintTradingPhase(strm, phase);
}
}
