#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingLimitRuleProvider
//****************************************************************************************

#include "strategy/Linkage.h"

namespace tbricks {

class Instrument;
class InstrumentIdentifier;
class LimitsWarmupRequest;
class TradingAggregatedLimitRule;
class TradingLimitRule;
class TradingLimitRuleRequest;

class STRATEGY_EXPORT TradingLimitRuleProvider
{
public:
    TradingLimitRuleProvider();
    virtual ~TradingLimitRuleProvider();

    TradingLimitRuleProvider(const TradingLimitRuleProvider &) = delete;
    TradingLimitRuleProvider & operator=(const TradingLimitRuleProvider &) = delete;

    virtual void HandleProvideGeneralRulesRequest(const TradingLimitRuleRequest & request) = 0;

    virtual void HandleProvideInstrumentRulesRequest(const TradingLimitRuleRequest & request, const InstrumentIdentifier & instrument_id);

    /*
     * Warmup request contains a instrument filter, that gives a hint about instruments
     * for which in the future limits will be requested. If warmup identifier of tradin
     * limit rule request is equal to identifier of warmup request, it means that the instrument
     * of tradin limit rule request gets into the instrument filter of this warmup request.
     */
    virtual void HandleLimitsWarmupRequest(const LimitsWarmupRequest & request);

    /*
     * Use this method to delete all rules previously provided by the plugin.
     * This method is automatically called after HandleDeleteRequest(), HandlePauseRequest()
     * callbacks and before app recovery. Also, in such situations, all trading limit rule
     * requests, received by plugin, automatically completed.
     */
    void DeleteAllRules() const;

    /*
     * Updates limit rule.
     *
     * Whenever a rule is updated as a response to a rule request,
     * UpdateRule(request, limitrule) should be called.
     * It can be done either synchronously when the rule is requested,
     * or asynchronously in case some data needed retrieval before
     * the rule could be updated.
     *
     * UpdateRule(limitrule) should be called whenever the rule has been
     * updated due to new data becoming avaliable.
     *
     * DeleteRule(limitrule) will throw exception if limitrule does not
     * have identifier or if identifier is empty.
     *
     * @param request          Trading limit rule request
     * @param limitrule        Limit rule
     */
    void UpdateRule(const TradingLimitRuleRequest & request, TradingLimitRule & limitrule) const;

    void UpdateRule(TradingLimitRule & limitrule) const;
    void DeleteRule(TradingLimitRule & limitrule) const;

    void UpdateRule(const TradingLimitRuleRequest & request, TradingAggregatedLimitRule & limitrule) const;

    void UpdateRule(TradingAggregatedLimitRule & limitrule) const;
    void DeleteRule(TradingAggregatedLimitRule & limitrule) const;
};
}
