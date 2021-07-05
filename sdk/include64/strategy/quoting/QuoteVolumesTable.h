#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteVolumesTable object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Types.h"

#include "strategy/type/QuotePegFallbackBehavior.h"
#include "strategy/quoting/QuoteIdentification.h"

#include <map>
#include <optional>

namespace tbricks {

class STRATEGY_EXPORT QuoteVolumesTable : public Printable
{
public:
    QuoteVolumesTable();
    QuoteVolumesTable(const QuoteVolumesTable & volumes);
    QuoteVolumesTable & operator=(const QuoteVolumesTable & volumes);
    virtual ~QuoteVolumesTable();

public:
    void AddTotalVolumes(const QuoteIdentification & id, const Volume & bid, const Volume & ask);

    bool GetTotalVolumes(const QuoteIdentification & id, Volume & bid, Volume & ask) const;

    void SetIsVolumesActive(const QuoteIdentification & id, const Boolean & is_bid_active, const Boolean & is_ask_active);

    bool GetIsVolumesActive(const QuoteIdentification & id, Boolean & is_bid_active, Boolean & is_ask_active) const;

    void SetQuotePriorityFactor(const QuoteIdentification & id, const Double & quote_bid_priority_factor, const Double & quote_ask_priority_factor);

    bool GetQuotePriorityFactor(const QuoteIdentification & id, Double & quote_bid_priority_factor, Double & quote_ask_priority_factor) const;

    void SetPegOffsets(const QuoteIdentification & id, const Integer & bid_offset, const Integer & ask_offset);

    bool GetPegOffsets(const QuoteIdentification & id, Integer & bid_offset, Integer & ask_offset) const;

    void SetVolumeThresholds(const QuoteIdentification & id, const Volume & bid_threshold, const Volume & ask_threshold);

    bool GetVolumeThresholds(const QuoteIdentification & id, Volume & bid_threshold, Volume & ask_threshold) const;

    void SetMinimumMarketVolumeThresholds(const QuoteIdentification & id, const Double & bid, const Double & ask);

    bool GetMinimumMarketVolumeThresholds(const QuoteIdentification & id, Double & bid, Double & ask) const;

    void SetVolumesMatchMarket(const QuoteIdentification & id, const Boolean & match_bid, const Boolean & match_ask);

    bool GetVolumesMatchMarket(const QuoteIdentification & id, Boolean & match_bid, Boolean & match_ask) const;

    void SetMaximumVolumes(const QuoteIdentification & id, const Volume & bid_max_volume, const Volume & ask_max_volume);

    bool GetMaximumVolumes(const QuoteIdentification & id, Volume & bid_max_volume, Volume & ask_max_volume) const;

    void SetEdgeVolumeFactors(const QuoteIdentification & id, const Double & bid_volume_factor, const Double & ask_volume_factor);

    bool GetEdgeVolumeFactors(const QuoteIdentification & id, Double & bid_volume_factor, Double & ask_volume_factor) const;

    void SetPegThroughputLimits(const QuoteIdentification & id, const Integer & bid_throughput_limit, const Integer & ask_throughput_limit);

    bool GetPegThroughputLimits(const QuoteIdentification & id, Integer & bid_throughput_limit, Integer & ask_throughput_limit);

    void SetPegThroughputTimeWindows(const QuoteIdentification & id,
                                     const Duration & bid_throughput_time_window,
                                     const Duration & ask_throughput_time_window);

    bool GetPegThroughputTimeWindows(const QuoteIdentification & id, Duration & bid_throughput_time_window, Duration & ask_throughput_time_window);

    void
    SetPegThrottlingDurations(const QuoteIdentification & id, const Duration & bid_throttling_duration, const Duration & ask_throttling_duration);

    bool GetPegThrottlingDurations(const QuoteIdentification & id, Duration & bid_throttling_duration, Duration & ask_throttling_duration);

    void SetRequestForQuoteIdentifier(const QuoteIdentification & id,
                                      const Identifier & bid_request_for_quote_id,
                                      const Identifier & ask_request_for_quote_id);

    bool GetRequestForQuoteIdentifier(const QuoteIdentification & id, Identifier & bid_request_for_quote_id, Identifier & ask_request_for_quote_id);

    void SetPegFallbackBehavior(const QuoteIdentification & id, const QuotePegFallbackBehavior & peg_behaviour);

    bool GetPegFallbackBehavior(const QuoteIdentification & id, QuotePegFallbackBehavior & peg_behaviour);

public:
    void Clear();

    bool Empty() const;

public:
    const std::vector<QuoteIdentification>::const_iterator begin() const;

    const std::vector<QuoteIdentification>::const_iterator end() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    struct QuoteVolume : public Printable
    {
        Boolean m_is_active;
        Volume m_volume;
        Double m_quote_priority_factor;
        Volume m_volume_threshold;
        Double m_minimum_market_volume_threshold;
        Integer m_peg_offset;
        Boolean m_match_market;
        Volume m_max_volume;
        Double m_edge_volume_factor;
        Integer m_peg_throughput_limit;
        Duration m_peg_throughput_time_window;
        Duration m_peg_throttling_duration;
        Identifier m_request_for_quote_id;
        std::optional<QuotePegFallbackBehavior> m_peg_fallback_behavior;

        bool Empty() const { return m_volume.Empty(); }

        void Clear();

        QuoteVolume() = default;

        virtual std::ostream & Print(std::ostream & strm) const;
    };

    void set(const QuoteIdentification & id, std::unique_ptr<QuoteVolume> && bid, std::unique_ptr<QuoteVolume> && ask);

    template <typename T>
    void set(const QuoteIdentification & id, T QuoteVolume::*v, const T & bid, const T & ask);

    template <typename T>
    bool get(const QuoteIdentification & id, T QuoteVolume::*v, T & bid, T & ask) const;

private:
    friend STRATEGY_EXPORT class Converter;
    friend STRATEGY_EXPORT class QuoteSet;

    void Merge(const QuoteVolumesTable & volumes);

private:
    std::vector<QuoteIdentification> m_quotes;
    std::vector<std::unique_ptr<QuoteVolume>> m_bid;
    std::vector<std::unique_ptr<QuoteVolume>> m_ask;
};

} // namespace tbricks
