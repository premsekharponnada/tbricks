#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CalculatedValuesRequestFull
//****************************************************************************************

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
#include "strategy/SafePointer.h"
#include <memory>

namespace tbricks {

class InstrumentParameters;
class InstrumentGroupParameters;
class InstrumentParameterDefinition;

namespace types {
class Parameters;
class CalculatedValuesRequest;
}

typedef Pair<Uuid, Uuid> CalculatedValueIdentifier;

/**
 * CalculatedValuesRequestFull represents a collection of rows, columns and overrides
 * which together form the request for calculated values provided by calculation apps.
 * Rows represent instruments or instrument groups for which calculated values are required,
 * columns represent the required calculated values and overrides represent instrument parameters
 * which should be considered overridden for simulation purposes by calculation apps
 * serving the request for calculated values.
 */
class STRATEGY_EXPORT CalculatedValuesRequestFull : public Printable
{
public:
    class RowIterator;
    class ColumnIterator;
    class OverrideIterator;

    /**
     * RowInfo represents instrument or instrument group with associated strategy parameters,
     * serving as the means to propagate row customization options to calculation apps, serving the request.
     */
    class STRATEGY_EXPORT RowInfo : public Printable
    {
    public:
        /**
         * NOTE: The default constructor is deleted because RowInfo objects are only meant to be created by API
         * internals.
         */
        RowInfo() = delete;

        /**
         * Copy constructor.
         */
        RowInfo(const RowInfo & info);

        /**
         * Move constructor.
         */
        RowInfo(RowInfo && info);

        /**
         * Destructor.
         */
        virtual ~RowInfo();

        /**
         * Assignment operator from lvalue reference.
         */
        RowInfo & operator=(const RowInfo & info);

        /**
         * Assignment operator from rvalue reference.
         */
        RowInfo & operator=(RowInfo && info);

        /**
         * Equality comparison operator.
         */
        bool operator==(const RowInfo & info) const;

        /**
         * Inequality comparison operator.
         */
        bool operator!=(const RowInfo & info) const;

    public:
        /**
         * Get the associated InstrumentVenueIdentification.
         *
         * @throws                      NullReferenceException if called on empty RowInfo
         * @return                      InstrumentVenueIdentification corresponding to the row, if any
         */
        const InstrumentVenueIdentification GetIVID() const;

        /**
         * Get the associated Instrument group identifier.
         *
         * @throws                      NullReferenceException if called on empty RowInfo
         * @return                      InstrumentGroupIdentifier corresponding to the row, if any
         */
        const InstrumentGroupIdentifier GetGroupIdentifier() const;

        /**
         * Get strategy parameters associated with the row.
         *
         * @throws                      NullReferenceException if called on empty RowInfo
         * @param parameters            The output container with strategy parameters for the row
         */
        void GetParameters(StrategyParameters & parameters) const;

        /**
         * Check whether the row has a particular strategy parameter associated with it.
         *
         * @throws                      NullReferenceException if called on empty RowInfo
         * @param definition            The definition of the checked strategy parameter
         * @return                      True if the row has the specified strategy parameter associated with it,
         *                              false otherwise
         */
        bool HasParameter(const ParameterDefinition & definition) const;

        /**
         * Retrieve the value of a particular strategy parameter associated with the row.
         *
         * @throws                      NullReferenceException if called on empty RowInfo
         * @param definition            The definition of the strategy parameter to be retrieved
         * @param value                 The output value of the retrieved strategy parameter
         * @return                      True if the row has the specified strategy parameter associated with it,
         *                              false otherwise
         */
        bool GetParameter(const ParameterDefinition & definition, AnyType & value) const;

        /**
         * @throws                      NullReferenceException if called on empty RowInfo
         * @return                      The hash of the row's strategy parameters
         */
        size_t GetParametersHash() const;

        /**
         * Check RowInfo for emptiness.
         *
         * @return                      True if RowInfo does not represent a valid
         *                              row of a calculated values request, false otherwise
         */
        bool Empty() const;

        /**
         * Clear RowInfo object, make it empty i.e. not pointing to any valid row of a calculated values request.
         */
        void Clear();

