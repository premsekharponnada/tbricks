#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Calculated properties stream.
//****************************************************************************************

#include "strategy/calculated_property/CalculatedPropertiesTable.h"
#include "strategy/calculated_property/CalculatedProperty.h"
#include "strategy/calculated_property/CalculatedPropertiesRequest.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream/InstrumentStream.h"
#include "strategy/stream_filter/PositionFilter.h"
#include "strategy/stream_filter/StrategyFilter.h"
#include "strategy/Order.h"
#include "strategy/stream/OrderStream.h"
#include "strategy/stream_filter/TradeFilter.h"
#include "strategy/stream_filter/PublicTradeFilter.h"
#include "strategy/stream_filter/DepthFilter.h"
#include "strategy/stream_filter/InstrumentGroupFilter.h"
#include "strategy/stream_filter/CashFilters.h"
#include "strategy/stream_filter/RequestForQuoteFilters.h"
#include "strategy/Position.h"

namespace tbricks {

/**
 * CalculatedPropertiesTable::Stream class is an interface to receive snapshots
 * and/or live table updates for properties and calculated LUA properties
 * specified in CalculatedPropertiesTable::Stream::Options object.
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
 *
 * @see CalculatedPropertiesTable::Stream
 */
class STRATEGY_EXPORT CalculatedPropertiesTable::Stream : public tbricks::Stream
{
public:
    class IHandler;
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
     *
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
     * Parameter "definitions" allows to select what specific instrument
     * table updates the caller is interested in.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Stream options
     */
    void Open(Type type, const Options & options);

    /**
     * Modify a stream.
     *
     * @param options                   Stream options
     */
    void Modify(const Options & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * CalculatedPropertiesTable::Stream::IHandler class is a callback interface to
 * handle instrument table stream events.
 *
 * @see CalculatedPropertiesTable::Stream
 */
class STRATEGY_EXPORT CalculatedPropertiesTable::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Table stream update handler.
     *
     * Method is called when a new table update becomes
     * available on the stream.
     *
     * @param stream                   Stream identifier
     * @param update                   Update data
     */
    virtual void HandleCalculatedProperties(const StreamIdentifier & stream_id, const CalculatedPropertiesTable::Update & update) = 0;

protected:
    virtual ~IHandler();
};

/**
 * CalculatedPropertiesTable::Stream::Options class is an interface to
 * set specific settings for CalculatedPropertiesTable::Stream
 */
class STRATEGY_EXPORT CalculatedPropertiesTable::Stream::Options : public Printable
{
public:
    Options();
    Options(const Options & src);
    virtual ~Options();
    Options & operator=(const Options & src);

    /**
     * Sets position filter for selected portfolio.
     * Erases previously set stream filter.
     *
     * @param portfolio_id             portfolio identifier
     * @param aggregaion_type          position aggregation type
     * @param filter                   position filter
     */
    void SetFilter(const PortfolioIdentifier & portfolio_id, Position::AggregationType aggregation_type, const PositionFilter & filter);

    /**
     * Sets stream filter for selected strategy. Erases previously set stream filter.
     *
     * @param strategy_id              strategy identifier
     * @param aggregaion_type          position aggregation type
     * @param filter                   position filter
     */
    void SetFilter(const StrategyIdentifier & strategy_id, Position::AggregationType aggregation_type, const PositionFilter & filter);

    /**
     * Sets instrument stream filter. Erases previously set stream filter.
     *
     * @param filter                   instrument filter
     */
    void SetFilter(const InstrumentStream::Filters::Filter & filter);

    /**
     * Sets strategy stream filter. Erases previously set stream filter.
     *
     * @param filter                   strategy filter
     */
    void SetFilter(const StrategyFilter & filter);

    /**
     * Sets order stream filter. Erases previously set stream filter.
     *
     * @param filter                   order filter
     */
    void SetFilter(const Order::Stream::Filters::Filter & filter);

    /**
     * Sets trade stream filter. Erases previously set stream filter.
     *
     * @param filter                   trade filter
     */
    void SetFilter(const TradeFilter & filter);

