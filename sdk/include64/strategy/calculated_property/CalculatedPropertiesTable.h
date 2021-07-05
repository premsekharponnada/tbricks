#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Calculated Property table container.
//****************************************************************************************

#include <iosfwd>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Strategy.h"
#include "strategy/Hash.h"

#include "strategy/type/AnyType.h"

#include "strategy/calculated_property/CalculatedPropertiesRequest.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream/StreamOptions.h"
#include "strategy/stream_throttle/CommonThrottle.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/Statistics.h"
#include "strategy/visualization/RowEntityType.h"

// \namespace tbricks
namespace tbricks {

/**
 * CalculatedPropertiesTable object stores a collection of values for properties
 * and calculated lua properties specified in CalculatedPropertiesTable::Stream::Options
 * and, through nested auxilliary classes, provides for distant manipulations.
 */
class STRATEGY_EXPORT CalculatedPropertiesTable : public Printable
{
public:
    enum RowDataType
    {
        RowDataTypePosition = static_cast<int>(visualization::RowEntityType::Position),
        RowDataTypeInstrument = static_cast<int>(visualization::RowEntityType::Instrument),
        RowDataTypeStrategy = static_cast<int>(visualization::RowEntityType::Strategy),
        RowDataTypeOrder = static_cast<int>(visualization::RowEntityType::Order),
        RowDataTypeTrade = static_cast<int>(visualization::RowEntityType::Trade),
        RowDataTypeInstrumentGroup = static_cast<int>(visualization::RowEntityType::InstrumentGroup),
        RowDataTypeCash = static_cast<int>(visualization::RowEntityType::Cash),
        RowDataTypeRequestForQuote = static_cast<int>(visualization::RowEntityType::RequestForQuote),
        RowDataTypeInstrumentComponent = static_cast<int>(visualization::RowEntityType::InstrumentComponent)
    };

    typedef Hash<Uuid, Variant> Columns;
    typedef Hash<Uuid, Columns> Rows;

public:
    class Update;
    class Stream;

public:
    CalculatedPropertiesTable();
    CalculatedPropertiesTable(const CalculatedPropertiesTable & values);

    CalculatedPropertiesTable & operator=(const CalculatedPropertiesTable & values);

    bool Empty() const;
    void Clear();

    const Rows & GetRows() const;
    Rows & GetRows();

    void Merge(const CalculatedPropertiesTable::Update & values);

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Rows m_rows;
};

/**
 * CalculatedInstrumentValues::Update, collection of updated values.
 */
class STRATEGY_EXPORT CalculatedPropertiesTable::Update : public Printable
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
        Iterator(const CalculatedPropertiesTable::Update & update);
        Iterator(const Iterator & iterator);
        Iterator & operator=(const Iterator & iterator);
        ~Iterator();

    public:
        const Uuid & GetColumnId() const;
        const Uuid & GetRowId() const;
        const Variant & GetValue() const;
        Iterator & operator++();
        bool IsLast() const;

    private:
        class IteratorImpl;
        IteratorImpl * m_impl;
    };

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

private:
    class Impl;
    Impl * m_impl;
};
}
