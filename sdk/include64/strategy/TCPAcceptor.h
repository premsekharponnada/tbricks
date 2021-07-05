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
#include "strategy/stream/TCPStream.h"

namespace tbricks {

class STRATEGY_EXPORT TCPAcceptor : public Printable
{
public:
    class IHandler;

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Accept() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    TCPAcceptor();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    TCPAcceptor(IHandler & handler);

    virtual ~TCPAcceptor();

    /**
     * %Set callback interface.
     *
     * Associates current object with a callback interface where
     * events will be delivered to.
     *
     * @param handler                   Callback interface
     */
    void SetCallback(IHandler & handler);

    /**
     * Start accept remote tcp connections.
     *
     * If accept is already opened, the call has no effect.
     *
     * @param port                      Local port
     */
    bool Accept(uint16_t port);

    /**
     * Start accept remote tcp connections.
     *
     * If accept is already opened, the call has no effect.
     *
     * @param port                      Local port
     * @param options                   Options, will be applied to accepted connections
     */
    bool Accept(uint16_t port, const TCPStream::Options & options);

    /**
     * Start accept remote tcp connections on any free port.
     *
     * If accept is already opened, the call has no effect.
     */
    bool Accept();

    /**
     * Start accept remote tcp connections on any free port.
     *
     * If accept is already opened, the call has no effect.
     *
     * @param options                   Options, will be applied to accepted connections
     */
    bool Accept(const TCPStream::Options & options);

    /**
     * Get local port.
     *
     * @return                          Local port
     */
    uint16_t GetPort() const { return m_port; }

    /**
     * Stop accept remote tcp connections.
     */
    void Close();

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    IHandler * m_handler;
    Uuid m_id;
    uint16_t m_port;
};

class STRATEGY_EXPORT TCPAcceptor::IHandler
{
public:
    /**
     * NOTE: This is a plain pointer and the app should explicitly delete it after Acceptor is closed.
     * Smart pointer is not needed here because -
     * Handler object can exist only within the plugin context.
     * Hence plugin should control ownership and freeing of it.
     * There is no reason to retain the Handler object outside plugin.
     */
    virtual TCPStream::IHandler * HandleConnectionEstablished(TCPStream & stream) = 0;

protected:
    virtual ~IHandler();
};
}
