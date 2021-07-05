#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OwnPriceLevelQuoteBook stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/Stream.h"
#include "strategy/OwnPriceLevelQuoteBook.h"

namespace tbricks {

/**
 * OwnPriceLevelQuoteBook::Stream class
 */
class STRATEGY_EXPORT OwnPriceLevelQuoteBook::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Options;

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    Stream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    Stream(IHandler & handler);

    /**
     * %Set callback interface.
     * Associates current stream object with a callback interface where
     * stream updates will be delivered to.
     *
     * If stream is already opened this method has no effect.
     *
     * @param handler                   Callback interface
     */
    void SetCallback(IHandler & handler);

    /**
     * Open a stream.
     *
     * Opens a stream for a given system instrument identifier, a given
     * Instrument venue identifier and options.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Stream options
     */
    void Open(Type type, const Options & options);

    /**
     * Requests stream data snapshot
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    uint64_t GetSnapshot(OwnPriceLevelQuoteBook & snapshot) const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;
};

/**
 * OwnPriceLevelQuoteBook::Stream::IHandler class
 */
class STRATEGY_EXPORT OwnPriceLevelQuoteBook::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) override {}

    virtual void HandleQuoteInformation(const StreamIdentifier & stream_id, const OwnPriceLevelQuoteBook::Update & update) = 0;

protected:
    virtual ~IHandler() override;
};
}
