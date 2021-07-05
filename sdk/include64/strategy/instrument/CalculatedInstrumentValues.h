#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument table container.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Hash.h"

#include "strategy/stream/Stream.h"
#include "strategy/stream/StreamOptions.h"
#include "strategy/stream/InstrumentStream.h"
#include "strategy/stream_throttle/CommonThrottle.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/pricing/InstrumentCalculatedValueDefinition.h"
#include "strategy/pricing/CalculatedValuesRequest.h"

#include <memory>

// \namespace tbricks
namespace tbricks {

namespace types {
class CalculatedValuesRequest;
}

class InstrumentIdentifier;
class InstrumentParameters;
class InstrumentGroupParameters;
class InstrumentParameterDefinition;
/**
 * CalculatedInstrumentValues object stores a collection of instrument
 * table and, through nested auxiliary classes, provides
 * for distant manipulations.
 */
class STRATEGY_EXPORT CalculatedInstrumentValues : public Printable
{
public:
    typedef Hash<Uuid, Variant> InstrumentValues;
    typedef Hash<CalculatedValuesRequest::RowInfo, InstrumentValues> Values;

public:
    class Update;
    class Stream;

public:
    /**
     * Default constructor, creates an empty object.
     */
    CalculatedInstrumentValues();

    /**
     * Copy constructor.
     */
    CalculatedInstrumentValues(const CalculatedInstrumentValues & values);

    /**
     * Destructor.
     */
    virtual ~CalculatedInstrumentValues();

    CalculatedInstrumentValues & operator=(const CalculatedInstrumentValues & values);

public:
    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no records in the
     *                                  container, false otherwise.
     */
    bool Empty() const;
    void Clear();

    const Values & GetValues() const;
    Values & GetValues();

    /**
     * Merge values.
     *
     * Updates container data with values from the argument.
     *
     * @param values                Update
     */
    void Merge(const CalculatedInstrumentValues::Update & values);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

/**
 * CalculatedInstrumentValues::Stream class is an interface to receive snapshots
 * and/or live instrument table updates.
 *
 * Stream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last Stream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 */
class STRATEGY_EXPORT CalculatedInstrumentValues::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Options;
    class ModifyOptions;

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
     * Stream options allow to specify what specific calculated values
     * updates the caller is interested in.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Stream options
     */
    void Open(Type type, const Options & options);

    /**
     * Modify a stream with full update of stream options
     *
     * @param options                   Stream options
     */
    void Modify(const Options & options);

    /**
     * Modify a stream with partial update of stream options
     *
     * @param options                   Partial update of stream options
     */
    void Modify(const ModifyOptions & options);

    /**
     * Check if stream has pending stream modifies.
     *
     *
     * @return                          "true" if stream has pending stream modifies
     */
    bool HasPendingStreamModifies() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * CalculatedInstrumentValues::Update, collection of updated instrument
 * table.
 */
class STRATEGY_EXPORT CalculatedInstrumentValues::Update : public Printable
{
public:
    Update();
    Update(const Update & update);
    Update & operator=(const Update & update);
    virtual ~Update();

public:
    bool Empty() const;
    void Clear();

public:
    class STRATEGY_EXPORT Iterator
    {
    public:
        Iterator();
        Iterator(const CalculatedInstrumentValues::Update & update);
        Iterator(const Iterator & iterator);
        Iterator & operator=(const Iterator & iterator);
        ~Iterator();

    public:
        const CalculatedValuesRequest::RowInfo & GetRowInfo() const;
        const Uuid & GetColumnId() const;
        const Uuid & GetRowId() const;

        const Variant & GetValue() const;

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

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

private:
    class CalculatedInstrumentValuesUpdateImpl;
    std::unique_ptr<CalculatedInstrumentValuesUpdateImpl> m_impl;

    mutable std::unique_ptr<Values> m_values;
};

/**
 * CalculatedInstrumentValues::Stream::IHandler class is a callback interface to
 * handle calculated values stream events.
 *
 * @see CalculatedInstrumentValues::Stream
 */
class STRATEGY_EXPORT CalculatedInstrumentValues::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Calculated values stream update handler.
     *
     * Method is called when a new instrument table update becomes
     * available on the stream.
     *
     * @param stream                   Stream identifier
     * @param update                   Update data
     */
    virtual void HandleCalculatedInstrumentValues(const StreamIdentifier & stream_id, const CalculatedInstrumentValues::Update & update) = 0;