        /**
         * @throws                      NullReferenceException if called on empty RowInfo
         * @return                      RowInfo's hash
         */
        size_t GetHash() const;

        /**
         * Print RowInfo to the output stream.
         */
        virtual std::ostream & Print(std::ostream & strm) const override;

        friend class RowIterator;
        friend class CalculatedValuesRequestFull;

    private:
        class Impl;

    public:
        RowInfo(std::unique_ptr<Impl> && impl);

    private:
        std::unique_ptr<Impl> m_impl;
    };

    /**
     * ColumnInfo represents particular requested calculated value with associated strategy parameters,
     * serving as the means to propagate column customization options to calculation apps, serving the request.
     */
    class STRATEGY_EXPORT ColumnInfo : public Printable
    {
    public:
        /**
         * NOTE: The default constructor is deleted because ColumnInfo objects are only meant to be created by API
         * internals.
         */
        ColumnInfo() = delete;

        /**
         * Copy constructor.
         */
        ColumnInfo(const ColumnInfo & info);

        /**
         * Move constructor.
         */
        ColumnInfo(ColumnInfo && info);

        /**
         * Destructor.
         */
        virtual ~ColumnInfo();

        /**
         * Assignment operator from rvalue reference.
         */
        ColumnInfo & operator=(const ColumnInfo & info);

        /**
         * Assignment operator from rvalue reference.
         */
        ColumnInfo & operator=(ColumnInfo && info);

        /**
         * Equality comparison operator.
         */
        bool operator==(const ColumnInfo & info) const;

        /**
         * Inequality comparison operator.
         */
        bool operator!=(const ColumnInfo & info) const;

    public:
        /**
         * Get the associated InstrumentCalculatedValueDefinition.
         *
         * @throws                      NullReferenceException if called on empty ColumnInfo
         * @return                      InstrumentCalculatedValueDefinition corresponding to the column
         */
        const InstrumentCalculatedValueDefinition GetDefinition() const;

        /**
         * Get strategy parameters associated with the column.
         *
         * @throws                      NullReferenceException if called on empty ColumnInfo
         * @param parameters            The output container with strategy parameters for the column
         */
        void GetParameters(StrategyParameters & parameters) const;

        /**
         * Check whether the row has a particular strategy parameter.
         *
         * @throws                      NullReferenceException if called on empty ColumnInfo
         * @param definition            The definition of the checked strategy parameter
         * @return                      True if the column has the specified strategy parameter associated with it,
         *                              false otherwise
         */
        bool HasParameter(const ParameterDefinition & definition) const;

        /**
         * Retrieve the value of a particular strategy parameter associated with the column.
         *
         * @throws                      NullReferenceException if called on empty ColumnInfo
         * @param definition            The definition of the strategy parameter to be retrieved
         * @param value                 The output value of the retrieved strategy parameter
         * @return                      True if the column has the specified strategy parameter associated with it,
         *                              false otherwise
         */
        bool GetParameter(const ParameterDefinition & definition, AnyType & value) const;

        /**
         * @throws                      NullReferenceException if called on empty ColumnInfo
         * @return                      The hash of the column's strategy parameters
         */
        size_t GetParametersHash() const;

        /**
         * Check ColumnInfo for emptiness.
         *
         * @return                      True if ColumnInfo does not represent a valid
         *                              column of a calculated values request, false otherwise
         */
        bool Empty() const;

        /**
         * Clear ColumnInfo object, make it empty i.e. not pointing to any valid column of a calculated values request.
         */
        void Clear();

        /**
         * @throws                      NullReferenceException if called on empty ColumnInfo
         * @return                      ColumnInfo's hash
         */
        size_t GetHash() const;

        /**
         * Print ColumnInfo to the output stream.
         */
        virtual std::ostream & Print(std::ostream & strm) const override;

        friend class RowIterator;
        friend class CalculatedValuesRequestFull;

    private:
        class Impl;

    public:
        ColumnInfo(std::unique_ptr<Impl> && impl);

    private:
        std::unique_ptr<Impl> m_impl;
    };

