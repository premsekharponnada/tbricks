#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Stream is used to check limit rules.
//
//****************************************************************************************

#include "strategy/stream/TradingLimitRuleStream.h"
#include "strategy/stream/InstrumentStream.h"
#include "strategy/limit/TradingLimitRuleUpdate.h"
#include "strategy/stream_filter/TradingLimitRuleFilters.h"

namespace tbricks { namespace test {
class LSImpl;

class STRATEGY_EXPORT VirtualLimitRuleStream
{
public:
    class Options : public TradingLimitRule::Stream::Options
    {
    public:
        Options() = default;
        Options(const Options &) = default;
        Options & operator=(const Options &) = default;

        Options(const TradingLimitRule::Stream::Options & o) : TradingLimitRule::Stream::Options(o) {}

    public:
        /**
         * Set warmup request identifier
         *
         * @param warmup_id     Warmup request identifier
         */
        void SetWarmupRequestId(Identifier warmup_id) { m_warmup_id = warmup_id; }

        /**
         * Get warmup request identifier
         *
         * @return              Warmup request identifier
         */
        Identifier GetWarmupRequestId() const { return m_warmup_id; }

    private:
        Identifier m_warmup_id;
    };

public:
    VirtualLimitRuleStream();
    ~VirtualLimitRuleStream();

public:
    /**
     * Open limit stream to TestEngine for instrument rules.
     *
     * @param type           Stream type
     * @param options        Stream options
     */
    void Open(Stream::Type type, const InstrumentIdentifier & instrument, const Options & options = {});

    /**
     * Open limit stream to TestEngine for general rules.
     *
     * @param type           Stream type
     * @param options        Stream options
     */
    void Open(Stream::Type type, const Options & options = {});

    /**
     * Close limit stream.
     */
    void Close();

    /**
     * It waits until an update is sent and gets all received updates.
     * Recomended to use after the snapshot is received.
     *
     * @return               Update.
     */
    std::vector<TradingLimitRule::Update> WaitLimitRuleUpdates();

    /**
     * Wait for stream snapshot and get all received updates.
     * If updates already taken with "WaitLimitRuleUpdates",
     * empty will be returned.
     *
     * @return               Update.
     */
    std::vector<TradingLimitRule::Update> WaitLimitRuleSnapshot();

    /**
     * Wait for limit rule to be deleted.
     *
     * @return              Vector of identifiers from invalidated TradingLimitRule objects
     */
    std::vector<Identifier> WaitLimitRuleDelete();
    /**
     * Wait for stream snapshot.
     */
    void WaitSnapshotEnd();

    /**
     * Send limit rules warmup request
     *
     * @return              Identifier of the warmup request
     */
    Identifier SendLimitRulesWarmupRequest(const InstrumentStream::Filters::Filter & filter);

private:
    LSImpl * m_impl;
    VirtualLimitRuleStream(const VirtualLimitRuleStream &) = delete;
    VirtualLimitRuleStream & operator=(const VirtualLimitRuleStream &) = delete;
};

} // \namespace test
} // \namespace tbricks
