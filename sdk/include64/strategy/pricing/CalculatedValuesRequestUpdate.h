#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CalculatedValuesRequestUpdate
//****************************************************************************************

#include "strategy/pricing/CalculatedValuesRequest.h"
#include "strategy/SharedPointer.h"

#include <memory>

namespace tbricks {

class STRATEGY_EXPORT CalculatedValuesRequestUpdate : public Printable
{
public:
    enum class State
    {
        UPDATE = 0,
        REMOVE
    };

    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const State state);

    class RowIterator;
    class ColumnIterator;
    class OverrideIterator;

    class STRATEGY_EXPORT RowInfo : public Printable
    {
    public:
        RowInfo() = delete;
        RowInfo(const RowInfo & info);
        RowInfo(RowInfo && info);
        RowInfo & operator=(const RowInfo & info);
        RowInfo & operator=(RowInfo && info);
        virtual ~RowInfo();

        bool operator==(const RowInfo & info) const;
        bool operator!=(const RowInfo & info) const;

    public:
        const InstrumentVenueIdentification GetIVID() const;
        const InstrumentGroupIdentifier GetGroupIdentifier() const;
        void GetStrategyParameters(StrategyParameters & parameters) const;

        State GetState() const;
        bool Empty() const;
        size_t GetHash() const;

        virtual std::ostream & Print(std::ostream & strm) const override;

        friend class RowIterator;
        friend class CalculatedValuesRequestUpdate;

    private:
        class Impl;

    public:
        RowInfo(std::unique_ptr<Impl> && impl);

    private:
        std::unique_ptr<Impl> m_impl;
    };

    class STRATEGY_EXPORT ColumnInfo : public Printable
    {
    public:
        ColumnInfo() = delete;
        ColumnInfo(const ColumnInfo & info);
        ColumnInfo(ColumnInfo && info);
        ColumnInfo & operator=(const ColumnInfo & info);
        ColumnInfo & operator=(ColumnInfo && info);
        virtual ~ColumnInfo();

        bool operator==(const ColumnInfo & info) const;
        bool operator!=(const ColumnInfo & info) const;

    public:
        const InstrumentCalculatedValueDefinition GetDefinition() const;
        void GetStrategyParameters(StrategyParameters & parameters) const;

        State GetState() const;
        bool Empty() const;
        virtual std::ostream & Print(std::ostream & strm) const override;

        friend class ColumnIterator;
        friend class CalculatedValuesRequestUpdate;

    private:
        class Impl;

    public:
        ColumnInfo(std::unique_ptr<Impl> && impl);

    private:
        std::unique_ptr<Impl> m_impl;
    };

    class STRATEGY_EXPORT OverrideInfo : public Printable
    {
    public:
        OverrideInfo() = delete;
        OverrideInfo(const OverrideInfo & info);
        OverrideInfo(OverrideInfo && info);
        OverrideInfo & operator=(const OverrideInfo & info);
        OverrideInfo & operator=(OverrideInfo && info);
        virtual ~OverrideInfo();

        bool operator==(const OverrideInfo & info) const;
        bool operator!=(const OverrideInfo & info) const;

    public:
        bool HasParameter(const InstrumentParameterDefinition & definition) const;
        bool GetParameter(const InstrumentParameterDefinition & definition, AnyType & value) const;

        bool GetInstrumentParameters(InstrumentParameters & parameters) const;
        bool GetInstrumentGroupParameters(InstrumentGroupParameters & parameters) const;

        State GetState() const;
        bool Empty() const;
        virtual std::ostream & Print(std::ostream & strm) const;

        friend class OverrideIterator;
        friend class CalculatedValuesRequestUpdate;

    private:
        class Impl;

    public:
        OverrideInfo(std::unique_ptr<Impl> && impl);

    private:
        std::unique_ptr<Impl> m_impl;
    };

public:
    CalculatedValuesRequestUpdate();
    CalculatedValuesRequestUpdate(const CalculatedValuesRequestUpdate & update);
    CalculatedValuesRequestUpdate & operator=(const CalculatedValuesRequestUpdate & update);
    virtual ~CalculatedValuesRequestUpdate();