    /**
     * OverrideInfo represents the information about instrument parameters overridden for particular instrument
     * or instrument group. This information should be used by calculation apps to provide calculated values
     * corresponding to the specified overridden values of instrument parameters instead of their actual values.
     */
    class STRATEGY_EXPORT OverrideInfo : public Printable
    {
    public:
        /**
         * NOTE: The default constructor is deleted because OverrideInfo objects are only meant to be created by API
         * internals.
         */
        OverrideInfo() = delete;

        /**
         * Copy constructor.
         */
        OverrideInfo(const OverrideInfo & info);

        /**
         * Move constructor.
         */
        OverrideInfo(OverrideInfo && info);

        /**
         * Destructor.
         */
        virtual ~OverrideInfo();

        /**
         * Assignment operator from lvalue reference.
         */
        OverrideInfo & operator=(const OverrideInfo & info);

        /**
         * Assignment operator from rvalue reference.
         */
        OverrideInfo & operator=(OverrideInfo && info);

        /**
         * Equality comparison operator.
         */
        bool operator==(const OverrideInfo & info) const;

        /**
         * Inequality comparison operator.
         */
        bool operator!=(const OverrideInfo & info) const;

    public:
        /**
         * Check whether there is an override of a particular instrument parameter.
         *
         * @throws                      NullReferenceException if called on empty OverrideInfo
         * @param definition            The definition of the checked instrument parameter
         * @return                      True if there is an override for the checked instrument parameter,
         *                              false otherwise
         */
        bool HasParameter(const InstrumentParameterDefinition & definition) const;

        /**
         * Retrieve the value of a particular overridden instrument parameter.
         *
         * @throws                      NullReferenceException if called on empty OverrideInfo
         * @param definition            The definition of the overridden instrument parameter to be retrieved
         * @param value                 The output value of the retrieved overridden instrument parameter
         * @return                      True if there is an override for the specified instrument,
         *                              false otherwise
         */
        bool GetParameter(const InstrumentParameterDefinition & definition, AnyType & value) const;

        /**
         * Get instrument parameters associated with instrument or group as InstrumentParameters.
         *
         * @throws                      NullReferenceException if called on empty OverrideInfo
         * @param parameters            The output container with overridden instrument parameters
         */
        bool GetInstrumentParameters(InstrumentParameters & parameters) const;

        /**
         * Get instrument parameters associated with instrument or group as InstrumentGroupParameters.
         *
         * @throws                      NullReferenceException if called on empty OverrideInfo
         * @param parameters            The output container with overridden instrument parameters
         */
        bool GetInstrumentGroupParameters(InstrumentGroupParameters & parameters) const;

        /**
         * Check OverrideInfo for emptiness.
         *
         * @return                      True if OverrideInfo does not represent a valid
         *                              override of a calculated values request, false otherwise
         */
        bool Empty() const;

        /**
         * Clear OverrideInfo object, make it empty i.e. not pointing to any valid override of a calculated values
         * request.
         */
        void Clear();

        /**
         * @throws                      NullReferenceException if called on empty OverrideInfo
         * @return                      OverrideInfo's hash
         */
        size_t GetHash() const;

        /**
         * Print OverrideInfo to the output stream.
         */
        virtual std::ostream & Print(std::ostream & strm) const override;

        friend class OverrideIterator;
        friend class CalculatedValuesRequestFull;

    private:
        class Impl;

    public:
        OverrideInfo(std::unique_ptr<Impl> && impl);

    private:
        std::unique_ptr<Impl> m_impl;
    };

    /**
     * Rows class represents the iterable collection of RowInfo objects.
     */
    class STRATEGY_EXPORT Rows : public Printable
    {
    public:
        Rows(const SafePointer<types::CalculatedValuesRequest> & request);

        /**
         * Copy constructor.
         */
        Rows(const Rows & rows);

        /**
         * Assignment operator.
         */
        Rows & operator=(const Rows & other);

        /**
         * Destructor.
         */
        virtual ~Rows();

        using const_iterator = CalculatedValuesRequestFull::RowIterator;

