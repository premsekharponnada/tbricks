#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Algo label component stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream/AlgoLabelStream.h"
#include "strategy/GermanHFTAlgoLabel.h"

namespace tbricks {

class STRATEGY_EXPORT GermanHFTAlgoLabel::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open();

protected:
    std::ostream & Print(std::ostream & strm) const override;
};

class STRATEGY_EXPORT GermanHFTAlgoLabel::Stream::IHandler : public AlgoLabel::Stream::IHandler
{
public:
    virtual void HandleGermanHFTAlgoLabel(const StreamIdentifier & stream_id, const GermanHFTAlgoLabel & component) = 0;

protected:
    virtual ~IHandler();
};
}
