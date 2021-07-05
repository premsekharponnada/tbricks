#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CalculatedValuesRequest
//****************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/Uuid.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/InstrumentGroupIdentifier.h"
#include "strategy/Printable.h"
#include "strategy/parameter/StrategyParameters.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/pricing/InstrumentCalculatedValueDefinition.h"
#include "strategy/SparseHash.h"
#include "strategy/Pair.h"

namespace tbricks {

class InstrumentParameters;
class InstrumentGroupParameters;
class InstrumentParameterDefinition;

namespace types {
class Parameters;
class CalculatedValuesRequest;
}

typedef Pair<Uuid, Uuid> CalculatedValueIdentifier;

class STRATEGY_EXPORT CalculatedValuesRequest : public Printable
{
public:
    class STRATEGY_EXPORT RowInfo : public Printable
    {
    public:
        RowInfo();
        RowInfo(const InstrumentVenueIdentification & ivid);
        RowInfo(const InstrumentGroupIdentifier & group_id);
        RowInfo(const RowInfo & info);
        virtual ~RowInfo();
        RowInfo & operator=(const RowInfo & info);

        bool operator==(const RowInfo & info) const;
        bool operator!=(const RowInfo & info) const;

    public:
        const InstrumentVenueIdentification & GetIVID() const { return m_ivid; }
        InstrumentVenueIdentification & GetIVID() { return m_ivid; }

        const InstrumentGroupIdentifier & GetGroupIdentifier() const { return m_group_id; }
        InstrumentGroupIdentifier & GetGroupIdentifier() { return m_group_id; }

        const StrategyParameters & GetParameters() const { return m_parameters; }
        StrategyParameters & GetParameters() { return m_parameters; }

        bool Empty() const;
        void Clear();

        size_t GetHash() const;

        virtual std::ostream & Print(std::ostream & strm) const;

    private:
        InstrumentVenueIdentification m_ivid;
        InstrumentGroupIdentifier m_group_id;
        StrategyParameters m_parameters;
    };

    class STRATEGY_EXPORT ColumnInfo : public Printable
    {
    public:
        ColumnInfo();
        ColumnInfo(const ColumnInfo & info);
        virtual ~ColumnInfo();
        ColumnInfo & operator=(const ColumnInfo & info);

        bool operator==(const ColumnInfo & info) const;
        bool operator!=(const ColumnInfo & info) const;

    public:
        const InstrumentCalculatedValueDefinition & GetDefinition() const;
        const StrategyParameters & GetParameters() const;

        InstrumentCalculatedValueDefinition & GetDefinition();
        StrategyParameters & GetParameters();

        bool Empty() const;
        void Clear();

        virtual std::ostream & Print(std::ostream & strm) const;

    private:
        InstrumentCalculatedValueDefinition m_definition;
        StrategyParameters m_parameters;
    };

    class STRATEGY_EXPORT OverrideInfo : public Printable
    {
    public:
        OverrideInfo();
        OverrideInfo(const OverrideInfo & info);
        OverrideInfo(OverrideInfo && info);
        virtual ~OverrideInfo();
        OverrideInfo & operator=(const OverrideInfo & info);
        OverrideInfo & operator=(OverrideInfo && info);

        bool operator==(const OverrideInfo & info) const;
        bool operator!=(const OverrideInfo & info) const;

    public:
        bool HasParameter(const InstrumentParameterDefinition & definition) const;
        bool GetParameter(const InstrumentParameterDefinition & definition, AnyType & value) const;

        bool GetInstrumentParameters(InstrumentParameters & parameters) const;
        bool GetInstrumentGroupParameters(InstrumentGroupParameters & parameters) const;

        bool Empty() const;
        void Clear();

        virtual std::ostream & Print(std::ostream & strm) const;

    public:
        types::Parameters & get_parameters();
        const types::Parameters & get_parameters() const;

    private:
        std::unique_ptr<types::Parameters> m_parameters;
    };

public:
    typedef SparseHash<Uuid, RowInfo> Rows;

    typedef SparseHash<Uuid, ColumnInfo> Columns;

    typedef SparseHash<Identifier, OverrideInfo> Overrides;

public:
    CalculatedValuesRequest();
    CalculatedValuesRequest(const CalculatedValuesRequest & request);
    virtual ~CalculatedValuesRequest();
    CalculatedValuesRequest & operator=(const CalculatedValuesRequest & request);

    const Rows & GetRows() const;
    Rows & GetRows();

    const Columns & GetColumns() const;
    Columns & GetColumns();

    const Overrides & GetOverrides() const;
    Overrides & GetOverrides();

    const StrategyParameters & GetParameters() const;
    StrategyParameters & GetParameters();

    bool Has(const CalculatedValueIdentifier & id) const;

    bool HasRow(const Uuid & row_id) const;

    void Swap(CalculatedValuesRequest & request);

    bool Empty() const;
    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Rows m_rows;
    Columns m_columns;
    Overrides m_overrides;
    StrategyParameters m_parameters;
};

inline size_t hash_value(const CalculatedValuesRequest::RowInfo & value)
{
    return value.GetHash();
}
}