        /**
         * @return                      Begin iterator of the collection
         */
        const_iterator begin() const;

        /**
         * @return                      End iterator of the collection
         */
        const_iterator end() const;

        /**
         * @return                      Begin iterator of the collection
         */
        const_iterator cbegin() const;

        /**
         * @return                      End iterator of the collection
         */
        const_iterator cend() const;

        /**
         * Find the iterator pointing to the row with the specified id.
         *
         * @param                       The identifier of the searched row
         * @return                      The iterator of the found row or end iterator
         */
        const_iterator find(const Uuid & row_id) const;

        /**
         * Check Rows for emptiness.
         *
         * @return                      True if the collection of rows is empty, false otherwise
         */
        bool empty() const;

        /**
         * @return                      The number of rows within the collection
         */
        size_t size() const;

        /**
         * Print Rows to the output stream.
         */
        virtual std::ostream & Print(std::ostream & strm) const override;

    private:
        SafePointer<types::CalculatedValuesRequest> m_request;
    };

    /**
     * Columns class represents the iterable collection of ColumnInfo objects.
     */
    class STRATEGY_EXPORT Columns : public Printable
    {
    public:
        Columns(const SafePointer<types::CalculatedValuesRequest> & request);

        /**
         * Copy constructor.
         */
        Columns(const Columns & columns);

        /**
         * Assignment operator.
         */
        Columns & operator=(const Columns & columns);

        /**
         * Destructor.
         */
        virtual ~Columns();

        using const_iterator = CalculatedValuesRequestFull::ColumnIterator;

        /**
         * @return                      Begin iterator of the collection
         */
        const_iterator begin() const;

        /**
         * @return                      End iterator of the collection
         */
        const_iterator end() const;

        /**
         * @return                      Begin iterator of the collection
         */
        const_iterator cbegin() const;

        /**
         * @return                      End iterator of the collection
         */
        const_iterator cend() const;

        /**
         * Find the iterator pointing to the column with the specified id.
         *
         * @param                       The identifier of the searched column
         * @return                      The iterator of the found column or end iterator
         */
        const_iterator find(const Uuid & column_id) const;

        /**
         * Check Columns for emptiness.
         *
         * @return                      True if the collection of columns is empty, false otherwise
         */
        bool empty() const;

        /**
         * @return                      The number of columns within the collection
         */
        size_t size() const;

        /**
         * Print Columns to the output stream.
         */
        virtual std::ostream & Print(std::ostream & strm) const override;

    private:
        SafePointer<types::CalculatedValuesRequest> m_request;
    };

    /**
     * Overrides class represents the iterable collection of OverrideInfo objects.
     */
    class STRATEGY_EXPORT Overrides : public Printable
    {
    public:
        Overrides(const SafePointer<types::CalculatedValuesRequest> & request);

        /**
         * Copy constructor.
         */
        Overrides(const Overrides & overrides);

        /**
         * Assignment operator.
         */
        Overrides & operator=(const Overrides & overrides);

        /**
         * Destructor.
         */
        virtual ~Overrides();

        using const_iterator = CalculatedValuesRequestFull::OverrideIterator;

        /**
         * @return                      Begin iterator of the collection
         */
        const_iterator begin() const;

        /**
         * @return                      End iterator of the collection
         */
        const_iterator end() const;

        /**
         * @return                      Begin iterator of the collection
         */
        const_iterator cbegin() const;

        /**
         * @return                      End iterator of the collection
         */
        const_iterator cend() const;

        /**
         * Find the iterator pointing to the override with the specified id.
         *
         * @param                       The identifier of the searched override
         * @return                      The iterator of the found override or end iterator
         */
        const_iterator find(const Uuid & override_id) const;

        /**
         * Check Overrides for emptiness.
         *
         * @return                      True if the collection of overrides is empty, false otherwise
         */
        bool empty() const;

        /**
         * @return                      The number of overrides within the collection
         */
        size_t size() const;

        /**
         * Print Overrides to the output stream.
         */
        virtual std::ostream & Print(std::ostream & strm) const override;