    /**
     * Stream end of modify.
     *
     * Called when all of the pending modification requests were processed by respective calculation apps,
     * assuming all of them support such functionality.
     *
     * @param stream                    Reference to event originator stream
     */
    virtual void HandleModifySnapshotEnd(const StreamIdentifier & stream);

protected:
    virtual ~IHandler();
};

class STRATEGY_EXPORT CalculatedInstrumentValues::Stream::Options : public StreamOptions<InstrumentStream::Filters::Filter, BasicThrottle>,
                                                                    public Printable
{
public:
    Options();
    Options(const Options & src);
    virtual ~Options();

    Options & operator=(const Options & src);

public:
    void SetMarketDataThrottle(const BasicThrottle & throttle);
    const BasicThrottle & GetMarketDataThrottle() const;
    BasicThrottle & GetMarketDataThrottle();

    void SetInstrumentParametersThrottle(const BasicThrottle & throttle);
    const BasicThrottle & GetInstrumentParametersThrottle() const;
    BasicThrottle & GetInstrumentParametersThrottle();

    void AddValue(const InstrumentCalculatedValueDefinition & definition);

    void AddValue(const Identifier & value_id, const InstrumentCalculatedValueDefinition & definition);

    void AddValue(const Identifier & value_id, const InstrumentCalculatedValueDefinition & definition, const StrategyParameters & parameters);

    Uuid AddInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    void AddInstrumentVenueIdentification(const Identifier & row_id, const InstrumentVenueIdentification & ivid);

    void
    AddInstrumentVenueIdentification(const Identifier & row_id, const InstrumentVenueIdentification & ivid, const StrategyParameters & parameters);

    Uuid AddInstrumentGroupIdentifier(const InstrumentGroupIdentifier & group_id);

    void AddInstrumentGroupIdentifier(const Identifier & row_id, const InstrumentGroupIdentifier & group_id);

    void AddInstrumentGroupIdentifier(const Identifier & row_id, const InstrumentGroupIdentifier & group_id, const StrategyParameters & parameters);

    bool AddOverrideParameters(const InstrumentIdentifier & instrument_id, const InstrumentParameters & parameters);

    bool AddOverrideParameters(const InstrumentGroupIdentifier & group_id, const InstrumentGroupParameters & parameters);

    void AddParameters(const StrategyParameters & parameters);

    void SetValuationDate(const DateTime & valuation_date);

    const CalculatedValuesRequest & GetCalculatedValuesRequest() const;
    CalculatedValuesRequest & GetCalculatedValuesRequest();

    void SetParameterContext(const Identifier & identifier);
    const Identifier & GetParameterContext() const;

    void SetParameterContextRanking(const Identifier & identifier);
    const Identifier & GetParameterContextRanking() const;

public:
    bool Empty() const;
    void Clear();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    BasicThrottle m_md_throttle;
    BasicThrottle m_ip_throttle;
    Identifier m_parameter_context;
    Identifier m_parameter_context_ranking;
    Boolean m_simulation_mode;
    CalculatedValuesRequest m_values_request;
};

class STRATEGY_EXPORT CalculatedInstrumentValues::Stream::ModifyOptions : public Printable
{
public:
    ModifyOptions();
    ModifyOptions(const ModifyOptions & src);
    virtual ~ModifyOptions();

    ModifyOptions & operator=(const ModifyOptions & src);

public:
    // === Rows ===

    // Add
    void AddInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    void AddInstrumentVenueIdentification(const Identifier & row_id, const InstrumentVenueIdentification & ivid);

    void
    AddInstrumentVenueIdentification(const Identifier & row_id, const InstrumentVenueIdentification & ivid, const StrategyParameters & parameters);

    void AddInstrumentGroupIdentifier(const InstrumentGroupIdentifier & group_id);

    void AddInstrumentGroupIdentifier(const Identifier & row_id, const InstrumentGroupIdentifier & group_id);

    void AddInstrumentGroupIdentifier(const Identifier & row_id, const InstrumentGroupIdentifier & group_id, const StrategyParameters & parameters);

    // Remove
    void RemoveRow(const Identifier & row_id);

    // === Columns ===

    // Add
    void AddValue(const Identifier & value_id, const InstrumentCalculatedValueDefinition & definition);

    void AddValue(const Identifier & value_id, const InstrumentCalculatedValueDefinition & definition, const StrategyParameters & parameters);

    // Remove
    void RemoveValue(const Identifier & value_id);

    // === Overrides ===

    // Add
    bool AddOverrideParameters(const InstrumentIdentifier & instrument_id, const InstrumentParameters & parameters);

    bool AddOverrideParameters(const InstrumentGroupIdentifier & group_id, const InstrumentGroupParameters & parameters);

    // Remove
    void RemoveOverrideParameters(const InstrumentIdentifier & instrument_id);

    void RemoveOverrideParameters(const InstrumentGroupIdentifier & group_id);

    // === Request (global) ===

    void AddParameters(const StrategyParameters & parameters);

    void SetValuationDate(const DateTime & valuation_date);

public:
    bool Empty() const;
    void Clear();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    const types::CalculatedValuesRequest & get_request() const;

private:
    std::unique_ptr<types::CalculatedValuesRequest> m_request;
};

} // \namespace tbricks
