#pragma once

//****************************************************************************
// Tbricks Strategy Framework.
//
// Copyright (c) 2006-2017 Tbricks AB.
//
// Distributed values object, stream, stream options, stream update.
//
//****************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/stream/Stream.h"

#include "strategy/type/ContextIdentifier.h"
#include "strategy/type/RankingIdentifier.h"
#include "strategy/stream_throttle/CommonThrottle.h"
#include "strategy/parameter/StrategyParameters.h"

#include "strategy/distributed_values/DistributedValueDefinition.h"
#include "strategy/distributed_values/DistributedValueIdentification.h"

namespace tbricks {

namespace test {
class STRATEGY_EXPORT VirtualDistributionStream;
}
// DistributedValues

class STRATEGY_EXPORT DistributedValues : public Printable
{
public:
    class Stream;
    class Update;
};

// DistributedValues::Update

class STRATEGY_EXPORT DistributedValues::Update : public Printable
{
public:
    Update();
    Update(const Update & update);
    Update & operator=(const Update & update);
    virtual ~Update();

public:
    class STRATEGY_EXPORT Iterator
    {
    public:
        Iterator();
        Iterator(const DistributedValues::Update & update);
        Iterator(const Iterator & iterator);
        Iterator & operator=(const Iterator & iterator);
        ~Iterator();

    public:
        const DistributedValueDefinition & GetDefinition() const;
        const DistributedValueIdentification & GetIdentification() const;

        bool GetValue(AnyType & value) const;

        bool operator==(const Iterator & iterator) const;
        bool operator!=(const Iterator & iterator) const;

        Iterator & operator++();
        Iterator operator++(int);

    private:
        class IteratorImpl;
        std::unique_ptr<IteratorImpl> m_impl;
    };

public:
    const Iterator begin() const;
    const Iterator end() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

/**
 * DistributedValues::Stream class is an interface to receive snapshots
 * and/or live instrument table updates.
 *
 * Stream is a reference to the internal stream object managed by
 * StrategyEngine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last Stream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 */
class STRATEGY_EXPORT DistributedValues::Stream : public tbricks::Stream
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
     * @param context                   Strategy context
     * @param handler                   Stream callback interface
     */
    Stream(IHandler & handler);

    /**
     * %Set callback interface.
     *
     * Associates current stream object with a callback interface where
     * stream updates will be delivered to.
     *
     * If stream is already opened this method has no effect.
     *
     * @param context                   Strategy context
     * @param handler                   Callback interface
     */
    void SetCallback(IHandler & handler);

    /**
     * Open a stream.
     *
     * Stream options allow to specify what specific distributed values
     * updates the caller is interested in.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Stream options
     */
    void Open(Type type, const Options & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * DistributedValues::Stream::IHandler class is a callback interface to
 * handle distributed values stream events.
 *
 * @see DistributedValues::Stream
 */
class STRATEGY_EXPORT DistributedValues::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & stream) {}

    /**
     * Calculated values stream update handler.
     *
     * Method is called when a new calculated values update becomes
     * available on the stream.
     *
     * @param stream                   Stream identifier
     * @param update                   Update data
     */
    virtual void HandleDistributedValues(const StreamIdentifier & identifier, const DistributedValues::Update & update) = 0;

protected:
    virtual ~IHandler();
};

// DistributedValues::Stream::Options

class STRATEGY_EXPORT DistributedValues::Stream::Options : public Printable
{
public:
    Options();
    Options(const Options & options);
    Options & operator=(const Options & options);
    virtual ~Options();

public:
    void Clear();
    bool Empty() const;

public:
    bool GetCoalescing() const;
    void SetCoalescing(bool coalescing);

public:
    Identifier AddValue(const DistributedValueDefinition & definition, const StrategyParameters & parameters);
    Identifier AddObject(const StrategyParameters & parameters);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Stream;
    friend STRATEGY_EXPORT class test::VirtualDistributionStream;

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};
}