    private:
        SafePointer<types::CalculatedValuesRequest> m_request;
    };

public:
    /**
     * Default constructor.
     *
     * Creates empty calculated values request i.e. the one containing
     * no rows, no columns, no overrides and no strategy parameters.
     */
    CalculatedValuesRequestFull();

    /**
     * Copy constructor.
     */
    CalculatedValuesRequestFull(const CalculatedValuesRequestFull & request);

    /**
     * Destructor.
     */
    virtual ~CalculatedValuesRequestFull();

    /**
     * Assignment operator.
     */
    CalculatedValuesRequestFull & operator=(const CalculatedValuesRequestFull & request);

    /**
     * @return                          Begin iterator for request's rows
     */
    RowIterator GetRowsBegin() const;

    /**
     * @return                          End iterator for request's rows
     */
    RowIterator GetRowsEnd() const;

    /**
     * @return                          Begin iterator for request's columns
     */
    ColumnIterator GetColumnsBegin() const;

    /**
     * @return                          End iterator for request's columns
     */
    ColumnIterator GetColumnsEnd() const;

    /**
     * @return                          Begin iterator for request's overrides
     */
    OverrideIterator GetOverridesBegin() const;

    /**
     * @return                          End iterator for request's overrides
     */
    OverrideIterator GetOverridesEnd() const;

    /**
     * Find row by identifier.
     *
     * @param row_id                    The identifier of the row being searched for
     * @return                          The iterator pointing to the found row or end iterator
     */
    RowIterator FindRow(const Identifier & row_id) const;

    /**
     * Find column by identifier.
     *
     * @param value_id                  The identifier of the column being searched for
     * @return                          The iterator pointing to the found column or end iterator
     */
    ColumnIterator FindColumn(const Identifier & value_id) const;

    /**
     * Find override by instrument identifier.
     *
     * @param instrument_id             The identifier of the instrument for which override
     *                                  parameters are searched
     * @return                          The iterator pointing to the found overrides or end iterator
     */
    OverrideIterator FindOverride(const InstrumentIdentifier & instrument_id) const;

    /**
     * Find override by instrument group identifier.
     *
     * @param group_id                  The identifier of the instrument group for which override
     *                                  parameters are searched
     * @return                          The iterator pointing to the found overrides or end iterator
     */
    OverrideIterator FindOverride(const InstrumentGroupIdentifier & group_id) const;

    /**
     * @return                          The collection of request's rows
     */
    Rows GetRows() const;

    /**
     * @return                          The collection of request's columns
     */
    Columns GetColumns() const;

    /**
     * @return                          The collection of request's overrides
     */
    Overrides GetOverrides() const;

    /**
     * Get strategy parameters associated with the whole request.
     *
     * @param parameters                The output container with request's strategy parameters
     */
    void GetParameters(StrategyParameters & parameters) const;

    /**
     * Check whether the request has a particular strategy parameter associated with it.
     *
     * @param definition                The definition of the checked strategy parameter
     * @return                          True if the request has such strategy parameter associated with it,
     *                                  false otherwise
     */
    bool HasParameter(const ParameterDefinition & definition) const;

    /**
     * Retrieve the value of a particular strategy parameter associated with the request.
     *
     * @param definition                The definition of the strategy parameter to be retrieved
     * @param value                     The output value of the retrieved strategy parameter
     */
    bool GetParameter(const ParameterDefinition & definition, AnyType & value) const;

    /**
     * @return                          The hash of the request's strategy parameters
     */
    size_t GetParametersHash() const;

    /**
     * Check whether the request contains the particular combination
     * of row identifier and column identifier.
     *
     * @param id                        The identifier of calculated value: a pair of row identifier
     *                                  and a column identifier
     * @return                          True if the request contains such row and column pair, false otherwise
     */
    bool Has(const CalculatedValueIdentifier & id) const;

    /**
     * Check whether the request contains the particular row.
     *
     * @param row_id                    The identifier of the row to be searched for within the request
     * @return                          True if the row corresponding to the identifier was found,
     *                                  false otherwise
     */
    bool HasRow(const Uuid & row_id) const;