    RowIterator GetRowsBegin() const;
    RowIterator GetRowsEnd() const;

    ColumnIterator GetColumnsBegin() const;
    ColumnIterator GetColumnsEnd() const;

    OverrideIterator GetOverridesBegin() const;
    OverrideIterator GetOverridesEnd() const;

    RowIterator FindRow(const Identifier & row_id) const;
    ColumnIterator FindColumn(const Identifier & value_id) const;
    OverrideIterator FindOverride(const InstrumentIdentifier & instrument_id) const;
    OverrideIterator FindOverride(const InstrumentGroupIdentifier & group_id) const;

    void GetStrategyParameters(StrategyParameters & parameters) const;

    virtual std::ostream & Print(std::ostream & strm) const override;

public:
    const types::CalculatedValuesRequest & get_request() const;
    types::CalculatedValuesRequest & get_request();

    CalculatedValuesRequestUpdate(const types::CalculatedValuesRequest & request);
    CalculatedValuesRequestUpdate(const SharedPointer<types::CalculatedValuesRequest> & request);

private:
    SharedPointer<types::CalculatedValuesRequest> m_request;
};

class STRATEGY_EXPORT CalculatedValuesRequestUpdate::RowIterator : public Printable
{
public:
    RowIterator() = delete;
    RowIterator(const RowIterator & it);
    RowIterator(RowIterator && it);
    RowIterator & operator=(const RowIterator & it);
    RowIterator & operator=(RowIterator && it);
    virtual ~RowIterator();

    bool operator==(const RowIterator & it) const;
    bool operator!=(const RowIterator & it) const;

    RowIterator & operator++();

    const CalculatedValuesRequestUpdate::RowInfo & GetRowInfo() const { return m_info; }
    const Uuid GetRowId() const;

    virtual std::ostream & Print(std::ostream & strm) const override;

    friend class CalculatedValuesRequestUpdate;

private:
    RowIterator(CalculatedValuesRequestUpdate::RowInfo && info);

    CalculatedValuesRequestUpdate::RowInfo m_info;
};

class STRATEGY_EXPORT CalculatedValuesRequestUpdate::ColumnIterator : public Printable
{
public:
    ColumnIterator() = delete;
    ColumnIterator(const ColumnIterator & it);
    ColumnIterator(ColumnIterator && it);
    ColumnIterator & operator=(const ColumnIterator & it);
    ColumnIterator & operator=(ColumnIterator && it);
    virtual ~ColumnIterator();

    bool operator==(const ColumnIterator & it) const;
    bool operator!=(const ColumnIterator & it) const;

    ColumnIterator & operator++();

    const CalculatedValuesRequestUpdate::ColumnInfo & GetColumnInfo() const { return m_info; }
    const Uuid GetColumnId() const;

    virtual std::ostream & Print(std::ostream & strm) const override;

    friend class CalculatedValuesRequestUpdate;

private:
    ColumnIterator(CalculatedValuesRequestUpdate::ColumnInfo && info);

    CalculatedValuesRequestUpdate::ColumnInfo m_info;
};

class STRATEGY_EXPORT CalculatedValuesRequestUpdate::OverrideIterator : public Printable
{
public:
    OverrideIterator() = delete;
    OverrideIterator(const OverrideIterator & it);
    OverrideIterator(OverrideIterator && it);
    OverrideIterator & operator=(const OverrideIterator & it);
    OverrideIterator & operator=(OverrideIterator && it);
    virtual ~OverrideIterator();

    bool operator==(const OverrideIterator & it) const;
    bool operator!=(const OverrideIterator & it) const;

    OverrideIterator & operator++();

    const Identifier GetOverrideIdentifier() const;
    const CalculatedValuesRequestUpdate::OverrideInfo & GetOverrideInfo() const { return m_info; }
    const InstrumentIdentifier GetInstrumentIdentifier() const;
    const InstrumentGroupIdentifier GetGroupIdentifier() const;

    virtual std::ostream & Print(std::ostream & strm) const override;

    friend class CalculatedValuesRequestUpdate;

private:
    OverrideIterator(CalculatedValuesRequestUpdate::OverrideInfo && info);

    CalculatedValuesRequestUpdate::OverrideInfo m_info;
};
}
