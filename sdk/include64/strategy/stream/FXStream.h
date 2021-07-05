#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// FX stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/FX.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_throttle/CommonThrottle.h"

namespace tbricks {

class STRATEGY_EXPORT FX::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Options;

public:
    class AnyFilter;

public:
    Stream();
    Stream(IHandler & handler);

public:
    void SetCallback(IHandler & handler);

    void Open(Type type, const Options & options);

    virtual void Close();

    virtual bool IsOpen() const;
    virtual bool IsSnapshotDone() const;
    virtual bool IsStale() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    class FXStreamImpl;
    FXStreamImpl * m_stream;
};

/**
 * FX::Stream::IHandler
 */
class STRATEGY_EXPORT FX::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleFX(const StreamIdentifier & stream, const FX::Update & update) = 0;

protected:
    virtual ~IHandler();
};

/**
 * FX::Stream::Options
 */
class STRATEGY_EXPORT FX::Stream::Options : public Printable
{
public:
    Options();
    Options(const Options & options);
    Options & operator=(const Options & options);
    virtual ~Options();

public:
    /**
     * %Set instrument parameters throttle
     *
     * @param[in]   BasicThrottle
     */
    void SetInstrumentParametersThrottle(const BasicThrottle & throttle);

    /**
     * Get instrument parameters throttle
     *
     * @return      Basic throttle
     */
    const BasicThrottle & GetInstrumentParametersThrottle() const;

    /**
     * %Set currency pair
     *
     * @param[in]   currency_1
     * @param[in]   currency_2
     */
    void SetCurrencyPair(const Currency & currency_1, const Currency & currency_2);

    /**
     * Get currency pair
     *
     * @retrun      Pair<Currency, Currency>
     */
    const Pair<Currency, Currency> & GetCurrencyPair() const;

    /**
     * %Set parameter context
     *
     * @param[in]   Parameter context identifier
     */
    void SetParameterContext(const Identifier & parameter_context);

    /**
     * Get parameter context identifier
     *
     * @return      Parameter context identifier
     */
    const Identifier & GetParameterContext() const;

    /**
     * %Set parameter context ranking
     *
     * @param[in]   Parameter context ranking identifier
     */
    void SetParameterContextRanking(const Identifier & parameter_context_ranking);

    /**
     * Get parameter context ranking identifier
     *
     * @return      Parameter context ranking identifier
     */
    const Identifier & GetParameterContextRanking() const;

    /**
     * %Set Reference Price Date
     *
     * @param[in]   Reference Price Date
     */
    void SetReferencePriceDate(const DateTime & reference_price_date);

    /**
     * Get Reference Price Date
     *
     * @return      Reference Price Date
     */
    const DateTime & GetReferencePriceDate() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    BasicThrottle m_ip_throttle;
    Pair<Currency, Currency> m_currency_pair;
    Identifier m_parameter_context;
    Identifier m_parameter_context_ranking;
    DateTime m_reference_price_date;
};

} // namespace tbricks