    /**
     * Check whether the request contains the particular column.
     *
     * @param column_id                 The identifier of the column to be searched for within the request
     * @return                          True if the column corresponding to the identifier was found,
     *                                  false otherwise
     */
    bool HasColumn(const Uuid & column_id) const;

    /**
     * Check whether the request contains the particular override.
     *
     * @param override_id               The identifier of the override to be searched for within the request
     * @return                          True if the override corresponding to the identifier was found,
     *                                  false otherwise
     */
    bool HasOverride(const Uuid & override_id) const;

    /**
     * Check the request for emptiness.
     *
     * @return                          True if the request contains no rows, no columns, no overrides
     *                                  and no strategy parameters, false otherwise
     */
    bool Empty() const;

    /**
     * Clear the request.
     */
    void Clear();

    /**
     * Print CalculatedValuesRequestFull to the output stream
     */
    virtual std::ostream & Print(std::ostream & strm) const override;

public:
    const types::CalculatedValuesRequest * get_request() const;

    CalculatedValuesRequestFull(const types::CalculatedValuesRequest & request);

private:
    SafePointer<types::CalculatedValuesRequest> m_request;
};

/**
 * RowIterator class is used for iteration over the set of calculated values request's rows.
 */
class STRATEGY_EXPORT CalculatedValuesRequestFull::RowIterator : public Printable
{
public:
    /**
     * The default constructor is deleted because RowIterator objects are only meant to be created by API internals.
     */
    RowIterator() = delete;

    /**
     * Copy constructor.
     */
    RowIterator(const RowIterator & it);

    /**
     * Move constructor.
     */
    RowIterator(RowIterator && it);

    /**
     * Assignment operator from lvalue reference.
     */
    RowIterator & operator=(const RowIterator & it);

    /**
     * Assignment operator from rvalue reference.
     */
    RowIterator & operator=(RowIterator && it);

    /**
     * Destructor.
     */
    virtual ~RowIterator();

    /**
     * Equality comparison operator.
     */
    bool operator==(const RowIterator & it) const;

    /**
     * Inequality comparison operator.
     */
    bool operator!=(const RowIterator & it) const;

    /**
     * Increment operator.
     *
     * @throws                          NullReferenceException if called on iterator equal to rows end
     * @return                          The reference to the next iterator
     */
    RowIterator & operator++();

    /**
     * Dereference operator.
     *
     * @return                          The reference to the iterator itself, the purpose is to make
     *                                  the iterator usable in C++11 range based for loop
     */
    RowIterator & operator*();

    /**
     * @return                          RowInfo corresponding to the iterator
     */
    const CalculatedValuesRequestFull::RowInfo & GetRowInfo() const { return m_info; }

    /**
     * @throws                          NullReferenceException if called on iterator equal to rows end
     * @return                          The identifier of the iterator's corresponding row
     */
    const Uuid GetRowId() const;

    /**
     * Print RowInfo corresponding to the iterator to the output stream.
     */
    virtual std::ostream & Print(std::ostream & strm) const override;

    friend class CalculatedValuesRequestFull;

private:
    RowIterator(CalculatedValuesRequestFull::RowInfo && info);

    CalculatedValuesRequestFull::RowInfo m_info;
};

/**
 * ColumnIterator class is used for iteration over the set of calculated values request's columns.
 */
class STRATEGY_EXPORT CalculatedValuesRequestFull::ColumnIterator : public Printable
{
public:
    /**
     * The default constructor is deleted because ColumnIterator objects are only meant to be created by API internals.
     */
    ColumnIterator() = delete;

    /**
     * Copy constructor.
     */
    ColumnIterator(const ColumnIterator & it);

    /**
     * Move constructor.
     */
    ColumnIterator(ColumnIterator && it);

    /**
     * Assignment operator from lvalue reference.
     */
    ColumnIterator & operator=(const ColumnIterator & it);

    /**
     * Assignment operator from rvalue reference.
     */
    ColumnIterator & operator=(ColumnIterator && it);

    /**
     * Destructor.
     */
    virtual ~ColumnIterator();

    /**
     * Equality comparison operator.
     */
    bool operator==(const ColumnIterator & it) const;

