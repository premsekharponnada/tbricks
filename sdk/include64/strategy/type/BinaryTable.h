#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BinaryTable is an efficient table class with a more restrictive interface than Table
//****************************************************************************************

#include <iosfwd>
#include <memory>

#include "strategy/DefinitionBase.h"
#include "strategy/Linkage.h"
#include "strategy/parameter/StrategyParameters.h"
#include "strategy/type/AnyType.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/TypeWithError.h"
#include "strategy/type/Uuid.h"

namespace tbricks {

class Variant;

namespace types {
class TableValues;
} // namespace types

namespace util {
class Buffer;
} // namespace util

/**
 *  BinaryTable
 */
class STRATEGY_EXPORT BinaryTable : public AnyType
{
public:
    BinaryTable();
    ~BinaryTable() override;

    BinaryTable(const BinaryTable & other);
    /**
     *  Copy assignment operator. Invalidates all iterators into this object.
     *
     *  @param  other           Existing object from which to copy data.
     */
    BinaryTable & operator=(const BinaryTable & other);

    /**
     *  Move constructor. Invalidates the passed object.
     *
     *  @param  other           Object from which to take contents.
     *
     *  @return                 Reference to *this
     */
    BinaryTable(BinaryTable && other) noexcept;
    /**
     *  Move assignment operator. Invalidates all iterators into the object
     *  assigned to, and invalidates the passed object.
     *
     *  @param  other           Object from which to take contents.
     *
     *  @return                 Reference to *this
     */
    BinaryTable & operator=(BinaryTable && other) noexcept;

    /**
     *  BinaryTable::Iterator does not satisfy the requirements of
     *  LegacyIterator, as it is not possible to directly dereference it.
     */
    class STRATEGY_EXPORT Iterator
    {
    public:
        class Impl;

        Iterator();
        /** @cond PRIVATE */
        Iterator(const util::Buffer & impl);
        /** @endcond */
        ~Iterator();

        Iterator(const Iterator & other);
        Iterator & operator=(const Iterator & other);

        /**
         *  Move constructor. Invalidates the passed object.
         *
         *  @param  other       Object from which to take contents.
         *
         *  @return             Reference to *this
         */
        Iterator(Iterator && other);
        /**
         *  Move assignment operator. Invalidates the passed object.
         *
         *  @param  other       Object from which to take contents.
         *
         *  @return             Reference to *this
         */
        Iterator & operator=(Iterator && other);

        Identifier GetColumnIdentifier() const;
        Identifier GetRowIdentifier() const;

        /**
         *  Fills the provided object with the contents to which the iterator
         *  points, if the types are compatible. Otherwise the object to which
         *  a reference was passed is left in a valid, but unspecified state.
         *
         *  @param  out         Object to be filled with the contents to which
         *                      the iterator points.
         *
         *  @return             Whether the object was successfully filled
         */
        bool GetValue(AnyType & out) const;
        /**
         *  @return             Variant filled with the contents to which the
         *                      iterator points, if the type is supported by
         *                      Variant. Otherwise an empty Variant.
         */
        Variant GetValue() const;

        [[nodiscard]] bool operator==(const Iterator & other) const;
        [[nodiscard]] bool operator!=(const Iterator & other) const;

        /**
         *  Prefix increment operator.
         *
         *  @return             Reference to the incremented operator
         */
        Iterator & operator++();
        /**
         *  Postfix increment operator. Incurs a memory allocation, should be
         *  avoided unless there is a strong reason to prefer it over the
         *  prefix version.
         *
         *  @return             Copy of the current state of the iterator
         */
        [[nodiscard]] Iterator operator++(int);

    private:
        std::unique_ptr<Impl> m_impl;
    };

    [[nodiscard]] Iterator begin() const;
    [[nodiscard]] Iterator cbegin() const;

    [[nodiscard]] Iterator end() const;
    [[nodiscard]] Iterator cend() const;