    /**
     * Sets instrument group stream filter. Erases previously set stream filter.
     *
     * @param filter                   instrument group filter
     */
    void SetFilter(const InstrumentGroupFilter & filter);

    /**
     * Sets cash stream filter. Erases previously set stream filter.
     *
     * @param filter                   cash filter
     */
    void SetFilter(const Cash::Stream::Filters::Filter & filter);

    /**
     * Sets cash stream filter. Erases previously set stream filter.
     *
     * @param filter                   cash filter
     * @param aggregation_type         cash aggregation type
     */
    void SetFilter(const Cash::Stream::Filters::Filter & filter, Cash::AggregationType aggregation_type);

    /**
     * Sets request for quote stream filter. Erases previously set stream filter.
     *
     * @param filter                   request for quote filter
     */
    void SetFilter(const RequestForQuote::Stream::Filters::Filter & filter);

    /**
     * Sets stream filter on composite instrument. Erases previously set stream filter.
     *
     * @param id                   composite instrument id
     */
    void SetCompositeInstrument(const InstrumentIdentifier & id);

    /**
     * Sets stream filter on specified instruments. Erases previously set stream filter.
     *
     * @param ids                   requested instrument identifiers
     */
    void SetInstruments(const std::vector<InstrumentIdentifier> & ids);

    /**
     * Sets GridSelection to track.
     *
     * @param selection             grid selection
     */
    void SetGridSelection(const GridSelection & selection);

    /**
     * Add CalculatedProperty by CalculatedPropertyDefinition. Related column id in
     * CalculatedPropertiesTable matches with definition identifier.
     *
     * @param def                  calculated property definition
     */
    void AddProperty(const CalculatedPropertyDefinition & def);

    /**
     * Add CalculatedProperty. Column id in CalculatedPropertiesTable matches with returned Uuid.
     *
     * @param p                    calculated property
     */
    Uuid AddProperty(const CalculatedProperty & p);

    /**
     * Add CalculatedProperty with related parameters.
     * Column id in CalculatedPropertiesTable matches with returned Uuid.
     *
     * @param p                    calculated property
     * @param params               calculated property parameters
     */
    Uuid AddProperty(const CalculatedProperty & p, const StrategyParameters & params);

    void SetParameters(const StrategyParameters & params);

    /**
     * Sets CalculatedPropertyFilter for stream
     *
     * @see CalculatedPropertyFilter
     */
    void SetCalculatedPropertyFilter(const CalculatedPropertyFilter & filter);

    /**
     * CalculatedPropertyFilter getter
     *
     * @see CalculatedPropertyFilter
     */
    const CalculatedPropertyFilter & GetCalculatedPropertyFilter() const;

    /**
     * Sets parameter context.
     *
     * @param identifier          parameter context identifier
     */
    void SetParameterContext(const Identifier & identifier);

    /**
     * @return parameter context identifier
     */
    const Identifier & GetParameterContext() const;

    /**
     * Sets ranking.
     *
     * @param identifier          ranking identifier
     */
    void SetParameterContextRanking(const Identifier & identifier);

    /**
     * @return ranking identifier
     */
    const Identifier & GetParameterContextRanking() const;

    /**
     * Stream filter getter
     *
     */
    const tbricks::Filter & GetFilter() const;
    const CalculatedPropertiesRequest & GetCalculatedPropertiesRequest() const;
    CalculatedPropertiesTable::RowDataType GetRowDataType() const;

    bool Empty() const;
    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    class CPFilter : public tbricks::Filter
    {
    public:
        CPFilter();
        CPFilter(const CPFilter & filter);
        ~CPFilter();
        CPFilter & operator=(const CPFilter & filter);
        virtual void Clear();
        virtual bool Empty() const;
        virtual tbricks::filter::FieldFilter GetValue() const;
        virtual std::ostream & Print(std::ostream & strm) const;
    };

    CPFilter m_filter;
    CalculatedPropertiesRequest m_request;
    CalculatedPropertiesTable::RowDataType m_data_type = CalculatedPropertiesTable::RowDataTypePosition;
    Identifier m_parameter_context;
    Identifier m_parameter_context_ranking;
};
}
