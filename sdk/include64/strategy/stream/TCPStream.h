#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TCP stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/Binary.h"
#include "strategy/stream/Stream.h"

namespace tbricks {

namespace pe {
class TCPModule;
class TCPStreamImpl;
}

class StrategyTCPStreamImpl;

enum class TCPDataType
{
    RAW,            /**< Raw tcp data */
    LENGTH_PREFIXED /**< Data from tcp stream will be splitted on length-prefixed messages (lenght prefix will be removed).
                       On data sending to all messages will be added prefix with message length. */
};

class STRATEGY_EXPORT TCPStream : public Stream
{
    friend class StrategyTCPAcceptorImpl;
    friend class StrategyTCPStreamImpl;
    friend class pe::TCPModule;

public:
    class IHandler;
    class Options;

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Connect() method will throws exception unless
     * SetCallback() is applied before.
     */
    TCPStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    TCPStream(IHandler & handler);

    /**
     * %Set callback interface.
     *
     * Associates current stream object with a callback interface where
     * stream updates will be delivered to.
     *
     * If stream is already opened this method has no effect.
     *
     * @param handler                   Callback interface
     */
    void SetCallback(IHandler & handler);

    /// @deprecated Deprecated in 2.14.5 use 'Connect()' with 'options' parameter instead.
    [[deprecated(DEPRECATE_LINK)]] void SetOutputSize(size_t size);
    /// @deprecated Deprecated in 2.14.5 use 'Connect()' with 'options' parameter instead.
    [[deprecated(DEPRECATE_LINK)]] size_t GetOutputSize() const;

    /// @deprecated Deprecated in 2.14.5 use 'Connect()' with 'options' parameter instead.
    [[deprecated(DEPRECATE_LINK)]] void SetOutputPrompt(const Binary & prompt);
    /// @deprecated Deprecated in 2.14.5 use 'Connect()' with 'options' parameter instead.
    [[deprecated(DEPRECATE_LINK)]] Binary GetOutputPrompt() const;

    /**
     * Open stream and connect to remote host.
     *
     * If stream is already opened, the call has no effect.
     *
     * @param host                      Remote host name or address
     * @param port                      Remote port
     */
    void Connect(const String & host, uint16_t port);

    /**
     * Open stream and connect to remote host.
     *
     * If stream is already opened, the call has no effect.
     *
     * @param host                      Remote host address or name
     * @param port                      Remote port
     * @param options                   Options
     */
    void Connect(const String & host, uint16_t port, const Options & options);

    /**
     * Send binary data to stream.
     *
     * @param data                      Binary data
     */
    void Send(const Binary & data);

    /**
     * Get remote host address.
     *
     * @return                          Remote host address
     */
    String GetHost() const;

    /**
     * Get remote port.
     *
     * @return                          Remote port
     */
    uint16_t GetPort() const;

protected:
    TCPStream(pe::TCPStreamImpl * stream_impl);
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyTCPStreamImpl * m_stream;
};

class STRATEGY_EXPORT TCPStream::IHandler
{
public:
    /**
     * Strategy stream update handler.
     *
     * Method is called when a new data becomes available on the stream.
     *
     * @param stream                    Reference to event originator stream
     * @param data                      Binary data
     */
    virtual void HandleData(TCPStream & stream, const Binary & data) = 0;

    /**
     * Stream open event.
     *
     * Called when tcp stream successfully connected to remote host.
     *
     * @param stream                    Reference to event originator stream
     */
    virtual void HandleStreamOpen(TCPStream & stream) = 0;

    /**
     * Stream close event.
     *
     * Called when tcp connection unexpectedly closed or closed from other side.
     * No updates will be delivered for the stream provided as a parameter
     * after this event.
     *
     * @param stream                    Reference to event originator stream
     */
    virtual void HandleStreamClose(TCPStream & stream) = 0;

protected:
    virtual ~IHandler();
};
}