    /**
     *  Merges the passed table into this object, keeping values from the
     *  passed table in the case of collisions. Invalidates iterators into this
     *  object.
     *
     *  If the merge fails, this object is in an invalid state.
     *
     *  @param  other           Table to merge into this object.
     *
     *  @return                 Whether the merge was successful.
     */
    bool Merge(const BinaryTable & other);

    void Clear();

    bool operator==(const BinaryTable & other) const;
    bool operator!=(const BinaryTable & other) const;
    bool operator<(const BinaryTable & other) const;
    bool operator>(const BinaryTable & other) const;
    bool operator<=(const BinaryTable & other) const;
    bool operator>=(const BinaryTable & other) const;

    // AnyType
    size_t GetHash() const override;

    bool Empty() const override;
    /** @cond PRIVATE */
    static constexpr TypeInfo GetTypeInfo() { return TypeInfo::SFT_BINARY_TABLE; }
    TypeInfo get_type_info() const override { return GetTypeInfo(); }

    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;
    /** @endcond */

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    friend STRATEGY_EXPORT class BinaryTableBuilder;

    std::unique_ptr<util::Buffer> m_data;
};

/**
 *  BinaryTableBuilder
 */
class STRATEGY_EXPORT BinaryTableBuilder : public Printable
{
public:
    BinaryTableBuilder();
    ~BinaryTableBuilder() override;

    BinaryTableBuilder(const BinaryTableBuilder & other);
    BinaryTableBuilder & operator=(const BinaryTableBuilder & other);

    BinaryTableBuilder(BinaryTableBuilder && other) noexcept;
    BinaryTableBuilder & operator=(BinaryTableBuilder && other) noexcept;

    /**
     *  Updates the value of a cell in the table.
     *
     *  @param  column_id       The column of the cell to update
     *  @param  row_id          The row of the cell to update
     *  @param  value           The new value
     */
    void UpdateCell(const Uuid & column_id, const Uuid & row_id, const AnyType & value);

    /**
     *  Updates the value of a cell in the table.
     *
     *  @param  def             The parameter definition of the column of the
     *                          cell to update
     *  @param  row_id          The row of the cell to update
     *  @param  value           The new value
     */
    void UpdateCell(const DefinitionBase & def, const Uuid & row_id, const AnyType & value) { UpdateCell(def.GetIdentifier(), row_id, value); }

    /**
     *  Updates the values of a row of cells in the table.
     *
     *  @param  row_id          The row to update
     *  @param  parameters      The set of new values
     */
    void UpdateRow(const Uuid & row_id, const StrategyParameters & parameters);

    /**
     *  Clears a cell in the table.
     *
     *  @param  column_id       The column of the cell to clear
     *  @param  row_id          The row of the cell to clear
     */
    void ClearCell(const Uuid & column_id, const Uuid & row_id);

    /**
     *  Clears a cell in the table.
     *
     *  @param  def             The parameter definition of the column of the
     *                          cell to clear
     *  @param  row_id          The row of the cell to clear
     */
    void ClearCell(const DefinitionBase & def, const Uuid & row_id) { ClearCell(def.GetIdentifier(), row_id); }

    /**
     *  Clears the table.
     */
    void Clear();

    /**
     *  Commits the current state of the builder into a BinaryTable object
     *  suitable for transmission and reading.
     *
     *  @return                 A packed and readable form of the table.
     */
    BinaryTable GetTable() const;

    /**
     *  Fills a BinaryTable object with the current state of the builder. If
     *  the builder object is empty, the parameter is left unchanged.
     *
     *  @param  out             The object to fill.
     */
    void GetTable(BinaryTable & out) const;

    /**
     *  @return                 Whether the table is empty.
     */
    bool Empty() const;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    std::unique_ptr<types::TableValues> m_data;
};

} // namespace tbricks

namespace std {

template <>
struct hash<tbricks::BinaryTable>
{
    using argument_type = tbricks::BinaryTable;
    using result_type = size_t;
    result_type operator()(const argument_type & data) const { return data.GetHash(); }
};

} // namespace std