    /**
     * Inequality comparison operator.
     */
    bool operator!=(const ColumnIterator & it) const;

    /**
     * Increment operator.
     *
     * @throws                          NullReferenceException if called on iterator equal to columns end
     * @return                          The reference to the next iterator
     */
    ColumnIterator & operator++();

    /**
     * Dereference operator.
     *
     * @return                          The reference to the iterator itself, the purpose is to make
     *                                  the iterator usable in C++11 range based for loop
     */
    ColumnIterator & operator*();

    /**
     * @return                          ColumnInfo corresponding to the iterator
     */
    const CalculatedValuesRequestFull::ColumnInfo & GetColumnInfo() const { return m_info; }

    /**
     * @throws                          NullReferenceException if called on iterator equal to columns end
     * @return                          The identifier of the iterator's corresponding column
     */
    const Uuid GetColumnId() const;

    /**
     * Print ColumnInfo corresponding to the iterator to the output stream.
     */
    virtual std::ostream & Print(std::ostream & strm) const override;

    friend class CalculatedValuesRequestFull;

private:
    ColumnIterator(CalculatedValuesRequestFull::ColumnInfo && info);

    CalculatedValuesRequestFull::ColumnInfo m_info;
};

/**
 * OverrideIterator class is used for iteration over the set of calculated values request's overrides.
 */
class STRATEGY_EXPORT CalculatedValuesRequestFull::OverrideIterator : public Printable
{
public:
    /**
     * NOTE: The default constructor is deleted because OverrideIterator objects are only meant to be created by API
     * internals.
     */
    OverrideIterator() = delete;

    /**
     * Copy constructor.
     */
    OverrideIterator(const OverrideIterator & it);

    /**
     * Move constructor.
     */
    OverrideIterator(OverrideIterator && it);

    /**
     * Assignment operator from lvalue reference.
     */
    OverrideIterator & operator=(const OverrideIterator & it);

    /**
     * Assignment operator from rvalue reference.
     */
    OverrideIterator & operator=(OverrideIterator && it);

    /**
     * Destructor.
     */
    virtual ~OverrideIterator();

    /**
     * Equality comparison operator.
     */
    bool operator==(const OverrideIterator & it) const;

    /**
     * Inequality comparison operator.
     */
    bool operator!=(const OverrideIterator & it) const;

    /**
     * Increment operator.
     *
     * @throws                          NullReferenceException if called on iterator equal to overrides end
     * @return                          The reference to the next iterator
     */
    OverrideIterator & operator++();

    /**
     * Dereference operator.
     *
     * @return                          The reference to the iterator itself, the purpose is to make
     *                                  the iterator usable in C++11 range based for loop
     */
    OverrideIterator & operator*();

    /**
     * @return                          The identifier of the iterator's corresponding override
     */
    const Uuid GetOverrideId() const;

    /**
     * @return                          OverrideInfo corresponding to the iterator
     */
    const CalculatedValuesRequestFull::OverrideInfo & GetOverrideInfo() const { return m_info; }

    /**
     * @throws                          NullReferenceException if called on iterator equal to overrides end
     * @return                          The instrument identifier corresponding to the iterator's override
     *                                  or empty instrument identifier, if the iterator corresponds to
     *                                  instrument group's override
     */
    const InstrumentIdentifier GetInstrumentIdentifier() const;

    /**
     * @throws                          NullReferenceException if called on iterator equal to overrides end
     * @return                          The instrument group identifier corresponding to the iterator's override
     *                                  or empty instrument group identifier, if the iterator corresponds to
     *                                  instrument's override
     */
    const InstrumentGroupIdentifier GetGroupIdentifier() const;

    /**
     * Print OverrideInfo corresponding to the iterator to the output stream.
     */
    virtual std::ostream & Print(std::ostream & strm) const override;

    friend class CalculatedValuesRequestFull;

private:
    OverrideIterator(CalculatedValuesRequestFull::OverrideInfo && info);

    CalculatedValuesRequestFull::OverrideInfo m_info;
};

} // namespace tbricks
