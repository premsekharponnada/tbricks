#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BestPrice stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/BestPrice.h"

#include "strategy/InstrumentVenueIdentification.h"

#include "strategy/stream/Stream.h"
#include "strategy/stream/BestPriceStream.h"
#include "strategy/stream/InstrumentStream.h"
#include "strategy/stream_throttle/BestPriceThrottle.h"
#include "strategy/stream/StreamOptions.h"

#include "strategy/Hash.h"

namespace tbricks {

class SnapBestPriceStreamOptions;

namespace strategy {
class SnapBestPriceStreamImpl;
}

/// @deprecated Deprecated in 2.13.0 as obsolete.
class STRATEGY_EXPORT[[deprecated(DEPRECATE_LINK)]] SnapBestPriceStream : public Stream
{
public:
    using Options = SnapBestPriceStreamOptions;

public:
    SnapBestPriceStream();
    SnapBestPriceStream(BestPriceStream::IHandler & handler);

    void SetCallback(BestPriceStream::IHandler & handler);

    void Open(Type type, const InstrumentIdentifier & instrument, const SnapBestPriceStreamOptions & options);

    virtual void Close();

    // IsStale() may not work properly for this stream.
    virtual bool IsStale() const;
    virtual bool IsOpen() const;
    virtual bool IsSnapshotDone() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    strategy::SnapBestPriceStreamImpl * m_stream;
};

/// SnapBestPriceStreamOptions
///
/// @deprecated Deprecated in 2.13.0 as obsolete.
class STRATEGY_EXPORT SnapBestPriceStreamOptions : public Printable
{
public:
    SnapBestPriceStreamOptions();
    SnapBestPriceStreamOptions(const SnapBestPriceStreamOptions & options);
    SnapBestPriceStreamOptions & operator=(const SnapBestPriceStreamOptions & options);
    virtual ~SnapBestPriceStreamOptions();

public:
    void SetCoalescing(bool coalescing);
    bool GetCoalescing() const;

    void SetBestPriceThrottle(const BestPriceThrottle & throttle);
    const BestPriceThrottle & GetBestPriceThrottle() const;
    BestPriceThrottle & GetBestPriceThrottle();

    void SetInstrumentParametersThrottle(const BasicThrottle & throttle);
    const BasicThrottle & GetInstrumentParametersThrottle() const;
    BasicThrottle & GetInstrumentParametersThrottle();

    void SetParameterContext(const Identifier & parameter_context);
    const Identifier & GetParameterContext() const;
    Identifier & GetParameterContext();

    void SetParameterContextRanking(const Identifier & parameter_context_ranking);
    const Identifier & GetParameterContextRanking() const;
    Identifier & GetParameterContextRanking();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    bool m_coalescing;
    BestPriceThrottle m_best_price_throttle;
    BasicThrottle m_instrument_parameters_throttle;
    Identifier m_parameter_context;
    Identifier m_parameter_context_ranking;
};
}
